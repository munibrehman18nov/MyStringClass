#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;

class CString
{
private:
	char *data;
	int size;
public:
	CString();
	~CString();
	operator int();
	operator float();
	void input();
	void display(); const
		void reSize(int);
	//	istream & operator >> (istream & x, Cstring& cs);
	//	ostream &operator << (ostream & x, Cstring& cs);
	CString::CString(int);
	CString(const char);
	CString(const char * const);
	CString & operator = ( CString &);
	CString( CString &);
	~CString();
	char & at(const int);
	char & operator [](const int);
	char & operator [](const int); const
		char& at(const int) const;
		int isEmpty(); const
		const int getLenght(); const
		int find(const char, const int);
		int find(const char * const, const int); const
		int insert(const int, const char * const);
	int insert(const int, const char);
	int remove(const int, const int);
	int remove(const char);
	void replace(const char);
	int replace(const char, const char);
	int replace(const char * const, const char * const);
	void trim();
	void trimLeft();
	void trimRight();
	void makeUpper();
	void makeLower();
	void reverse();
	void operator +=(const CString&);
	void operator +=(const char * const);
	void concatEqual(const CString &);
	void concatEqual(const char * const);
	int operator ==( CString&);
	int isEqual( CString &);
		int operator ==(const char *const);
	int isEqual(const char * const);
	CString left(int);
	CString right(int);
	CString operator + (const CString&); const
		CString concat( CString&);
		CString operator +( char * const);  const
		CString concat(const char * const); const

		CString tokenize( char *);
	CString ::operator int();

	CString(CString &&);
	CString & operator = (CString &&);
};
#endif
ostream &operator<<(ostream &, const CString&);
istream &operator>>(istream &, const CString&);
int arrlen(char []);
int arrlen(char const []);
int convertoint(char);