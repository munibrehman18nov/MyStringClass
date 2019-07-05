#include "String.h"
#include<iostream>
using namespace std;

CString::CString()
{
	size = 0;
	data = 0;

}
void CString::input()
{
	size = 1;
	data = new char[size];
	char ch = ' ';
	int i = 0;
	while (ch != '\n')
	{
		if (i == size - 1)
		{
			size = size * 2;
			reSize(size);
		}
		cin.get(ch);
		if (ch != '\n')
		{
			data[i] = ch;
		}
		else if (ch == '\n')
		{
			data[i] = '\0';
			break;
		}
		i++;
	}
	//data[i] = '\0';
}
/*CString::CString(int s)
{
size = s;
data = new char [size];

}*/
CString::CString(const char c)
{
	size = 1;
	data = new char[size];
	data[size - 1] = c;
}
CString::CString(const char * const ref)
{
	size = arrlen(ref) + 1;
	data = new char[size];
	strcpy(data, ref);
	data[size - 1] = '\0';
}
//here is copy constructor
CString & CString::operator = (const CString & ref)
{

	if (this == &ref)
	{
		return *this;
	}
	this->~CString();
	size = ref.size;
	data = new char[size];
	for (int i = 0; i < ref.getLenght(); i++)
	{
		data[i] = ref.data[i];
		data[i + 1] = '\0';
	}
	return *this;
}
CString::CString(const CString & ref)
{
	size = ref.size;
	data = new char[size + 1];
	int i = 0, x = ref.getLenght();
	for (i; i < x; i++)
	{
		data[i] = ref.data[i];
		data[i + 1] = '\0';
	}

}
CString::~CString()
{
	if (data)
	{
		delete[] data;
		data = 0;
		size = 0;
	}

}
/*
void CString::input()
{
cout << "\nenter your string.";
cin.getline(data, 1000);
}
*/
char & CString::at(const int index)
{
	if (index >= 0 && index < size)
		return data[index];
	else
		exit(0);
}
char &CString:: operator [](const int index)
{
	if (index >= 0 && index < size)
		return data[index];
	else
		exit(0);

}
char &CString:: operator [](const int index) const
{
	if (index >= 0 && index < size)
		return data[index];
	else
		exit(0);

}

const char & CString::at(const int index) const
{
	if (index >= 0 && index < size)
		return data[index];
	else
		exit(0);

}
int CString::isEmpty() const
{
	if (getLenght() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CString::getLenght()const
{

	int i = 0;
	while (data[i] != '\0'&& i<size)
	{
		i++;
	}
	return i;



}
void CString::display()const
{
	if (data)
	{
		cout << "\n" << data;
	}
	else
		exit(0);
}
int CString::find(const char ch, const int start) const
{
	int x = start;
	bool flag = true;
	while (x<getLenght())
	{
		if (data[x] == ch)
		{
			flag = false;
			return 1;
		}
		x++;
	}
	if (flag == true)
	{
		return 0;
	}

}
int CString::find(const char * const substr, const int start)const
{
	int x = start, ind;
	bool flag;
	int l = arrlen(substr);
	while (x<getLenght())
	{
		flag = false;
		if (data[x] == substr[0])
		{
			flag = true;
			ind = x;
			int m = x + 1;
			for (int j = 1; j < l; j++)
			{
				if (data[m] != substr[j])
				{
					flag = false;
					break;
				}
				m++;
			}
			if (flag == true)
			{
				return ind;
			}
		}
		x++;
	}
	if (flag == false)
	{
		return -1;
	}
}
int CString::insert(const int index, const char * const substr)
{
	if (data)
	{
		int x = index, y = arrlen(substr);
		reSize(size + y);
		for (int i = 0; i < arrlen(substr); i++)
		{
			int j = getLenght() - 1;
			data[j + 2] = '\0';
			for (j; j >= x; j--)
			{
				data[j + 1] = data[j];
			}
			data[x] = substr[i];
			x++;
		}
		return 1;
	}
	else
		return 0;
}

int CString::insert(const int index, const char ch)
{
	if (data)
	{
		int j = getLenght() - 1;
		data[j + 2] = '\0';
		for (j; j >= index; j--)
		{
			data[j + 1] = data[j];
		}
		data[index] = ch;

		return 1;
	}
	else
		return 0;
}
int CString::remove(const int index, const int count)
{
	if (count + index <= getLenght())
	{
		for (int i = 0; i < count; i++)
		{

			for (int j = index; j< size; j++)
			{
				data[j] = data[j + 1];
			}
		}
		return 1;
	}
	else if (count + index>  getLenght())
	{
		return 0;
	}
}
int CString::remove(const char ch)
{
	int len = getLenght();
	for (int i = 0; i < len; i++)
	{
		if (data[i] == ch)
		{
			for (int j = i; j <len; j++)
			{
				data[j] = data[j + 1];
			}
		}
	}
	return 1;

}
void CString::replace(const char newC)
{
	int len = getLenght();
	for (int i = 0; i < len; i++)
	{
		if (data[i] != '\t' || data[i] != ' ')
		{
			for (int j = i; j <len; j++)
			{
				data[j] = newC;
			}
		}
	}

}
int CString::replace(const char old, const char newC)
{
	int len = getLenght();
	for (int i = 0; i < len; i++)
	{
		if (data[i] == old)
		{
			for (int j = i; j <len; j++)
			{
				data[j] = newC;
			}
		}
	}
	return 1;

}
int CString::replace(const char * const  old, const char * const newC)
{
	if (find(old, 0) != -1)
	{
		int x = find(old, 0);

		remove(x, arrlen(old));
		insert(x, newC);
		return 1;
	}
	else
	{
		exit(0);
	}

}
void CString::trim()
{
	trimLeft();
	trimRight();

}
void CString::trimLeft()
{
	while (data[0] == '\n' || data[0] == '\t' || data[0] == ' ')
	{
		remove(0, 1);
	}
}
void CString::trimRight()
{
	int x = getLenght();
	while (data[x - 1] == '\n' || data[x - 1] == '\t' || data[x - 1] == ' ')
	{
		data[x - 1] = '\0';
		x--;
	}

}
void CString::makeUpper()
{
	int x = getLenght();
	for (int i = 0; i < x; i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;

		}
	}
}
void CString::makeLower()
{

	int x = getLenght();
	for (int i = 0; i < x; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;

		}
	}
}
void CString::reverse()
{
	int x = getLenght() - 1, i = 0;
	char *p = new char[x + 2];
	for (i, x; i < getLenght(); x--, i++)
	{
		p[i] = data[x];
		p[i + 1] = '\0';
	}
	delete[]data;
	data = p;
}
// sir wala resize
void CString::reSize(int ns)
{
	if (ns <= 0)
	{
		this->~CString();
		return;
	}
	char * temp = new char[ns];
	int i = 0;
	while (i<ns && i<size)
	{
		temp[i] = data[i];
		i++;
	}
	this->~CString();
	data = temp;
	size = ns;
}
// my resize
/*void CString::reSize(const int add)
{
int x = add, i = 0;
char *p = new char[add+1 ];
p[i] = '\0';
int y = getLenght();
for (i; i < getLenght() && i < add; i++)
{
p[i] = data[i];
}
p[i] = '\0';
delete[]data;
data = p;
size = add+1;
}*/
//here is concat equal
void CString::operator +=(const CString& s2)
{
	int l1 = getLenght(), l2 = s2.getLenght();
	size = l1 + l2 + 1;
	char *p = new char[l1 + l2 + 1];
	for (int i = 0; i < l1; i++)
	{
		p[i] = data[i];
	}
	for (int i = 0; i < l2; i++)
	{
		p[l1] = s2.data[i];
		p[l1 + 1] = '\0';
		l1++;
	}
	delete[] data;
	data = p;

}
void CString::operator +=(const char * const s2)
{
	int len = arrlen(s2), l = getLenght();
	size = len + l + 1;
	char *p = new char[l + len + 1];
	for (int i = 0; i < l; i++)
	{
		p[i] = data[i];
	}
	for (int i = 0; i < len; i++)
	{
		p[l] = s2[i];
		p[l + 1] = '\0';
		l++;
	}
	delete[] data;
	data = p;

}

void CString::concatEqual(const CString & s2)
{
	int l1 = getLenght(), l2 = s2.getLenght();
	size = l1 + l2 + 1;
	char *p = new char[l1 + l2 + 1];
	for (int i = 0; i < l1; i++)
	{
		p[i] = data[i];
	}
	for (int i = 0; i < l2; i++)
	{
		p[l1] = s2.data[i];
		p[l1 + 1] = '\0';
		l1++;
	}
	delete[] data;
	data = p;

}
void CString::concatEqual(const char * const s2)
{
	int len = arrlen(s2), l = getLenght();
	size = l + len + 1;
	char *p = new char[l + len + 1];
	for (int i = 0; i < l; i++)
	{
		p[i] = data[i];
	}
	for (int i = 0; i < len; i++)
	{
		p[l] = s2[i];
		p[l + 1] = '\0';
		l++;
	}
	delete[] data;
	data = p;

}
int CString::operator ==(const CString& s2)
{
	bool flag = true;
	if (getLenght() == s2.getLenght())
	{
		int x = getLenght();
		for (int i = 0; i <x; i++)
		{
			if (data[i] != s2.data[i])
			{
				flag = false;
				return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
int CString::isEqual(const CString & s2)const
{
	bool flag = true;
	if (getLenght() == s2.getLenght())
	{
		int x = getLenght();
		for (int i = 0; i <x; i++)
		{
			if (data[i] != s2.data[i])
			{
				flag = false;
				return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
int CString::operator ==(const char *const s2)
{
	bool flag = true;

	if ((getLenght()) == arrlen(s2))
	{
		int x = getLenght();
		for (int i = 0; i <x; i++)
		{
			if (data[i] != s2[i])
			{
				flag = false;
				return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
int CString::isEqual(const char * const s2)
{
	bool flag = true;
	if (getLenght() == arrlen(s2))
	{
		int x = getLenght();
		for (int i = 0; i <x; i++)
		{
			if (data[i] != s2[i])
			{
				flag = false;
				return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
CString CString::left(int count)
{
	CString str(' ');
	str.size = getLenght() - count + 1;
	str.reSize(size);
	for (int i = 0, j = count; j < getLenght(); j++, i++)
	{
		str.data[i] = data[j];
		str.data[i + 1] = '\0';
	}
	return str;

}
CString CString::right(int count)
{
	CString str(' ');
	str.size = getLenght() - count + 1;
	str.reSize(size);
	for (int i = 0; i < str.size - 1; i++)
	{
		str.data[i] = data[i];
		str.data[i + 1] = '\0';
	}
	return str;

}
CString CString::operator + (const CString& s2) const
{

	CString str(*this);
	str.concatEqual(s2);
	return str;
}
CString CString::concat(const CString& s2) const
{
	CString str(*this);
	str.concatEqual(s2);
	return str;
}
CString CString::operator +(const char * const s2)  const
{
	CString ss(*this);
	ss.concatEqual(s2);

	return ss;

}
CString CString::concat(const char * const s2)  const
{
	CString ss(*this);
	ss.concatEqual(s2);

	return ss;

}
int arrlen(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}
int arrlen(char const a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}
CString CString::tokenize(const char * const delim)
{
	int a;
	bool flag = true;
	for (int i = 0; i < getLenght(); i++)
	{
		for (int j = 0; j < arrlen(delim); j++)
		{
			if (data[i] == delim[j])
			{
				flag = false;
				a = i;
				break;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
	if (flag == true)
	{
		a = -1;
	}
	if (a != -1)
	{
		int b = getLenght();
		char * r = new char[a];
		int i = 0;
		int j = 0;
		while (i < a)
		{
			r[i] = data[i];
			i = i + 1;
		}
		r[i] = '\0';
		i = i + 1;
		j = 0;
		while (data[i] != '\0')
		{
			data[j] = data[i];
			i = i + 1;
			j = j + 1;
		}
		data[j] = '\0';
		CString s(r);
		return s;
	}
}
CString ::operator int()
{
	int num = 0;
	int i = 0;
	while (data[i] != '\0')
	{
		num = (num * 10) + (data[i] - '0');
		i++;
	}
	return num;

}
istream & operator >> (istream & x, CString& cs)
{
	cs.input();
	return x;

}
ostream &operator << (ostream & x, CString& cs)
{
	cs.display();
	return x;

}
int convertoint(char c)
{
	int num = 0;
	num = num * 10 + (c - '0');
	return num;
}
CString::CString(CString && ref)
{
	data = ref.data;
	ref.data = nullptr;
	size = ref.size;
}
CString & CString::operator = (CString && ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~CString();
	data = ref.data;
	ref.data = nullptr;
	size = ref.size;
	return *this;
}