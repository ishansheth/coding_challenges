//https://www.hackerrank.com/challenges/sansa-and-xor
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    for(int i = 0;i<T;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j = 0;j<n;j++){
            cin>>a[j];
        }
        int res=0;
        if(n%2 != 0){
            for(int j = 0;j<n;j+=2){
                res ^= a[j];
            }            
        }else{
            res = 0;
        }       
        cout<<res<<endl; 
    }
    return 0;
}
