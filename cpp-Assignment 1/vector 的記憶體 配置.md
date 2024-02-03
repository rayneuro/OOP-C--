# MSVC , Clang ,  GNU GCC

They all are C/C++ compilers with different architecture of which MSVC does not follow latest C++ standards (C even more). Clang (LLVM) and GCC usually have parts of latest standard, eg C++23.

MSVC is great for Windows development, both x86 and ARM, cause MS delivers lots of libraries and full support for Windows out of the box - just install Visual Studio.
Other too are integrated into other IDEs, eg Eclipse. Clang is also part of Visual Studio installation and could be installed without any issues.

Clang and GCC might have issues with libraries, eg STL, while MSVC comes with full support (of course not all latest features).

From code quality they are similar. In some cases Clang will make faster/smaller code, on others GCC or MSVC. I saw few benchmarks where other compliers were significantly faster than 3 above but also slower in other cases.



# 實做 vector 的記憶體配置

由於GNU C++ (g++) 的 vector 內部記憶體分配方式(memory manage)與 MSVC C++
的 memory allocate 方式不同 , 所以需要不同的時方法 .


在 GNU 11.4 中, vector capacity 的分配方式為:

```
#include <iostream>
#include <vector>

int main()
{
  using namespace std;
  
  vector<int> normal;
  cout << normal.capacity() << endl;
  
  for (unsigned int loop = 0; loop != 10; ++loop)
  {
      normal.push_back(1);
      cout << normal.capacity() << endl;
  }
  
  cin.get();
  return 0;
}
```

輸出為 
```
0
1
2
4
4
8
8
8
8
16
16
```
MSVC 2013 and MSVC 2019 為
```
0
1
2
3
4
6
6
9
9
9
13
```

由此可知 GNU vector的分配為size()超過capacity()時, capacity()會以 2的冪次（2's power）的方式增加


而 MSVC 是以 capacity() * 3/2 的方式增加


# Pointer 的注意事項

```
int a[4] = {1,2,3,4}
int *ptr = a; // 給予 ptr a-array 的 address
ptr++ ; // 容易出事
以 

```

### C++ and C : * vs [] as a function parameter

> To the compiler, there is no difference.
It reads different though. **[]** suggests you want to pass an array to the function, whereas * could also mean just a simple pointer.
Note that arrays decay to pointers when passed as parameters (in case you didn't already know).