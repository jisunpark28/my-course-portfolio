#include "Header.h"
namespace jisun {
	IntArray::IntArray(size_t size) {
		if (!size) m_size = 1;
		m_data = new int[m_size = size] {};
	}
	IntArray::IntArray(const IntArray& other) {
		m_data = new int[m_size = other.m_size] {};
		for (size_t i = 0; i < m_size; m_data[i] = other[i], i++);
	}
	IntArray& IntArray::operator=(const IntArray& other) {
		if (this != &other) {
			delete m_data;
			m_data = new int[m_size = other.m_size] {};
			for (size_t i = 0; i < m_size; m_data[i] = other[i], i++);
		}
		return *this;
	}
	IntArray::IntArray(IntArray&& other)noexcept {
		m_data = other.m_data;
		m_size = other.m_size;
		other.m_data = new int[1] {};
		other.m_size = 1;
	}
	IntArray& IntArray::operator=(IntArray&& other)noexcept {
		if (this != &other) {
			delete m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			other.m_data = new int[1] {};
			other.m_size = 1;
		}
		return *this;
	}
	IntArray::~IntArray() {
		delete[] m_data;
	}

	int& IntArray::operator[](size_t index) {
		if (m_size <= index) {
			int* tmpData = new int[index + 1] {};
			for (size_t i = 0; i < m_size; tmpData[i] = m_data[i], i++);
			delete[] m_data;
			m_data = tmpData;
			m_size = index + 1;
		}
		return m_data[index];
	}
	const int& IntArray::operator[](size_t index) const {
		if (m_size <= index) {
			IntArray* tmpObj = const_cast<IntArray*>(this);
			int* tmpData = new int[index + 1] {};
			for (size_t i = 0; i < m_size; tmpData[i] = m_data[i], i++);
			delete[] m_data;
			tmpObj->m_data = tmpData;
			tmpObj->m_size = index + 1;
		}
		return m_data[index];
	}
	size_t IntArray::size() const {
		return m_size;
	}
}