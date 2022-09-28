#include "var.h"

//операторы сравнения
bool var::operator==(int val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i == val;
	}
	else if (DataType == 2) {
		return value_d == (double)val;
	}
	else if (DataType == 3) {
		char buff[80];
		_itoa_s(val, buff, 80, 10);
		if (value_s.MyStrCmp(MyString(buff)) == 0) {
			return true;
		}
		else return false;
	}
	return false;
}

bool var::operator==(double val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i == (int)val;
	}
	else if (DataType == 2) {
		return value_d == val;
	}
	else if (DataType == 3) {
		char buff[80];
		_itoa_s(val, buff, 80, 10);
		if (value_s.MyStrCmp(MyString(buff)) == 0) {
			return true;
		}
		else return false;
	}
}

bool var::operator==(const MyString& val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i == atoi(val.My_Str());
	}
	else if (DataType == 2) {
		return value_d == strtod(val.My_Str(), nullptr);
	}
	else if (DataType == 3) {
		if (value_s.MyStrCmp(val) == 0) {
			return true;
		}
		else return false;
	}
}

bool var::operator==(const char* val) const {
	return (*this == MyString(val));
}

bool var::operator==(const var& obj) const {
	if (obj.DataType == 1) {
		return *this == obj.value_i;
	}
	else if (obj.DataType == 2) {
		return *this == obj.value_d;
	}
	else if (obj.DataType == 3) {
		return *this == obj.value_s;
	}
	else return false;
}

//операторы неравенства
bool var::operator!=(int val) const {
	return !(*this == val);
}

bool var::operator!=(double val) const {
	return !(*this == val);
}

bool var::operator!=(const MyString& val) const {
	return !(*this == val);
}

bool var::operator!=(const char* val) const {
	return !(*this == val);
}

bool var::operator!=(const var& obj) const {
	return !(*this == obj);
}


//операторы больше
bool var::operator>(int val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i > val;
	}
	else if (DataType == 2) {
		return value_d > (double)val;
	}
	else if (DataType == 3) {
		char buff[80];
		_itoa_s(val, buff, 80, 10);
		if (value_s.MyStrCmp(MyString(buff)) > 0) {
			return true;
		}
		else return false;
	}
	return false;
}

bool var::operator>(double val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i > (int)val;
	}
	else if (DataType == 2) {
		return value_d > val;
	}
	else if (DataType == 3) {
		char buff[20];
		_itoa_s(int(val * 1000), buff, 20, 10);
		buff[strlen(buff) - 1] = buff[strlen(buff) - 2];
		buff[strlen(buff) - 2] = buff[strlen(buff) - 3];
		buff[strlen(buff) - 3] = '.';
		if (value_s.MyStrCmp(MyString(buff)) > 0) {
			return true;
		}
		else return false;
	}
}

bool var::operator>(const MyString& val) const {
	if (DataType == -1) {
		return false;
	}
	else if (DataType == 1) {
		return value_i > atoi(val.My_Str());
	}
	else if (DataType == 2) {
		return value_d > strtod(val.My_Str(), nullptr);
	}
	else if (DataType == 3) {
		if (value_s.MyStrCmp(val) > 0) {
			return true;
		}
		else return false;
	}
}

bool var::operator>(const char* val) const {
	return (*this == MyString(val));
}

bool var::operator>(const var& obj) const {
	if (obj.DataType == 1) {
		return *this > obj.value_i;
	}
	else if (obj.DataType == 2) {
		return *this > obj.value_d;
	}
	else if (obj.DataType == 3) {
		return *this > obj.value_s;
	}
	else return false;
}


//операторы меньше
bool var::operator<(int val) const {
	return ((*this != val) && !(*this > val));
}

bool var::operator<(double val) const {
	return ((*this != val) && !(*this > val));

}

bool var::operator<(const MyString& val) const {
	return ((*this != val) && !(*this > val));

}

bool var::operator<(const char* val) const {
	return ((*this != val) && !(*this > val));

}

bool var::operator<(const var& obj) const {
	return ((*this != obj) && !(*this > obj));
}

//операторы больше или равно
bool var::operator>=(int val) const {
	return ((*this > val) || (*this == val));
}

bool var::operator>=(double val) const {
	return ((*this > val) || (*this == val));
}

bool var::operator>=(const MyString& val) const {
	return ((*this > val) || (*this == val));
}

bool var::operator>=(const char* val) const {
	return ((*this > val) || (*this == val));
}

bool var::operator>=(const var& obj) const {
	return ((*this > obj) || (*this == obj));
}

//операторы меньше или равно
bool var::operator<=(int val) const {
	return ((*this < val) || (*this == val));
}

bool var::operator<=(double val) const {
	return ((*this < val) || (*this == val));
}

bool var::operator<=(const MyString& val) const {
	return ((*this < val) || (*this == val));
}

bool var::operator<=(const char* val) const {
	return ((*this < val) || (*this == val));
}

bool var::operator<=(const var& obj) const {
	return ((*this < obj) || (*this == obj));
}