#include <iostream>
#include <vector>
#include "Vector.h"


using std::cout;
using std::endl;


// Determines if two vectors are equal.
bool equal( vector &left, std::vector< int > &right )
{
   if( left.capacity() != right.capacity() ){
      cout << "Vector capacity is " << left.capacity() << endl;
      cout << "STL vector capacity is " << right.capacity() << endl;
      return false;
   }

   if( left.size() != right.size() ){

      cout << "Vector size is " << left.size() << endl;
      cout << "STL vector size is " << right.size() << endl;
      return false;
   }

   for( size_t i = 0; i < right.size(); ++i )
      if( left.element( i ) != right[ i ] ){
         cout << "Vector element is " << left.element(i) << endl;
         cout << "STL vector element is " << right[i] << endl; 
         return false;
      }

   return true;
}

const int number = 5000;

void testAssignment1()
{
   vector vector3;
   std::vector< int > vector4;

   unsigned int numErrors = number;
   unsigned int length;
   int value;
   for( unsigned int i = 0; i < number; i++ )
   {
      vector vector1;
      std::vector< int > vector2;
      length = rand() % 200;
      for( unsigned int j = 0; j < length; j++ )
      {
         value = 1 + rand() % 99;
         vector1.push_back( value );
         vector2.push_back( value );
      }

      vector3.assign( vector1 ); // vector3 = vector1
      vector4 = vector2;

      if( equal( vector3, vector4 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}


int main()
{
    std::vector< int > v;
    int seed = time(0);
    srand(seed);
    for( unsigned int length = 0; length < 16; ++length )
    {
        v.resize(length);
        cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }

    cout << "For random sizes: \n";

    for( unsigned int length = 16; length > 0; --length )
    {
        
        auto s = rand() % 100;
        v.resize(s);
        cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }

    cout << "Test random vector assigned: \n";
    std::vector<int> v1;
    for(auto i = 0; i < 16; i++)
    {
        
        
    //vector v2();
        for(auto j = 0; j < 16; j++)
        {
            v1.push_back(rand() % 100);
            //v2.push_back(rand() % 100);
        }
        
        std::vector<int> v2(v1);
        
        
        cout << "For v1 Size: " << v1.size() << " Capacity: " << v1.capacity() << endl;
        cout << "For v2 (Copy from v1) Size: " << v2.size() << " Capacity: " << v2.capacity() << endl;
    }

    std::cout << "Test random vector = operator overloading :  " <<  std::endl;

    std::vector<int> v3;
    for(auto i = 0; i < 16; i++)
    {
        
        for(auto j = 0; j < 16; j++)
        {
            v3.push_back(rand() % 100);
            //v2.push_back(rand() % 100);
        }
        
        std::vector<int> v2 ;
        v2 = v3;
        
        
        cout << "For v3 Size: " << v3.size() << " Capacity: " << v3.capacity() << endl;
        cout << "For v2 (Copy from v3) Size: " << v2.size() << " Capacity: " << v2.capacity() << endl;
    }
    
    cout << "Test For operator overloading = : (TestAssignement)" << endl;

    std::vector<int> v4;

    for(auto i = 0; i < 16; i++)
    {
        
        std::vector<int> v2 ;

        int length = rand() % 200;
        for(auto j = 0; j < length; j++)
        {
            v2.push_back(rand() % 100);
            //v2.push_back(rand() % 100);
        }
        
        
        v4 = v2;
        
        cout << "For v2 Size: " << v2.size() << " Capacity: " << v2.capacity() << endl;
        cout << "For v4 (Copy from v2) Size: " << v4.size() << " Capacity: " << v4.capacity() << endl;
    }

    testAssignment1();

    std::cin.get();
    return 0;

} // namespace
