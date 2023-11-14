#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
  void setHead(Node* node);
  void setTail(Node* node);
protected:
  Student* student;
  Node* head;
  Node* tail;
}

#endif
