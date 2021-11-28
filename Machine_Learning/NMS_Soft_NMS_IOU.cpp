#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
/**
非极大值抑制NMS Soft-NMS IOU计算实现
*/

float IOU(vector<float> &A, vector<float> &B){
	// 左上右下坐标(x1,y1,x2,y2)
	float w = max(0.0f, min(A[2], B[2]) - max(A[0], B[0]) + 1);
	float h = max(0.0f, min(A[3], B[3]) - max(A[1], B[1]) + 1);
	float area1 = (A[2] - A[0] + 1) * (A[3] - A[1] + 1);
	float area2 = (B[2] - B[0] + 1) * (B[3] - B[1] + 1);
	float inter = w * h;
	float iou = inter / (area1 + area2 - inter);
	return iou;
}

bool sort_score(vector<float> &box1, vector<float> &box2){
	return (box1[4] > box2[4]);
}

void NMS(vector<vector<float> > &vec_boxes, float thresh) {
	// box[0:4]: x1, x2, y1, y2; box[4]: score
	// 按分值从大到小排序
	std::sort(vec_boxes.begin(), vec_boxes.end(), sort_score);
	//标志，false代表留下，true代表扔掉
	vector<bool> del(vec_boxes.size(), false);
	for (size_t i = 0; i < vec_boxes.size()-1; i++){
		if (!del[i]){
			for (size_t j = i + 1; j < vec_boxes.size(); j++){
				if (!del[j] && IOU(vec_boxes[i], vec_boxes[j]) >= thresh){
						del[j] = true; //IOU大于阈值扔掉
				}
			}
		}
	}
	vector<vector<float>> result;
	for (size_t i = 0; i < vec_boxes.size(); i++){
		if (!del[i]) {
			result.push_back(vec_boxes[i]);
		}
	}
	vec_boxes.clear();
	vector<vector<float> >().swap(vec_boxes);
	vec_boxes = result;
}


vector<vector<float> > Soft_NMS(vector<vector<float> > vec_boxes, float sigma = 0.5, 
	float Nt = 0.5, float threshold = 0.1, unsigned int method = 0){
	int box_len = vec_boxes.size();
	for (int i = 0; i < box_len; i++){
		float tmp_x1 = vec_boxes[i][0];
		float tmp_y1 = vec_boxes[i][1];
		float tmp_x2 = vec_boxes[i][2];
		float tmp_y2 = vec_boxes[i][3];
		float tmp_score = vec_boxes[i][4];
		int max_pos = i;
		float max_scores = tmp_score;

		// get max box
		int pos = i + 1;
		while (pos < box_len){
			if (max_scores < vec_boxes[pos][4]){
				max_scores = vec_boxes[pos][4];
				max_pos = pos;
			}
			pos++;
		}

		//add max box as a detection
		vec_boxes[i][0] = vec_boxes[max_pos][0];
		vec_boxes[i][1] = vec_boxes[max_pos][1];
		vec_boxes[i][2] = vec_boxes[max_pos][2];
		vec_boxes[i][3] = vec_boxes[max_pos][3];
		vec_boxes[i][4] = vec_boxes[max_pos][4];

		// swap ith box with position of max box
		vec_boxes[max_pos][0] = tmp_x1;
		vec_boxes[max_pos][1] = tmp_y1;
		vec_boxes[max_pos][2] = tmp_x2;
		vec_boxes[max_pos][3] = tmp_y2;
		vec_boxes[max_pos][4] = tmp_score;

		// 将置信度最高的 box 赋给临时变量
		tmp_x1 = vec_boxes[i][0];
		tmp_y1 = vec_boxes[i][1];
		tmp_x2 = vec_boxes[i][2];
		tmp_y2 = vec_boxes[i][3];
		tmp_score = vec_boxes[i][4];

		pos = i + 1;
		while (pos < box_len){
			float x1 = vec_boxes[pos][0];
			float y1 = vec_boxes[pos][1];
			float x2 = vec_boxes[pos][2];
			float y2 = vec_boxes[pos][3];
			float area = (x2 - x1 + 1) * (y2 - y1 + 1);

			float iw = (min(tmp_x2, x2) - max(tmp_x1, x1) + 1);
			float ih = (min(tmp_y2, y2) - max(tmp_y1, y1) + 1);
			if (iw > 0 && ih> 0){
				float overlaps = iw * ih;
				float iou = overlaps / ((tmp_x2 - tmp_x1 + 1) * (tmp_y2 - tmp_y1 + 1) + area - overlaps);

				float weight = 0;
				if (method == 1){ //线性
					if (iou > Nt){
						weight = 1 - iou;
					}
					else{
						weight = 1;
					}
				}
				else if (method == 2){ // gaussian
					weight = exp(-(iou*iou) / sigma);
				}
				else{ // original NMS
					if (iou > Nt){
						weight = 0;
					}
					else{
						weight = 1;
					}
				}
				// 赋予该box新的置信度
				vec_boxes[pos][4] = weight * vec_boxes[pos][4];
				// 如果box得分低于阈值thresh，则通过与最后一个框交换来丢弃该框
				if (vec_boxes[pos][4] < threshold){
					vec_boxes[pos][0] = vec_boxes[box_len - 1][0];
					vec_boxes[pos][1] = vec_boxes[box_len - 1][1];
					vec_boxes[pos][2] = vec_boxes[box_len - 1][2];
					vec_boxes[pos][3] = vec_boxes[box_len - 1][3];
					vec_boxes[pos][4] = vec_boxes[box_len - 1][4];
					box_len--;
					pos--;
				}
			}
			pos++;
		}
	}
	vector<vector<float> > result(box_len);
	for (int i = 0; i < box_len; i++){
		result[i].resize(5);
		result[i][0] = vec_boxes[i][0];
		result[i][1] = vec_boxes[i][1];
		result[i][2] = vec_boxes[i][2];
		result[i][3] = vec_boxes[i][3];
		result[i][4] = vec_boxes[i][4];
	}
	return result;
}


int main(){
	vector<vector<float> > vec_boxes = { { 0, 0, 100, 101, 0.9f }, { 5, 6, 90, 110, 0.7f }, 
										{ 17, 19, 80, 120, 0.8f }, { 10, 8, 115, 105, 0.5f }};
	vector<vector<float> > result = Soft_NMS(vec_boxes, 0.5, 0.5, 0.1, 2);
	for (size_t i = 0; i < result.size(); i++){
		cout << result[i][0] << " " << result[i][1] << " " << result[i][2]
			<< " " << result[i][3] << " " << result[i][4] << endl;
	}
	system("pause");
	return 0;
}