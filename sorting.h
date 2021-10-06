#include <iomanip>

inline void display(int a[], int n){
  int i;
  for(i=0;i<n;i++){
    cout<<setw(5)<<a[i];
  }
  cout<<endl;

}

// selection sort function module in C 
void selectionSort(int data[], int length) 
{ 
	int i, j, m, mi; 
	for (i = 0; i < length - 1; i++) 
	{ 
	   /* find the minimum */ 
	   mi = i; 
	   for (j = i+1; j < length; j++) 
	   { 
	      if (data[j] < data[mi]) { mi = j; } 
	   } 

     if(i!=mi) swap(data[i],data[mi]);
     display(data,length);
     
	} 
} 



void insertion(int a[],int n){
 int i,j;
  int new_number= 2; //decendingly
  int temp;
  //    int a[N]={5,10,15};
 // your a is sorted

  for(j=n-1;j>=0;j--){
      if(new_number<a[j]){
          a[j+1]=a[j];  
          //5 10 15 15
          //5 10 10 15
          //5 5 10 15
         
      }
      else break;
    }
   a[j+1] =new_number;
   // 2 5


}

inline void swap(int &a,int &b){
 int temp;
  temp=a;
  a=b;
  b=temp;
  
}

void bubbleSort(int a[],int n){

int i,j;
int sorted;
// how may pair to compare?
for(j=1;j<=n-1;j++){
  sorted=0;
  for(i=0;i<n-(j);i++) // n-2
  if(a[i]<a[i+1]){   // a[4] <a[5]
      swap(a[i],a[i+1]);
      sorted=1;
  }
  if(sorted==0) break;
  display(a,n);
 }
  
}




