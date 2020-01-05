#include <iostream>

#include "myclass.h"

int main (int argc, char * argv[])
{
    MyClass * myObj = new MyClass(999);

    int id = myObj->get_id();
    
    std::cout << "Hello!" << std::endl;
    std::cout << "ID: " << id << std::endl;
    
    return 0;
}
