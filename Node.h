#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{
public:
  Node(Student* studentIN);
  void setHead(Node* &node);
  void setTail(Node* &node);
  Node* getHead();
  ~Node();
  Student* getStudent();
  void nullifyHead();
protected:
  Student* student;
  Node* head;
};

#endif
