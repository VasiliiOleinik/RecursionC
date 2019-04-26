// HelloRecursion.cpp:
//


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using std::cout;
using std::cin;
using std::setw;

void init();
void f();
void g();
void h();

int cnt = 0;
int fact(int n);
long long fibo(int n);
long long fibo1(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	init();
	f();
	// cout << cnt << "\n";
	
	cnt = 0;
	g();

	int f1 = fact(5);
	cout << "Factorial " << 5 <<"! = " << f1 << "\n";

	for (int i = 1; i <= 50; i++) {
		long long f2 = fibo1(i);
		cout << "Fibonacci number " << i << " = " << f2 << "\n";
	} // for i
	return 0;
} // _tmain


// Preparing the application for work
void init()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(GetTickCount());
} // init


// Direct recursion
void f() {
	
	cout << ++cnt << "\n";
	if (cnt == 5) return;

	f();
} // f

// Indirect recursion from g () is called h (), from h () - g ()
void g() {
	cout << "g: " << ++cnt << "\n";
	if (cnt >= 5) return;
	h();
} // g

void h() {
	cout << "h: " << ++cnt << "\n";
	if (cnt >= 5) return;
	g();
} // h


//--------------- Examples of using ---------------------
int fact(int n){
	if (n == 1) return 1;
	        
	return n * fact(n - 1);
} // fact


long long fibo(int n) {
	if (n <= 2) return 1;
	return fibo(n - 1) + fibo(n - 2);
} // fibo


long long fibo1(int n) {
	long long t1, t2, s;

	t1 = t2 = 1;
	s = 0;
	for (int i = 3; i <= n; i++) {
		s = t1 + t2;
		t2 = t1;
		t1 = s;
	} // for i

	return s;
} // fibo