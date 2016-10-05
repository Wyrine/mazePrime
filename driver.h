/*driver header file
  driver.h
*/

//the header file can only be defined once
#pragma once

//the header files used for the driver
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include "prime.h"

//defining the std namespace used
using namespace std;

const int MAX_LINE = 1000;

//function prototypes
void fileCheck(ifstream& input);
void readFile(ifstream& input);
bool spaceCheck(string line);
void swapChar(char &a, char &b);
void permuteString(string line, int i, int n, int& curSpot);
void mazeRead(string curLine, ifstream& input);
void tokenize(int& row, int& col, char* line = NULL);
bool recurseMaze(vector<string> maze, int curRow, int curCol, int finalRow, int finalCol);
