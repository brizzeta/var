#pragma once
#include "MyString.h"
#include <iostream>

class var
{
	int value_i;
	double value_d;
	MyString value_s;
	int DataType;
	//вывод
	friend std::ostream& operator<<(std::ostream& os, const var& obj);
public:
	//конструкторы
	var();
	var(int val);
	var(double val);
	var(const char* val);
	var(const MyString& val);
	var(const var& val); 

	//геттеры
	int Get_Int() const { 
		return value_i; 
	}
	double Get_Double() const { 
		return value_d; 
	}
	const char* GetConst_Char() const {
		char* buff = new char[value_s.MyStrlen() + 1];
		strcpy_s(buff, value_s.MyStrlen() + 1, value_s.My_Str());
		return buff;
	}
	MyString Get_String() const { 
		return value_s; 
	}

	//операторы конвертации
	operator int();
	operator double();
	operator const char*();

	//арифметические операторы
	var operator+(int val)const;
	var operator+(double val)const;
	var operator+(const char* val)const;
	var operator+(const MyString& val)const;
	var operator+(const var& obj)const;

	var operator-(int val)const;
	var operator-(double val)const;
	var operator-(const char* val)const;
	var operator-(const MyString& val)const;
	var operator-(const var& obj)const;

	var operator*(int val)const;
	var operator*(double val)const;
	var operator*(const char* val)const;
	var operator*(const MyString& val)const;
	var operator*(const var& obj)const;

	var operator/(int val)const;
	var operator/(double val)const;
	var operator/(const char* val)const;
	var operator/(const MyString& val)const;
	var operator/(const var& obj)const;

	var& operator=(int val);
	var& operator=(double val);
	var& operator=(const char* val);
	var& operator=(const MyString& val);
	var& operator=(const var& obj);

	var& operator+=(int val);
	var& operator+=(double val);
	var& operator+=(const char* val);
	var& operator+=(const MyString& val);
	var& operator+=(const var& obj);

	var& operator-=(int val);
	var& operator-=(double val);
	var& operator-=(const char* val);
	var& operator-=(const MyString& val);
	var& operator-=(const var& obj);

	var& operator*=(int val);
	var& operator*=(double val);
	var& operator*=(const char* val);
	var& operator*=(const MyString& val);
	var& operator*=(const var& obj);

	var& operator/=(int val);
	var& operator/=(double val);
	var& operator/=(const char* val);
	var& operator/=(const MyString& val);
	var& operator/=(const var& obj);

	//операторы сравнения
	bool operator==(int val) const;
	bool operator==(double val) const;
	bool operator==(const char* val) const;
	bool operator==(const MyString& val) const;
	bool operator==(const var& obj) const;

	bool operator!=(int val) const;
	bool operator!=(double val) const;
	bool operator!=(const char* val) const;
	bool operator!=(const MyString& val) const;
	bool operator!=(const var& obj) const;

	bool operator>(int val) const;
	bool operator>(double val) const;
	bool operator>(const char* val) const;
	bool operator>(const MyString& val) const;
	bool operator>(const var& obj) const;

	bool operator<(int val) const;
	bool operator<(double val) const;
	bool operator<(const char* val) const;
	bool operator<(const MyString& val) const;
	bool operator<(const var& obj) const;

	bool operator>=(int val) const;
	bool operator>=(double val) const;
	bool operator>=(const char* val) const;
	bool operator>=(const MyString& val) const;
	bool operator>=(const var& obj) const;

	bool operator<=(int val) const;
	bool operator<=(double val) const;
	bool operator<=(const char* val) const;
	bool operator<=(const MyString& val) const;
	bool operator<=(const var& obj) const;
};

//глобальные операторы
int operator+(int val, const var& obj);
double operator+(double val, const var& obj);
MyString operator+(const MyString& val, const var& obj);
const char* operator+(const char* val, const var& obj);

int operator-(int val, const var& obj);
double operator-(double val, const var& obj);
MyString operator-(const MyString& val, const var& obj);
const char* operator-(const char* val, const var& obj);

int operator*(int val, const var& obj);
double operator*(double val, const var& obj);
MyString operator*(const MyString& val, const var& obj);
const char* operator*(const char* val, const var& obj);

int operator/(int val, const var& obj);
double operator/(double val, const var& obj);
MyString operator/(const MyString& val, const var& obj);
const char* operator/(const char* val, const var& obj);

bool operator==(int val, const var& obj);
bool operator==(double val, const var& obj);
bool operator==(const MyString& val, const var& obj);
bool operator==(const char* val, const var& obj);

bool operator!=(int val, const var& obj);
bool operator!=(double val, const var& obj);
bool operator!=(const MyString& val, const var& obj);
bool operator!=(const char* val, const var& obj);

bool operator>(int val, const var& obj);
bool operator>(double val, const var& obj);
bool operator>(const MyString& val, const var& obj);
bool operator>(const char* val, const var& obj);

bool operator<(int val, const var& obj);
bool operator<(double val, const var& obj);
bool operator<(const MyString& val, const var& obj);
bool operator<(const char* val, const var& obj);

bool operator>=(int val, const var& obj);
bool operator>=(double val, const var& obj);
bool operator>=(const MyString& val, const var& obj);
bool operator>=(const char* val, const var& obj);

bool operator<=(int val, const var& obj);
bool operator<=(double val, const var& obj);
bool operator<=(const MyString& val, const var& obj);
bool operator<=(const char* val, const var& obj);