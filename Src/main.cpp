#include "converter.hpp"

#include <iostream>
#include <iomanip>


int main()
{
    std::string start_date{"23102014"};

    std::cout 
        << std::endl
        << "Converting DDmmYYYY to YYmmDD" 
        << std::endl
        << std::endl
        << "Result of converting " 
        << std::quoted(start_date) 
        << " : " 
        << std::quoted(*date::DdMmYyyyDateToYyMmDd(start_date)) 
        << std::endl
        << std::endl;
}
