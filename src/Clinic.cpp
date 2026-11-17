#include "Clinic.h"

#include <algorithm>
#include <cctype>

namespace {
std::string toLower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}
}

Doctor& Clinic::addDoctor(const std::string& name, const std::string& license,
                          const std::string& specialty) {
    doctors.push_back(std::make_unique<Doctor>(name, license, specialty));
    return *doctors.back();
}

Patient& Clinic::addPatient(const std::string& name, const std::string& condition,
                            int age, double heightIn, double weightLb) {
    patients.push_back(std::make_unique<Patient>(name, condition, age, heightIn, weightLb));
    return *patients.back();
}

void Clinic::assignDoctor(Patient& patient, Doctor& doctor) {
    if (patient.getDoctor()) patient.getDoctor()->removePatient(&patient);
    patient.setDoctor(&doctor);
    doctor.addPatient(&patient);
}

void Clinic::scheduleAppointment(Patient& patient, const Date& date) {
    patient.setNextAppointment(date);
}

std::vector<Patient*> Clinic::listPatients() const {
    std::vector<Patient*> result;
    for (const auto& p : patients) result.push_back(p.get());
    sortByName(result);
    return result;
}

std::vector<Patient*> Clinic::listCalendar() const {
    std::vector<Patient*> result;
    for (const auto& p : patients)
        if (p->getNextAppointment().isSet()) result.push_back(p.get());
    sortByDate(result);
    return result;
}

std::vector<Patient*> Clinic::searchByName(const std::string& query) const {
    std::vector<Patient*> result;
    const std::string q = toLower(query);
    for (const auto& p : patients)
        if (toLower(p->getName()).find(q) != std::string::npos) result.push_back(p.get());
    sortByName(result);
    return result;
}

std::vector<Patient*> Clinic::searchByDate(const Date& date) const {
    std::vector<Patient*> result;
    for (const auto& p : patients)
        if (p->getNextAppointment() == date) result.push_back(p.get());
    sortByName(result);
    return result;
}

void Clinic::sortByName(std::vector<Patient*>& list) {
    std::sort(list.begin(), list.end(), [](const Patient* a, const Patient* b) {
        return toLower(a->getName()) < toLower(b->getName());
    });
}

void Clinic::sortByDate(std::vector<Patient*>& list) {
    std::sort(list.begin(), list.end(), [](const Patient* a, const Patient* b) {
        return a->getNextAppointment() < b->getNextAppointment();
    });
}

Doctor* Clinic::findDoctor(const std::string& name) const {
    for (const auto& d : doctors)
        if (toLower(d->getName()) == toLower(name)) return d.get();
    return nullptr;
}
