#include<bits/stdc++.h>
using namespace std;

void merge(int arr[][3],int l,int mid,int h){
    int n1= mid - l +1;
    int n2 = h-mid ;
    int arr1[n1][3],arr2[n2][3];
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
        
     
        
        if(arr1[i][1]  > arr2[j][1]){
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
        /* code */
         arr[k][0] = arr2[j][0];
            arr[k][1] = arr2[j][1];
            arr[k][2] = arr2[j][2]; 
            j ++;
             k++ ;

    }
    
    

}

void mergesort(int arr[][3] ,int l,int h){
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
    int i,j,arr[n][3];
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    mergesort(arr,0,n-1);
     for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int op[n];
    
    
    int k=0,time,dead,flag=0,flag2=0,val,c=0;
    if(arr[0][2]!=0){
        time=1;
        dead=arr[0][2]-time;
        
        val=arr[0][1];
    
    
        op[k++] = arr[0][2];
    }
    else{
        time =0;
        dead = 0;
        val  =0;
        

    }

    for(i=1;i<n;i++){
        if(arr[i][2]==0){
            continue;
        }
        c = k;
        flag = 0;
        flag2 =0;

        for(j=c-1;j>=0;j--){
            if(arr[i][2] == op[j]){
                flag2 =1;
            }

            if((arr[i][2] == op[j] && dead <=0) || (arr[i][2] < time && dead<=0)){
                flag=1;
                break ;
            }
            else if(arr[i][2] < time && flag2 == 1){
                flag=1;
                break;
            }
            
        }
        if(flag==0){
            op[k++] = arr[i][2];
            val = val + arr[i][1];
            time ++;
            dead = arr[i][2] - time ;
        }
    }

    for(i=0;i<k;i++){
        cout<<op[i]<<" ";
    }
    cout<<endl;
    cout<<val;



    return 0;
}