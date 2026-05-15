#include "IntArray.h"
namespace seneca {
	IntArray::IntArray(size_t size) {
		if (!size) size = 1;
		m_data = new int[m_size = size] {};
	}

	IntArray::IntArray(const IntArray& src) {
		m_data = new int[m_size = src.m_size] {};
		for (size_t i = 0; i < m_size; m_data[i] = src[i], i++); //src[i] calls operator[], returns lvalue
	}

	IntArray& IntArray::operator=(const IntArray& src) {
		if (this != &src) {
			delete[] m_data;
			m_data = new int[m_size = m_size] {};
			for (size_t i = 0; i < m_size; m_data[i] = src[i], i++);
		}
		return *this;
	}

	IntArray::~IntArray() {
		delete[] m_data;
	}

	int& IntArray::operator[](size_t index) {
		if (index >= m_size) {
			int* newdata = new int[index + 1] {};
			for (size_t i = 0; i < m_size; newdata[i] = m_data[i], i++);
			delete[] m_data;
			m_data = newdata;
			m_size = index + 1;
		}
		return m_data[index];
	}

	const int& IntArray::operator[](size_t index) const {
		//return m_data[index % m_size];
		if (index >= m_size) {
			IntArray* nonConstThis = const_cast<IntArray*>(this);
			int* newdata = new int[index + 1] {};
			for (size_t i=0; i < m_size; newdata[i] = m_data[i], i++);
			delete[] m_data;
			nonConstThis->m_data = newdata;
			nonConstThis->m_size = index + 1;
		}
		return m_data[index];
	}

	size_t IntArray::size() const {
		return m_size;
	}

}

/*
	we can not call the construction as a function!
*/