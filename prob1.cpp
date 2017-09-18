//https://www.hackerrank.com/challenges/funny-string
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin>>N;
    cin.ignore();
    string s[N];
    for(int i = 0;i<N;i++){
        getline(cin,s[i]);
    }
    
    for(int i = 0;i<N;i++){
        int count = 0;
        string temp = s[i];
        int j,k;
        if(temp.length()%2 == 0){
            for(j = 0,k = temp.length()-1; j < temp.length()/2-1,k > temp.length()/2-1; j++,k--){
                if(abs(temp[j] - temp[j+1]) == abs(temp[k] - temp[k-1])){
                    count++;
                }
            }
            if(count == temp.length()/2){
                cout<<"Funny"<<endl;
            }else{
                cout<<"Not Funny"<<endl;
            }
            
        }else{
            for(j = 0,k = temp.length()-1; j <= temp.length()/2-1; j++,k--){
                if(abs(temp[j] - temp[j+1]) == abs(temp[k] - temp[k-1])){
                    count++;
                }
            }
            
            if(count == temp.length()/2 ){
                cout<<"Funny"<<endl;
            }else{
                cout<<"Not Funny"<<endl;
            }
        }
    }
    return 0;
}
