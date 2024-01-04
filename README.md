Sutantu Balamurugan
Saurabh Vasdev


Clang Tidy Error Information:

The main.cpp Enrollment variable has been left alone because Professor Pisan created that one.

All altera-* warnings are ignorable according to the professor

Move is used in the constructors to fix clang-tidy errors

University and Enrollmentsystem class needs the destructor but doesn't need a copy constructor, move constructor or assignment of any of those so clang-tidy errors associated with it can't be fixed

For enrollmentsystem.h constructor doesn't initalize activeUniversity, it could be fixed by setting the active university to the first university added to the system but that isn't the purpose, the setActiveUniversity method is supposed to do that so that is left as is.

courseNumber and courseTitle being adjacent variable types is not fixable because that would require a change in the variable names and that would lessen variable clarity (this includes the two notes that are also listed)