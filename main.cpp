#include <iostream>
#include <time.h>
#include <string>
using namespace std;

void select_bad(int &arr[4]);//assign numbers to bad, good, player
int player_num(int &arr[4]);
select()//ask the player to choose numbers (a parameter to determine how many)
round_result()//determine whether one round is success
game_continue()//determine whether to continue a game
final_result()//determine the final result
  
int main(){
  cout<<"Welcome to Avalon!"<<endl;
}



void select_bad(int &arr[4]){
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

int player_num(int &arr[4]){
  srand((unsigned)time(NULL));
  bool flag=1;
  int playernum;
  while (flag){
    playernum=rand()%10;
    bool flag2=0;
    for (int i=0;i<4;i++){
      if (arr[i]==playernum){
        flag2=1;
      }
    }
    if (flag2=0){
      flag=0;
    }
  }
}
  
  
//arr[4]contains 4 integer from 0 to 9 represents for bad ministers.
