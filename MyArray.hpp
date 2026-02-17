#ifndef _MY_ARRAY_HPP_
#define _MY_ARRAY_HPP_
#include <memory>
#include <initializer_list>
#include <iostream>
#include <span>
#include <utility>
#include <sstream>
#include <algorithm>

class MyArray
{
public:
	explicit MyArray(size_t size);
	explicit MyArray(std::initializer_list<int> list);

	MyArray(const MyArray& originalArray);
	MyArray& operator= (const MyArray& originalArray);

	MyArray(MyArray&& originalArray) noexcept;
	MyArray& operator= (MyArray&& originalArray) noexcept;

	std::string toString() const;

	bool operator== (const MyArray& originalArray) const noexcept;
	
	int& operator[] (size_t index);
	const int& operator[] (size_t index) const;

	explicit operator bool() const noexcept;

	MyArray& operator++();
	MyArray operator++(int);

	size_t size() const noexcept;
	

private:
	std::unique_ptr<int[]> ptr;
	size_t arrSize{ 0 };
	friend void swap(MyArray &firstObj, MyArray &secondObj) noexcept;
};

#endif // !_MY_ARRAY_HPP_
