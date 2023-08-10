# imitative-string
模拟string类，C++中string类是个管理字符串的类，而在面试中，如何模拟实现string类也是一个考点，我在这里简单的实现一下如何模拟实现一个string类。  
# 解释说明
成员变量：  
char* _str表示字符串指针，size_t _size表示字符串的长度（不包含'\0'），size_t _capacity表示申请的内存空间的大小;  

成员函数：  
主要包括各种运算符重载和增删改查的实现，这里不一一详细解释，具体看代码，上面有详细的解释。



# 测试效果
Test1-Test4  

![image](https://github.com/keen1dream/data-structure/blob/main/img/01.png)  

Test5-Test8  
![image](https://github.com/keen1dream/data-structure/blob/main/img/02.png)  

Test9-Test10  

![image](https://github.com/keen1dream/data-structure/blob/main/img/03.png)  

# 总结
我的这个版本也有很多不完善的地方，比如拷贝构造函数可以优化很多，然后就是string接口太多了，还有很多接口我都没有实现，欢迎大家在我的基础上去增加完善。
