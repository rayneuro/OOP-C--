// string internal header

#ifndef STRING
#define STRING

// CLASS StringVal
template < typename ValueType >
class StringVal
{
public:
	using value_type = ValueType;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;

	StringVal()
		: bx(),
		mySize(0),
		myRes(15)
	{
	}

	value_type* myPtr()
	{
		if (myRes < 16)
			return bx.buf;
		else
			return bx.ptr;
	}

	const value_type* myPtr() const
	{
		if (myRes < 16)
			return bx.buf;
		else
			return bx.ptr;
	}

	union Bxty // storage for small buffer or pointer to larger one
	{
		value_type buf[16];
		pointer ptr;
	} bx;

	size_type mySize; // current length of string
	size_type myRes;  // current storage reserved for string
};

class string // null-terminated transparent array of elements
{
	using ScaryVal = StringVal< char >;

public:
	using value_type = char;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;

	using iterator = value_type*;
	using const_iterator = const value_type*;

	// empty string constructor (default constructor)
	// Constructs an empty string, with a length of zero characters.
	string()
		: myData()
	{
	}

	// String destructor
	// Destroys the string object.
	// Deallocates all the storage capacity allocated by the string.
	~string()
	{
		if (myData.myRes > 15)
			delete[] myData.bx.ptr;
	}

	// Inserts character ch into the string right before the character
	// indicated by "where".
	iterator insert(const_iterator where, const char ch)
	{
		if (where >= myData.myPtr() && where <= myData.myPtr() + myData.mySize)
		{
			const_iterator t1 = where;
			int news = myData.mySize + 1;
			int size = myData.mySize;
			int cont = 0;
			iterator cot = myData.myPtr();
			int l = myData.mySize;

			for (; t1 != cot; cot++, cont++)
			{
			}
			if (news < 16 && myData.myRes <16) // modify
			{
				for (; l != cont; l--)
				{
					myData.bx.buf[l] = myData.bx.buf[l - 1];
				}
				myData.bx.buf[cont] = ch;
				myData.mySize = news;
				myData.bx.buf[news] = '\0';
			}
			else if (news > myData.myRes)
			{
				pointer a = new value_type[size + 1];
				pointer k = myData.myPtr();
				for (int i = 0; i <= size; i++)
				{
					a[i] = k[i];
				}
				size_type newc = myData.myRes * 3 / 2;  //add
				if (newc < ((news / 16) * 16 + 15)) {   //add
					newc = ((news / 16) * 16 + 15);
				}
				iterator la = myData.myPtr();

				if (myData.myRes > 15) delete[] myData.bx.ptr;

				myData.bx.ptr = new value_type[newc + 1];
				if (la == myData.myPtr()) {
					myData.bx.ptr = new value_type[newc + 1];
				}
				myData.myRes = newc;
				k = myData.myPtr();
				for (int i = 0; i <= size; i++)
				{
					k[i] = a[i];
				}
				delete[] a;
				
			}

			if (news > 15 || myData.myRes > 15){ // modify
				int l2 = myData.mySize;  // add
				for (; l2 != cont; l2--)
				{
					myData.bx.ptr[l2] = myData.bx.ptr[l2 - 1];
				}
				myData.bx.ptr[cont] = ch;
				myData.mySize = news;
				myData.bx.ptr[news] = '\0';
			}

		}
		else
			return nullptr;
	}

	// Erases the character pointed by p.
	iterator erase(const_iterator where)
	{
		if (where >= myData.myPtr() && where < myData.myPtr() + myData.mySize)
		{
			const_iterator t1 = where;
			int size = (*this).size();
			
			int cont = 0;
			iterator cot = myData.myPtr();
			for (; t1 != cot; cot++,cont++)
			{
			}
			if (myData.myRes > 15){
				for (; cont != myData.mySize; cont++) //add
				{
					myData.bx.ptr[cont] = myData.bx.ptr[cont + 1];
				}
			}
			else if( myData.myRes == 15){
				for (; cont != myData.mySize ; cont++)   //add
				{
					myData.bx.buf[cont] = myData.bx.buf[cont + 1];
				}
			}
			--(myData.mySize);
		}
		else
			return nullptr;
	}

	// Erases the contents of the string, which becomes an empty string
	// (with a length of 0 characters).
	void clear()
	{
		myData.mySize = 0;
		myData.myPtr()[0] = value_type();
	}

	// Returns an iterator pointing to the first character of the string.
	iterator begin()
	{
		return iterator(myData.myPtr());
	}

	// Returns an iterator pointing to the first character of the string.
	const_iterator begin() const
	{
		return const_iterator(myData.myPtr());
	}

	// Returns an iterator pointing to the past-the-end character of the string.
	// The past-the-end character is a theoretical character
	// that would follow the last character in the string.
	// It shall not be dereferenced.
	// If the object is an empty string, this function returns the same as string::begin.
	iterator end()
	{
		return iterator(myData.myPtr() + static_cast<difference_type>(myData.mySize));
	}

	// Returns an iterator pointing to the past-the-end character of the string.
	// The past-the-end character is a theoretical character
	// that would follow the last character in the string.
	// It shall not be dereferenced.
	// If the object is an empty string, this function returns the same as string::begin.
	const_iterator end() const
	{
		return const_iterator(myData.myPtr() + static_cast<difference_type>(myData.mySize));
	}

	// Returns a reference to the character at position pos in the string.
	reference operator[](const size_type off)
	{
		if (off > myData.mySize)
		{
			cout << "string subscript out of range\n";
			exit(1);
		}

		return myData.myPtr()[off];
	}

	// Returns a reference to the character at position pos in the string.
	const_reference operator[](const size_type off) const
	{
		if (off > myData.mySize)
		{
			cout << "string subscript out of range\n";
			exit(1);
		}

		return myData.myPtr()[off];
	}

	// Returns the length of the string, in terms of bytes.
	// This is the number of actual bytes that conform the contents of the string,
	// which is not necessarily equal to its storage capacity.
	size_type size() const
	{
		return myData.mySize;
	}

	// Returns the size of the storage space currently allocated for the string,
	// expressed in terms of bytes.
	// This capacity is not necessarily equal to the string length.
	// It can be equal or greater, with the extra space allowing the object
	// to optimize its operations when new characters are added to the string.
	size_type capacity() const
	{
		return myData.myRes;
	}

	// Returns whether the string is empty (i.e. whether its length is 0).
	bool empty() const
	{
		return myData.mySize == 0;
	}

private:
	ScaryVal myData;
};

#endif // STRING
