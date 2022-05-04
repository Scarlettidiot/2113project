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

int main(){
  cout<<"Welcome to Avalon!"<<endl;
  int arr[4];
  assign(arr[4]);
  cout<<"Loading successful. Game starts."<<endl;
  cout<<"ROUND I"<<endl;
  cout<<"please select 3 minisers to join the task"<<endl;
  int *a=new int[3];
  for (int i=0;i<3;i++){
    cin>>a[i];
  }
  if (round_result(a)==0){
    cout<<"FAIL"<<endl;
  }
  else if (round_result(a)==1){
    cout<<"SUCCESS!"<<endl;
  }
  delete [] a;
  cout<<"ROUND II"<<endl;
  cout<<"please select 4 minisers to join the task"<<endl;
  int *a=new int[4];
  for (int i=0;i<4;i++){
    cin>>a[i];
  }
  if (round_result(a)==0){
    cout<<"FAIL"<<endl;
  }
  else if (round_result(a)==1){
    cout<<"SUCCESS!"<<endl;
  }
  delete [] a;
  if (consecutive()=1){//means that two consecutive round occurs;
    hints();
  }
  cout<<"ROUND III"<<endl;
  cout<<"please select 4 minisers to join the task"<<endl;
  int *a=new int[4];
  for (int i=0;i<4;i++){
    cin>>a[i];
  }
  if (round_result(a)==0){
    cout<<"FAIL"<<endl;
  }
  else if (round_result(a)==1){
    cout<<"SUCCESS!"<<endl;
  }
  delete [] a;
  if (consecutive()=1){//means that two consecutive round occurs;
    hints();
  }
  game_continue();
  cout<<"ROUND IV"<<endl;
  cout<<"please select 5 minisers to join the task"<<endl;
  int *a=new int[5];
  for (int i=0;i<5;i++){
    cin>>a[i];
  }
  if (round_result(a)==0){
    cout<<"FAIL"<<endl;
  }
  else if (round_result(a)==1){
    cout<<"SUCCESS!"<<endl;
  }
  delete [] a;
  if (consecutive()=1){//means that two consecutive round occurs;
    hints();
  }
  game_continue();
  cout<<"ROUND V"<<endl;
  cout<<"please select 5 minisers to join the task"<<endl;
  int *a=new int[5];
  for (int i=0;i<5;i++){
    cin>>a[i];
  }
  if (round_result(a)==0){
    cout<<"FAIL"<<endl;
  }
  else if (round_result(a)==1){
    cout<<"SUCCESS!"<<endl;
  }
  delete [] a;
  final_result();
  return 0;
}



assign(int arr[]){
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

