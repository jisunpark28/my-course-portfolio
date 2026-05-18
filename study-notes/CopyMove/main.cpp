#include <iostream>
#include <utility>
#include <string>
#include "Header.h"
using namespace std;
using namespace jisun;

void print(string name, IntArray src) {
	cout << name << " => [";
	for (size_t i = 0; i < src.size(); i++) {
		cout << src[i];
		if (i != src.size() - 1) cout << ", ";
	}
	cout << "]" << endl;
}

int main() {
	cout << "Constructor" << endl;
	IntArray I{ 5 }, J{ 10 };
	for (int i = 1; i < 11; I[i - 1] = i * 10, i++);
	print("I", I);
	print("J", J);

	cout << endl << "MOVE: I => J" << ": Move Assignment Operator" << endl;
	J = move(I);
	print("I", I);
	print("J", J);


	cout << endl << "MOVE: J => K" << ": Move Constructor" << endl;
	IntArray K = move(J);
	print("J", J);
	print("K", K);


	cout << endl << "COPY: K => I" << ": Copy Assignment Operator" << endl;
	I = K;
	print("K", K);
	print("I", I);

	cout << endl << "COPY: I => M" << ": Copy Constructor" << endl;
	IntArray M = I;
	print("I", I);
	print("M", M);

	return 0;
}