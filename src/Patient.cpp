#include "Patient.h"
#include "Doctor.h"

#include <sstream>

Patient::Patient(const std::string& name, const std::string& condition,
                 int age, double heightIn, double weightLb)
    : name(name), condition(condition), age(age), height(heightIn), weight(weightLb) {}

std::string Patient::toString() const {
    std::ostringstream out;
    out << name << " | age " << age << " | " << condition
        << " | last: " << lastAppointment.toString()
        << " | next: " << nextAppointment.toString()
        << " | doctor: " << (doctor ? doctor->getName() : "(unassigned)");
    return out.str();
}
