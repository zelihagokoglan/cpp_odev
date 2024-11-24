#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:

    int size;  
    int capacity;

    string* names;
    string* studentNumbers;
    float* midterms;
    float* secondExams;
    float* assignments;
    float* finals;
    int* attendance;

    void resize(); 

public:
    Student(); 
    ~Student(); 

    void readFromCSV(const string& filename);
    float average(int index) const;
    void print() const;
    void print(int status) const;
    void print(const string& outputFile) const;
};

#endif
