#include "Variable.h"

Variable::Variable(int buff){
	*this->buff = buff;
}

Variable::Variable(){
	this->buff = nullptr;
}


Variable::~Variable(){
	delete buff;
}

void Variable::setInt(int x){
	this->buff = reinterpret_cast <char*>(&x);
}

void Variable::setDouble(double x){
	cout << x << endl;
	this->buff = reinterpret_cast <char*>(&x);
	cout << this->buff << endl;
}

void Variable::setChar(char x){
	this->buff = reinterpret_cast <char*>(&x);
}

void Variable::setShort(short x){
	this->buff = reinterpret_cast <char*>(&x);
}

void Variable::setUnsigned(unsigned x){
	this->buff = reinterpret_cast <char*>(&x);
}

int Variable::getInt()
{
	return  *reinterpret_cast <int*>(this->buff);
}

double Variable::getDouble()
{
	return  *reinterpret_cast <double*>(this->buff);
}

char Variable::getChar(){
	return *reinterpret_cast <char*>(this->buff);
}

unsigned Variable::getUnsigned()
{
	return *reinterpret_cast <unsigned*>(this->buff);
}

short Variable::getShort(){
	return *reinterpret_cast <short*>(this->buff);
}
