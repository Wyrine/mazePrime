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

void readFile(ifstream& input){
  string curLine;
  while(getline(input, curLine)){
    if(spaceCheck(curLine)){
      //just read in dimensions of maze
      mazeRead(curLine, input);
      break;
    }
    else {
      int x = atoi(curLine.c_str());
      for(int z = 1; z <= x; z++){
        curLine.clear();
        getline(input, curLine);
        if(isdigit(curLine[0])){
          Prime prime(stoi(curLine));
        }
        else{
          cout << "The permutations of " << curLine << " are:\n";
          //call permutation function
          int i = 1;
          permuteString(curLine, 0, curLine.size()-1, i);
        }
      }
    curLine.clear();
    }
  }
}

//readFile is a function that has a void return
//and an ifstream input file that is passed by reference as it's parameter
//that reads the file per line and figures out which function to call
/*void readFile(ifstream& input){
  string curLine;
  while(getline(input, curLine)){
    //if the first character read in is a digit
    if(isdigit(curLine[0])){
      //check to see if there's a space in the string
      if(spaceCheck(curLine)){
        //just read in the dimensions of the maze
      } else{//prime number check, create Prime class instance
          Prime prime(stoi(curLine));
      }
    }
    //if the first character read in is a letter in the alphabet
    else if(isalpha(curLine[0])){
      cout << "The permutations of " << curLine << " are:\n";
      //call permutation function
    }
    curLine.clear();
  }
}
*/

//
void permuteString(string line, int i, int n, int &curSpot){
  if (i == n){
     cout << "\t" << curSpot << ". " <<  line << endl;
     curSpot++;
  }
  else
    for(int j = i; j<line.size(); j++){
      swap(line[i], line[j]);
      permuteString(line, i+1, n, curSpot);
      swap(line[i], line[j]);
    }
}

//swapChar takes in two characters and swaps them,
//it has a void return type but it has two
//characters passed by reference as the argument
void swapChar(char &a, char &b){
  char temp;
  temp = a;
  a = b;
  b = temp;
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

void mazeRead(string curLine, ifstream& input){
  int rows, cols, startRow, startCol, endRow, endCol;
  tokenize(rows, cols, (char*)curLine.c_str());
  vector<string> maze;
  getline(input, curLine);
  tokenize(startRow, startCol, (char*)curLine.c_str());
  getline(input, curLine);
  tokenize(endRow, endCol, (char*)curLine.c_str());
  for (int i = 0; i < rows; i++){
    if(!getline(input, curLine)) break;
    maze.push_back(curLine);
    cout << maze[i] << endl;
  }
  if(recurseMaze(maze, startRow, startCol, endRow, endCol))
    cout << "\nMaze solved Successfully." << endl;
  else{
    cout << "\nThe maze has no solution." << endl;
  }
}

bool recurseMaze(vector<string> maze, int curRow, int curCol, int finalRow, int finalCol){
  CURRENT = '*';
  printMaze(maze);
  if(curRow == finalRow && curCol == finalCol) return true;
  if(LEFT == '.') {
    if(recurseMaze(maze, curRow, curCol-1, finalRow, finalCol) == false)
      LEFT = 'x';
    else return true;
  }
  if(RIGHT == '.') {
    if(recurseMaze(maze, curRow, curCol+1, finalRow, finalCol) == false)
      RIGHT = 'x';
    else return true;
  }
  if(DOWN == '.'){
    if(recurseMaze(maze, curRow+1, curCol, finalRow, finalCol) == false)
      DOWN = 'x';
    else return true;
  }
  if(UP == '.'){
    if(recurseMaze(maze, curRow-1, curCol, finalRow, finalCol) == false)
      DOWN = 'x';
    else return true;
  }
  return false;
}

void printMaze(vector<string> maze){
  cout << endl;
  for(vector<string>::iterator it = maze.begin(); it != maze.end(); it++){
    cout << *it << endl;
  }
}

void tokenize(int& row, int& col, char* line){
  row = atoi(strtok(line, " \n"));
  col = atoi(strtok(NULL, " \n"));
}
