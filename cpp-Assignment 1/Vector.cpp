

#include "Vector.h" // include definition of class vector 
#include <iostream>
// empty container constructor (default constructor)
// Constructs an empty container, with no elements.
vector::vector()
{
	myFirst = myLast = myEnd = nullptr;
}

// fill constructor
// Constructs a container with "count" elements.
// Each element is initialized as 0.
vector::vector(const size_type count)
{
	myFirst = new value_type[count];
	for (size_type i = 0; i < count; i++)
	{
		myFirst[i] = 0;
	}
	myLast = myFirst + count;
	myEnd = myFirst + count;

}

// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector(const vector & right)
{
	const size_type rightc = right.myEnd - right.myFirst;
	const size_type rights = right.myLast - right.myFirst;
	

	myFirst = new value_type[rights];
	
	for (size_type i = 0; i < rights ; i++)
	{
		myFirst[i] = right.myFirst[i];
	}
	myLast = myFirst + rights;
	myEnd = myFirst + rights;

}

// Vector destructor
// Destroys the container object.
// Deallocates all the storage capacity allocated by the vector.
vector::~vector()
{
	if (myFirst != nullptr)
		delete[] myFirst;
}

// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the vector size by one,
// which causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
void vector::push_back(const value_type& val)
{
	size_type originalSize = size();
	resize(originalSize + 1);
	myFirst[originalSize] = val;
}

// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
// Copies all the elements from "right" into the container
// (with "right" preserving its contents).
vector& vector::assign(const vector& right)
{
	if (this != &right) // avoid self-assignment
	{	
		const size_type rightc = right.myEnd - right.myFirst;
		const size_type rights = right.myLast - right.myFirst;
		
		
		pointer newFirst;
		
		// this vector capacity is equal to right.size()
		if( capacity() == 0){
			
			delete[] myFirst;
			myFirst = newFirst;
			myLast = myFirst + rights;
			myEnd = myFirst + rights;

		}else{

			myLast = myFirst + rights;
		}

				
		for(size_type i=0 ; i < rights; i++)
		{
			myFirst[i] = right.myFirst[i];
		}
		
		
		
	}

	return *this; // enables x = y = z, for example
}

// Resizes the vector so that it contains newSize elements.
// If newSize is smaller than the current vector size,
// the content is reduced to its first newSize elements, removing those beyond.
// If newSize is greater than the current vector size,
// the content is expanded by inserting at the end
// as many elements as needed to reach a size of newSize.
// The new elements are initialized as 0.
// If newSize is also greater than the current vector capacity,
// an automatic reallocation of the allocated storage space takes place.
void vector::resize(const size_type newSize)
{	
	size_type tempc = capacity();
	size_type newcap = size()*2;
	
	
	const size_type temps = size();

	
	
	if (temps == newSize)
	{
		return;
	}
	if (temps > newSize) {

		myLast = myFirst + newSize;
		return;
	}
	if (temps < newSize)
	{
		if (tempc >= newSize)
		{	
			
			myLast = myFirst + newSize;
			for (size_type i = temps; i <newSize ; i++)
			{
				myFirst[i] = 0;
			}
		}
		else if ( newcap < newSize) // If the 2 * size() is smaller than newSize
		{	
			value_type * arr = new value_type[newSize];

			for (size_type i = 0; i < temps; i++)
			{
				arr[i] = myFirst[i];
			}
			
			delete[] myFirst;

			myFirst = arr;
			
			for (size_type i = temps; i < newSize; i++)
			{
				arr[i] = 0;
			}
			myEnd = myFirst + newSize;
			myLast = myFirst + newSize;
		}
		else	//  2 * size() is bigger than newSize
		{	
			
			value_type* arr = new value_type[newcap];

			for (size_type i = 0; i < temps; i++)
			{
				arr[i] = myFirst[i];
				
			}

			delete[] myFirst;

			myFirst = arr;

			for(size_type i=temps; i< newSize;i++)
				arr[i] = 0;
			
		
			myLast = myFirst + newSize;
			myEnd = myFirst + newcap;
		}
		
	}

	

}

// Removes the last element in the vector,
// effectively reducing the container size by one.
void vector::pop_back()
{
	if (size() > 0)
		--myLast;
}

// Removes all elements from the vector (which are destroyed),
// leaving the container with a size of 0.
// A reallocation is not guaranteed to happen,
// and the vector capacity is not guaranteed to change due to calling this function.
void vector::clear()
{
	myLast = myFirst;
}

// Returns an iterator pointing to the first element in the vector.
// If the container is empty, the returned iterator value shall not be dereferenced.
vector::pointer vector::begin()
{
	return myFirst;
}

// Returns the number of elements in the vector.
// This is the number of actual objects held in the vector,
// which is not necessarily equal to its storage capacity.
vector::size_type vector::size()
{
	return (myLast - myFirst);
}

// Returns the size of the storage space currently allocated for the vector,
// expressed in terms of elements.
// This capacity is not necessarily equal to the vector size.
// It can be equal or greater, with the extra space allowing to accommodate
// for growth without the need to reallocate on each insertion.
vector::size_type vector::capacity()
{
	return (myEnd - myFirst);
}

// Returns a reference to the element at position "pos" in the vector container.
vector::value_type& vector::element(const size_type pos)
{
	return myFirst[pos];
}


