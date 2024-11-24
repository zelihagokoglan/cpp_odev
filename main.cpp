#include "student.h"
#include <iostream>

using namespace std;

int main() {
    Student students;

    // girdi.csv dosyasını oku
    students.readFromCSV("girdi.csv");

    // Tüm listeyi yazdır
    cout << "Tüm Öğrenciler:" << endl;
    students.print();

    // Geçenleri yazdır
    cout << "\nGeçen Öğrenciler:" << endl;
    students.print(1);

    // Kalanları yazdır
    cout << "\nKalan Öğrenciler:" << endl;
    students.print(0);

    // Sonuçları dosyaya yaz
    students.print("output.csv");

    return 0;
}
