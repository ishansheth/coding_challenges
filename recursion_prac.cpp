#include <iostream>
#include <string>
#include <vector>
#include <map>


/**
https://www.geeksforgeeks.org/print-a-pattern-without-using-any-loop/
**/
//finding max number from array approach 2

void printPattern(int n){
  if(n<0){
    std::cout<<n<<std::endl;
    return;
  }

  std::cout<<n<<std::endl;
  printPattern(n-5);
  std::cout<<n<<std::endl;  
}

int fun(int a[],int n){
  int x;
  if(n==1)
    return a[0];
  else
    x = fun(a,n-1);

  if(x > a[n-1])
    return x;
  else
    return a[n-1];

}
//finding max number from array approach 2
int fun1(int a[],int n,int x){
  if(n==0)
    return x;
    
  if(x < a[n-1]){
    x = a[n-1];
  }
  return fun1(a,n-1,x);
}

int main(){
  std::cout<<"pattern"<<std::endl;
  printPattern(16);

  int arr[] = {12,10,30,50,100};
  
  std::cout<<"max number"<<std::endl;
  std::cout<<fun(arr,5)<<std::endl;

  std::cout<<"fun1--------"<<std::endl;
  std::cout<<fun1(arr,5,0)<<std::endl;

}
