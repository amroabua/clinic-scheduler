#include "Doctor.h"
#include "Patient.h"

#include <algorithm>
#include <sstream>

Doctor::Doctor(const std::string& name, const std::string& license, const std::string& specialty)
    : name(name), license(license), specialty(specialty) {}

void Doctor::addPatient(Patient* patient) {
    if (std::find(patients.begin(), patients.end(), patient) == patients.end())
        patients.push_back(patient);
}

void Doctor::removePatient(Patient* patient) {
    patients.erase(std::remove(patients.begin(), patients.end(), patient), patients.end());
}

std::string Doctor::listPatients() const {
    std::ostringstream out;
    out << "Dr. " << name << " (" << specialty << ", license " << license << ")\n";
    if (patients.empty()) out << "  No patients assigned.\n";
    for (const Patient* p : patients) out << "  " << p->toString() << '\n';
    return out.str();
}
