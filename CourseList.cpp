//  CourseList.cpp
//  course record manager
//  Created by meadi lemma on 10/08/24.

#include "CourseList.h"
#include <iostream>

using namespace std;

// Constructor for the CourseNode
CourseNode::CourseNode(string code, int hours, char grade) {
    this->courseCode = code;
    this->creditHours = hours;
    this->grade = grade;
    this->next = nullptr;
}

// Constructor for CourseList
CourseList::CourseList() {
    head = nullptr;
}

// Destructor for CourseList to delete all nodes
CourseList::~CourseList() {
    deleteAllNodes();
}

// Add a course to the list in increasing order of course code
void CourseList::addCourse(string code, int hours, char grade) {
    CourseNode* newNode = new CourseNode(code, hours, grade);
    if (!head || code < head->courseCode) {
        newNode->next = head;
        head = newNode;
    } else {
        CourseNode* current = head;
        while (current->next && current->next->courseCode < code) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Delete a specific course from the list
void CourseList::deleteCourse(string code) {
    if (!head) return;
    if (head->courseCode == code) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    CourseNode* current = head;
    while (current->next && current->next->courseCode != code) {
        current = current->next;
    }
    if (current->next) {
        CourseNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Delete all nodes from the list
void CourseList::deleteAllNodes() {
    while (head) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Display all courses in the list
void CourseList::displayCourses() {
    CourseNode* current = head;
    if (!current) {
        cout << "No courses available." << endl;
        return;
    }
    while (current) {
        cout << "Course: " << current->courseCode
             << ", Credit Hours: " << current->creditHours
             << ", Grade: " << current->grade << endl;
        current = current->next;
    }
}
