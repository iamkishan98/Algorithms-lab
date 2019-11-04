#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSubseq(string str1,string str2){
    int m= str1.length();
    int n = str2.length();
    int j=0,i;
    for(i=0;i<m && j<n ;i++){
        if(str1[i]==str2[j]){
            j++;
        }
    }
    return (j==m);
}
string largestsubstring(vector<string> str1, string str2){
    int len=0;
    string result="";
    for(string word: str1){
        if(len<word.length() && isSubseq(word,str2)){
            result =word;
            len = word.length();
        }
    }
    return result;


}

int main(){
    vector <string> dict={"apple","applei","app"};
    string str="abpplei";
    cout<<largestsubstring(dict,str);
    return 0;
}