#include "var.h"

var::var() {
	value_i = 0;
	value_d = 0;
	DataType = -1;
}

var::var(int val) {
	value_i = val;
	DataType = 1;
}

var::var(double val) {
	value_d = val;
	DataType = 2;
}

var::var(const char* val) {
	value_s = val;
	DataType = 3;
}

var::var(const MyString& val) {
	value_s = val;
	DataType = 3;
}

var::var(const var& val) {
	value_i = val.value_i;
	value_d = val.value_d;
	value_s = val.value_s;
	DataType = val.DataType;
}