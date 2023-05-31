#define N 9
#include <iostream>
using namespace std;
#include "sorting.h"

int main(int argc,char ** argv) {
  int *a,i;
  for(i=1;i<argc;i++)
    a[i-1]=atoi(argv[i]);


  display(a,N);
  bubbleSort(a,N); 
   //insertion(a,N);

  // selectionSort(a,N);
  // display(a,N);
}

// new number =2 
