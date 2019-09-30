#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;
int findarray(int [],int);
int findarray(int a[],int n){
    int count=0;
    unordered_set<int> hset;
    int b=0;
    int c=1;
    int d;
    int max=a[0];
    for(int i=0;i<n;i++){
        if(max< a[i]){
         max = a[i];        
        }
        else{
            continue;
        }
    }
    hset.insert(b);
    hset.insert(c);
    while( d < max){
        d = b+c;
        b= c;
        c = d;
        hset.insert(d);

    }
    cout<<"{";
    for ( d = 0; d< n; d++)
    {
        /* code */
        
        if(hset.find(a[d]) != hset.end())
        {
            count ++;
            cout<<a[d]<<"\t";
        }    
        

    }
    cout<<"}";
    
    return count; 
}
int main(){
    int a[]={6,1,3,8,18,13};
    int n=sizeof(a)/sizeof(a[0]);
    int p =findarray(a,n);
    cout<<p;
    return 0;
}