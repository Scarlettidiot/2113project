#include <iostream>
#include <time.h>
using namespace std;

void select(int &arr[]){
  int m=0,arr[4];
  srand((unsigned)time(NULL));
  for (int i=0;i<4;i++){
    arr[i]=rand()%10;//randomly select one number
    for (int k=0;k<i;k++){
      if (arr[k]==arr[i]){
        i--;
      }
    }
  }
  
