#include <iostream>
#include <time.h>
#include "assign.h"
using namespace std;

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
  
//arr[4]contains 4 integer from 0 to 9 represents for bad ministers.
