#include "course.h"
#include "student.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

// ostream &operator<<(ostream &out, const Course &course) { return out; }

// Constructor
Course::Course(string courseNumber, string courseTitle)
    : courseNum(move(courseNumber)), courseTitle(move(courseTitle)) {}

// Accessors
string Course::getCourseNumber() const { return courseNum; }

string Course::getCourseTitle() const { return courseTitle; }

// Remove student from course
bool Course::removeStudent(int studentID) {
  // If the student can be removed from the course remove them and return true
  // else return false
  if (studentListWithID.count(studentID) != 0) {
    studentListWithID.erase(studentID);
    return true;
  }
  return false;
}

// Add student to course
bool Course::addStudent(int studentID, Student *student) {
  // If the student can be added to the course add them and return true
  // else return false
  if (studentListWithID.count(studentID) == 0) {
    studentListWithID[studentID] = student;
    return true;
  }
  return false;
}

// Returns a string of the students in the class ordered by last name
string Course::getClassListByLastName() const {
  // Make a vector of students to sort through
  vector<Student *> studentsInClass;

  // Add students to the vector
  for (const auto &students : studentListWithID) {
    studentsInClass.push_back(students.second);
  }

  // Sort vector
  sort(studentsInClass.begin(), studentsInClass.end(), cmpLastName);

  // // Return the string in order by last name
  stringstream student;
  string classListByLastName = "[";
  if (!studentsInClass.empty()) {
    student << *studentsInClass[0];
    classListByLastName.append(student.str());
  }
  for (int i = 1; i < studentsInClass.size(); i++) {
    student.str("");
    student << *studentsInClass[i];
    classListByLastName.append(", " + student.str());
  }
  classListByLastName.append("]");
  return classListByLastName;
}

// Returns a string of the students in the class ordered by their ID number
string Course::getClassListByID() const {
  // Make a vector of students to sort through
  vector<Student *> studentsInClass;

  // Add students to the vector
  for (const auto &students : studentListWithID) {
    studentsInClass.push_back(students.second);
  }

  // Sort vector
  sort(studentsInClass.begin(), studentsInClass.end(), cmpID);

  // // Return the string in order by last name
  stringstream student;
  string classListByLastName = "[";
  if (!studentsInClass.empty()) {
    student << *studentsInClass[0];
    classListByLastName.append(student.str());
  }
  for (int i = 1; i < studentsInClass.size(); i++) {
    student.str("");
    student << *studentsInClass[i];
    classListByLastName.append(", " + student.str());
  }
  classListByLastName.append("]");
  return classListByLastName;
}

// Compare helper method to sort students based on their last name
bool Course::cmpLastName(const Student *one, const Student *two) {
  return one->getStudentLastName() < two->getStudentLastName();
}

// Compare helper method to sort students based on their student ID
bool Course::cmpID(Student *one, Student *two) {
  return one->getStudentID() < two->getStudentID();
}