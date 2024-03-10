/**
 * Author: Nadine Uwajeneza
 * Date: 09/02/2024

 * Simply, this program is going to read the fixation points from and input file, and checks the duplicate cooardinates, if is there, its not displayed in the output file, in each scanpath must have the 1000 coardinates, and at the end of each set have -1 as x and -1 as y coardinate, and must not be displayed in the output file.
 * this program has the firt line input number which range between 1 and 10 integer, it is not supposed to go beyond, that nummber indicates the of test case, on the remaining line there is a fixation point number followed by the x and y coardinate. those coardinate range between 0 and 2000.
 
 *  And this code has been tested in the input file, with the different test cases
 
 *  Functionality
 * This program Reads input from file with a fixation points with various test cases
 * Then start with checking the duplicates in each test cases if is there it is not displayed on output file, and at the end of each test case it has a star(*************************)
 
 * Format of input and output file
 * 
 * Input file is named "input.txt" located in my data folder, it has the first line as the number of test cases, followed 3 points of fixation number, x-coardinate and y-coardinate. at the end of each test case has the x and y as negative one 
 * output file is named "output.txt" located also in my data folder, in this file contains the uniqueness no duplicate included in he test case and at the end of each test case has the star
 * 
 * Solution strategy
 * 1. Read the number of test case
 * 2. Iterate through each test case
 * 3. Read fixation points until termination point(-1, -1) is encountered 
 * 4. Check for valid fixation points the coardinates within a range and no duplicate
 * 5. write valid fixation ponts to the output file
 * 6. Reap steps 3-5 for each test case
 * 
 * Test strategy
 * First test with input containing duplicate fixation point.
 * second test with input containing the coardinates within out of range means x and y coardinate is not between 0 and 2000.
 * Third test with the input same as the other input. 
 * Fourth test with a noramal case with a coardinate within a range x and y coardinate variate between 0 and 2000.
 * Firth test with single fixation point within a range
 * sixth test case with the coardinate of more than 1000 pooints, in the output file there should be only 1000.
 * 
 *Complexity analysis 
 * 1. Time Complexity
 * Reading input File O(n)
 * Storage Location Function O(m) where m in number of fixation point stored(which is maximum)
 * Main Loop: (outer Loop: O(t), t is the test case. and Inner Loop: O(f), this reas the number of fixations pont until termination, f is numbrt of fixation pointd in that fixation point)
 * overall Time Complexity expressed as O(n + tf + tm)
 * 
 * 2. Space complexity
 * Array which stores Fixation points has O(1), my array has the sixe of 1000 rows and columns 3
 * Other variables O(1), like the entry point other words test case number, tempory variable for reading coordinates 
 * Overall space complexity expressed as O(1)
*/

#include <iostream>
#include <fstream>
#include "assignment.h"
using namespace std;


//The two dimensional array 1000 number of rows for each test case and 3 for the number of column, fixation point number, x coardinate and y-cooardinate
int myArry[1000][3];
int entry = 0; //current fixation point stored


//Function to store a fixation point andncheck for duplicate 
int storage_location(int testcase, int x, int y){
 for(int i = 0; i < entry ; i++){

   //check the matching fixation point
    if(myArry[i][2] != 0 && myArry[i][0]== x && myArry[i][1] == y){
        //duplicate found, reomove it
        return-1;

    }   
 }

//add the fixation point to the array
 myArry[entry][0] = x ;
 myArry[entry][1] = y ;
 myArry[entry][2] = 1 ;

 //increment the entry count
 return entry++;
   
}

int main(){

//This is line for opening a file
ifstream myInfile("../data/input.txt");

//open the output file for test case
ofstream myOutfile("../data/output.txt");

int number_of_test_cases;
float t, x, y;

//rear the number of test case and write my andrew Id in thr output file
myInfile >> number_of_test_cases;
myOutfile <<"nuwajene"<< endl;

//check the number of test case 
if(number_of_test_cases < 1 || number_of_test_cases > 10){
   myOutfile<<"Test cases must validate in range of 1 and 10" <<endl;
   }
else{

//for Loop through the test
for(int testcase = 1; testcase <= number_of_test_cases; ++testcase){
   entry = 0; //reset entry count for test case
   int fixation_counter = 0; //counter of fixation point in the current test case
   //Read fixation points until termination point encountered
   while(fixation_counter < 1000){
      myInfile >> t >> x >> y;

    //check end case
      if (x == -1 && y == -1){
         break;
      }

      //validate the fixation point
      if(x < 0 || x > 2000 || y < 0 || y > 2000){
         // cout<<"Invalid fixation point coordinates" <<endl;
         continue;
      }else{

      //call the storage
      int result = storage_location(testcase, x, y);
       if(result != -1){
         if(fixation_counter < 1000){
         //output the location data 
          myOutfile <<result+1 << " " << " " << x << " " << y <<endl;

         }
         fixation_counter ++; //increment fixation counter 
         
       
       }

   }
   }
  myOutfile << "**********"<<endl;
}
}
myInfile.close();
myOutfile.close();
return 0;
}


