#include "myclass.h"

MyClass::MyClass(int id)
{
    m_id = id;
}

MyClass::~MyClass()
{
}

int MyClass::get_id()
{
    return m_id;
}
