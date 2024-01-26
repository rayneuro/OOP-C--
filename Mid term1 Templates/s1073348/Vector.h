

// vector standard header

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

// CLASS TEMPLATE VectorVal
template< typename ValueType >
class VectorVal
{
public:
	using value_type = ValueType;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;

	VectorVal()
		: myFirst(),
		myLast(),
		myEnd()
	{
	}

	pointer myFirst; // pointer to beginning of array
	pointer myLast;  // pointer to current end of sequence
	pointer myEnd;   // pointer to end of array
};


// CLASS TEMPLATE vector
template< typename Ty >
class vector // varying size array of values
{
public:
	using value_type = Ty;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = Ty&;
	using const_reference = const Ty&;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

private:
	using ScaryVal = VectorVal< Ty >;

public:
	using iterator = value_type*;
	using const_iterator = const value_type*;

	// empty container constructor (default constructor)
	// Constructs an empty container, with no elements.
	vector()
		: myData()
	{

	}

	// fill constructor
	// Constructs a container with "count" elements.
	// Each element is initialized as 0.
	vector(const size_type count)
		: myData()
	{
		// did not modify
		if (count != 0)
		{
			myData.myFirst = new value_type[count];
			iterator f1 = myData.myFirst;
			iterator f12 = myData.myFirst;
			for (int i = 0; i != count; f1++, i++) // modify
			{
				*f1 = 0;				
			}
			myData.myLast = f1; 
			myData.myEnd = f1; 

		}
	}

	// copy constructor
	// Constructs a container with a copy of each of the elements in "right",
	// in the same order.
	vector(const vector& right)
		: myData()
	{
		const size_type rightc = right.myData.myEnd - right.myData.myFirst;
		const size_type rights = right.myData.myLast - right.myData.myFirst;
		myData.myFirst = new value_type[rights];

		for (size_type i = 0; i < rights; i++)
		{
			myData.myFirst[i] = right.myData.myFirst[i];
		}
		myData.myLast = myData.myFirst + rights;
		myData.myEnd = myData.myFirst + rights;   // modify
	}

	// Vector destructor
	// Destroys the container object.
	// Deallocates all the storage capacity allocated by the vector.
	~vector()
	{
		if (myData.myFirst != nullptr)
			delete[] myData.myFirst;
	}

	// The vector is extended by inserting a new element before the element
	// at the specified position, effectively increasing the container size by one.
	// This causes an automatic reallocation of the allocated storage space
	// if and only if the new vector size surpasses the current vector capacity.
	// Relocates all the elements that were after "where" to their new positions.
	iterator insert(const_iterator where, const value_type& val)
	{
		// did not modify
		if (where >= myData.myFirst && where <= myData.myLast)
		{
			const_iterator t1 = where;
			int s = (*this).size() + 1;
			int cont = 0;
			iterator cot = begin();
			for (; t1 != cot; cot++)
			{
				cont++;
			}
			if (size() + 1 > capacity())
			{
				pointer a = new value_type[size()];
				pointer k = myData.myFirst;

				for (int i = 0; i < size(); i++)
				{
					a[i] = k[i];
				}
				int size = (*this).size();
				int newc;
				if (capacity() * 3 / 2 > s)
				{
					newc = capacity() * 3 / 2;
				}
				else {
					newc = s;
				}
				iterator la = myData.myFirst;
				delete[] myData.myFirst;

				myData.myFirst = new value_type[newc];
				while (la == myData.myFirst) {
					myData.myFirst = new value_type[newc];
				}

				k = myData.myFirst;
				for (int i = 0; i < size; i++)
				{
					k[i] = a[i];
				}
				delete[] a;
				myData.myEnd = myData.myFirst + newc;
				myData.myLast = myData.myFirst + size;
			}

			iterator last = myData.myLast;


			for (; myData.myFirst + cont != last; last--)
			{
				*last = *(last - 1);
			}
			*(last) = val;
			myData.myLast = myData.myFirst + s;

		}
		else
			return nullptr;
	}

	// Removes from the vector either a single element (where).
	// This effectively reduces the container size by one, which is destroyed.
	// Relocates all the elements after the element erased to their new positions.
	iterator erase(const_iterator where)
	{
		// did not modift
		if (where >= myData.myFirst && where < myData.myLast)
		{
			const_iterator t1 = where;
			int size = (*this).size();
			int cont = 0;
			iterator cot = myData.myFirst;
			for (; t1 != cot; cot++)
			{
				cont++;
			}
			for (; cot != myData.myLast - 1; cot++)
			{
				(*cot) = *(cot + 1);
			}

			myData.myLast = myData.myFirst + size - 1;

		}
		else
			return nullptr;
	}

	// Removes all elements from the vector (which are destroyed),
	// leaving the container with a size of 0.
	// A reallocation is not guaranteed to happen,
	// and the vector capacity is not guaranteed to change due to calling this function.
	void clear() // erase all
	{
		myData.myLast = myData.myFirst;
	}

	// Returns an iterator pointing to the first element in the vector.
	// If the container is empty, the returned iterator value shall not be dereferenced.
	iterator begin()
	{
		return myData.myFirst;
	}

	// Returns an iterator pointing to the first element in the vector.
	// If the container is empty, the returned iterator value shall not be dereferenced.
	const_iterator begin() const
	{
		return const_iterator(myData.myFirst);
	}

	// Returns an iterator referring to the past-the-end element in the vector container.
	// The past-the-end element is the theoretical element
	// that would follow the last element in the vector.
	// It does not point to any element, and thus shall not be dereferenced.
	// If the container is empty, this function returns the same as vector::begin.
	iterator end()
	{
		return myData.myLast;
	}

	// Returns an iterator referring to the past-the-end element in the vector container.
	// The past-the-end element is the theoretical element
	// that would follow the last element in the vector.
	// It does not point to any element, and thus shall not be dereferenced.
	// If the container is empty, this function returns the same as vector::begin.
	const_iterator end() const
	{
		return const_iterator(myData.myLast);
	}

	// Returns whether the vector is empty (i.e. whether its size is 0).
	bool empty() const
	{
		return myData.myFirst == myData.myLast;
	}

	// Returns the number of elements in the vector.
	// This is the number of actual objects held in the vector,
	// which is not necessarily equal to its storage capacity.
	size_type size() const
	{
		return static_cast<size_type>(myData.myLast - myData.myFirst);
	}

	// Returns the size of the storage space currently allocated for the vector,
	// expressed in terms of elements.
	// This capacity is not necessarily equal to the vector size.
	// It can be equal or greater, with the extra space allowing to accommodate
	// for growth without the need to reallocate on each insertion.
	size_type capacity() const
	{
		return static_cast<size_type>(myData.myEnd - myData.myFirst);
	}

	// Returns a reference to the element at position "pos" in the vector container.
	value_type& operator[](const size_type pos)
	{
		if (pos >= static_cast<size_type>(myData.myLast - myData.myFirst))
		{
			cout << "vector subscript out of range\n";
			exit(1);
		}

		return myData.myFirst[pos];
	}

	// Returns a reference to the element at position "pos" in the vector container.
	const value_type& operator[](const size_type pos) const
	{
		if (pos >= static_cast<size_type>(myData.myLast - myData.myFirst))
		{
			cout << "vector subscript out of range\n";
			exit(1);
		}

		return myData.myFirst[pos];
	}

private:
	ScaryVal myData;
};

// determine if two Arrays are equal and return true, otherwise return false
template< typename Ty >
bool operator==(const vector< Ty >& left, const vector< Ty >& right)
{
	if (left.size() != right.size())
		return false;
	else {

		for (int i = 0; i < left.size(); i++)  // modify
		{
			if (left[i] == right[i])
				continue;
			else
				return false;
		}
		return true;
	}
}

#endif // VECTOR_H 