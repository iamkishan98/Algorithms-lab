#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point {
  int x;
  int y;

};
void merge(Point arr[],int l,int mid,int h){
  int m = mid-l+1;
  int n = h-mid;
  Point l1[m],l2[n];
  int i,j,k;
  for(i=0;i<m;i++){
    l1[i].x= arr[l+i].x;
    l1[i].y = arr[l+i].y;
  }
  for(i=0;i<n;i++){
    l2[i].x = arr[mid +i+1].x;
    l2[i].y = arr[mid+i+1].y;
  }

  i=0;
  k=l;
  j=0;

    while(i<m && j<n){
      if(l1[i].x  <  l2[j].x){
        arr[k].x = l1[i].x;
        arr[k].y = l1[i].y;
        i ++;
      }
      else{
        arr[k].x = l2[j].x;
        arr[k].y = l2[j].y;
        j ++;
      }

       k++;
    }

    while(i< m){
      arr[k].x = l1[i].x;
      arr[k].y = l1[i].y;
      i ++;
      k ++;
    }

    while(j < n){
      arr[k].x = l2[j].x;
      arr[k].y = l2[j].y;
      j ++;
      k ++;
    }


}
void mergesort(Point arr[] , int l,int h){
  if(l<h){
    int mid = l +(h-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}

int main(){
  Point p[] ={{2,3},{4,1},{14,30},{40,50},{5,1} ,{12,10},{3,4}};
  int n = sizeof(p)/sizeof(p[0]);
  mergesort(p,0,n-1);
  for(int i=0;i<n;i++){
    cout<<p[i].x<<" ,"<<p[i].y<<"\n";
  }
  return 0;
}
