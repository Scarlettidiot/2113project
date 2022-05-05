#include <iostream>
#include <time.h>
#include <string>
#include "Avalon.h"
using namespace std;

const int badcount = 4; //contains the constant number of bad ministers.
const int round = 5; //the maximum round of the game.
const int GpSize[5] = {3, 4, 4, 5, 5}; //the restricted number of ministers in each round.

//print lines to separate screen output of each round.
void print_lines()
{
  cout << endl;
  cout << "------------------------------------------------------------------" << endl;
  cout << endl;
}

//print the simple portraits of the ministers.
void print_mstrs() 
{
  cout << endl;
  cout << "(!-!) (@-@) (#-#) ($-$) (^-^) (&-&) (*-*) (>-<) (Q-Q) (T-T)" <<endl;
  cout << "  0     1     2     3     4     5     6     7     8     9  " <<endl;
  cout << endl;
}

// to test if the input is valid.
// if the input in one round has repeaded numbers or contains other numbers out of range, return false.
//if the input is valid,return true.

bool test_value(int currGroup[],int csize){
  for(int i=0;i<csize;i++){
    if (currGroup[i]>=0&&currGroup[i]<=9)
    {
      for (int k=0;k<i;k++){
        if (currGroup[i]==currGroup[k]){
          return false;
        }
      }
    }
    else{
      return false;
    }
  }
  return true;
}

//select_group() store players' inputs into the array currGroup[].
  //inputs:
    //currGroup[]: the group of ministers that the player selected to complete the task.
    //csize: the size of car that carries the ministers in the current round.
void select_group(int currGroup[], int csize)
{
  for (int i = 0; i < csize; i++)
  {
    cin >> currGroup[i];
  }
  for (int i=0; i<csize;i++)
  {
    if (!test_value(currGroup,csize))
    {
      cout<<"Input error! Please input again!"<<endl;
      delete [] currGroup;
      int *currGroup = new int [csize];
      select_group(currGroup,csize);
    }
    else{
      return;
    }
  }
}


//fill_rrslt() fill default number 0 to the array rresult[] to set the starting values.
  //inputs:
    //rresult[]: the array that records all past round's pass or fail results.
void fill_rrslt(int rresult[])
{
  for (int i = 0; i < round; i++)
  {
    rresult[i] = 0;
  }
}

//round_result() counts the number of bad ministers in player's selection by comparing them to bad[].
  //inputs:
    //csize: the size of car that carries the ministers in the current round. 
    //car: the group of ministers that the player selected to complete the task.
    //bad: the arrays containing bad ministers' indexes.
  //output:
    //badNum: the number of bad ministers counted.
int round_result(int csize, int gp[], int bad[])
{
  int badNum = 0;
  for (int i = 0; i < csize; i++)
  {
    for (int j = 0; j < badcount; j++)
    {
      if (gp[i] == bad[j])
      {
        badNum++;
      }
    }
  }
  return badNum;
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

//final_result() calculate the pass and fail of each round to determine the win/lose.
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

//randomly select 4 numbers to be bad guy.
//input: the created array in main function
//turn this array to an array stores 4 number representing the bad ministers.
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
}

//to randomly provide one bad minister's number when the player encounters 2 consecutive fail.
//input: the array stores bad numbers.
//output: one bad minister's number.
void hints(int arr[]) 
{ 
  srand((unsigned)time(NULL));
  int hint=rand()%4;
  cout<<"One of the bad guy is:"<<arr[hint]<<endl;
}

//when game fails, print out all the bad ministers.
void print_bad(int arr[])
{
  cout<<"The bad ministers are: ";
  for (int i=0;i<4;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//to determine whether to give hints or not.
//if the player meet with two consecutive fail and choose to have hints, then it will return true.
bool give_hints(int i, int rresult[])
{
  if (i>=1 && rresult[i]==2 && rresult[i-1]==2)
  {
    cout<<"After two successful sabotage, one of the bad ministers reveal flaws."<<endl;
    cout<<"You have a chance to trace down, please select （Yes or No）"<<endl;
    string ans;
    cin>>ans;
    if (ans=="Yes")
    {
      return true;
    }
    else if (ans=="No")
    {
      return false;
    }
    else{
      cout<<"invalid input. Please input again.";
      give_hints(i,rresult);
    }
  }
}

