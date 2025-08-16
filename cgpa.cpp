#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course {
    string name;
    double grade;
    int creditHours;
};

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<Course> courses(n);
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << " Name: ";
        cin.ignore();
        getline(cin, courses[i].name);

        cout << "Grade (0-10): ";
        cin >> courses[i].grade;
        cout << "Credit Hours: ";
        cin >> courses[i].creditHours;

        totalCredits += courses[i].creditHours;
        totalGradePoints += courses[i].grade * courses[i].creditHours;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\n--- Semester Report ---\n";
    for (auto &c : courses) {
        cout << c.name << " | Grade: " << c.grade << " | Credits: " << c.creditHours << "\n";
    }
    cout << "Final GPA: " << gpa << "\n";
    cout << "CGPA (Same as GPA for single semester): " << gpa << "\n";

    return 0;
}