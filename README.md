# funcheck
This is a header which can be used to check whether a class has a member function of a ceraint name and signature.

Example:
```cpp
#include <iostream>
#include <string>
#include "funcheck.h"

// define what functions you want to check for
//          (call_name,  function_name, function signature)
DEF_FUNCHECK(has_func1,  func1,         int(const std::string&))
DEF_FUNCHECK(has_func2,  func2,         int(int))

class X {
    int func1(const std::string&) { return 42; } 
    double func2(int a) { return 42; } // wrong signature
    int funky2(int a) { return 42; } // wrong name 
};

int main(){
    std::cout << funcheck::has_func1<X>() << std::endl; // prints 1
    std::cout << funcheck::has_func2<X>() << std::endl; // prints 0
    return 0;
}
```
