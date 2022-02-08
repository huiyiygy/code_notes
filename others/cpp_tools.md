# C++常用库函数

[TOC]

## C++输出、输出

```cpp

```

## string常用库函数
```cpp
// 创建
string s = "abc";

// 字符串长度
int n = s.size(); // size()和length()实现相同
int n = s.length();

// 复制(深复制)，修改s中某个字符，不会影响s1
string s = s1;

// 拼接
string s = s1 + s2;

// 索引，修改某个位置的字符
s[5] = 'a';

// 查找
int pos = s.find(s1, n);     //从s中位置n开始，正向查找第一次出现s1的位置，并返回（包括0），n 默认为 0。若找不到则 pos = s.npos

int pos = s.find(s1, 2, 2); //从s中的 第2个字符 开始正向查找 s1的 前2个 字符

int pos = s.rfind(s1, n);    //从s中倒数第n个字符开始，逆向查找第一次出现s1的位置，并返回，n 默认为s.end()。若找不到则 pos = s.npos

int pos = s.rfind(s1, 2, 2); //从s中倒数第2个字符 开始逆向查找 s1的 前2个 字符

// 截取
string s1 = s.substr(pos, n);  //截取s中从pos开始（包括0）的n个字符的子串，并返回

string s1 = s.substr(pos);     //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回

// 替换
s.replace(pos, n, s1);    // 用s1替换s中从pos开始（包括0）的n个字符的子串

int pos = s.find(b);  // 用字符串a 替换 s中 所有的 字符串 b
while(pos != s.npos){
    s.replace(pos, b.length(), a);
    pos = s.find(b);
}

// 排序
// 将s中字符从小到大排序
// 注意：sort()会修改s中内容，若不希望影响，可先新建一个string temp = s，然后对temp进行排序
sort(s.begin(), s.end());
```

## vector常用库函数
```cpp

```