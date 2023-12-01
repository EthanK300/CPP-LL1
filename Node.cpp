#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(Student* studentIN){
  student = studentIN;
  head = NULL;
}

Node::~Node(){
  delete student;
}

void Node::setHead(Node* &node){
  head = node;
}

Node* Node::getHead(){
  return head;
}

Student* Node::getStudent(){
  return student;
}

void Node::nullifyHead(){
  head = NULL;
}
