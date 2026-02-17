#include "MyArray.hpp"

MyArray::MyArray(size_t size)
{
	this->arrSize = size;
	this->ptr = std::make_unique<int[]>(size);
}

MyArray::MyArray(std::initializer_list<int> list)
{
	this->arrSize = list.size();
	this->ptr = std::make_unique<int[]>(list.size());
	std::copy(std::begin(list), std::end(list), this->ptr.get());
}

MyArray::MyArray(const MyArray& originalArray)
{
	this->arrSize = originalArray.size();
	this->ptr = std::make_unique<int[]>(originalArray.size());
	const std::span<const int> source{originalArray.ptr.get(), originalArray.size()};
	std::copy(std::begin(source), std::end(source), this->ptr.get());
}

MyArray& MyArray::operator=(const MyArray& originalArray)
{
	MyArray temp(originalArray);
	if (this != &originalArray)
	{
		swap(*this, temp);
	}
	return *this;
}

MyArray::MyArray(MyArray&& originalArray) noexcept
{
	this->arrSize = std::exchange(originalArray.arrSize, 0);
	this->ptr = std::move(originalArray.ptr);
}

MyArray& MyArray::operator=(MyArray&& originalArray) noexcept
{
	if (this != &originalArray)
	{
		this->arrSize = std::exchange(originalArray.arrSize, 0);
		this->ptr = std::move(originalArray.ptr);
	}
	return *this;
}

std::string MyArray::toString() const
{
	const std::span<const int> items = { this->ptr.get(), this->size() };
	std::ostringstream output;

	for (size_t i = 0; auto& item : items)
	{
		i++;
		output << item << (i < this->arrSize ? " " : "");
	}
	return output.str();
}

bool MyArray::operator==(const MyArray& originalArray) const noexcept
{
	const std::span<const int> leftArr{ this->ptr.get(), this->arrSize };
	const std::span<const int> rigthArr{ originalArray.ptr.get(), originalArray.size() };
	return std::equal(std::begin(leftArr), std::end(leftArr), std::begin(rigthArr), std::end(rigthArr));
}

int& MyArray::operator[](size_t index)
{
	if (index >= this->arrSize)
	{
		throw std::out_of_range("ERROR");
	}
	return this->ptr[index];
}

const int& MyArray::operator[] (size_t index) const
{
	if (index >= this->arrSize)
	{
		throw std::out_of_range("ERROR");
	}
	return this->ptr[index];
}

MyArray::operator bool() const noexcept
{
	return size() != 0;
}

MyArray& MyArray::operator++()
{
	const std::span<int> items{ this->ptr.get(), this->arrSize };
	std::for_each(std::begin(items), std::end(items), )
}

MyArray MyArray::operator++(int)
{
	[]() {};
}

size_t MyArray::size() const noexcept
{
	return this->arrSize;
}

void swap(MyArray& firstObj, MyArray& secondObj) noexcept
{
	std::swap(firstObj.arrSize, secondObj.arrSize);
	firstObj.ptr.swap(secondObj.ptr);

}


