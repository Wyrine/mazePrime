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
  //while the file is readable
  while(getline(input, curLine)){
    //if there is a space in the line that was just read
    if(spaceCheck(curLine)){
      //just read in dimensions of maze
      mazeRead(curLine, input);
    }
    //otherwise it's either a permutation or a prime problem
    else {
      //convert the number read into an int from a string
      int x = atoi(curLine.c_str());
      //loop through that many times
      for(int z = 1; z <= x; z++){
        curLine.clear();
        //read the line
        getline(input, curLine);
        //if it's a digit, call the prime class to find a solution
        if(isdigit(curLine[0])){
          Prime prime(stoi(curLine));
        }
        //otherwise it's a permutations
        else{
          cout << "The permutations of " << curLine << " are:\n";
          //this int i is used to print out the number of permutations there are
          int i = 1;
          //call the permutation method
          permuteString(curLine, 0, curLine.size()-1, i);
        }
      }
    curLine.clear();
    }
  }
  input.close();
}

//a void return function that takes a string argument, and 3 ints with one
//passed by reference.
void permuteString(string line, int i, int n, int &curSpot){
  //base case
  if (i == n){
     cout << "\t" << curSpot << ". " <<  line << endl;
     curSpot++;
  }
  //recursive case
  else
    for(int j = i; j<line.size(); j++){
      //calling the swap function
      swap(line[i], line[j]);
      //calling itself
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

//mazeRead takes in a string and a file reference
void mazeRead(string curLine, ifstream& input){
  //saving the locations of the start and the finish
  int startRow, startCol, endRow, endCol;
  //creating a maze vector
  vector<string> maze;
  //reading a line and calling tokenize
  getline(input, curLine);
  tokenize(startRow, startCol, (char*)curLine.c_str());
  getline(input, curLine);
  tokenize(endRow, endCol, (char*)curLine.c_str());
  //reading in the maze
  while(getline(input, curLine)){
    //pushing back the maze on the vector
    maze.push_back(curLine);
    //and printing the back
    cout << maze.back() << endl;
  }
  //calling the recursiveMaze function, if it returns true then the maze was solved
  if(recurseMaze(maze, startRow, startCol, endRow, endCol))
    cout << "\nMaze solved Successfully." << endl;
  else{//otherwise it was not solved
    cout << "\nThe maze has no solution." << endl;
  }
}

//recurseMaze is a boolean function that has a vector of strings as the maze and 4 ints
//two of which are the starting the location and two are the ending the location
bool recurseMaze(vector<string> maze, int curRow, int curCol, int finalRow, int finalCol){
  //print that the current location is starred
  CURRENT = '*';
  //print the maze
  printMaze(maze);
  //if we reached the finalRow and finalCol, the maze was solved
  if(curRow == finalRow && curCol == finalCol) return true;
  //if left is a possible move, go there
  if(LEFT == '.' || LEFT == ' ' || LEFT == '\t') {
    //if it returns false, that was a dead end and mark that path with an X
    if(recurseMaze(maze, curRow, curCol-1, finalRow, finalCol) == false)
      LEFT = 'x';
    //otherwise maze was solved
    else return true;
  }
  //if right is a possible move, go there
  if(RIGHT == '.' || RIGHT == ' ' || RIGHT == '\t') {
    //if it returns false, that was a dead end and mark that path with an X
    if(recurseMaze(maze, curRow, curCol+1, finalRow, finalCol) == false)
      RIGHT = 'x';
    //otherwise maze was solved
    else return true;
  }
  //if down was a possible move, go there
  if(DOWN == '.' || DOWN == ' ' || DOWN == '\t'){
    //if it returns false, that was a dead end and mark that path with an X
    if(recurseMaze(maze, curRow+1, curCol, finalRow, finalCol) == false)
      DOWN = 'x';
    //otherwise maze was solved
    else return true;
  }
  //if up was a possible move, go there
  if(UP == '.' || UP == ' ' || UP == '\t'){
    //if it returns false, that was a dead end and mark that path with an X
    if(recurseMaze(maze, curRow-1, curCol, finalRow, finalCol) == false)
      UP = 'x';
    //otherwise maze was solved
    else return true;
  }
  //no moves to make, return false
  return false;
}

//iterate through the vector and print the maze
void printMaze(vector<string> maze){
  cout << endl;
  for(vector<string>::iterator it = maze.begin(); it != maze.end(); it++){
    cout << *it << endl;
  }
}

//tokenizes each line and returns the integer version of that
void tokenize(int& row, int& col, char* line){
  row = atoi(strtok(line, " \n"));
  col = atoi(strtok(NULL, " \n"));
}
