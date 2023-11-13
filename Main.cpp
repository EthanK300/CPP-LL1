#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

void ADDNODE();
void DELETENODE();
void GETSTUDENTINFO();

int main(){
  bool active = true;
  char terminal[80];
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
    if(!strcmp(terminal, "ADDNODE")){
      
    }else if(!strcmp(terminal, "GETSTUDENTINFO")){
      
    }else if(!strcmp(terminal, "DELETENODE")){
      
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}
