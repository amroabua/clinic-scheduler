#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Date.h"

class Doctor;

class Patient {
public:
    Patient(const std::string& name, const std::string& condition,
            int age, double heightIn, double weightLb);

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getCondition() const { return condition; }
    int getAge() const { return age; }
    double getHeight() const { return height; }
    double getWeight() const { return weight; }
    const Date& getLastAppointment() const { return lastAppointment; }
    const Date& getNextAppointment() const { return nextAppointment; }
    Doctor* getDoctor() const { return doctor; }

    // Setters
    void setCondition(const std::string& c) { condition = c; }
    void setAge(int a) { age = a; }
    void setHeight(double h) { height = h; }
    void setWeight(double w) { weight = w; }
    void setLastAppointment(const Date& d) { lastAppointment = d; }
    void setNextAppointment(const Date& d) { nextAppointment = d; }
    void setDoctor(Doctor* d) { doctor = d; }

    // One-line summary for the GUI print area.
    std::string toString() const;

private:
    std::string name;
    std::string condition;
    int age;
    double height;   // inches
    double weight;   // pounds
    Date lastAppointment;
    Date nextAppointment;
    Doctor* doctor = nullptr;   // not owned
};

#endif
