#include "String.h" // include definition of class String

string::string()
	: bx(),
	mySize(0),
	myRes(15)
{
}

string::string(const char* const ptr, const size_type count)
	: bx(),
	mySize(0),
	myRes(15)
{
	if (count<=15)
	{
		for (size_type i = 0; i < count; i++)
			bx.buf[i] = ptr[i];
		bx.buf[count] = '\0';
		mySize = count;
		myRes = 15;

	}
	else if(count > 15)
	{
		size_type newMyRes;
		newMyRes = (count / 16) * 16 + 15;
		
		
		bx.ptr = new value_type[newMyRes+1];
		for (size_type i = 0; i < count; i++)
			bx.ptr[i] = ptr[i];
		bx.ptr[count] = '\0';
		mySize = count;
		myRes = newMyRes;

	}


}

string::string(const size_type count, const char ch)
	: bx(),
	mySize(0),
	myRes(15)
{	
	if (count <= 15)
	{
		for (size_type i = 0; i < count; i++)
			bx.buf[i] = ch;
		bx.buf[count] = '\0';
		mySize = count;
		myRes = 15;

	}
	else if(count > 15)
	{		
		size_type newMyRes = (count / 16) * 16 + 15;
		
		bx.ptr = new value_type[newMyRes+1];
		for (size_type i = 0; i < count; i++)
			bx.ptr[i] = ch;
		bx.ptr[count] = '\0';
		mySize = count;
		myRes = newMyRes;
	}

}


string::string(const string& right)
	: bx(),
	 mySize(0),
	 myRes(15)
{
	resize(right.mySize);

	for (unsigned int i = 0; i <= mySize; i++)
		myPtr()[i] = right.myPtr()[i];
}

 

string::~string()
{
	if (myRes > 15)
		delete[] bx.ptr;
}

string::value_type* string::myPtr()
{
	if (myRes < 16)
		return bx.buf;
	else
		return bx.ptr;
}

const string::value_type* string::myPtr() const
{
	if (myRes < 16)
		return bx.buf;
	else
		return bx.ptr;
}

string& string::assign(const string& right)
{
	if (this != &right)
	{
		
		
		
		resize(right.mySize);
		for (unsigned int i = 0; i < mySize; i++)
			myPtr()[i] = right.myPtr()[i];
		
		
	}
	return *this;
}
	
	
	



void string::clear()
{
	mySize = 0;
	myPtr()[0] = value_type();
}

string::iterator string::begin()
{
	return iterator(myPtr());
}

string::const_iterator string::begin() const
{
	return const_iterator(myPtr());
}

string::iterator string::end()
{
	return iterator(myPtr() + static_cast<difference_type>(mySize));
}

string::const_iterator string::end() const
{
	return const_iterator(myPtr() + static_cast<difference_type>(mySize));
}

string::reference string::element(const size_type off)
{
	return myPtr()[off];
}

string::const_reference string::element(const size_type off) const
{
	return myPtr()[off];
}

void string::push_back(char ch)
{
	resize(mySize + 1);
	myPtr()[mySize - 1] = ch;
}

void string::pop_back()
{
	if (mySize > 0)
		--mySize;
}

string::reference string::front()
{
	return myPtr()[0];
}

string::const_reference string::front() const
{
	return myPtr()[0];
}

string::reference string::back()
{
	return myPtr()[mySize - 1];
}

string::const_reference string::back() const
{
	return myPtr()[mySize - 1];
}

const char* string::c_str() const
{
	return myPtr();
}

string::size_type string::size() const
{
	return mySize;
}

void string::resize(const size_type newSize, const char ch)
{
	if(newSize <= myRes)
	{
		if (myRes <= 15)
		{
			if (newSize < mySize) {
				bx.buf[newSize] = '\0';
			}
			else if (newSize >= mySize)
			{
				for (size_type i = mySize; i <newSize; i++)
				{
					bx.buf[i] = ch;
				}
				bx.buf[newSize] = '\0';
			}
			mySize = newSize;

			
		}
		else if(myRes > 15)
		{
			if(newSize <= mySize)
			{	
				bx.ptr[newSize] = '\0';
			}
			else if (newSize > mySize)
			{
				for (size_type i = mySize; i < newSize; i++)
				{
					bx.ptr[i] = ch;
				}
				bx.ptr[newSize] = '\0';
				
			}
			mySize = newSize;

		}
	} 
	else if(newSize > myRes)
	{	
		size_type newMyRes = myRes * 3 / 2;
		if (newMyRes < ((newSize / 16) * 16 + 15)){
			newMyRes = ((newSize / 16) * 16 + 15);
		}
		if (myRes <= 15)
		{
			pointer arr = new value_type[mySize+1];
			for (size_type i = 0; i <= mySize; i++)
			{
				arr[i] = bx.buf[i];
			}
			bx.ptr = new value_type[newMyRes+1];
			for (size_type i = 0; i <= mySize; i++)
			{
				bx.ptr[i] = arr[i];
			}
			delete [] arr;
			for (size_type i = mySize; i < newSize; i++)
			{
				bx.ptr[i] = ch;
			}
			bx.ptr[newSize] = '\0';
			mySize = newSize;
			myRes = newMyRes;
		}
		else if (myRes > 15){

			pointer arr = new value_type[mySize+1];
			for (size_type i = 0; i < mySize; i++)
			{
				arr[i] = bx.ptr[i];
			}
			delete[]bx.ptr;
			bx.ptr = new value_type[newMyRes + 1];
			for (size_type i = 0; i < mySize; i++)
			{
				bx.ptr[i] = arr[i];
			}
			delete[] arr;
			for (size_type i = mySize; i < newSize; i++)
			{
				bx.ptr[i] = ch;
			}
			bx.ptr[newSize] = '\0';
			
			mySize = newSize;
			myRes = newMyRes;

		}
	
	}
}

string::size_type string::capacity() const
{
	return myRes;
}

bool string::empty() const
{
	return mySize == 0;
}