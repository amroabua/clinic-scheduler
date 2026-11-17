#ifndef CLINIC_H
#define CLINIC_H

#include <memory>
#include <string>
#include <vector>
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"

// Manager class: owns every patient and doctor, and handles the
// search/sort/calendar features the GUI buttons call.
class Clinic {
public:
    Doctor& addDoctor(const std::string& name, const std::string& license,
                      const std::string& specialty);
    Patient& addPatient(const std::string& name, const std::string& condition,
                        int age, double heightIn, double weightLb);

    void assignDoctor(Patient& patient, Doctor& doctor);
    void scheduleAppointment(Patient& patient, const Date& date);

    // GUI: "List Patients"
    std::vector<Patient*> listPatients() const;
    // GUI: "List Calendar" - patients with an upcoming appointment, by date
    std::vector<Patient*> listCalendar() const;
    // GUI: "Search by Name" - case-insensitive partial match
    std::vector<Patient*> searchByName(const std::string& query) const;
    // GUI: "Search by Date" - next appointment on that date
    std::vector<Patient*> searchByDate(const Date& date) const;

    static void sortByName(std::vector<Patient*>& list);
    static void sortByDate(std::vector<Patient*>& list);

    Doctor* findDoctor(const std::string& name) const;
    const std::vector<std::unique_ptr<Doctor>>& getDoctors() const { return doctors; }

private:
    std::vector<std::unique_ptr<Patient>> patients;
    std::vector<std::unique_ptr<Doctor>> doctors;
};

#endif
