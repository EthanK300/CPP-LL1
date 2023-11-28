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
      if(beforeHead != NULL){
	beforeHead = currentHead;
      }
      currentHead = currentHead->getHead();
    }
    if(beforeHead != NULL){
      beforeHead->setHead(node);
    }
    node->setHead(currentHead);
    Node* currentHead2 = headNode;
    while(currentHead2 != NULL){
      currentHead2 = currentHead2->getHead();
    }
    cout << headNode->getHead()->getStudent()->getStudentID() << endl;
    return;
  }
}

void DELETENODE(Node* &headNode){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  Node* currentNode = headNode;
  Node* previousNode = NULL;
  cout << "Enter student ID: " << endl;
  cin.clear();
  cin >> terminal;
  ID = atoi(terminal);
  if(currentNode == NULL){
    cout << "Nothing to search for! there are no nodes!" << endl;
    return;
  }
  while(currentNode->getStudent()->getStudentID() != ID){
    previousNode = currentNode;
    currentNode = currentNode->getHead();
  }
  while(true){
    cin.get();
    cout << "Delete the student? y/n" << endl;
    cin.clear();
    cin >> terminal;
    if(!strcmp(terminal, "y")){
      //delete the student(?) or the node(?)
      Node* newHead = currentNode->getHead();
      if(previousNode != NULL){
	previousNode->setHead(newHead);
      }
      delete currentNode;
      headNode = NULL;
      cout << "Deleted student" << endl;
      return;
    }else if(!strcmp(terminal, "n")){
      cout << "Deleted nothing." << endl;
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted." << endl;
      exit(0);
    }else{
      cout << "Bad input." << endl;
    }
  }
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
  
    if(currentNode == NULL){
      cout << "Nothing to search for! there are no nodes!" << endl;
      return;
    }
    while(currentNode != NULL){
      cout << currentNode->getStudent()->getStudentID() << endl;
      if(currentNode->getStudent()->getStudentID() == ID){
	currentNode->getStudent()->printInfo();
	return;
      }else{
	currentNode = currentNode->getHead();
	if(currentNode == NULL){
	  cout << "No student with that ID!" << endl;
	  return;
	}
      }
    }
  }
  return;
}
