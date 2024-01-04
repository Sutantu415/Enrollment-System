#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Student;

class Course {
  friend class Student;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Course &course);

public:
  // Constructor
  Course(string courseNumber, string courseTitle);

  // Accessors
  string getCourseNumber() const;
  string getCourseTitle() const;

  // Add student to course
  bool addStudent(int studentID, Student *student);

  // Remove student from course
  bool removeStudent(int studentID);

  // Returns a string of the students in the class ordered by last name
  string getClassListByLastName() const;

  // Returns a string of the students in the class ordered by their
  string getClassListByID() const;

private:
  // Fields (Course information)
  string courseNum;
  string courseTitle;

  // Containers for student access
  map<int, Student *> studentListWithID;

  // Compare methods for sorting
  static bool cmpLastName(const Student *one, const Student *two);
  static bool cmpID(Student *one, Student *two);
};

#endif