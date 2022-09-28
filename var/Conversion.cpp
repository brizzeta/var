#include "var.h"

//оператор конвертации int
var::operator int()
{
	if (DataType == -1)
		return -1;
	else if (DataType == 1)
		return value_i;
	else if (DataType == 2)
		return (int)value_d;
	else if (DataType == 3)
		return atoi(value_s.My_Str());
}

//оператор конвертации double
var::operator double()
{
	if (DataType == -1)
		return -1.0;
	else if (DataType == 1)
		return (double)value_i;
	else if (DataType == 2)
		return value_d;
	else if (DataType == 3)
		return strtod(value_s.My_Str(), nullptr);
}

//оператор конвертации const char*
var::operator const char*()
{
	if (DataType == -1) {
		return nullptr;
	}
	else if (DataType == 1) {
		char* buff = new char[20];
		_itoa_s(value_i, buff, 20, 10);
		return buff;
	}
	else if (DataType == 2) {
		char* buff = new char[20];
		_itoa_s(int(value_d * 1000), buff, 20, 10);
		buff[strlen(buff) - 1] = buff[strlen(buff) - 2];
		buff[strlen(buff) - 2] = buff[strlen(buff) - 3];
		buff[strlen(buff) - 3] = '.';
		return buff;
	}
	else if (DataType == 3) {
		return value_s.My_Str();
	}
}