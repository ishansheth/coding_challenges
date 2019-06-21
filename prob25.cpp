#include <iostream>
#include <string>

/**
   geeksforgeeks problem
   https://www.geeksforgeeks.org/check-if-a-number-is-palindrome/

   check if number if pelindrome
   2001 not a pelindrome
   2005002 is a pelindrome
 **/

bool checkPelindromeNumber(int num,int* copy){
  if(num == 0)
    return true;

  int digit = num%10;
  auto res = checkPelindromeNumber(num/10,copy);
  int past = *copy %10;
  *copy /= 10;
  if(past == digit)
    return res & true;
  else
    return res & false;
  
}


int main(){
  int a = 2055202;
  int* b = &a;
  if(checkPelindromeNumber(a,b)){
    std::cout<<"yes";
  }else{
    std::cout<<"no";
  }
}
