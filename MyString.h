//MyString.h : Declaretion of class:'MyString'
#ifndef MYSTRING_H
#define MYSTRING_H

//See implementation in MyString.cpp
//class:'MyStiring' :A class implement string type by using array.
class MyString
{
private:
	char *str;
	int length;

	int* _failure();
public:
	MyString(char*);
	void frequency();
	int find(MyString &pat);
	void print();
	int size();
};
#endif