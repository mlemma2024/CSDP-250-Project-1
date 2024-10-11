//
//  main.cpp
//  course record manager
//
//  Created by meadi lemma on 10/07/24.
//

#include <iostream>
#include "CourseList.h"

using namespace std;

int main() {
    CourseList courses;
    string code;
    int hours;
    char grade;
    
    // Input 10 courses
    cout << "Enter 10 courses (course code, credit hours, grade):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Course " << (i + 1) << ":" << endl;
        cout << "Course Code: ";
        cin >> code;
        cout << "Credit Hours: ";
        cin >> hours;
        cout << "Grade: ";
        cin >> grade;
        courses.addCourse(code, hours, grade);
    }

    // Display the course list
    cout << "Course list before deletion:" << endl;
    courses.displayCourses();

    // Delete two courses
    cout << "Enter the course code of two courses to delete:" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "Course Code: ";
        cin >> code;
        courses.deleteCourse(code);
    }

    // Display the course list after deletion
    cout << "Course list after deletion:" << endl;
    courses.displayCourses();

    return 0;
}
