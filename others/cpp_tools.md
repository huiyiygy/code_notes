# C++常用库函数

[TOC]

## C++输出、输出

```cpp

```

## string常用库函数
```cpp
// 01. 创建
string s = "abc";

// 02. 字符串长度
int n = s.size(); // size()和length()实现相同
int n = s.length();

// 03. 复制
string s = s1; // 深复制，修改s中某个字符，不会影响s1

// 04.添加
s.append ("ABC")  // 在s末尾添加一个"ABC"字符串

// 05. 拼接
string s = s1 + s2;

// 06. 索引，修改某个位置的字符
s[5] = 'a';

// 07. 删除
s.erase(2,n);   //从下标为2的位置删除n个字符,比如: "ABCD"  --> "ABD"，n默认为1

// 08. 查找
int pos = s.find(s1, n);     //从s中位置n开始，正向查找第一次出现s1的位置，并返回（包括0），n 默认为 0。若找不到则 pos = s.npos

int pos = s.find(s1, 2, 2); //从s中的 第2个字符 开始正向查找 s1的 前2个 字符

int pos = s.rfind(s1, n);    //从s中倒数第n个字符开始，逆向查找第一次出现s1的位置，并返回，n 默认为s.end()。若找不到则 pos = s.npos

int pos = s.rfind(s1, 2, 2); //从s中倒数第2个字符 开始逆向查找 s1的 前2个 字符

// 09. 截取
string s1 = s.substr(pos, n);  //截取s中从pos开始（包括0）的n个字符的子串，并返回

string s1 = s.substr(pos);     //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回

// 10. 拆分 将 A 字符串，根据 B 拆分为多个子串
vector<string> result = str_spilt(A, B); // str_spilt()函数 实现见./String/001_str_spilt.cpp

// 11. 翻转 将 "abcd"  翻转为 "dcba"
#include<algorithm> // 需要引入包
string s1 = reverse(s.begin(), s.end());
string s1(s.rbegin(), s.rend()); // 第二种翻转方法，利用字符串逆向迭代器

// 12. 替换
s.replace(pos, n, s1);    // 用s1替换s中从pos开始（包括0）的n个字符的子串

int pos = s.find(b);  // 用字符串a 替换 s中 所有的 字符串 b
while(pos != s.npos){
    s.replace(pos, b.length(), a);
    pos = s.find(b);
}

// 13. 排序
// 将s中字符从小到大排序
// 注意：sort()会修改s中内容，若不希望影响，可先新建一个string temp = s，然后对temp进行排序
sort(s.begin(), s.end());

// 14. 比较大小
// 操作符包括 >、<、==、>=、<=、!=
// 原理 两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇’\0’为止，’\0’的ASCII值为 0
// ASCII值大小 0-9数字：48-57 大写字母：65-90 小写字母 97-122
// 如 "abc" > "abC" ，由于小写字符'c' 的 ASCII值比 大写字符'C'的 大，故 直接返回 true
// 如 "878945665" > "91"，由于 第一位 '8' 的ASCII值 比 '9'小，故直接返回 false，后续
bool flag = s1 > s2; 

// 15. 字符串 转 数字
#include<cstdlib> // 需要引入包
int res = std::stoi("-00123abc"); // res= -123 会保留负号，会把数字前的0抹除，非数字部分不会转换
long res = std::stol("-00123abc");
long long res = std::stoll("-00123abc");

// 16. 数字 转 字符串
string s = std::to_string(-123.48);  // s = "-123.48"  只支持十进制数字，int/float/unsign均支持，并会保留负号

// 17. 字符串正向迭代器，逆向迭代器
s.begin() // 字符正向首位
s.end()  // 字符正向末位  // 二者在字符串正向迭代时，配合使用

s.rbegin() // 字符逆向首位
s.rend() // 字符逆向末位  // 二者在字符串逆向迭代时，配合使用
```

## vector常用库函数
```cpp

```