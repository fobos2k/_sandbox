#define _GLIBCXX_USE_CXX11_ABI 0

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE boost_TestSecondClass

#include <boost/test/included/unit_test.hpp>
#include "Isolator.h"

#include "secondclass.h"

BOOST_AUTO_TEST_CASE( TestFAKEConcreteClass )
{
    SecondClass * fakeClass = FAKE_ALL<SecondClass>(0);

    BOOST_TEST(fakeClass);

    ISOLATOR_CLEANUP();
}

BOOST_AUTO_TEST_CASE( TestFAKEGetID )
{
    SecondClass * fakeClass = FAKE_ALL<SecondClass>(0);
    WHEN_CALLED(fakeClass->get_id()).Return(0);

    BOOST_TEST(fakeClass->get_id() == 0);

    ISOLATOR_CLEANUP();
}
