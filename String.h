#include <string.h>
#include <iostream>
using namespace std;


class String
{
	char * str;
	int n;
	int IsEqual(const String& S) const { return strcmp(str, S.str); }
	int IsLessThan(const String& S) const { return (strcmp(str, S.str) <= 0); }
public:
	String() { n = -1; str = 0; };
	explicit String(int nstr) { n = nstr<0 ? 0 : nstr; str = new char[n + 1]; str[n] = 0; }
	String(const char* s);
	String(const String&);
	String(String&&);
	~String() { delete[] str; };
	String& operator = (const String&);
	String& operator = (String&&);
	String& operator += (const String&);
	String operator () (int i, int j); //возвращает подстроку
									   //operator char*() {return str;} //оператор преобразования типа String к char*
	char& operator [] (int n) { return str[n-1]; }
	char operator [] (int n) const { return str[n - 1]; }
	friend int operator == (const String& s1, const String& s2)
	{
		return s1.IsEqual(s2);
	}
	friend int operator < (const String& s1, const String& s2)
	{
		return s1.IsLessThan(s2);
	}
	friend int operator != (const String& s1, const String& s2)
	{
		return !(s1 == s2);
	}
	friend int operator > (const String& s1, const String& s2)
	{
		return (s2<s1);
	}
	friend int operator <= (const String& s1, const String& s2)
	{
		return !(s2<s1);
	}
	friend int operator >= (const String& s1, const String& s2)
	{
		return !(s1<s2);
	}
	friend String operator + (const String&, const String&);
	friend ostream&  operator << (ostream& out, const String& S)
	{
		if (S.str) out << S.str; return out;
	};
	friend istream&  operator >> (istream& in, String& S);
};
