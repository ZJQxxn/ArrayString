//MyString.cpp : Implementation of class:'MyString'
#include "MyString.h"
#include <iostream>
using std::cout;
using std::endl;

//constructor
MyString::MyString(char *str)
	:str(str)
{
	int index = 0;
	char temp = str[index];
	while (temp != '\0')
	{
		index++;
		temp = str[index];
	}
	length = index;
}


//private operations
/*
	Calculate failure function for each chars

	Return:int*
*/
int* MyString::_failure()
{
	//f[index] indicate how many steps pattern will move forward after mismatching at 'index'
	int *f = new int[length];
	f[0] = -1;
	//traverse all the chars
	for (int index = 1; index < length; index++)
	{
		int i = f[index - 1];
		while ((*(str+index) != *(str+i + 1)) && (i >= 0))
		{
			i = f[i];
		}
		if (*(str+index) == *(str+i + 1))
		{
			f[index] = i + 1;
		}
		else
		{
			f[index] = 0;
		}
	}
	return f;
}


//public Operation
/*
	Determine the frequency of each charactor in a string
	and print them.

	Return:void
*/
void MyString::frequency()
{
	int *frequency = new int[length];
	char *charactor = new char[length];
	int counts = 0;
	//traverse through 'str'
	for (int i = 0; i < length; i++)
	{
		//traverse through all the distinct char
		int j = 0;
		for (; j < counts; j++)
		{
			if (str[i] == charactor[j])
			{
				frequency[j]++;
				break;
			}
		}
		//if this charactor appears for the first time
		if (j == counts)
		{
			charactor[j] = str[i];
			frequency[j] = 1;
			counts++;
		}
	}
	
	//print result
	cout << "Frequency:\n";
	for (int index = 0; index < counts; index++)
	{
		cout << charactor[index] << '\t' << frequency[index] << endl;
	}
}

/*
	Find pattern 'pat' in this string,return the beginning index 
	of pattern.Return -1 if not found.

	Parameter:pat	MyString	The pattern string.

	Return:int	Beginning index of pattern in this string.
*/
int MyString::find(MyString &pat)
{
	int str_index = 0;
	int pat_index = 0;
	int *f = pat._failure();
	while (str_index < length && pat_index < pat.length)
	{
		if (*(str+str_index) == *(pat.str+pat_index))
		{
			str_index++;
			pat_index++;
		}
		else
		{
			if (pat_index == 0)
			{
				str_index++;
			}
			else
			{
				pat_index = f[pat_index - 1] + 1;
			}
		}
	}
	if (pat_index == pat.length)
	{
		return str_index - pat.length;
	}
	else
	{
		return -1;
	}
}

/*
	Print this string

	Return:void
*/
void MyString::print()
{
	cout << "String content:" << str << endl;
}

/*
	Get length of string.

	Return:int	The length of string
*/
int MyString::size()
{
	return length;
}