#include <iostream>
#include <stack>
#include <algorithm>

//https://www.geeksforgeeks.org/merging-intervals/

struct interval{
  int start,end;
};

bool compareInterval(interval i1,interval i2){
  return (i1.start < i2.start);
}


void mergeIntervals(interval arr[],int n){
  if(n <= 0)
    return;

  std::stack<interval> s;

  std::sort(arr,arr+n,compareInterval);

  s.push(arr[0]);

  for(int i = 1;i<n;i++){
    interval top = s.top();

    if(top.end < arr[i].start)
      s.push(arr[i]);

    else if(top.end < arr[i].end){
      top.end = arr[i].end;
      s.pop();
      s.push(top);
    }
  }

  while(!s.empty()){
    interval i = s.top();
    std::cout<<i.start<<"  "<<i.end<<std::endl;
    s.pop();
  }

  return;
}

int main(){
  interval arr[] = {{6,8},{1,9},{2,4},{4,7}};

  mergeIntervals(arr, sizeof(arr)/sizeof(arr[0]));
}
