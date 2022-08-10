#pragma once

#include <memory>
#include <string>


namespace date
{
    std::shared_ptr<std::string> DdMmYyyyDateToYyMmDd(const std::string& dd_mm_yyyy_date);
}
