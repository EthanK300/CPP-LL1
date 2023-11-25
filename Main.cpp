#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

void ADDNODE(Node* &head);
void DELETENODE(Node* &head);
void GETSTUDENTINFO(Node* &head);

/*
Author Ethan K, list linked by nodes pointing to each other, sorted by student id..... why am i here
 */

int main(){
  bool active = true;
  char terminal[80];
  Node* head = NULL;
  cout << "List of commands: ADDNODE, GETSTUDENTINFO, DELETENODE, QUIT" << endl;
  while(active){
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //assume good input
    Node* currentNode = head;
    if(!strcmp(terminal, "ADDNODE")){
      ADDNODE(head);
    }else if(!strcmp(terminal, "GETSTUDENTINFO")){
      GETSTUDENTINFO(head);
    }else if(!strcmp(terminal, "DELETENODE")){
      DELETENODE(head);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

void ADDNODE(Node* &headNode){
  Student* student = new Student();
  Node* node = new Node(student);
  if(headNode == NULL){
    headNode = node;
    return;
  }else{
    Node* currentHead = headNode;
    Node* beforeHead = NULL;
    while(currentHead->getStudent()->getStudentID() < node->getStudent()->getStudentID()){
      beforeHead = currentHead;
      currentHead = currentHead->getHead();
    }
    beforeHead->setHead(node);
    node->setHead(currentHead);
    return;
  }
}

void DELETENODE(Node* &headNode){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  Node* currentNode = headNode;
  while(parseable){
    cout << "Enter student ID: " << endl;
    cin.clear();
    cin >> terminal;
    ID = atoi(terminal);
  }
  if(currentNode == NULL){
    cout << "Nothing to search for! there are no nodes!" << endl;
    return;
  }
  while(currentNode->getStudent()->getStudentID() != ID){
    currentNode = currentNode->getHead();
  }
  while((!strcmp(terminal, "y")) || (!strcmp(terminal, "n")) || (!strcmp(terminal, "QUIT"))){
    cin.get();
    cout << "Delete the student? y/n" << endl;
    cin.clear();
    cin >> terminal;
    if(!strcmp(terminal, "y")){
      //delete the student(?) or the node(?)


      
    }else if(!strcmp(terminal, "n")){
      cout << "Deleted nothing." << endl;
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted." << endl;
      exit(0);
    }else{
      cout << "Bad input." << endl;
    }
  }
  return;
}

void GETSTUDENTINFO(Node* &headNode){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  Node* currentNode = headNode;
  while(parseable){
    cout << "Enter student ID: " << endl;
    cin.clear();
    cin >> terminal;
    ID = atoi(terminal);
  }
  if(currentNode == NULL){
    cout << "Nothing to search for! there are no nodes!" << endl;
  }
  while(currentNode != NULL){
    if(currentNode->getStudent()->getStudentID() == ID){
      currentNode->getStudent()->printInfo();
    }else{
      currentNode = currentNode->getHead();
    }
  }
  return;
}
