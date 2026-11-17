#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>

class Patient;

class Doctor {
public:
    Doctor(const std::string& name, const std::string& license, const std::string& specialty);

    const std::string& getName() const { return name; }
    const std::string& getLicense() const { return license; }
    const std::string& getSpecialty() const { return specialty; }

    void addPatient(Patient* patient);
    void removePatient(Patient* patient);
    const std::vector<Patient*>& getPatients() const { return patients; }

    // Returns a printable list of this doctor's patients.
    std::string listPatients() const;

private:
    std::string name;
    std::string license;
    std::string specialty;
    std::vector<Patient*> patients;   // not owned; Clinic owns all patients
};

#endif
