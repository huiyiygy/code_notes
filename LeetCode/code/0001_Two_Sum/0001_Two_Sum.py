# -*- coding:utf-8 -*-
"""
输入: nums = [2, 7, 11, 15], target = 9
输出: [0, 1]
"""

class Solution:
    def twoSum(self, nums, target):
        n = len(nums)
        temp_dict = {}
        result = []
        for i in range(n):
            another = target - nums[i]
            index = temp_dict.get(another, -1)
            if index != -1:
                result.append(index)
                result.append(i)
                break
            else:
                temp_dict[nums[i]] = i
        return result

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    s = Solution()
    result = s.twoSum(nums, target)
    print(result)
