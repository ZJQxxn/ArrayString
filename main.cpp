//main.cpp : Man funtion to test class:'MyString'
#include "MyString.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	MyString str1("abcdbac");
	MyString str2("cd");
	str1.print();
	str2.print();
	cout << "Find str2 in str1 at:" << str1.find(str2) << endl;
	system("pause");
	return 0;
}