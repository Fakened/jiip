#include <iostream>
#include <vector>
#include "Triple.h"

using namespace std;



template<typename T>

T minx(T a, T b) {
	if (a < b)
	return a;
	return b;
}

template<typename X>

X maxx(X a, X b) {
	if (a > b)
	return a;
	return b;
}

template<typename A>

A printArray(A arr[], A i) {
	return arr[i];
}


template<typename Z >

Z find(vector<Z> vec, Z x) {
	int i;
	for (i = 0; i < vec.size(); i++) {
		if (x == vec[i])
		return i;
	}
	return -1;
}

int main()
{
	int a[3] = { 1,2,3 };
	vector<int> vec = {1,2,3,4,5,6};

	cout << maxx(2.5, 3.3) << endl;
	cout << minx(2, 3) << endl;
	cout << printArray(a, 1) << endl;
	cout << find(vec, 10) << endl;
	cout << endl << endl;

	Triple<int> v1;
	Triple<double> v2;
	Triple<string> v3;

	v1.setFirst(1);
	v2.setFirst(2);
	v3.setFirst("a");
	cout << v1.getFirst() << " " << v2.getFirst() << " " << v3.getFirst() << endl;
}