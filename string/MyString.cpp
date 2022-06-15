#include "MyString.h"
#include <cstring>
#include <iostream>
#include <cassert>
MyString::MyString() {
	str = new char[1];
	str[0] = '\0';
	capacity = 2;
}
MyString::MyString(const char* st) {

	if (st == nullptr) {
		str = new char[1];
		str[0] = '\0';
		capacity = 2;
		return;
	}
	
	len = strlen(st);
	capacity = (len + 1) * 2;
	str = new char[capacity];
	strcpy_s(str, len + 1, st);
	std::cout << str <<std::endl;
}
MyString::MyString(std::initializer_list<const char> list)
{
	if (list.size() == 0) {
		str = new char[1];
		str[0] = '\0';
		capacity = 2;
		return;
	}
	len = list.size();
	capacity = (len + 1) * 2;
	str = new char[capacity];
	int it = 0;
	for (auto i : list) {
		str[it++] = i;
	}
	str[len] = '\0';
}
MyString::MyString(const MyString& obj)
{
	this->len = obj.len;
	this->capacity = obj.capacity;
	this->str = new char[capacity];
	strcpy_s(this->str, len + 1, obj.str);
}
MyString::MyString(MyString&& obj) noexcept
{
	this->str = obj.str;
	this->capacity = obj.capacity;
	this->len = obj.len;
	obj.str = nullptr;
	obj.capacity = 0;
	obj.len = 0;
}
MyString::~MyString() {
	delete[] str;
}


MyString& MyString::operator=(const MyString& obj)
{
	if (this->str != nullptr) {
		delete[] str;
	}
	this->len = obj.len;
	this->capacity = obj.capacity;
	this->str = new char[capacity];
	strcpy_s(this->str, len + 1, obj.str);
	return *this;
}

MyString& MyString::operator=(MyString&& obj)
{
	if (this == &obj) return *this;
	this->str = obj.str;
	this->capacity = obj.capacity;
	this->len = obj.len;
	obj.str = nullptr;
	obj.capacity = 0;
	obj.len = 0;
	return *this;
}

char& MyString::operator[](const int pos)
{
	assert(pos < len && pos > 0);
	return str[pos];
}

const char& MyString::operator[](const int pos) const
{
	assert(pos <= len && pos >= 0);
	return str[pos];
}

bool MyString::operator==(const MyString& obj) const
{
	return strcmp(this->str, obj.str) == 0 ? true : false;
}

bool MyString::operator!=(const MyString& obj) const
{
	return !operator==(obj);
}

MyString MyString::operator+(const MyString& obj) const
{
	size_t size = this->len + obj.len;
	char* arr = new char[size + 1];
	arr[0] = '\0';
	strcat_s(arr, size + 1, this->str);
	strcat_s(arr, size + 1, &(obj[0]));
	std::cout << arr << std::endl;
	return MyString(arr);
}

MyString& MyString::operator+=(const MyString& obj)
{
	this->len += obj.len;
	if ((static_cast<int>(capacity) - static_cast<int>(len) - 1) < 0) {
		char* temp = new char[this->len + 1];
		strcpy_s(temp, this->len + 1, this->str);
		this->str = new char[len + 1];
		strcpy_s(this->str, strlen(temp) + 1, temp);
		delete[] temp;
	}
	strcat_s(this->str, this->len + 1, obj.str);
	std::cout << this->str << std::endl;
	return *this;
}

bool MyString::operator<=(const MyString& obj) const
{
	return strcmp(this->str, obj.str) <= 0 ? true : false;
}

bool MyString::operator<(const MyString& obj) const
{
	return strcmp(this->str, obj.str) < 0 ? true : false;
}

bool MyString::operator>(const MyString& obj) const
{
	return strcmp(this->str, obj.str) > 0 ? true : false;
}

bool MyString::operator>=(const MyString& obj) const
{
	return strcmp(this->str, obj.str) >= 0 ? true : false;
}

bool MyString::empty() const
{
	return len == 0 ? true : false;
}

void MyString::reserve(int buf)
{
	if (buf < 0) throw 4;
	if (buf > capacity) {
		try {
			char* temp;
			temp = new char[this->len + 1];
			temp[0] = '\0';
			strcpy_s(temp, this->len + 1, this->str);
			delete[] this->str;
			this->str = new char[buf];
			strcpy_s(this->str, this->len + 1, temp);
			this->capacity = buf;
			delete[] temp;
		}
		catch (int) {
			std::cout << "Wrong position";
		}
		catch (...) {
			std::cout << "Cannot allocate memory of this size";
		}

	}
	if (buf <= capacity) return;

}

size_t MyString::getCapacity() const
{
	return capacity;
}

void MyString::clear()
{
	delete[] this->str;
	len = 0;
	this->str = new char[1];
	str[0] = '\0';
}

bool MyString::insert(const int pos, const char ch)
{
	if (pos < len) {
		if ((static_cast<int>(capacity) - static_cast<int>(len) - 1) <= 0){
			reserve((len + 1)* 2);
		}
		for (int i = len; i >= pos; --i) {
			std::swap(str[i], str[i + 1]);
		}
		str[pos] = ch;
		++len;
		return true;
	}
	else 
		return false;
}

bool MyString::erase(const int pos)
{
	if (pos < 0 || pos >= len) {
		return false;
	}
	else {
		for (int i = pos; i <= len; ++i) {
			std::swap(str[i], str[i + 1]);
		}
		--len;
	}
}

void MyString::push_back(const char ch)
{
	if (len + 2 > capacity) {
		reserve((len + 1) * 2);
	}
	std::swap(str[len], str[len + 1]);
	str[len] = ch;
	++len;
}

void MyString::pop_back()
{
	std::swap(str[len], str[len - 1]);
	--len;
}

void MyString::append(const int count, const char ch)
{
	if (count + len + 2 > capacity) {
		reserve((len + 1) * 2 + count);
	}
	std::swap(str[len], str[len + count]);
	for (int i = len; i < len + count; ++i) {
		str[i] = ch;
	}
	len += count;
}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
	out << obj.str;
	return out;
}
