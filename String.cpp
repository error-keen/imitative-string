#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"

//增删改查
//扩容
void String::Expand(size_t n) {
	//先申请大小为n的内存空间
	char* tmp = new char[n];
	//然后复制
	strcpy(tmp, _str);
	delete[] _str;
	_str = tmp;
	_capacity = n;
}
//增
//尾插一个字符
void String::PushBack(char ch) {
	if (_size + 1 >= _capacity) {
		//直接扩大两倍
		Expand(_capacity * 2);
	}
	_str[_size++] = ch;
	_str[_size] = '\0';
}

//尾插一个字符串
void String::PushBack(const char* str) {
	size_t str_size = strlen(str);
	if (_size + str_size + 1 >= _capacity) {
		//如果空间不够就进行扩容
		_capacity += str_size;
		Expand(_capacity);
		//然后再拷贝
		while (*str != '\0') {
			_str[_size++] = *str++;
		}
		_str[_size] = '\0';
	}
}

//头插一个字符
void String::PushFront(char ch) {
	if (_size + 1 >= _capacity) {
		//扩容
		Expand(_capacity * 2);
	}
	//要头插一个字符串，先把最后一个元素设置为\0
	_str[_size + 1] = '\0';
	for (int i = _size; i > 0; --i) {
		_str[i] = _str[i - 1];
	}
	_str[0] = ch;
	_size += 1;
}

//头插一个字符串
void String::PushFront(const char* str) {
	//计算出要插入的字符串的长度
	size_t str_size = strlen(str);
	//如果要插入的字符串的长度加上原有的字符串长度大于已有的容量，就进行扩容
	if (str_size + _size + 1 >= _capacity) {
		_capacity = str_size + _size + 1;
		//扩容
		Expand(_capacity);
	}
	//_capacity表示容量，总共可以有多少个元素
	//事实上，我们可以认为_size是_str字符数组的最后一个元素了，因为它存的是'\0'
	_str[_size + str_size] = '\0';
	//所以，最后一个元素应该是在_capacity-2的位置
	size_t index_prev = _size;
	size_t index_last = _size + str_size - 1;
	while (index_prev) {
		_str[index_last--] = _str[--index_prev];
	}
	//index_prev当前一定是0
	while (*str != '\0') {
		_str[index_prev++] = *str++;
	}
	_size += str_size;
}

//尾删
void String::PopBack() {
	//判断字符串是否为空字符串
	if (_size == 0) {
		printf("字符串已为空!\n");
		return;
	}
	_size--;
	_str[_size] = '\0';
}

//在指定位置插入一个字符
void String::Insert(size_t pos, char ch) {
	if (pos > _size) {
		//可以等于_size，表示尾插了一个字符
		//为了让Insert更通用，就不调用pushback尾插了
		printf("pos位置传入错误!\n");
		return;
	}
	else {
		//pos的位置是正常的，可以插入
		if (_size + 1 >= _capacity) {
			//扩容
			Expand(_capacity*2);
		}
		//先把'\0'加上
		_str[_size + 1] = '\0';
		//先把pos之后的位置全部向后挪一个位置(包括pos)
		for (int i = _size; i > (int)pos; --i) {
			_str[i] = _str[i - 1];
		}
		//然后再在pos的位置插入字符
		_str[pos] = ch;
		_size++;
	}
}

//在指定位置插入一个字符串
void String::Insert(size_t pos, const char* str) {
	//先判断参数是否正确
	if (pos > _size) {
		printf("pos位置传入错误!\n");
		return;
	}
	//求出要插入字符串的长度
	size_t str_size = strlen(str);
	if (str_size == 0) {
		//表示要插入的字符串是空字符串，直接返回
		return;
	}
	//然后判断_capaciy是否足够
	if (_size + str_size + 1 > _capacity) {
		//原本字符串中字符的个数加上要插入的字符串字符的个数再加上'\0'就是我们需要的空间
		_capacity = _size + str_size + 1;
		Expand(_capacity);
	}
	//把'\0'先加上
	int last_index = _size + str_size;
	_str[last_index--] = '\0';
	//然后把pos之后的字符串都向后挪str_size个位置
	for (int i = _size - 1; i >= (int)pos; --i) {
		_str[last_index--] = _str[i];
	}
	//然后从pos位置开始插入要插入的字符串
	while (*str != '\0') {
		_str[pos++] = *str++;
	}
	//更新size
	_size += str_size;
}

//在指定位置之后删除长度为n的字符
void String::Erase(size_t pos, size_t n) {
	//判断参数的合法性
	//pos等于_size是"合法"的，但是没有意义,'\0'是不能删除的
	//所以这里直接就判断为不合法了
	if (pos >= _size) {
		//传入的位置pos不合法
		printf("pos位置传入不合法!\n");
		return;
	}
	//删除pos之后的n个元素
	if (pos + n < _size) {
		//删除pos之后n个字符
		size_t index_erase = pos + n;
		while (index_erase != _size) {
			_str[pos++] = _str[index_erase++];
		}
	}
	//当pos + n大于等于_size时，都是删除pos之后的所有元素
	_str[pos] = '\0';
	_size = pos;
}

//[]运算符重载
char& String::operator[](size_t pos) {
	return _str[pos];
}

//查找字符
int String::Find(char ch) {
	for (size_t i = 0; i < _size; ++i) {
		if (_str[i] == ch) {
			//找到了就返回下标
			return i;
		}
	}
	return -1;
}
//获取子串nextval数组
void String::getNextval(const char* pattern, int* nextval) {
    int patternLen = strlen(pattern); // 获取子串的长度
    int i = 0, j = -1; // 初始化i和j的值
    nextval[0] = -1; // 第一个元素的值为-1

    while (i < patternLen - 1) { // 循环遍历子串
        if (j == -1 || pattern[i] == pattern[j]) { // 如果j为-1或者当前字符与子串的字符相等
            i++; // i和j都向后移动一位
            j++;
            if (pattern[i] != pattern[j]) // 如果当前字符与子串的字符不相等
                nextval[i] = j; // nextval[i]的值为j
            else
                nextval[i] = nextval[j]; // nextval[i]的值为nextval[j]
        } else {
            j = nextval[j]; // 如果当前字符与子串的字符不相等，j的值为nextval[j]
        }
    }
}

//查找字符串
int String::Find(const char* pattern) {
    int textlen = _size; // 获取文本的长度
    int patternlen = strlen(pattern); // 获取子串的长度

    if (patternlen == 0) {
        return -1; // 子串为空，直接返回-1
    }

    int* nextval = new int[patternlen]; // 创建一个数组用于存储子串的nextval数组
    getNextval(pattern, nextval); // 获取子串的nextval数组

    int i = 0, j = 0; // 初始化i和j的值
    while (i < textlen && j < patternlen) { // 循环遍历文本和子串
        if (j == -1 || _str[i] == pattern[j]) { // 如果j为-1或者当前字符与子串的字符相等
            i++; // i和j都向后移动一位
            j++;
        } else {
            j = nextval[j]; // 如果当前字符与子串的字符不相等，j的值为nextval[j]
        }
    }

    delete[] nextval; // 释放内存

    if (j == patternlen) {
        return i - j; // 找到子串的位置
    } else {
        return -1; // 未找到子串
    }
}


//运算符重载
//+
//字符
String String::operator+(char ch) {
	//重新开辟一块内存空间，然后加上去再返回
	String tmp(_str);
	tmp.Insert(_size, ch);
	return tmp;
}

//字符串
String String::operator+(const char* str) {
	String tmp(_str);
	tmp.Insert(_size, str);
	return tmp;
}

//+=
//字符
String& String::operator+=(char ch) {
	Insert(_size, ch);
	return *this;
}

//字符串
String& String::operator+=(const char* str) {
	Insert(_size, str);
	return *this;
}

//比较
bool String::operator>(const String& s) {
	int i = 0;
	while (_str[i] == s._str[i] && i < _size) {
		//当两个字符串字符相等时进入循环
		i++;
	}
	//不相等或遍历完了_str时退出循环
	if (i == _size) {
		//表示_str遍历完了,则肯定不大于
		return false;
	}
	return _str[i] > s._str[i] ? true : false;
}

bool String::operator==(const String& s) {
	int i = 0;
	while (_str[i] == s._str[i] && i < _size) {
		i++;
	}
	//遍历两个字符串，如果遍历完了，则表示相等
	if (i == _size && s._str[i] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

bool String::operator>=(const String& s) {
	if (*this > s || *this == s) {
		return true;
	}
	return false;
}

bool String::operator<(const String& s) {
	if (!(*this >= s)) {
		return true;
	}
	return false;
}

bool String::operator<=(const String& s) {
	if (*this > s) {
		return false;
	}
	return true;
}

bool String::operator!=(const String& s) {
	if (*this == s) {
		return false;
	}
	return true;
}

