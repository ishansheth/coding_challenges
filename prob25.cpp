#include <iostream>
#include <string>
#include <stack>
#include <vector>
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

struct Node{
  int i;
  Node* next;
};

/**
   geeksforgeeks problem: check if linked list is pelindrome
 **/

bool isListPalindrome(Node* head){
  // this approach of using stack takes O(n) time ans space complexity
  std::stack<int> s;
  Node* l = head;
  bool res = true;
  while(l){
    s.push(l->i);
    l = l->next;
  }
  l = head;
  while(!s.empty()){
    if(s.top() != l->i){
      res = false;
      break;
    }
    s.pop();
    l = l->next;
  }
  return res;
}

// another approach is to reverse the half of the link list and then traverse it from both of the ends



/**
Print all possible strings of length k that can be formed from a set of n characters
https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
**/
void printStrings(std::vector<char> set, std::string str,int k,int n){

  if(k==n){
    std::cout<<str<<std::endl;
    return;
  }
    
  for(int i = 0;i<set.size();i++){
    str[n] = set[i];
    printStrings(set,str,k,n+1);
  }
}

/**
   print the all the subset of a set
   there is a little difference between this and above problem
 **/
void allSubsetOfSet(std::vector<char>& set,char* subset,int n){
  if(n == set.size()){
    char* str = new char[set.size()];
    int j = 0;
    for(int i = 0;i<set.size();i++){
      if(subset[i] != ' '){
	str[j] = subset[i];
	j++;
      }
    }
    std::cout<<str<<std::endl;
    return;
  }

  
  subset[n] = ' ';
  allSubsetOfSet(set,subset,n+1);    
  subset[n] = set[n];
  allSubsetOfSet(set,subset,n+1);
    
}

// find the longest consecutive characters substring length
// aabbbbc -> 4     aabbbbcddddddddd -> 9
void longestConsecutiveCharacter(std::string str){

  int i = 0,j= 1;
  int count = 1;
  int max = 1;
  while(i<str.size() && j<str.size()){
    if(str[i] == str[j]){
      j++;
      count++;
    }else{
      i++;
      j++;
    }
    if(count>=max)
      max = count;
  }
  std::cout<<"max count:"<<max<<std::endl;
}


void duplicateZeros(std::vector<int>& arr){
  std::vector<int> res;
  for(int i = 0;i<arr.size();i++){
    if(res.size() == arr.size())
      break;

    if(arr[i] == 0){
      res.push_back(0);
      res.push_back(0);      
    }else{
      res.push_back(arr[i]);
    }
  }

}



int main(){
  int a = 2055202;
  int* b = &a;
  if(checkPelindromeNumber(a,b)){
    std::cout<<"yes"<<std::endl;
  }else{
    std::cout<<"no"<<std::endl;
  }

  Node* head = new Node;
  head->i = 1;
  head->next = new Node;
  head->next->i = 2;
  head->next->next = new Node;
  head->next->next->i = 4;

  if(isListPalindrome(head)){
    std::cout<<"list is pelindrome"<<std::endl;
  }else{
    std::cout<<"list is not pelindrome"<<std::endl;
  }

  std::vector<char> set = {'a','b','c','d'};
  char* s = new char[4];
  //  printStrings(set,s,4,0);

  //    allSubsetOfSet(set,s,0);

  std::vector<int> arr = {0,0,0,0,0,0,0,0};

  //  duplicateZeros(arr);
  std::cout<<arr.size()<<std::endl;

  std::string st = "aabbbbcddddddddd";
  longestConsecutiveCharacter(st);
}
