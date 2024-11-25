#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    string name;
    string studentNumber;
    float midterm;
    float secondExam;
    float homework;
    float finalExam;
    int attendance;

public:
    Student(const string&, const string&, float, float, float, float, int);

    ~Student();

    float calculateAverage() const;

    void print(ofstream& ) const;

    static Student* readFromCSV(const string&);

    /*string getName() const { return name; }
    string getStudentNumber() const { return studentNumber; }
    float getAverage() const { return calculateAverage(); }*/
};

#endif // STUDENT_H
