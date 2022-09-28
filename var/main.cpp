#include "var.h"
#include <iostream>
using namespace std;

int main() {
	var a = 15;
	var b = "Hello";
	var c = 7.8;
	var d = "50";
	b = a + d;
	cout << b; // Выведет 65
	if (a == b) cout << "Equal\n"; else cout << "Not Equal\n";
}