#include "secondclass.h"

SecondClass::SecondClass(int id)
{
    m_id = id;
}

SecondClass::~SecondClass()
{
}

int SecondClass::get_id()
{
    return m_id;
}
