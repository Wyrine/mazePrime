/*Driver program
  main.cpp
*/

//header files used for the program
#include "driver.h"

//the std namespace that will be used
using namespace std;

int main(){
  //opening the data file that will be used
  ifstream input("ola3data.txt");
  //greeting the user
  cout << "Welcome to the recursive solution's program.\n";
  //calling fileCheck to see if the input file opened correctly
  fileCheck(input);
  //calling readFile to read in data from the file into the appropriate storage
  readFile(input);
}
