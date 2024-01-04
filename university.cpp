#include "university.h"
#include "student.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Constructor
University::University(string universityName)
    : universityName(move(universityName)) {}

// Deconstructor
University::~University() {
  // Delete all the student pointers
  for (auto &student : universityStudents) {
    delete student.second;
  }
  // Clear the student map
  universityStudents.clear();

  // Delete all the course pointers
  for (auto &course : universityCourses) {
    delete course.second;
  }
  // Clear the course map
  universityCourses.clear();
}

// Accessor
string University::getUniversityName() const { return universityName; }

// Read list of students for the current university
bool University::readCourseList(const string &filename) {
  string readLine;
  ifstream file;
  file.open(filename);
  // If file didn't get read/opened return false
  if (!file.is_open()) {
    return false;
  }
  // Read each line and create a course obect for each one
  while (getline(file, readLine)) {
    string courseNumber = readLine.substr(0, 6);
    string courseTitle = readLine.substr(7, readLine.size());
    if (universityCourses.count(courseNumber) == 0) {
      universityCourses[courseNumber] = new Course(courseNumber, courseTitle);
    }
  }

  return true;
}

// Read list of students for the current university
bool University::readStudentList(const string &filename) {
  string readLine;
  ifstream file;
  file.open(filename);
  // If file didn't get read/opened return false
  if (!file.is_open()) {
    return false;
  }
  // Read each line and create a student object for each one
  while (getline(file, readLine)) {
    int studentID = stoi(readLine.substr(0, 4));
    string studentName = readLine.substr(5, readLine.size());
    if (universityStudents.count(studentID) == 0) {
      universityStudents[studentID] = new Student(studentID, studentName);
    }
  }

  return true;
}

// Read enrollment info and add the student to the course and vice versa
bool University::readEnrollmentInfo(const string &filename) {
  string readLine;
  ifstream file;
  file.open(filename);
  // If file didn't get read/opened return false
  if (!file.is_open()) {
    return false;
  }
  while (getline(file, readLine)) {
    int studentID = stoi(readLine.substr(0, 4));
    string courseNumber = readLine.substr(5, readLine.size());
    if (universityStudents.count(studentID) != 0 &&
        universityCourses.count(courseNumber) != 0) {
      universityStudents.at(studentID)->addCourse(
          courseNumber, universityCourses.at(courseNumber));
      universityCourses.at(courseNumber)
          ->addStudent(studentID, universityStudents.at(studentID));
    }
  }

  return true;
}

// Drop student from given course, return true if successful
bool University::dropCourse(int studentID, const string &courseNumber) {
  // Check for valid student ID and course number
  if (universityStudents.count(studentID) == 0 ||
      universityCourses.count(courseNumber) == 0) {
    return false;
  }
  bool dropped = false;
  // Drop course if valid (both will either be true or false so the return check
  // can be assigned to either)
  universityStudents.at(studentID)->dropCourse(courseNumber);
  dropped = universityCourses.at(courseNumber)->removeStudent(studentID);

  return dropped;
}

// Add course if student and course are in the university and student isn't
// already enrolled
bool University::addCourse(int studentID, const string &courseNumber) {
  // Check for valid student ID and course number
  if (universityStudents.count(studentID) == 0 ||
      universityCourses.count(courseNumber) == 0) {
    return false;
  }
  bool added = false;
  // Add course if valid (both will either be true or false so the return check
  // can be assigned to either)
  universityStudents.at(studentID)->addCourse(
      courseNumber, universityCourses.at(courseNumber));
  added = universityCourses.at(courseNumber)
              ->addStudent(studentID, universityStudents.at(studentID));

  return added;
}

// Checks if student is in the course
bool University::isInCourse(int studentID, const string &courseNumber) const {
  return universityStudents.at(studentID)->isInCourse(courseNumber);
}

// The returned courses are separated by commas and sorted by course name
string University::getEnrolledCourses(int studentID) const {
  string enrolledCourses = "[";
  for (const auto &courseInfo :
       universityStudents.at(studentID)->enrolledCourses) {
    enrolledCourses.append(courseInfo.first + ", ");
  }
  // If the student is enrolled in courses, we have to remove the end comma and
  // the space
  if (enrolledCourses.size() > 1) {
    enrolledCourses = enrolledCourses.substr(0, enrolledCourses.size() - 1);
    enrolledCourses[enrolledCourses.size() - 1] = ']';
  } else {
    enrolledCourses.append("]");
  }

  return enrolledCourses;
}

// Get students in the class ordered by their last name
string University::getClassListByLastName(const string &courseNumber) const {
  return universityCourses.at(courseNumber)->getClassListByLastName();
}

// Get students in the class ordered by their student IDs
string University::getClassListByID(const string &courseNumber) const {
  return universityCourses.at(courseNumber)->getClassListByID();
}

// Get course title from course number
string University::getCourseTitle(const string &courseNumber) const {
  return universityCourses.at(courseNumber)->getCourseTitle();
}