// Temporary console front end so the classes can be tested before the GUI exists.
// Each menu option matches a button from the GUI sketch; the GUI will call the
// same Clinic methods.

#include <iostream>
#include <limits>
#include <string>
#include "Clinic.h"

static void print(const std::vector<Patient*>& list) {
    if (list.empty()) { std::cout << "  (no results)\n"; return; }
    for (const Patient* p : list) std::cout << "  " << p->toString() << '\n';
}

static Date readDate() {
    Date d;
    char dash;
    std::cout << "Date (YYYY-MM-DD): ";
    std::cin >> d.year >> dash >> d.month >> dash >> d.day;
    return d;
}

static void seed(Clinic& clinic) {
    Doctor& smith = clinic.addDoctor("Smith", "GA-10234", "Family Medicine");
    Doctor& lee = clinic.addDoctor("Lee", "GA-20987", "Cardiology");

    Patient& a = clinic.addPatient("Jane Doe", "Hypertension", 54, 65, 160);
    Patient& b = clinic.addPatient("John Roe", "Annual checkup", 31, 70, 180);
    clinic.assignDoctor(a, lee);
    clinic.assignDoctor(b, smith);
    a.setLastAppointment({2026, 10, 2});
    clinic.scheduleAppointment(a, {2026, 12, 1});
    clinic.scheduleAppointment(b, {2026, 11, 20});
}

int main() {
    Clinic clinic;
    seed(clinic);

    while (true) {
        std::cout << "\n=== Clinic Scheduler ===\n"
                  << "1) List Patients\n2) List Calendar\n3) Search by Name\n"
                  << "4) Search by Date\n5) New Patient\n6) List Doctors\n0) Quit\n> ";
        int choice;
        if (!(std::cin >> choice)) break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) break;
        if (choice == 1) print(clinic.listPatients());
        else if (choice == 2) print(clinic.listCalendar());
        else if (choice == 3) {
            std::string q;
            std::cout << "Name: ";
            std::getline(std::cin, q);
            print(clinic.searchByName(q));
        } else if (choice == 4) {
            print(clinic.searchByDate(readDate()));
        } else if (choice == 5) {
            std::string name, condition, doctorName;
            int age; double h, w;
            std::cout << "Name: ";              std::getline(std::cin, name);
            std::cout << "Condition: ";         std::getline(std::cin, condition);
            std::cout << "Age height(in) weight(lb): "; std::cin >> age >> h >> w;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Patient& p = clinic.addPatient(name, condition, age, h, w);
            std::cout << "Doctor name (blank to skip): "; std::getline(std::cin, doctorName);
            if (Doctor* d = clinic.findDoctor(doctorName)) clinic.assignDoctor(p, *d);
            std::cout << "Added: " << p.toString() << '\n';
        } else if (choice == 6) {
            for (const auto& d : clinic.getDoctors()) std::cout << d->listPatients();
        }
    }
    return 0;
}
