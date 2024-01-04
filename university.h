#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <map>
#include <string>

using namespace std;

class University {
  friend class EnrollmentSystem;

public:
  // Constructor
  explicit University(string universityName);

  // Deconstructor (responsible for deleting all pointers)
  ~University();

  // Read the student list for current active university
  // return true if file successfully read
  bool readStudentList(const string &filename);

  // Read the course list for current active university
  // return true if file successfully read
  bool readCourseList(const string &filename);

  // Read the student enrollment information for current active university
  // return true if file successfully read
  bool readEnrollmentInfo(const string &filename);

  // For modularity, enrollment doesn't have direct access to student and
  // course, so university will call those functions

  // Accessors
  string getUniversityName() const;

  // Functions from student class
  //  Accessors
  int getStudentID() const;
  string getStudentName() const;

  // Drop student from given course, return true if successful
  bool dropCourse(int studentID, const string &courseNumber);

  // Add student to the given course, return true if successful
  bool addCourse(int studentID, const string &courseNumber);

  // Return true if student is in the given course
  bool isInCourse(int studentID, const string &courseNumber) const;

  // The returned courses are separated by commas and sorted by course name
  string getEnrolledCourses(int studentID) const;

  // Functions from course class
  //  Accessors
  int getCourseNumber() const;
  string getCourseTitle(const string &courseNumber) const;

  // Add student to course
  bool addStudent(int studentID, const string &courseNumber);

  // Remove student from course
  bool removeStudent(int studentID, const string &courseNumber);

  // Returns a string of the students in the class ordered by last name
  string getClassListByLastName(const string &courseNumber) const;

  // Returns a string of the students in the class ordered by their
  string getClassListByID(const string &courseNumber) const;

private:
  // Fields (Stores university name)
  string universityName;

  // Container of course pointers
  map<string, Course *> universityCourses;

  // Container of student pointers
  map<int, Student *> universityStudents;
};

#endif