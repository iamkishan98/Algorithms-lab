#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    int res =count(n);
    printf("%d",res);
    return 0;
}
int count(int n){
    int count=0,num;
    for(int i=0;i<=n;i++)
    {
        num=i;
        while( num >0){
            if(num%2 ==1){
                count ++;

            }
            num /=2;
        }

    }
    return count;
}