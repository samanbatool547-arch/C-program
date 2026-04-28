#include <iostream>
using namespace std;

void cgpaCheck();
void votingCheck();
void crSelection();

int main() {
    cgpaCheck();
    votingCheck();
    crSelection();
    return 0;
}

// Function 1: CGPA Check
void cgpaCheck() {
    float cgpa;
    cout << "Enter CGPA: ";
    cin >> cgpa;

    if(cgpa >= 3.5)
        cout << "Excellent Result\n";
    else if(cgpa >= 3.0)
        cout << "Good Result\n";
    else if(cgpa >= 2.0)
        cout << "Average Result\n";
    else
        cout << "Poor Result\n";
}

// Function 2: Voting Check
void votingCheck() {
    int age;
    cout << "Enter Age: ";
    cin >> age;

    if(age >= 18)
        cout << "Eligible for Voting\n";
    else
        cout << "Not Eligible for Voting\n";
}

// Function 3: CR Selection
void crSelection() {
    int marks, attendance;

    cout << "Enter Marks: ";
    cin >> marks;

    cout << "Enter Attendance: ";
    cin >> attendance;

    if(marks >= 80 && attendance >= 75)
        cout << "Selected as CR\n";
    else
        cout << "Not Selected as CR\n";
}
