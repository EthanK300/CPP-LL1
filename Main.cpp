#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

void ADDNODE();
void DELETENODE();
void GETSTUDENTINFO();

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
      ADDNOD(head);
    }else if(!strcmp(terminal, "GETSTUDENTINFO")){
      GETSTUDENTINFO(head);
    }else if(!strcmp(terminal, "DELETENODE")){
      DELETENODE(heaD);
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
  }else{
    Node* currentHead = headNode;
    while(currentHead != NULL){
      if(headNode->getStudent()->getStudentID < node->getStudent()->getStudentID()){
	
      }else{
	node->setHead(headNode);
	headNode = node;
	return;
      }
    }
  }
}

void DELETENODE(Node* &headNode){

}

void GETSTUDENTINFO(Node* &headNode){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  while(parseable){
    cout << "Enter student ID: " << endl;
    cin.clear();
    cin >> terminal;
    ID = atoi(terminal);
  }
  if(headNode == NULL){
    cout << "Nothing to search for! there are no nodes!" << endl;
  }
  while(headNode != NULL){
    
  }
}
