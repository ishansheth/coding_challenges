//https://www.hackerrank.com/challenges/the-love-letter-mystery/
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

    for(int k = 0; k < T; k++)
    {
        string str;
        cin >> str;

        string dup(str);
        reverse(dup.begin(), dup.end());

        int cnt = 0;
        if(str.compare(dup))
        {
            int i = 0, j = str.length() - 1;
            while(i < j)
            {
                cnt += abs(str.at(i) - str.at(j));
                i++;
                j--;
            }
        }   

        cout << cnt << endl;

    }
            return 0;
}
