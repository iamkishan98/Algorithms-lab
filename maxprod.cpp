#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    
    register int i;
    int c,j,k,l;
    int pos_max1=0,pos_max2=0,neg_max1=0,neg_max2=0;
    long int prod1=0,prod2=0;
    register int count1=0,count2=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
       if(arr[i]>0){ 
           
         
            if(arr[i]>pos_max1){
                pos_max2 =pos_max1;
                pos_max1=arr[i];

                j=c;
                c=i;
            }
            else if(arr[i]>pos_max2){
                pos_max2 =arr[i];
                j=i;
            }
            else{
                continue;
            }
           
         
       }
       else{
          
               /* code */
           
           
           if(arr[i]<neg_max1){
               neg_max2=neg_max1;
               neg_max1=arr[i];
                l=k;
               k=i;
           }
           else if (arr[i]<neg_max2){
               neg_max2 =arr[i];
               l =i;
           }
           
               /* code */
           else{
               continue;
           }
          
           
       }
  
    }
       prod1= pos_max1 *pos_max2;
       prod2 =neg_max1 * neg_max2;
       if(prod1 >prod2){
           cout<<"{"<<pos_max1<<","<<pos_max2<<"}";
       }
       else{
           cout<<"{"<<neg_max1<<","<<neg_max2<<"}";
       }
    return 0;
}