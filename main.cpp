#include <iostream>
#include <time.h>
#include <string>
using namespace std;

assign(int arr[]);//assign numbers to bad, good, player
select()//as choose nuk the player nummbers (a parameter to determine how many)
round_result()//determine the e whether one round is success
game_continue()//determine whether to continue a game
final_result()//determinfinal result
  
int main(){
  cout<<"Welcome to Avalon!"<<endl;
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

