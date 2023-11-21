#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(){
  cout << "Input first name: " << endl;
  cin.clear();
  cin >> firstName;
  cout << "Input last name: " << endl;
  cin.clear();
  cin >> lastName;
  cout << "Input student ID: " << endl;
  cin.clear();
  cin >> studentID;
  cout << "Input student's GPA: " << endl;
  cin.clear();
  cin >> GPA;
  cout << "Added student" << endl;
  cin.clear();
}
