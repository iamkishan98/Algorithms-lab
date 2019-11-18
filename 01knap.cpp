#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int W,int val[],int wt[],int tab[][51]){

   
    int i,w;

    for(i=0;i<=n;i++){

        for(w=0;w<=W;w++){

            if(i ==0 || w==0){
                tab[i][w] =0;
            }
            else if(wt[i-1] <= W)
            {
                tab[i][w] = max(val[i-1] + tab[i-1][w - wt[i-1]] , tab[i-1][w]); 
            }
            else{
                tab[i][w] = tab[i-1][w];
            }
            
        }
    }

    return tab[n][W];
}
int main(){
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int capacity = 50;
    int i,j,tab[4][51];
    cout<<knapsack(3,capacity,val,wt,tab)<<endl;
    for(i=0;i<4;i++){
        for(j=0;j<51;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    
        for(j=3;j>0;j--){
            if(tab[j-1][51] != tab[j][51]){
                cout<<j<<" ";
            }
        }
  
    return 0;
}