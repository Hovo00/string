#ifndef MY_STRING_H
#define MY_STRING_H
#include <initializer_list>
#include <iostream>

class MyString
{
public:
	//Constructors and destructor
	MyString();
	MyString(const char *);
	MyString(std::initializer_list<const char>);
	MyString(const MyString&);
	MyString(MyString&&) noexcept;
	~MyString();

	//Operators
	MyString& operator = (const MyString&);
	MyString& operator = (MyString&&);
	char& operator[](const int);
	const char& operator[](const int) const;
	bool operator == (const MyString&) const;
	bool operator != (const MyString&) const;
	MyString operator +(const MyString& )const;
	MyString& operator +=(const MyString&);
	bool operator <=(const MyString&) const;
	bool operator <(const MyString&) const;
	bool operator >(const MyString&) const;
	bool operator >=(const MyString&) const;
	friend std::ostream& operator <<(std::ostream& , const MyString&);
	
	//FUNCTIONS
	bool empty() const;
	void reserve(int);
	size_t getCapacity() const;
	void clear();
	bool insert(const int, const char);
	bool erase(const int);
	void push_back(const char);
	void pop_back();
	void append(const int, const char);

private:
	char* str = nullptr;
	size_t len = 0;
	size_t capacity = 0;
};

#endif

