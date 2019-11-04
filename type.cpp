#include<iostream>
using namespace std;
int main(){
  int *a;
  a= new int[5];
  int i=0;
  while (i<5)
  {
    /* code */
    cin>>*(a+i);
    i++;
  }

 
  for ( int j = 0; j < i; j++)
  {
    /* code */
    cout<<*(a+j);
  }
  delete []a;
  
  
}
