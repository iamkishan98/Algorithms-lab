#include<iostream>
void calc(int [],int);
using namespace std;
int main(){
    int arr[]={2,3,4,36};
    int n= sizeof(arr)/sizeof(arr[0]);
    calc(arr,n);
    return 0;
}
void calc(int a[],int n){
    int i,j;
    int sum=0;
    int count;
    for(i=0;i<32;i++){
        count =0;
        for(j=0;j<n;j++){
            if(a[j]& (1<<i)){
                count ++;
            }
        }
        sum +=count*(n-count)*2;
    }
    cout<<sum;

}