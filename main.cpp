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
  int bad[badcount];
  assign(bad);
  cout<<"Loading successful. Game starts."<<endl;
  int *rresult = new int [round];//a dynamic array for storing game status for each round 
  fill_rrslt(rresult);
  for (int i = 0; i< round; i++)
  {
    int csize = GpSize[i];//variable storing the current group size of the round.
    cout << "This is round " <<i+1<<"."<<endl;
    print_mstrs();
    cout << "Please select " <<csize<< " ministers to complete the task."<<endl;
    int *currGroup = new int [csize]; //a dynamic array storing the selected numbers for each round. Will be updated in every new round.
    select_group(currGroup, csize); //read player's inputs and store them into the current group.
    cout << "The ministers are on the mission..." << endl;
    if (round_result(n, currGroup, bad))
    {
      rresult[i] = 2; //record the fail round as 2 in rresult[] to manage the game status.
      cout<< "Ouch! The task was sabotaged. " << round_result(n, currGroup, bad) << " of the ministers did the thing."<<endl;
      if (give_hints(i,rresult))
      {
        hints(bad);
      }
      }
    }
    else if (round_result(n, currGroup, bad) == 0)
    {
      rresult[i] = 1; //record the pass round as 1 in rresult[] to manage the game status.
      cout<<"Yay! This task is successful. Everyone in the team is loyal to the Kindom :)"<<endl;
      
    }
    delete [] currGroup; //release the memory of player's selected numbers after each round.
    if (!game_continue(rresult))
      break;

  }
 
  cout<<"Counting final results..."<<endl;
  if (final_result(rresult))
  {
    cout<<"You win! XD"<<endl;
  }
  else if (!final_result(rresult))
  {
    cout<<"Sorry, you lost :("<<endl;
  }
  
  print_bad(bad);
  
  delete [] rresult;
  

  return 0;
}
