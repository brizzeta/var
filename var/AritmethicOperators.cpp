#include "var.h"

//операторы сложения
var var::operator+(int val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i + val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d + (double)val;
	}
	else if (temp.DataType == 3) {
		char buff[20];
		_itoa_s(val, buff, 20, 10);
		temp.value_s.MyStrCat(buff);
	}
	return temp;
}
var var::operator+(double val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i + (int)val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d + val;
	}
	else if (temp.DataType == 3) {
		char buff[20];
		_itoa_s(int(val * 1000), buff, 20, 10);
		buff[strlen(buff) - 1] = buff[strlen(buff) - 2];
		buff[strlen(buff) - 2] = buff[strlen(buff) - 3];
		buff[strlen(buff) - 3] = '.';
		temp.value_s.MyStrCat(buff);
	}
	return temp;
}
var var::operator+(const char* val)const {
	return (*this + MyString(val));
}
var var::operator+(const MyString& val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i + atoi(val.My_Str());
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d + strtod(val.My_Str(), nullptr);
	}
	else if (temp.DataType == 3) {
		temp.value_s.MyStrCat(val);
	}
	return temp;
}
var var::operator+(const var& obj)const {
	var temp(*this);

	if (obj.DataType == 1) {
		temp = temp + obj.value_i;
	}
	else if (obj.DataType == 2) {
		temp = temp + obj.value_d;
	}
	else if (obj.DataType == 3) {
		temp = temp + obj.value_s;
	}
	return temp;
}

//операторы вычитания
var var::operator-(int val)const {
	if (this->DataType == 3) {
		return *this;
	}
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i - val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d - (double)val;
	}
	return temp;
}
var var::operator-(double val)const {
	if (this->DataType == 3) {
		return *this;
	}
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i - (int)val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d - val;
	}
	return temp;
}
var var::operator-(const char* val)const {
	return(*this - MyString(val));
}
var var::operator-(const MyString& val)const {
	if (this->DataType == 3) {
		return *this;
	}
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i - atoi(val.My_Str());
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d - strtod(val.My_Str(), nullptr);
	}
	return temp;
}
var var::operator-(const var& obj)const {
	var temp(*this);

	if (obj.DataType == 1)
		temp = temp - obj.value_i;
	else if (obj.DataType == 2)
		temp = temp - obj.value_d;
	else if (obj.DataType == 3)
		temp = temp - obj.value_s;

	return temp;
}

//операторы умножения
var var::operator*(int val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i * val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d * (double)val;
	}
	return temp;
}
var var::operator*(double val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i * (int)val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d * val;
	}
	return temp;
}
var var::operator*(const char* val)const {
	return (*this * MyString(val));
}
var var::operator*(const MyString& val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i * atoi(val.My_Str());
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d * strtod(val.My_Str(), nullptr);
	}
	else if (temp.DataType == 3) {
		for (int i = 0; i < temp.value_s.MyStrlen(); i++) {
			if (val.My_Strchr(temp.value_s[i]) == -1) {
				temp.value_s.MyDelChr(temp.value_s[i]);
				i = 0;
			}
		}
	}
	return temp;
}
var var::operator*(const var& obj)const {
	var temp(*this);

	if (obj.DataType == 1) {
		temp = temp * obj.value_i;
	}
	else if (obj.DataType == 2) {
		temp = temp * obj.value_d;
	}
	else if (obj.DataType == 3) {
		temp = temp * obj.value_s;
	}
	return temp;
}

//операторы деления
var var::operator/(int val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i / val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d / (double)val;
	}
	return temp;
}
var var::operator/(double val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i / (int)val;
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d / val;
	}
	return temp;
}
var var::operator/(const char* val)const {
	return (*this / MyString(val));
}
var var::operator/(const MyString& val)const {
	var temp(*this);

	if (temp.DataType == -1) {
		temp = val;
	}
	else if (temp.DataType == 1) {
		temp.value_i = temp.value_i / atoi(val.My_Str());
	}
	else if (temp.DataType == 2) {
		temp.value_d = temp.value_d / strtod(val.My_Str(), nullptr);
	}
	else if (temp.DataType == 3) {
		for (int i = 0; i < val.MyStrlen(); i++) {
			temp.value_s.MyDelChr(val[i]);
		}
	}
	return temp;
}
var var::operator/(const var& obj)const {
	var temp(*this);

	if (obj.DataType == 1) {
		temp = temp / obj.value_i;
	}
	else if (obj.DataType == 2) {
		temp = temp / obj.value_d;
	}
	else if (obj.DataType == 3) {
		temp = temp / obj.value_s;
	}

	return temp;
}

//операторы короткой формы сложения
var& var::operator+=(int val) {
	*this = *this + val;
	return *this;
}
var& var::operator+=(double val) {
	*this = *this + val;
	return *this;
}
var& var::operator+=(const char* val) {
	*this = *this + val;
	return *this;
}
var& var::operator+=(const MyString& val) {
	*this = *this + val;
	return *this;
}
var& var::operator+=(const var& obj) {
	*this = *this + obj;
	return *this;
}

//операторы короткой формы вычитания
var& var::operator-=(int val) {
	*this = *this - val;
	return *this;
}
var& var::operator-=(double val) {
	*this = *this - val;
	return *this;
}
var& var::operator-=(const char* val) {
	*this = *this - val;
	return *this;
}
var& var::operator-=(const MyString& val) {
	*this = *this - val;
	return *this;
}
var& var::operator-=(const var& obj) {
	*this = *this - obj;
	return *this;
}

//операторы короткой формы умножения
var& var::operator*=(int val) {
	*this = *this * val;
	return *this;
}
var& var::operator*=(double val) {
	*this = *this * val;
	return *this;
}
var& var::operator*=(const char* val) {
	*this = *this * val;
	return *this;
}
var& var::operator*=(const MyString& val) {
	*this = *this * val;
	return *this;
}
var& var::operator*=(const var& obj) {
	*this = *this * obj;
	return *this;
}

//операторы короткой формы деления
var& var::operator/=(int val) {
	*this = *this / val;
	return *this;
}
var& var::operator/=(double val) {
	*this = *this / val;
	return *this;
}
var& var::operator/=(const char* val) {
	*this = *this / val;
	return *this;
}
var& var::operator/=(const MyString& val) {
	*this = *this / val;
	return *this;
}
var& var::operator/=(const var& obj) {
	*this = *this / obj;
	return *this;
}

//операторы присвяивания
var& var::operator=(int val) {
	value_i = val;
	value_d = 0;
	value_s = "\0";
	DataType = 1;
	return *this;
}

var& var::operator=(double val) {
	value_d = val;
	value_i = 0;
	value_s = "\0";
	DataType = 2;
	return *this;
}

var& var::operator=(const char* val) {
	value_s = val;
	value_i = 0;
	value_d = 0;
	DataType = 3;
	return *this;
}

var& var::operator=(const MyString& val) {
	value_s = val;
	value_i = 0;
	value_d = 0;
	DataType = 3;
	return *this;
}

var& var::operator=(const var& obj) {
	if (this == &obj || this->DataType == -1) {
		return *this;
	}
	value_i = obj.value_i;
	value_d = obj.value_d;
	value_s = obj.value_s;
	DataType = obj.DataType;
	return *this;
}