#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void findminmax(int *arr,int low,int high, int &min ,int &max){
  
     if (low == high)            
    {
        if (max < arr[low])  
            max = arr[low];

        if (min > arr[high])   
            min = arr[high];

        return;
    }
         if (high - low == 1)            
    {
        if (arr[low] < arr[high])   
        {
            if (min > arr[low])     
                min = arr[low];

            if (max < arr[high])    
                max = arr[high];
        }
        else
        {
            if (min > arr[high])    
                min = arr[high];

            if (max < arr[low])
                max = arr[low];
        }
        return;
    }
    
        int mid = low +(high-low)/2;
        
        findminmax(arr,low,mid,min,max);
        findminmax(arr,mid+1,high,min,max);
    
       
    
}
int main(){
    int arr[]={4,2,10,67,98,69,56};
    int n = sizeof(arr)/sizeof(arr[0]);
     int max = INT_MIN, min = INT_MAX;
    findminmax(arr,0,n-1,min,max);

    cout<<min<<" "<<max;

}