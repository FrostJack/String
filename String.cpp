#include "stdafx.h"
#include "String.h"

String::String(const char* s) : n(strlen(s)), str(nullptr) {
	str = new char[n + 1];
	if (n != 0) {
		strcpy(str, s);
	}
	else str[n] = 0;
}

String::String(const String& s) : n(s.n), str(nullptr) {
	if (n >= 0) {
		str = new char[n + 1];
		strcpy(str, s.str);
	}
}

String::String(String&& s) : n(s.n), str(s.str) {
	s.str = nullptr;
	s.n = -1;
}

String& String::operator= (const String& s) {
	if (this != &s) {
		if (n != s.n) {
			delete[] str;
			str = nullptr;
			n = s.n;
		}
		if (n >= 0) {
			str = new char[n + 1];
			strcpy(str, s.str);
		}
	}
	return *this;
}

String& String::operator= (String&& s) {
	if (this != &s) {
		n = s.n;
		s.n = -1;
		delete[] str;
		str = s.str;
		s.str = nullptr;
	}
	return *this;
}

String& String::operator+= (const String& s) {
	if (s.n > 0) {
		char* temp;
		if (n > 0)
			temp = new char[n + s.n + 1];
		else
			temp = new char[s.n + 1];
		if (n > 0) {
			strcpy(temp, str);
			strcat(temp, s.str);
			n += s.n;
		}
		else {
			strcpy(temp, s.str);
			n = s.n;
		}
		delete[] str;
		str = temp;
	}
	return *this;
}

String String::operator() (int i, int j) {
	String subs;
	subs.str = new char[j - i + 2];
	char* p = str;
	p += (i - 1);
	strncpy(subs.str, p, j - i + 1);
	subs.str[j - i + 1] = 0;
	subs.n = j - i + 1;
	return subs;
}

String operator+ (const String& addend, const String& summand) {
	String sum(addend);
	sum += summand;
	return sum;
}

istream&  operator >> (istream& in, String& S) {
	char* string = new char[1000];
	cin >> string;
	String temp(string);
	S = move(temp);
	return in;
}