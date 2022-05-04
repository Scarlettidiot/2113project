#include <iostream>
#include <time.h>
#include <string>
#include "Avalon.h"
using namespace std;

const int badcount = 4; //contains the constant number of bad ministers.
const int round = 5; //the maximum round of the game.
const int rcarsize[5] = {3, 4, 4, 5, 5}; //the restricted number of ministers in each round.


void hints(int arr[]) //to randomly provide one bad minister's number when the player encounters 2 consecutive fail.
{ 
  srand((unsigned)time(NULL));
  int hint=rand()%4;
  cout<<"One of the bad guy is:"<<arr[hint]<<endl;
}

int main()
{
  cout<<"Welcome to Avalon. "<<endl;
  int arr[badcount];
  assign(arr);
  cout<<"Loading successful. Game starts."<<endl;
  int *rresult = new int [round];
  for (int i = 0; i< round; i++)
  {
    int n = rcarsize[i];
    cout << "This is round " <<i+1<<"."<<endl;
    cout << "(!-!) (@-@) (#-#) ($-$) (^-^) (&-&) (*-*) (>-<) (Q-Q) (T-T)" <<endl;
    cout << "  0     1     2     3     4     5     6     7     8     9  " <<endl;
    cout << "Please select " <<n<< " ministers to complete the task."<<endl;
    int *currentcar = new int [n]; 
    for (int j = 0; j < n; j++)
    {
      cin >> currentcar[j];
    }
    if (round_result(n, currentcar, arr))
    {
      rresult[i] = 1;
      cout<<"Yay! This task is successful :)."<<endl;
    }
    else if (round_result(n, currentcar, arr) == 0)
    {
      rresult[i] = 2;
      cout<<"Ouch! There is at least one bad guy in the team. Task failed :(."<<endl;
      if (i>=1 && rresult[i-1]==2){
        cout<<"After two successful sabotage, one of the bad ministers reveal flaws."<<endl;
        cout<<"You have a chance to trace down, please select （Yes or No）"<<endl;
        string ans;
        cin>>ans;
        if (ans=="Yes"){
          hints(arr);
        }
      }
    }
    delete [] currentcar;
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
  
  delete [] rresult;
  

  return 0;
}
