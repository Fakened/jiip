#pragma once
#include <iostream>

using namespace std;

class Foo{
	static int howMany;
public:
	Foo();
	~Foo();
	static void getInstances();
};

