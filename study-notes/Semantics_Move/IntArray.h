#ifndef SENECA_INTARRAY_H
#define SENECA_INTARRAY_H
namespace seneca {
	class IntArray {
		size_t m_size{};
		int* m_data{};
	public:
		IntArray(size_t size);
		// Rule of five
		IntArray(const IntArray& other);
		IntArray& operator=(const IntArray& other);
		IntArray(IntArray&& other)noexcept; // move constructor
		IntArray& operator=(IntArray&& other)noexcept; // move assignment
		virtual ~IntArray();
		// Setter & Getter (to use the Obj like a array)
		int& operator[](size_t index); 
		const int& operator[](size_t index) const; 
		size_t size() const;

		
	};
}

#endif

/*

*/

