#include "converter.hpp"


namespace date
{
    std::shared_ptr<std::string> DdMmYyyyDateToYyMmDd( const std::string& dd_mm_yyyy_date )
    {
        // e.g. 20102014 to 141020 or DDmmYYYY to YYmmDD

        if ( dd_mm_yyyy_date.size() < std::string("20102014").size() ) 
        {
            return nullptr;
        }

        std::string yy_mm_dd_date = dd_mm_yyyy_date.substr(0, 2);

        yy_mm_dd_date.insert(0, dd_mm_yyyy_date.substr(2, 2));

        yy_mm_dd_date.insert(0, dd_mm_yyyy_date.substr(6));

        return std::make_shared<std::string>(yy_mm_dd_date);
    }
}
