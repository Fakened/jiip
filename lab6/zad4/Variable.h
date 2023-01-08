#pragma once
#include <iostream>
using namespace std;
class Variable
{
	char *buff;
public:
	Variable();
	Variable(int buff);
	~Variable();
	void setInt(int x);
	void setDouble(double x);
	void setChar(char x);
	void setShort(short x);
	void setUnsigned(unsigned x);
	int getInt();
	double getDouble();
	char getChar();
	short getShort();
	unsigned getUnsigned();
};

