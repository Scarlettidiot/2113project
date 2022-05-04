#include <iostream>
#include <time.h>
#include <string>
using namespace std;

const int badcount = 4; //contains the constant number of bad ministers.
const int round = 5; //the maximum round of the game.
const int rcarsize[5] = {3, 4, 4, 5, 5}; //the restricted number of ministers in each round.

void assign(int arr[]){
  srand((unsigned)time(NULL));
  for (int i=0;i<4;i++){
    arr[i]=rand()%10;//randomly select one number
    for (int k=0;k<i;k++){
      if (arr[k]==arr[i]){
        i--;
      }
    }
  }
}//arr[4]contains 4 integer from 0 to 9 represents for bad ministers.

//round_result() decide whether the task is successful (whether player's selection contains number in arr[4].
  //inputs:
    //csize: the size of car that carries the ministers in the current round. 
    //car: the group of ministers that the player selected to complete the task.
    //bad: the arrays containing bad ministers' indexes.
  //output:
    //true if there is no bad miniter in the group. 
    //false if there is at least one minister in the group.
bool round_result(int csize, int car[], int bad[])
{
  for (int i = 0; i < csize; i++)
  {
    for (int j = 0; j < badcount; j++)
    {
      if (car[i] == car[j])
      {
        return false;
      }
    }
  }
  return true;
}

//track_pf() track the pass and fail in each round. Used in game_continue() and final_result().
  //inputs:
    //rresult[]: the array that records all past round's pass or fail results.
    //pass: interger record times of pass results.
    //fail: interger record times of fail results.
  //no output but make change of the pass and fail variables.
void track_pf(int rresult[], int &pass, int &fail)
{
  for (int i = 0; i < round; i++)
  {
    if (rresult[i] == 1)
      pass++;
    else if (rresult[i] == 2)
      fail++;
  }
}

//game_continue() determines whether the win and lose has been a certainty.
  //inputs:
    //rresult[]: the array that records all past round's pass or fail results.
  //outputs:
    //true if there is already 3 pass or 3 fail results. (three out of five rounds successed then the player can win the game)
    //false if the win or lose has not been a certainty.
bool game_continue(int rresult[])
{
  int pass = 0, fail = 0;
  track_pf(rresult, pass, fail);
  if (pass == 3 || fail == 3)
    return false;
  else
    return true;
}

//final_result calculate the pass and fail of each round to determine the win/lose.
  //inputs:
    //rresult[]: the array that records all past round's pass or fail results.
  //outputs:
    //true if win (>=3 passes), false if lose. 
bool final_result(int rresult[])
{
  int pass = 0, fail = 0;
  track_pf(rresult, pass, fail);
  if (pass >= 3)
    return true;
  else
    return false;
}

void hints(int arr[]){
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
      //
      if (i>=1 && rresult[i-1]==2){
        cout<<"After two successful sabotage, one of the bad ministers reveal flaws."<<endl;
        cout<<"You have a chance to trace down, please select （Yes or No）"<<endl;
        string ans;
        cin>>ans;
        if (ans=="Yes")
          hints(arr);
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
