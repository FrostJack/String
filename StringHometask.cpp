// StringHometask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"
using namespace std;

int main()
{
	char* test = "MMisthebest";
	char* t = "MM";
	char* est = "isthebest";
	String a("MMisthebest");
	String b(0);
	String c(3);
	String d(-3);
	String e;
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;

	String f = t;
	String g = est;
	cout << f << " " << g << endl;
	
	String h = move(g);
	String i(move(f));
	cout << f << " " << g << " " << h << " " << i << " " << endl;

	i += h;
	cout << i << endl;;

	String j = i(1, 2);
	String k = i(2, 1);
	String l = i(3, strlen(test));
	cout << j << " " << l << " " << k << endl;

	String m = j + l;
	cout << m << endl;

	String in;
	cout << "Pls, writeln some string to test operator>> for class String" << endl;
	cin >> in;
	cout << in << endl;

	char c1 = m[1];
	m[11] = '!';
	cout << c1 << " " << m << endl;

	m += m;
	cout << m << endl;

	m = m + m;
	cout << m << endl;
    return 0;
}

