#pragma once

//深浅拷贝
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class String {
public:
	//构造函数
	//函数的作用是构造一个String对象
	String(const char* str = "") {
		_size = strlen(str);
		//+1是因为要保存'\0'
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size + 1;
	}
	//拷贝构造函数
	String(const String& s)
	:_str(new char[strlen(s._str) + 1]){
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	//赋值运算符重载

	//传统写法
	//String& operator=(const String& s) {
	//	if (this != &s) {
	//		//传统写法是规规矩矩的
	//		//先把旧的内存空间释放
	//		delete[] _str;
	//		//然后再申请新的内存空间
	//		_str = new char[s._capacity];
	//		//然后再拷贝过去
	//		strcpy(_str, s._str);
	//		_size = s._size;
	//		_capacity = s._capacity;
	//		return *this;
	//	}
	//}



	//现代写法1
	//String& operator=(const String& s) {
	//	if (this != &s) {
	//		//创建一个临时变量,这里是用的拷贝构造函数，也可以用构造函数
	//		String tmp(s);
	//		//然后使用swap函数交换
	//		swap(_str, tmp._str);
	//		//tmp在函数结束时直接销毁
	//		_size = tmp._size;
	//		_capacity = tmp._capacity;
	//	}
	//	return *this;
	//}
	//


	//现代写法2
	//String& operator=(String s) {
	//	if (this != &s) {
	//		//传入进来的参数是传值的，函数结束后会销毁，跟上面的临时变量一样
	//		swap(_str, s._str);
	//		_size = s._size;
	//		_capacity = s._capacity;
	//	}
	//	return *this;
	//}
	//

	//现代写法4
	void Swap(String& s) {
		char* tmp = s._str;
		s._str = _str;
		_str = tmp;
	}
	String& operator=(String& s) {
		if (this != &s) {
			//这种方法也是先创建一个临时变量
			String tmp(s._str);
			//然后把两个对象的_str指针交换
			Swap(tmp);
			//然后更新_size和_capacity
			_size = tmp._size;
			_capacity = tmp._capacity;
		}
		return *this;
	}

	//赋值运算符重载
	String& operator=(const char* str) {
		//删除旧的字符
		delete[] _str;

		//计算出字符串大小
		size_t str_size = strlen(str);
		//开辟内存空间
		_capacity = str_size + 1;
		_str = new char[_capacity];
		//复制
		strcpy(_str, str);
		_size = _capacity - 1;
		return *this;
	}

	//析构函数
	~String() {
		delete[] _str;
		_str = NULL;
		_size = 0;
		_capacity = 0;
		cout << "~String" << endl;
	}

	//增删改查
	//扩容
	void Expand(size_t n);
	//增
	//尾插一个字符
	void PushBack(char ch);
	//尾插一个字符串
	void PushBack(const char* str);
	//头插一个字符
	void PushFront(char ch);
	//头插一个字符串
	void PushFront(const char* str);
	//尾删
	void PopBack();
	//在指定位置插入一个字符
	void Insert(size_t pos, char ch);
	//在指定位置插入一个字符串
	void Insert(size_t pos, const char* ch);
	//在指定位置之后删除长度为n的字符
	void Erase(size_t pos, size_t n = 1);

	char& operator[](size_t pos);

	//查找字符
	int Find(char ch);

	//使用KMP查找字符串
	//获取子串nextval数组
	void getNextval(const char* pattern, int* nextval);
	//也可以将该函数放在private成员函数中，避免外部直接调用该函数
	//这样可以提高代码的封装性和安全性。
    int Find(const char* pattern);

	//运算符重载
	//+
	//字符
	String operator+(char ch);
	//字符串
	String operator+(const char* str);
	//+=
	//字符
	String& operator+=(char ch);
	//字符串
	String& operator+=(const char* ch);

	//比较
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

	//返回_size
	size_t String_size() {
		return _size;
	}
	//返回_capacity
	size_t String_capacity() {
		return _capacity;
	}
	//返回字符串
	char* String_str() {
		return _str;
	}
	//打印字符串
	void Show() {
		printf("%s\n", _str);
	}
private:
	char* _str;// 缓冲区指针
	size_t _size;// 字符串长度
	size_t _capacity;// 缓冲区容量
};
