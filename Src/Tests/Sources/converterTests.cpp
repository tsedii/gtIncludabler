#include "converter.hpp"

#include <gtest/gtest.h>


TEST(ConverterTestSuite, empty_date)
{
    ASSERT_EQ( date::DdMmYyyyDateToYyMmDd( std::string( "" ) ), nullptr );
}

TEST(ConverterTestSuite, date_convert)
{
    std::string start_date{"30122045"};

    ASSERT_EQ( *date::DdMmYyyyDateToYyMmDd( start_date ), std::string("451230") );
}
