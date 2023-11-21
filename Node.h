#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{
public:
  Node(Student* &studentIN);
  void setHead(Node* &node);
  void setTail(Node* &node);
  Node* getHead();
  Student* getStudent();
protected:
  Student* student;
  Node* head;
>>>>>>> cf863f6ac43e8c633e7e27afadc863d6f961e67d
};

#endif
