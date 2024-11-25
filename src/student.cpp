#include "student.h"
#include <sstream>
#include <iomanip>

Student::Student(const string& name, const string& studentNumber, float midterm, float secondExam, float homework, float finalExam, int attendance)
    : name(name), studentNumber(studentNumber), midterm(midterm), secondExam(secondExam), homework(homework), finalExam(finalExam), attendance(attendance) {}

Student::~Student() {}

float Student::calculateAverage() const {
    return (midterm * 0.2f) + (secondExam * 0.2f) + (homework * 0.2f) + (finalExam * 0.4f);
}

void Student::print(ofstream& outputFile) const {
    outputFile << left << setw(15) << name
               << left << setw(6) << studentNumber
               << right << setw(6) << fixed << setprecision(2) << calculateAverage()
               << endl;
}

Student* Student::readFromCSV(const string& line) {
    stringstream ss(line);
    string name, studentNumber;
    float midterm, secondExam, homework, finalExam;
    int attendance;

    getline(ss, name, ',');
    getline(ss, studentNumber, ',');
    ss >> midterm;
    ss.ignore(1);
    ss >> secondExam;
    ss.ignore(1);
    ss >> homework;
    ss.ignore(1);
    ss >> finalExam;
    ss.ignore(1);
    ss >> attendance;

    return new Student(name, studentNumber, midterm, secondExam, homework, finalExam, attendance);
}
