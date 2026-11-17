#include "Date.h"

#include <iomanip>
#include <sstream>
#include <tuple>

std::string Date::toString() const {
    if (!isSet()) return "(none)";
    std::ostringstream out;
    out << year << '-' << std::setw(2) << std::setfill('0') << month
        << '-' << std::setw(2) << std::setfill('0') << day;
    return out.str();
}

bool Date::operator<(const Date& other) const {
    return std::tie(year, month, day) < std::tie(other.year, other.month, other.day);
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}
