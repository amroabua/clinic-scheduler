# Clinic Scheduler

C++ class project for Object Oriented Programming: a tool for an office admin to manage patients, doctors and appointments.

## Classes
- **Patient**: name, condition, age, height, weight, last/next appointment, assigned doctor
- **Doctor**: name, license, specialty, `listPatients()`
- **Clinic**: owns all patients and doctors; search, sort and calendar features (what the GUI buttons call)
- **Date**: simple year/month/day used for appointments

`main.cpp` is a temporary console menu so the classes can be tested. The GUI (List Patients, List Calendar, Search by Name/Date, New Patient, Print Area) will call the same `Clinic` methods.

## Build
```
cmake -S . -B build
cmake --build build
./build/clinic
```
Or without CMake: `g++ -std=c++17 -Iinclude src/*.cpp -o clinic`

## Git workflow
1. `git clone <repo url>` (first time only)
2. `git pull` before you start working
3. Make your changes
4. `git add .`
5. `git commit -m "what you changed"`
6. `git push`

Tip: work on different files at the same time to avoid merge conflicts. GitHub Desktop is an easy alternative to the command line.
