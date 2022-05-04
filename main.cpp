#include <iostream>
#include <time.h>
#include <string>
using namespace std;

assign(int arr[]);//assign numbers to bad, good, player
select()//as choose nuk the player nummbers (a parameter to determine how many)
round_result()//determine the e whether one round is success
game_continue()//determine whether to continue a game
final_result()//determinfinal result
  
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

const int badcount = 4;
const int round = 5;
const int rcarsize[5] = {3, 4, 4, 5, 5}

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

bool round_result(int csize, int car[], int bad[])
{
  for (int i = 0; i < csize; i++)
  {
    for (int j = 0; j < badcount; j++)
    {
      if (car[i] == bad[j])
      {
        return false;
      }
    }
  }
  return true;
}

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
bool game_continue(int rresult[])
{
  int pass = 0, fail = 0;
  track_pf(rresult, pass, fail);
  if (pass == 3 || fail == 3)
    return false;
  else
    return true;
}

bool final_result(int rresult[])
{
  int pass = 0, fail = 0;
  track_pf(rresult, pass, fail);
  if (pass >= 3)
    return true;
  else
    return false;
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
