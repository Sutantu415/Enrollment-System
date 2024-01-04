#include "student.h"
#include "course.h"

#include <sstream>

using namespace std;

// Constructor
Student::Student(int studentID, string studentName)
    : studentID(studentID), studentName(move(studentName)) {}

// Accessors
int Student::getStudentID() const { return studentID; }

string Student::getStudentName() const { return studentName; }

string Student::getStudentFirstName() const {
  auto delimiter = studentName.find(' ');
  return studentName.substr(0, delimiter);
}

string Student::getStudentLastName() const {
  auto delimiter = studentName.find(' ');
  return studentName.substr(delimiter + 1, studentName.size());
}

// Drop student from given course, return true if successful
bool Student::dropCourse(const string &courseNumber) {
  // If student is enrolled in the course then drop them, else false
  if (enrolledCourses.count(courseNumber) != 0) {
    enrolledCourses.erase(courseNumber);
    return true;
  }
  return false;
}

// Add student to given course and return true if successful
bool Student::addCourse(const string &courseNumber, Course *course) {
  // If student isn't enrolled in the course then enroll them, else false
  if (enrolledCourses.count(courseNumber) == 0) {
    enrolledCourses[courseNumber] = course;
    return true;
  }
  return false;
}

// Check if student is in the course
bool Student::isInCourse(const string &courseNumber) const {
  return enrolledCourses.count(courseNumber) != 0;
}

ostream &operator<<(ostream &out, const Student &student) {
  out << student.getStudentLastName() << ", " << student.getStudentFirstName()
      << " (" << to_string(student.getStudentID()) << ")";
  return out;
}