//  CourseList.h
//  course record manager
//  Created by meadi lemma on 10/08/24.
#ifndef COURSELIST_H
#define COURSELIST_H

#include <string>
using namespace std;

class CourseNode {
public:
    string courseCode;
    int creditHours;
    char grade;
    CourseNode* next;

    // Constructor to initialize node
    CourseNode(string code, int hours, char grade);
};

class CourseList {
private:
    CourseNode* head;

public:
    CourseList();   // Constructor
    ~CourseList();  // Destructor to delete all nodes

    void addCourse(string code, int hours, char grade);  // Add a course to the list
    void deleteCourse(string code);  // Delete a specific course
    void deleteAllNodes();  // Delete all nodes in the list
    void displayCourses();  // Display all courses
};

#endif // COURSELIST_H
