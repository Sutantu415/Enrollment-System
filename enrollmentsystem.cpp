#include "enrollmentsystem.h"
#include "university.h"

#include <cassert>
#include <map>
#include <vector>

using namespace std;

bool EnrollmentSystem::addUniversity(const string &name) {
  // Checks if the university already exists
  if (universities.count(name) > 0) {
    return false;
  }
  // Creating a new object (University) and inserting into map
  universities[name] = new University(name);
  return true;
}

EnrollmentSystem::~EnrollmentSystem() {
  // Delete all the university pointers
  for (auto &university : universities) {
    delete university.second;
  }
  universities.clear();
}

bool EnrollmentSystem::setCurrentUniversity(const string &name) {

  // Checking if the unviersity with the name that was given exists
  if (universities.count(name) == 0) {
    return false; // returns false if it does not exist in the list
  }
  currentUniversity = universities[name];
  return true;
}

// Returns name of currentUniversity
string EnrollmentSystem::getUniversityName() const {
  return this->currentUniversity->getUniversityName();
}

// Reads the course list of the currentUnviersity
bool EnrollmentSystem::readCourseList(const string &filename) {
  return currentUniversity->readCourseList(filename);
}

// Reads the list of students for the currentUniveristy
bool EnrollmentSystem::readStudentList(const string &filename) {
  return currentUniversity->readStudentList(filename);
}

// Reads the enrollmentInfo from the student in the currenUniversity
bool EnrollmentSystem::readEnrollmentInfo(const string &filename) {
  return currentUniversity->readEnrollmentInfo(filename);
}

// Dropping the student with their ID and from the course (CourseNum) in the
// specificed currentUniversity
bool EnrollmentSystem::dropCourse(int studentID, const string &courseNumber) {
  return currentUniversity->dropCourse(studentID, courseNumber);
}

// Adds the student with their ID and from the course (coureNumber) in the
// specified currentUniversity
bool EnrollmentSystem::addCourse(int studentID, const string &courseNumber) {
  return currentUniversity->addCourse(studentID, courseNumber);
}

// Sees if the student is in the course by checking StudentID and the specifc
// courseNumber in the currentUniversity
bool EnrollmentSystem::isInCourse(int studentID,
                                  const string &courseNumber) const {
  return currentUniversity->isInCourse(studentID, courseNumber);
}

// All the enrolledcourses from the specific student (StudentID) in the
// currentUniversity
string EnrollmentSystem::getEnrolledCourses(int studentID) const {
  return currentUniversity->getEnrolledCourses(studentID);
}

// Seeing the title of the specific course (CourseNumber) in the current
// University
string EnrollmentSystem::getCourseTitle(const string &courseNumber) const {
  return currentUniversity->getCourseTitle(courseNumber);
}

// Sorting class list by last name of students for currentUniversity
string
EnrollmentSystem::getClassListByLastName(const string &courseNumber) const {
  return currentUniversity->getClassListByLastName(courseNumber);
}

// Seeing class List sorted by ID of students in specific course for the
// currentUniversity
string EnrollmentSystem::getClassListByID(const string &courseNumber) const {
  return currentUniversity->getClassListByID(courseNumber);
}