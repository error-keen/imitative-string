 #define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"

#define TESTHEAD  printf("---------------------%s-------------------\n", __FUNCTION__)

//测试构造函数
void Test1() {
	TESTHEAD;
	//构造函数
	//正常构造
	String s("hello");
	s.Show();
	printf("expect 6, actual: _size = %d, _capacity = %d\n",
		s.String_size(), s.String_capacity());
	//缺省构造
	String s2;
	s2.Show();
	printf("expect 1, actual: _size = %d, _capacity = %d\n",
		s2.String_size(), s2.String_capacity());

	//拷贝构造函数
	//正常拷贝构造
	String s3 = s;
	s3.Show();
	printf("expect 6, actual: _size = %d, _capacity = %d\n",
		s3.String_size(), s3.String_capacity());
	//拷贝构造一个空字符串
	String s4(s2);
	s4.Show();
	printf("expect 1, actual: _size = %d, _capacity = %d\n",
		s4.String_size(), s4.String_capacity());
	String s5 = "hello world";
	s5.Show();
	String s6 = "";
	s6.Show();
}

//测试赋值运算符重载
void Test2() {
	TESTHEAD;
	String s1("hello world");
	s1.Show();
	String s2("hello");
	s2 = s1;
	s2.Show();
}

//测试尾插
void Test3() {
	TESTHEAD;
	//尾插字符
	String s1("hello");
	s1.Show();
	s1.PushBack(' ');
	s1.PushBack('w');
	s1.PushBack('o');
	s1.PushBack('r');
	s1.PushBack('l');
	s1.PushBack('d');
	s1.Show();
	//尾插字符串
	s1.PushBack(" hello world!");
	s1.Show();
	//尾插一个空字符串
	s1.PushBack("");
	s1.Show();
}

//测试头插
void Test4() {
	TESTHEAD;
	//头插一个字符
	String s1("ello");
	s1.Show();
	s1.PushFront('h');
	s1.Show();
	s1.PushFront('e');
	s1.Show();
	//头插一个字符串
	String s2("world!");
	s2.Show();
	s2.PushFront("hello ");
	s2.Show();
	s2.PushFront("");
	s2.Show();
}

//测试尾删
void Test5() {
	TESTHEAD;
	String s1("hello");
	s1.Show();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.Show();
	s1.PopBack();
	s1.PopBack();
	s1.Show();
	s1.PopBack();
}

//测试insert函数
void Test6() {
	TESTHEAD;
	//测试插入一个字符
	String s1("ello worl");
	s1.Show();
	//在开头位置插入
	s1.Insert(0, 'h');
	s1.Show();
	//在中间位置插入
	s1.Insert(5, '~');
	s1.Show();
	//在末尾插入
	s1.Insert(11, 'd');
	s1.Show();

	//测试插入字符串
	String s2("adefg");
	s2.Show();
	//在开头插入一个字符串
	s2.Insert(0, "hehe ");
	s2.Show();
	//在末尾插入一个字符串
	size_t pos = s2.String_size();
	s2.Insert(pos, "higklmnopq");
	s2.Show();
	//在中间插入一个字符串
	s2.Insert(6, "bc");
	s2.Show();
	//插入一个空字符串
	s2.Insert(0, "");
	s2.Insert(5, "");
	pos = s2.String_size();
	s2.Insert(pos, "");
	s2.Show();
	//传入非法的pos位置
	pos = 200;
	s2.Insert(pos, "hehe");
}

//测试删除一个元素
void Test7() {
	TESTHEAD;
	String s1("hello world!");
	s1.Show();
	//传入pos位置正确，n小于pos之后的字符串长度
	s1.Erase(0, 6);
	s1.Show();
	//传入pos位置正确，n大于pos之后的字符串长度
	s1.Erase(0, 10);
	s1.Show();
	//传入pos位置正确，n等于pos之后的字符串长度
	String s2("hello");
	s2.Show();
	s2.Erase(2, 3);
	s2.Show();
	//传入pos的位置正确，n缺省
	s2.Erase(1);
	s2.Show();
	//传入pos的位置错误
	s2.Erase(2);

}

//测试Find
void Test8() {
	TESTHEAD;
	//测试用例1，有多种只匹配前几个的
	String s1("abcbcdbcdef");
	char* find = "bcde";
	size_t pos = s1.Find(find);
	printf("expect 6, actual:%lu\n", pos);

	//测试用例2，要查找的刚好是源字符串
	String s2("abcd");
	char* find2 = "abcd";
	size_t pos2 = s2.Find(find2);
	printf("expecr 0, acutla:%lu\n", pos2);

	//测试用例3,查找的字符串刚好在_str的末尾
	String s3("asebcde");
	char* find3 = "bcde";
	size_t pos3 = s3.Find(find3);
	printf("expect 3, actual:%lu\n", pos3);

	//测试用例4，没有可查找的字符串
	String s4("abdfdsg");
	char* find4 = "saf";
	size_t pos4 = s4.Find(find4);
	printf("expect -1, actual: %d\n", (int)pos4);
}

//测试+ +=
void Test9() {
	TESTHEAD;
	String s1("hello worl");
	s1.Show();
	String s2 = s1 + 'd';
	s2.Show();
	String s3=s2 + " hello world!";
	s3.Show();

	s1 += 'd';
	s1.Show();

	s1 += " hello world";
	s1.Show();
}

//测试 > >= < <= == !=
void Test10() {
	TESTHEAD;
	String s1("hello world");
	String s2("hello worle");
	//测试>
	if (s2 > s1) {
		printf("s2 > s1\n");
	}
	s1 = "hello";
	s1.Show();
	s2 = "hello";
	s2.Show();
	if (s2 > s1 || s1 > s2) {
		//打印不出来是正常的
		printf("错误\n");
	}
	//测试==
	if (s1 == s2) {
		printf("s1 == s2\n");
	}
	s1 = "hellop";
	if (s1 == s2) {
		printf("错误\n");
	}
	//测试>=
	//测试<
	//测试<=
	//测试!=
}

void Test() {
	TESTHEAD;
	String s1("hehehe");
	String s2("hehehe");
	if (s2 > s1) {
		printf("right");
	}
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	char* p1 = "";
	char*  p2 = "abcdefg";
	swap(p1, p2);
	cout << "p1:";
	cout << p1 << endl;
	//Test();
	system("pause");
	return 0;
}
