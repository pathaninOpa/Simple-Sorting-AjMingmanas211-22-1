#include <iostream>
using namespace std;
#include "sorting.h"

int main(int argc,char ** argv) {
  int *a,i;
  int n = 6;
  int a1[] = {1, 2, 3, 4 , 5, 6};
  int a2[] = {5, 2, 8, 1, 9, 3};
  int a3[] = {9, 8, 7, 6, 5, 4};
  
  compare(a1,n);
  compare(a2,n);
  compare(a3,n);
  
}

