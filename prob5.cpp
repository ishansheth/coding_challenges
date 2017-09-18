//https://www.hackerrank.com/challenges/palindrome-index
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    string s;
    cin.ignore();
    for(int i = 0;i<n;i++){
        getline(cin,s);
        int j,k;
        int count=0;
        
            for(j=0, k=s.length()-1 ; j<s.length()/2;j++,k--){
                if(s[j] == s[k]){
                    count++;
                    continue;
                }else{
                    break;
                }
            }
            if(count == s.length()/2){
                cout<<"-1"<<endl;
            }else{
                    cout<<j<<endl;                
            }
        
    }   
    return 0;
}


