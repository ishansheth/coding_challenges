//https://www.hackerrank.com/challenges/xor-se
#include <iostream>

using namespace std;

long long answerFromOneToN(long long position){
    
    long long m = position%8;
    long long n = position>>3;
    long long b = n*8;
    long long result = 0;
    
    switch(m){
            case 0: result = b;
            break;
            case 1: result = b + 1;
            break;
            case 2:
            case 3: result = 2;
            break;
            case 4: result = b + 6;
            break;
            case 5: result = b + 7;
            break;
            case 6:
            case 7: result = 0;
            break;
        }
    
    return result;
}
    
int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        long long L;
        long long R;
        cin >> L >> R;

        long long al = answerFromOneToN(L-1);
        long long ar =  answerFromOneToN(R);
        long long answer = al^ar;
        
        cout << answer << endl;

    }
    return 0;
}
