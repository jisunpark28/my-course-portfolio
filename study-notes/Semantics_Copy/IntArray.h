#ifndef SENECA_INTARRAY_H
#define SENECA_INTARRAY_H
namespace seneca {
	class IntArray {
		size_t m_size{};
		int* m_data{};
	public:
		IntArray(size_t size);
		// Rule of Three
		IntArray(const IntArray& src);
		IntArray& operator=(const IntArray& src); 
		virtual ~IntArray();
		// Setter & Getter (to use the Obj like a array)
		int& operator[](size_t index); //obj[new_index]=value, The operator[] returns an lvalue reference to the element at new_index
		const int& operator[](size_t index) const; // obj[new_index] --> obj.operator[](new_index)
		size_t size() const;
		/*IntArray(IntArray&& other)noexcept;
		IntArray& operator=(IntArray&& other)noexcept;*/
		//
	};
}

#endif

/*
	#pragma once vs #ifndef/#define/#endif 
		Role: Prevents multiple inclusions (compiles only once)
		Why use traditional guards (#ifndef) instead? 
			. To ensure backwards compatibility
			. C++ standard library headers still use them
			. To practice Conditional Compilation
*/

/*
	Int Array Resizing Steps
	 . Check: Boundary validation (index >= m_size)
	 . Allocate: New dynamic memory (new_data, size: index + 1, zero-initialized)
	 . Copy: Old elements to new_data
	 . Delete: Old memory (delete[] m_data) to prevent leak
	 . Update: Pointer (m_data = new_data) & Size (m_size = index + 1)
	 . Return: Lvalue reference (m_data[index])

*/

/*
	Copy Semantics Steps
	1. Concept (Bottle Analogy)
	 . Target: Deep Copy (Independent duplication)
	 . Analogy: Check target's water amount, go to faucet, fill new exact amount
	 . Result: Two independent objects (Heavy DMA overhead)

	2. Copy Constructor (const Type&)
	 . Parameter: const reference (Read-only, original unchanged)
	 . Allocate: New dynamic memory (DMA)
	 . Copy: Loop and duplicate data elements
	 . Warning: Calling constructor inside body creates temporary object (Do not do it)
	
	3. Copy Assignment (operator= const Type&)
	 . Check: Self-assignment (this != &src)
	 . Delete: Current memory (Prevent memory leak)
	 . Allocate: New dynamic memory (DMA)
	 . Copy: Loop and duplicate data elements
	 . Return: Current object reference (*this)

*/

