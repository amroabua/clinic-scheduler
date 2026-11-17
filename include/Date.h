#ifndef DATE_H
#define DATE_H

#include <string>

// Simple calendar date used for appointments.
struct Date {
    int year = 0;
    int month = 0;
    int day = 0;

    bool isSet() const { return year != 0; }
    std::string toString() const;   // "YYYY-MM-DD" or "(none)"

    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
};

#endif
