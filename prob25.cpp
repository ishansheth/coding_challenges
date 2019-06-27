#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <limits>

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


// leetcode problem: reverse the digits of the interger number
int reverseNumber(int x){
  if (x == -2147483648) //If x is equal to the min then we can't negate it without overflowing.
    return 0;//would overflow since the desired output is -8463847412;
  
  bool is_negative = x < 0;
  if (is_negative)
    x = -x;

  int reverse = 0;
	
  while (x > 0) {
    int digit = x % 10;
    x = x / 10;
    if (reverse > std::numeric_limits<int>::max() / 10)
      return 0;//The result would overflow
    reverse = 10 * reverse;
    reverse += digit;
  }
        
  if (is_negative)
    reverse = -reverse;
  return reverse;
}


struct Node{
  int i;
  Node* next;
};

/**
   geeksforgeeks problem: check if linked list is pelindrome

// another approach is to reverse the half of the link list and then traverse it from both of the ends

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
// abcd -> 1        a->1
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

int myatoi(std::string str){
  long ans=0;
  int p = 0;
  bool neg = false;
  bool alpha = false;
  bool digit = false;
  // whenever looping backwards, always i should be int n unsigned int
  for(int i = str.size()-1; i>=0;i--){
    if(str[i] == ' '){
      continue;
    }
    
    if(str[i] == '-'){
      digit = true;
      neg = true;
      continue;
    }

    if(str[i] == '.'){
      ans = 0;
      digit = true;
      p = 0;
      continue;
    }
    
    if(str[i] >= '0' && str[i]<='9'){
      digit = true;
      int num = str[i]-'0';
      ans += pow(10,p)*num;
      p++;
    }else{
      alpha = true;
      if(digit)
	return 0;
    }

  }
  
  if(neg)
    ans = -1*ans;

  if(ans > std::numeric_limits<int>::max())
    return std::numeric_limits<int>::max();
  else if(ans < std::numeric_limits<int>::min())
    return std::numeric_limits<int>::min();

  return ans;
}



std::string recursionStringReverse(std::string str,int k){

  if(k == (str.size())/2){
    return str;
  }

  char temp = str[k];
  str[k] = str[str.size()-k-1];
  str[str.size()-k-1] = temp;

  auto x = recursionStringReverse(str,k+1);

  return x;
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

  std::string st = "a";
  //  longestConsecutiveCharacter(st);

  std::cout<<myatoi("3.1433")<<std::endl;

  std::cout<<"reverse recursion:"<<recursionStringReverse("isha",0)<<std::endl;

  std::cout<<"reversed digit:"<<reverseNumber(123)<<std::endl;

}
