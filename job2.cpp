#include<bits/stdc++.h>
using namespace std;
void merge(int arr[][2],int l,int mid,int h){
    int n1= mid - l +1;
    int n2 = h-mid ;
    int arr1[n1][2],arr2[n2][2];
    int i,j,k;
    for(i=0;i<n1;i++){
        for ( j = 0; j < 2; j++)
        {
          
            arr1[i][j] = arr[l+i][j];
        }
        
    }
    for(i=0;i<n2;i++){
        for(j=0;j<2;j++){
            arr2[i][j] = arr[mid + i + 1][j];
        }
    }
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2)
    {
        
     
        
        if(arr1[i][1]  < arr2[j][1]){
            arr[k][0] = arr1[i][0];
            arr[k][1] = arr1[i][1];
           // arr[k][2] = arr1[i][2]; 
            i ++;
        }
        else{
             arr[k][0] = arr2[j][0];
            arr[k][1] = arr2[j][1];
            //arr[k][2] = arr2[j][2]; 
            j ++;

        }
        k ++;
    }
    while(i<n1){
        arr[k][0] = arr1[i][0];
            arr[k][1] = arr1[i][1];
           // arr[k][2] = arr1[i][2]; 
            i ++;
             k++;
    }
    while (j<n2)
    {
        /* code */
         arr[k][0] = arr2[j][0];
            arr[k][1] = arr2[j][1];
            //arr[k][2] = arr2[j][2]; 
            j ++;
             k++ ;

    }
    
    

}

void mergesort(int arr[][2] ,int l,int h){
    int mid;
    if(l<h){
        mid = l +(h-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main(){
    int n,i,j,k;
    cin>>n;
    int arr[n][2];
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    mergesort(arr,0,n-1);
    cout<<"After sorting by finish time ="<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int count=0,end=0;
    int op[n];
    for(i=0;i<n;i++){
        if(arr[i][0] >= end && arr[i][1] > 0){
            op[count] = i + 1;
            count ++;
        
            end = arr[i][1];
        }
    }
    cout<<"Job sequence of scheduling = "<<endl;
    for(i=0;i<count;i++){
        cout<<op[i]<<" "; 
    }
    cout<<endl;
    cout<<"Maximum no of jobs = "<<count;


    return 0;
}