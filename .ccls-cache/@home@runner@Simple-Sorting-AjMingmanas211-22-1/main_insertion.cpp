#include <iostream>
using namespace std;
#include "sorting.h"

int main(int argc,char ** argv) {
  int *a,i;
  int n = argc-1;
  a=new int[n];
  for(i=1;i<argc;i++)
    a[i-1]=atoi(argv[i]);
  
  insertionSort(a,n);
}