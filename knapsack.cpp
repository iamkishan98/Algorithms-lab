#include<bits/stdc++.h>
using namespace std;
void merge(double arr[][3],int l,int mid,int h){
    int n1= mid - l +1;
    int n2 = h-mid ;
    double arr1[n1][3],arr2[n2][3];
    int i,j,k;
    for(i=0;i<n1;i++){
        for ( j = 0; j < 3; j++)
        {
          
            arr1[i][j] = arr[l+i][j];
        }
        
    }
    
    for(i=0;i<n2;i++){
        for(j=0;j<3;j++){
            arr2[i][j] = arr[mid + i + 1][j];
        }
    }
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2)
    {
        
     
        
        if(arr1[i][2]  > arr2[j][2]){
            arr[k][0] = arr1[i][0];
            arr[k][1] = arr1[i][1];
           arr[k][2] = arr1[i][2]; 
            i ++;
        }
        else{
             arr[k][0] = arr2[j][0];
            arr[k][1] = arr2[j][1];
            arr[k][2] = arr2[j][2]; 
            j ++;

        }
        k ++;
    }
    while(i<n1){
        arr[k][0] = arr1[i][0];
            arr[k][1] = arr1[i][1];
           arr[k][2] = arr1[i][2]; 
            i ++;
             k++;
    }
    while (j<n2)
    {
        
         arr[k][0] = arr2[j][0];
            arr[k][1] = arr2[j][1];
            arr[k][2] = arr2[j][2]; 
            j ++;
             k++ ;

    }
    
    

}

void mergesort(double arr[][3] ,int l,int h){
    int mid;
    if(l<h){
        mid = l +(h-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main(){
    int n;
    cin>>n;
    double capacity;
    cin>>capacity;

    int i,j;
    double arr[n][3];
    for(i=0;i<n;i++){
        for(j=0;j< 2;j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<"Calculating profit/weight ratio"<<endl;
    for(i=0;i<n;i++){
        arr[i][2] = arr[i][1] / arr[i][0];
    }
    
    mergesort(arr,0,n-1);
    cout<<"After sorting ="<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
    double profit=0,cur=0;
    for(i=0;i<n;i++){
        if(cur + arr[i][0] <= capacity){
            cur = cur + arr[i][0];
            profit = profit + arr[i][1];
            cout<<"Weight = "<<cur<<" Profit = "<<profit<<endl;
        }
        else{
            
            profit = profit + (arr[i][1] * ((capacity - cur)/arr[i][0]));
           // cout<<profit<<endl;
            break; 
        }
    }

    cout<<"Maximum profit = "<<profit;
    cout<<endl;
    return 0;
}