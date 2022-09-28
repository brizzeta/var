#include "var.h"

//глобальные операторы сложения
int operator+(int val, const var& obj) {
	var temp = val;
	temp = temp + obj;
	return temp.Get_Int();
}

double operator+(double val, const var& obj) {
	var temp = val;
	temp = temp + obj;
	return temp.Get_Double();
}

MyString operator+(const MyString& val, const var& obj) {
	var temp = val;
	temp = temp + obj;
	return temp.Get_String();
}

const char* operator+(const char* val, const var& obj) {
	var temp = val;
	temp = temp + obj;
	return temp.GetConst_Char();
}

//глобальные операторы вычитания
int operator-(int val, const var& obj) {
	var temp = val;
	temp = temp - obj;
	return temp.Get_Int();
}

double operator-(double val, const var& obj) {
	var temp = val;
	temp = temp - obj;
	return temp.Get_Double();
}

MyString operator-(const MyString& val, const var& obj) {
	var temp = val;
	temp = temp - obj;
	return temp.Get_String();
}

const char* operator-(const char* val, const var& obj) {
	var temp = val;
	temp = temp - obj;
	return temp.GetConst_Char();
}

//глобальные операторы умножения
int operator*(int val, const var& obj) {
	var temp = val;
	temp = temp * obj;
	return temp.Get_Int();
}

double operator*(double val, const var& obj) {
	var temp = val;
	temp = temp * obj;
	return temp.Get_Double();
}

MyString operator*(const MyString& val, const var& obj) {
	var temp = val;
	temp = temp * obj;
	return temp.Get_String();
}

const char* operator*(const char* val, const var& obj) {
	var temp = val;
	temp = temp * obj;
	return temp.GetConst_Char();
}

//глобальные операторы деления
int operator/(int val, const var& obj) {
	var temp = val;
	temp = temp / obj;
	return temp.Get_Int();
}

double operator/(double val, const var& obj) {
	var temp = val;
	temp = temp / obj;
	return temp.Get_Double();
}

MyString operator/(const MyString& val, const var& obj) {
	var temp = val;
	temp = temp / obj;
	return temp.Get_String();
}

const char* operator/(const char* val, const var& obj) {
	var temp = val;
	temp = temp / obj;
	return temp.GetConst_Char();
}

//глобальные операторы равенства
bool operator==(int val, const var& obj) {
	return (obj == val);
}

bool operator==(double val, const var& obj) {
	return (obj == val);
}

bool operator==(const MyString& val, const var& obj) {
	return (obj == val);
}

bool operator==(const char* val, const var& obj) {
	return (obj == val);
}

//глобальные операторы неравнества
bool operator!=(int val, const var& obj) {
	return (obj != val);
}

bool operator!=(double val, const var& obj) {
	return (obj != val);
}

bool operator!=(const MyString& val, const var& obj) {
	return (obj != val);
}

bool operator!=(const char* val, const var& obj) {
	return (obj != val);
}

//глобальные операторы больше
bool operator>(int val, const var& obj) {
	return (obj < val);
}

bool operator>(double val, const var& obj) {
	return (obj < val);
}

bool operator>(const MyString& val, const var& obj) {
	return (obj < val);
}

bool operator>(const char* val, const var& obj) {
	return (obj < val);
}

//глобальные операторы меньше
bool operator<(int val, const var& obj) {
	return (obj > val);
}

bool operator<(double val, const var& obj) {
	return (obj > val);
}

bool operator<(const MyString& val, const var& obj) {
	return (obj > val);
}

bool operator<(const char* val, const var& obj) {
	return (obj > val);
}

//глобальные операторы больше или равно
bool operator>=(int val, const var& obj) {
	return (obj <= val);
}

bool operator>=(double val, const var& obj) {
	return (obj <= val);
}

bool operator>=(const MyString& val, const var& obj) {
	return (obj <= val);
}

bool operator>=(const char* val, const var& obj) {
	return (obj <= val);
}

//глобальные операторы меньше или равно
bool operator<=(int val, const var& obj) {
	return (obj >= val);
}

bool operator<=(double val, const var& obj) {
	return (obj >= val);
}

bool operator<=(const MyString& val, const var& obj) {
	return (obj >= val);
}

bool operator<=(const char* val, const var& obj) {
	return (obj >= val);
}

//вывод
std::ostream& operator<<(std::ostream& os, const var& obj) {
	if (obj.DataType == 1) {
		os << obj.value_i;
	}
	else if (obj.DataType == 2) {
		os << obj.value_d;
	}
	else if (obj.DataType == 3) {
		os << obj.value_s;
	}
	return os;
}