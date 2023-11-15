#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(){
  student = new Student();
}

void Node::setHead(Node* &node){
  head = node;
}

void Node::setTail(Node* &node){
  tail = node;
}
