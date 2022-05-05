#include <iostream>
#include <time.h>
#include <string>
#include "Avalon.h"
using namespace std;

const int badcount = 4; //contains the constant number of bad ministers.
const int round = 5; //the maximum round of the game.
const int GpSize[5] = {3, 4, 4, 5, 5}; //the restricted number of ministers in each round.

int main()
{
  cout<<"Welcome to Avalon. "<<endl;
  //assign random number to the bad ministers in the new game.
  int bad[badcount];
  assign(bad);
  
  cout<<"Loading successful. Game starts."<<endl;
  
  //create a dynamic array rresult for storing game status for each round. rresult:round result. 
  int *rresult = new int [round];
    //fill int 0 in the array to indicate the empty round. (record null status).
    fill_rrslt(rresult);
  
  //enter the rounds which is carried out by a for loop.
  for (int i = 0; i< round; i++)
  {
    //a variable storing the current group size of the round.
    int csize = GpSize[i];
    
    //output which round is on the current status.
    cout << "This is round " <<i+1<<"."<<endl;
    
    //print the ministers' figures.
    print_mstrs();
    
    cout << "Please select " <<csize<< " ministers to complete the task."<<endl;
    
    //a dynamic array storing the selected numbers for each round. Will be updated in every new round.
    int *currGroup = new int [csize]; 
      //read player's inputs and store them into the current group.
      select_group(currGroup, csize); 
    
    
    cout << "The ministers are on the mission..." << endl;
    
    //decide the round result.
    if (round_result(i, currGroup, bad))
    {
      rresult[i] = 2; //record the fail round as 2 in rresult[] to manage the game status.
      cout<< "Ouch! The task was sabotaged. " << round_result(i, currGroup, bad) << " of the ministers did the thing."<<endl;
      if (give_hints(i,rresult))
      {
        hints(bad);
      }
    }
    else if (round_result(i, currGroup, bad) == 0)
    {
      rresult[i] = 1; //record the pass round as 1 in rresult[] to manage the game status.
      cout<<"Yay! This task is successful. Everyone in the team is loyal to the Kindom :)"<<endl;   
    }
    
    //release the memory of player's selected numbers after each round.
    delete [] currGroup; 
    
    //decide whether to continue the rounds.
    if (!game_continue(rresult))
      break;

  }
 
  //out of the loop for rounds. Game ended. Output the final results.
  cout<<"Counting final results..."<<endl;
  if (final_result(rresult))
  {
    cout<<"You win! XD"<<endl;
  }
  else if (!final_result(rresult))
  {
    cout<<"Sorry, you lost :("<<endl;
  }
  
  //output the identities of the bad ministers.
  print_bad(bad);
  
  //release the memory of rresult (for recording the game status).
  delete [] rresult;
  

  return 0;
}
