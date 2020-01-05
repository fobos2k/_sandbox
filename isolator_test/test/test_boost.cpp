#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE boost_RecmanagerTestSuite

#include <boost/test/unit_test.hpp>
#include "Isolator.h"

#include "myclass.h"

BOOST_AUTO_TEST_SUITE( test_suite1 )

BOOST_AUTO_TEST_CASE( constructors_test )
{
    BOOST_TEST_MESSAGE("First...");
    auto realClass = new MyClass(999);
    std::cout << realClass << std::endl;
    BOOST_TEST(realClass);
    BOOST_TEST(realClass->get_id() == 999);

    BOOST_TEST_MESSAGE("Second...");
    // auto fakeClass = FAKE<MyClass>(FakeOptions::CallOriginal);
    // std::cout << fakeClass << std::endl;
    
    // ISOLATOR_INVOKE_CONSTRUCTOR(fakeClass, 999);
    // BOOST_TEST(fakeClass->get_id() == 999);
    BOOST_TEST(true);
    
    
    ISOLATOR_CLEANUP();
}

BOOST_AUTO_TEST_SUITE_END()

