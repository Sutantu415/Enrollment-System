#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Course;

class Student {
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Student &student);

public:
  // Constructor
  Student(int studentID, string studentName);

  // Accessors
  int getStudentID() const;
  string getStudentName() const;
  string getStudentFirstName() const;
  string getStudentLastName() const;

  // Drop student from given course, return true if successful
  bool dropCourse(const string &courseNumber);

  // Add student to the given course, return true if successful
  bool addCourse(const string &courseNumber, Course *course);

  // Return true if student is in the given course
  bool isInCourse(const string &courseNumber) const;

private:
  // Fields
  int studentID;
  string studentName;
  // Container of Course pointers student is currently enrolled in
  map<string, Course *> enrolledCourses;
};

#endif