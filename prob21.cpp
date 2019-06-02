#include <iostream>
#include <string>
#include <map>

void swap(char* x,char* y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

// Reference: geeksforgeeks
void stringPermutation(char* str,int l,int r){
  if(l == r)
    std::cout<<str<<std::endl;
  else{
    for(unsigned i = l;i<=r;i++){
      swap(str+l,str+i);
      stringPermutation(str,l+1,r);
      swap(str+l,str+i);
    }
  }
}

void iterativePermutation(char* str,unsigned size){
  for(unsigned i = 0;i<size;i++){

  }
}
void reverseString(std::string& str){
  for(unsigned i = 0,j = str.size()-1;i<str.size()/2;i++,j--){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }

}
void getDuplicateChar(std::string str){
  std::map<char,int> countMap;

  for(unsigned i=0;i<str.size();i++){
    if(countMap.count(str[i])>0){
      countMap[str[i]]++;
    }else{
      countMap[str[i]] = 1;
    }
  }

  for(auto& ele:countMap){
    if(ele.second>1){
      std::cout<<ele.first<<std::endl;
    }
  }
}

void checkAnagrams(std::string str1,std::string str2){

}

int main(){
  char s[] = "isha";
  stringPermutation(s,0,3);

  std::string ss = "ishann";
  reverseString(ss);
  std::cout<<"ss:"<<ss<<std::endl;

  getDuplicateChar(ss);
}
