#include<iostream>
using namespace std;
template <typename T>
T sum(T x,T y){
return (x+y);
}
int main(){
    cout<<sum<int>(9,4);
    cout<<sum<char>('a','z');
    return 0;
}