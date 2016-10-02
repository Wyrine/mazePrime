/*driver function file
  driver.cpp
*/

//the driver header file is included because it has all of the header files needed
#include "driver.h"

//defining the std namespace that is used
using namespace std;

//fileCheck is a function that has a void return
//and an ifstream input file that is passed by reference as it's parameter
//that checks to see if the input file was opened properly
//and if it has not it iterates and asks for a new file name
//until it opens properly
void fileCheck(ifstream& input){
  char fileName[50];
  while(input.fail()){
    cout << "Input file failed. Enter the name of the input file you'd like to open: \n";
    cin >> fileName;
    input.open(fileName);
  }
}

//readFile is a function that has a void return
//and an ifstream input file that is passed by reference as it's parameter
//that reads the file per line and figures out which function to call
void readFile(ifstream& input){
  string curLine;
  while(getline(input, curLine)){
    //if the first character read in is a digit
    if(isdigit(curLine[0])){
      //check to see if there's a space in the string
      if(spaceCheck(curLine)){
        //just read in the dimensions of the maze
      } else{//prime number, call function
          Prime prime(stoi(curLine));
      }
    }
    //if the first character read in is a letter in the alphabet
    else if(isalpha(curLine[0])){
      //call permutation function
    }
    curLine.clear();
  }
}

//spaceCheck is a function that returns a boolean
//and is passed a string. Returns true if there is a
//space in the string, otherwise false
bool spaceCheck(string line){
  int len = line.length();
  for(int i= 0; i < len; i++){
    if(line[i] == ' ') return true;
  }
  return false;
}
