#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

int main() {
    string filename = "girdi.csv";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Dosya acilmadi: " << filename << endl;
        return 1;
    }

    ofstream outputFile("output.csv");
    if (!outputFile.is_open()) {
        cerr << "output.csv dosyası acimadi!" << endl;
        return 1;
    }

    vector<Student*> students;
    string line;

    while (getline(inputFile, line)) {
        if (!line.empty()) {
            Student* student = Student::readFromCSV(line);
            students.push_back(student);
        }
    }

    inputFile.close();

    outputFile << "Gecen Ogrenciler:\n\n";
    for (const auto& student : students) {
        if (student->calculateAverage() >= 50) {
            student->print(outputFile);
        }
    }

    outputFile << "\n\n";

    outputFile << "Kalan Ogrenciler:\n\n";
    for (const auto& student : students) {
        if (student->calculateAverage() < 50) {
            student->print(outputFile);
        }
    }

    cout<<"dosyaya yazmaa islemi tamamlandi...";

    for (auto& student : students) {
        delete student;
    }
    students.clear();

    outputFile.close();
    return 0;
}
