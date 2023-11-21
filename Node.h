#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{
public:
  Node();
  void setHead(Node* node);
  void setTail(Node* node);
protected:
  Student* student;
  Node* head;
  Node* tail;
};

#endif
