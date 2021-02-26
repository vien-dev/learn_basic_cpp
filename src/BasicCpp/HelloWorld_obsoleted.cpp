//============================================================================
// Name        : HelloWorld.cpp
// Author      : Vien Mai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//to use printf
#include <cstdio>

#include <iostream>
using namespace std;

static void learn_conditionals();
static void learn_while();
static void learn_for_loop();
static void learn_range_based_for_loop();
static void learn_printf();

int main() {
	learn_printf();

	return 0;
}

static void learn_printf() {
	printf("Hello World %d\n", 5);
	puts("Hello World");
	printf("Exit");
	printf("Exit");
}

static void learn_range_based_for_loop() {
	int array[] = { 1, 2, 3, 4, 5, 6 };
	char s[] = "String";

	for ( int i: array ) cout << "i is " << i << endl;

	for ( char c : s ) {
		if ( 0 == c ) break;
		cout << "c is " << c << endl;
	}
}

static void learn_for_loop() {
	char s[] = "Hello World!";

	for (int i = 0; s[i]; i++) {
		cout << "Value at " << i << " is " << s[i] << endl;
	}

	for (char *cp = s; *cp; cp++) {
		cout << *cp << endl;
	}
}

static void learn_while() {
	int a[] = { 1, 2, 3, 4, 5 };
	int i = 0;

	while (i < 5) {
		if (3 == i) break;
		cout << "Index " << i << " value " << a[i] << endl;
		i++;
	}
}

static void learn_conditionals() {
	cout << "True has value of " << (1 < 5) << endl;
	cout << "False has value of " << (1 > 5) << endl;

	if ( -1 ) {
		cout << "condition true" << endl;
	} else {
		cout << "condition false" << endl;
	}
}
