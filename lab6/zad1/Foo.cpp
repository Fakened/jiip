#include "Foo.h"


int Foo::howMany = 0;

Foo::Foo(){
	howMany++;
}

Foo::~Foo() {
	howMany--;
}

void Foo::getInstances(){
	return howMany;
}

