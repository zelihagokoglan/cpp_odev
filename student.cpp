#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Student::Student() {
    size = 0;
    capacity = 10;

    names = new string[capacity];
    studentNumbers = new string[capacity];
    midterms = new float[capacity];
    secondExams = new float[capacity];
    assignments = new float[capacity];
    finals = new float[capacity];
    attendance = new int[capacity];
}

Student::~Student() {
    delete[] names;
    delete[] studentNumbers;
    delete[] midterms;
    delete[] secondExams;
    delete[] assignments;
    delete[] finals;
    delete[] attendance;
}

void Student::resize() {
    int newCapacity = capacity * 2;

    string* newNames = new string[newCapacity];
    string* newStudentNumbers = new string[newCapacity];
    float* newMidterms = new float[newCapacity];
    float* newSecondExams = new float[newCapacity];
    float* newAssignments = new float[newCapacity];
    float* newFinals = new float[newCapacity];
    int* newAttendance = new int[newCapacity];

    for (int i = 0; i < size; ++i) {
        newNames[i] = names[i];
        newStudentNumbers[i] = studentNumbers[i];
        newMidterms[i] = midterms[i];
        newSecondExams[i] = secondExams[i];
        newAssignments[i] = assignments[i];
        newFinals[i] = finals[i];
        newAttendance[i] = attendance[i];
    }

    delete[] names;
    delete[] studentNumbers;
    delete[] midterms;
    delete[] secondExams;
    delete[] assignments;
    delete[] finals;
    delete[] attendance;

    names = newNames;
    studentNumbers = newStudentNumbers;
    midterms = newMidterms;
    secondExams = newSecondExams;
    assignments = newAssignments;
    finals = newFinals;
    attendance = newAttendance;

    capacity = newCapacity;
}

void Student::readFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Dosya açılamadı: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (size >= capacity) {
            resize();
        }

        stringstream ss(line);
        string value;

        getline(ss, value, ',');
        names[size] = value;

        getline(ss, value, ',');
        studentNumbers[size] = value;

        getline(ss, value, ',');
        midterms[size] = stof(value);

        getline(ss, value, ',');
        secondExams[size] = stof(value);

        getline(ss, value, ',');
        assignments[size] = stof(value);

        getline(ss, value, ',');
        finals[size] = stof(value);

        getline(ss, value, ',');
        attendance[size] = stoi(value);

        size++;
    }
    file.close();
}

float Student::average(int index) const {
    return midterms[index] * 0.2 + secondExams[index] * 0.2 +
           assignments[index] * 0.2 + finals[index] * 0.4;
}

void Student::print() const {
    for (int i = 0; i < size; ++i) {
        cout << setw(10) << names[i] << " | "
             << studentNumbers[i] << " | "
             << "Ortalama: " << fixed << setprecision(2) << average(i)
             << endl;
    }
}

void Student::print(int status) const {
    for (int i = 0; i < size; ++i) {
        float avg = average(i);
        if ((status == 1 && avg >= 50) || (status == 0 && avg < 50)) {
            cout << setw(10) << names[i] << " | "
                 << studentNumbers[i] << " | "
                 << "Ortalama: " << fixed << setprecision(2) << avg
                 << endl;
        }
    }
}

void Student::print(const string& outputFile) const {
    ofstream file(outputFile);
    if (!file.is_open()) {
        cerr << "Dosya açılamadı: " << outputFile << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << names[i] << "," << studentNumbers[i] << ","
             << average(i) << endl;
    }
    file.close();
}
