#pragma once
#include <iostream>
using namespace std;

class MyString {
    char* str;
    int size;
    static int count;
    friend ostream& operator<<(ostream& os, const MyString& obj);
public:
    MyString();                            //конструктор по умолчанию
    MyString(int);                         //конструктор создающий строку произвольного размера
    MyString(const char* str);             //конструктор принимающий строку
    MyString(const MyString& string1);     //конструктор копирования
    int MyStrlen()const;                   //метод подсчёта длины строки
    void Print();                          //метод вывода
    void Input();                          //метод ввода с клавиатуры
    void MyStrCpy(MyString&);              //метод копирывания строку
    bool My_Strstr(const char*);           //метод поиска подстроки в строке
    int My_Strchr(char)const;              //метод поиска заданного символа в строке
    void MyDelChr(char);                   //удаление заданных символов в строке
    int MyStrCmp(const MyString& b)const;  //сравнение строк
    void MyStrCat(const MyString& b);      //объединение строк
    static int GetCount();
    MyString& operator=(const MyString& obj);     //оператор присваивания
    void operator() ();                           //оператор вызова функции
    operator int()const;                          //оператор преобразование типов из int
    operator char* ()const;                       //оператор преобразование типов из char
    char operator[](int index)const;              //поиск по индексу
    const char* My_Str()const;                    //возвращает указатель на строку
    ~MyString() {
        delete[] str;
    }
};
int MyString::count = 0;

int MyString::GetCount() {    //статический метод подсчёта объектов
    return count;
}
MyString::MyString() {        //конструктор по умолчанию
    str = new char[80];
    str[0] = '\0';
    size = 0;
    count++;
}
MyString::MyString(int size) { //конструктор создающий строку произвольного размера
    str = nullptr;
    this->size = size;
    str = new char[size + 1];
    count++;
}
MyString::MyString(const char* str) { //конструктор принимающий строку
    size = strlen(str);
    this->str = new char[size + 1];

    for (int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    count++;
}
MyString::MyString(const MyString& string1) {  //конструктор копирования
    count++;
    size = string1.size;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        str[i] = string1.str[i];
    str[size] = '\0';
}

int MyString::MyStrlen()const {        //метод подсчёта длины строки
    return size;
}
bool MyString::My_Strstr(const char* str) { //метод поиска подстроки в строке
    int i = 0, j = 0;
    int nTemp = i;
    int nStrLen = strlen(this->str);
    int nStrSubLen = strlen(str);
    for (i = 0; i < nStrLen - nStrSubLen; i++)
    {
        nTemp = i;
        for (j = 0; j < nStrSubLen; j++)
        {
            if (this->str[nTemp] == str[j])
            {
                if (j == nStrSubLen - 1)
                    return 1;
                nTemp++;
            }
            else
                break;
        }
    }
    return 0;
}
int MyString::My_Strchr(char c)const {       //метод поиска заданного символа в строке
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i; //возвращение индекса
        }
        else {
            i++;
        }
    }
    return -1; //возвращение -1 если не найденно
}
int MyString::MyStrCmp(const MyString& b)const {   //сравнение строк
    int i = 0;
    int flag = 0; //если первая строка больше = 1, если другая больше = -1, если одинаковые = 0
    while (flag == 0)
    {
        if (str[i] > b.str[i])
            flag = 1;
        else if (str[i] < b.str[i])
            flag = -1;
        if (str[i] == '\0')
            break;
        i++;
    }
    return flag;
}
void MyString::MyStrCat(const MyString& b)   //объединение строк
{
    char* temp = new char[size + b.size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = str[i];
    }
    for (int i = 0; i < b.size; i++)
    {
        temp[i + size] = b.str[i];
    }
    size += b.size;
    temp[size] = '\0';
    delete[] str;
    str = temp;
}
void MyString::MyDelChr(char c) {      //удаление заданных символов в строке
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != c)
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}
void MyString::Print() {             //вывод
    cout << "Str: " << str << endl;
}
void MyString::Input() {             //ввод с клавиатуры
    cout << "Enter text: ";
    cin.getline(str, size);
}
void MyString::MyStrCpy(MyString& b) //метод копирывания строки
{
    while ((*str++ = *b.str++) != '\0' && size--);
}

MyString& MyString::operator=(const MyString& obj) { //оператор присваивания
    if (this == &obj) {
        return *this;
    }
    if (str != nullptr) {
        delete[] str;
    }

    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    size = obj.size;

    for (int i = 0; i < size; i++) {
        if (str[i] != '\0') {
            break;
        }
        str[i] = obj.str[i];
    }
    return *this;
}
void MyString::operator() () {  //оператор вызова функции
    cout << "String: " << str << endl << endl << endl;
}
MyString::operator int()const {     //оператор преобразование типов из int
    return size;
}
MyString::operator char* ()const {  //оператор преобразование типов из char
    return str;
}
char MyString::operator[](int index)const {  //поиск по индексу
    if (index >= 0 && index <= size) {
        return str[index];
    }
    return str[0];
}

const char* MyString::My_Str()const {  //возвращает указатель на строку
    return str;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
    for (int i = 0; i < obj.size; i++) {
        os << obj[i];
    }
    return os;
}