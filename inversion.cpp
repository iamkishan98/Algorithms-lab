#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int _mergesort(int arr[],int temp[],int l,int h);
int mergesort(int arr[],int n){
    int temp[n];
    return _mergesort(arr,temp,0,n-1);

}
int merge(int arr[],int temp[],int l,int mid,int h){
    int inv=0;
    int i,j,k;
    i =l;
    j=mid;
    k=l;

    while(i<=mid-1 && j<=h){
        if(arr[i]<=arr[j]){
            temp[k++]= arr[i];
            i++;
        }
        else{
            inv = inv +(mid-i);
            temp[k++] =arr[j++];
        }
    }

    while(i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=h){
        temp[k++] = arr[j++];

    }

    for(i=l;i<=h;i++){
        arr[i] = temp[i];
    }
    return inv;


}
int _mergesort(int arr[],int temp[],int l,int h){
    int mid,inv=0;
    if(l<h){
        mid = (l+h)/2;
        inv  = _mergesort(arr,temp,l,mid);
        inv+=_mergesort(arr,temp,mid+1,h);

        inv += merge(arr,temp,l,mid+1,h);
    }
    return inv;
}
int main(){
 int arr[]={2,4,1,3,5};
 int n = sizeof(arr)/sizeof(arr[0]);
 int temp = mergesort(arr,n);
 cout<<temp;

return 0;
}