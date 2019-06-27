#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// remove the adjacent duplicate characters from text which are present in the filter string
// text: aaabbbccddd    filter: bcd
// ans: aaabcd
// text: aaabbbccdddaaa    filter: abc
// ans: abcddda

std::string processString1(std::string text,std::string filter){
  for(unsigned int i = 0;i<text.size()-1;){
    if(filter.find(text[i]) != std::string::npos || filter.empty()){
      unsigned int count = 0;
      for(unsigned int j = i+1;j<text.size();j++){
	if(text[j] == text[i]){
	  count++;
	}else{
	  break;
	}
      }
      if(count > 0){
	text.erase(i,count);
	i = i + count -1;
      }else{
	i++;
      }
    }else{
      i++;
    }
  }
  return text;
}
// another simpler approach for the above function
std::string processString2(std::string text,std::string filter){
  for(unsigned int i = 0;i<text.size()-1;){
    if(filter.find(text[i]) != std::string::npos || filter.empty()){
      if(text[i] == text[i+1]){
	text.erase(i,1);
     }else{
	i++;
     }
    }else{
      i++;
    }
  }
  return text;
}



// find the first duplicate character in the string 
char findDuplicateChar(std::string str){
  int mem[255] = {0};
  int i= 0;
  for(;i<str.size();i++){
    int dis = int(str[i]);
    if(mem[dis] == 0)
      mem[dis]++;
    else
      break;
  }
  return str[i];
}

// number of ways to decode a message

int decodeMessage(std::string message){
  
}

//https://www.geeksforgeeks.org/print-all-non-increasing-sequences-of-sum-equal-to-a-given-number/


bool checkpeli(std::string ss, int i, int j){
  bool res = true;
  while(i!=j && j != i+1){
    if(ss[i] == ss[j]){
      i++;
      j--;
    }else{
      res = false;
      break;
    }
  }
  return res;
}


std::string longestPelindromSubstring(std::string str){
}


// leet code problem 
int reverseInteger(int x){
  std::cout<<x;
  int output = 0;
  std::vector<int> a;
  while(x){
    a.push_back(x%10);
    x = x/10;
  }

  for(int i = 0;i<a.size();i++){
    output += a[i]*pow(10,a.size()-i-1);
  }
  return output;
}

double findMedianSortedArrays(std::vector<int>& arr1,std::vector<int>& arr2){
  std::vector<int> arr3(arr1.size()+arr2.size());
  
  int i = 0,j=0,k=0;
  for(;i<arr1.size() && j<arr2.size();){
    if(arr1[i] < arr2[j]){
      arr3[k] = arr1[i];
      i++;
    }else{
      arr3[k] = arr2[j];
      j++;
    }
    k++;
  }

  while(i<arr1.size())
    arr3[k++] = arr1[i++];

  while(j<arr2.size())
    arr3[k++] = arr2[j++];

  if(arr3.size()%2 == 0){
    return (arr3[arr3.size()/2 -1] + arr3[arr3.size()/2])/2.f;
  }else{
    return arr3[arr3.size()/2];
  }
}


int main(){

  std::string ans = processString2("aaabbbccaaa","bc");
  //  std::cout<<ans<<std::endl;
  //  generate(4);

  //  reverseInteger(1534236469);

  std::vector<int> a = {1,6,9};
  std::vector<int> b = {2,4};
  auto med = findMedianSortedArrays(a,b);
  std::cout<<med<<std::endl;
}
