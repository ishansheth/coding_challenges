#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>

class MinHeap{
  int* harr;
  int capacity;
  int heap_size;
  
public:
  MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
  }

  void swap(){
  }
  
  int parent(int i){return (i-1)/2;}

  int left(int i){return (2*i + 1);}

  int right(int i){return (2*i + 2);}

  void heapify(){
    int index = 0;
    while(left(index) < heap_size){
      int smallerindex = left(index);
      if(right(index)<heap_size && (harr[right(index)] < harr[left(index)])){
	smallerindex = right(index);
      }

      if(harr[index] < harr[smallerindex]){
	break;
      }else{
	int swapval = harr[smallerindex];
	harr[smallerindex] = harr[index];
	harr[index] = swapval;
      }
      index = smallerindex;
    }
  }
  
  void insertValue(int value){
    harr[heap_size] = value;
    heap_size++;
    int index = heap_size-1;
    while(parent(index) >= 0 && harr[parent(index)] > value){
      int parentVal = harr[parent(index)];
      harr[parent(index)] = value;
      harr[index] = parentVal;
      index = parent(index);
    }
    
  }

  int poll(){
    int minVal = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    heapify();    
    return minVal;
  }
  
  void printHeap(){
    for(int i= 0;i<heap_size;i++){
      std::cout<<harr[i]<<std::endl;
    }
  }
};

void selectionSort(int* arr,int size){
  int idx = 0;
  while(idx != size-1){
    for(int i = idx+1;i<size;i++){
      if(arr[idx]>arr[i]){
	int temp = arr[idx];
	arr[idx] = arr[i];
	arr[i] = temp;
      }
    }
    idx++;
  }
}

void bubbleSort(int* arr,int size){

  for(int i = 0;i<= size-2;i++){
    for(int j = 0;j<size-i-1;j++){
      if(arr[j] > arr[j+1]){
	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
      }      
    }
  }
}

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int return_val;
    bool found= false;
    std::sort(A.begin(),A.end());
    A.erase(std::remove_if(A.begin(),A.end(),[](int a){return a<0;}),std::end(A));
        
    for(unsigned int i = 0;i<A.size();i++){
        if(abs(A[i+1] - A[i]) >= 2){
            return_val = A[i] +1;
            found = true;
            break;
        }
    }
    
    if(!found){
        return_val = A[A.size()-1] + 1;
    }
    return return_val;
}


unsigned int copyStrings(void* source,void* destination, unsigned int size,unsigned int history_size){
  int historyBuffer[255] = {0};
  unsigned int bytesCopied = 0;
    
  for(int i = 0;i<size;i++){
    if(isalpha(*(char*)source)){
      if(i<history_size){
	*(char*)destination = *(char*)source;
	historyBuffer[*(char*)source]++;
	bytesCopied++;
	(char*)destination++;
	(char*)source++;
      }else{
	if(historyBuffer[*(char*)source]==0){
	  *(char*)destination = *(char*)source;
	  historyBuffer[*(char*)source]++;
	  bytesCopied++;
	  (char*)destination++;
	  (char*)source++;
	}else{
	  historyBuffer[*((char*)source - history_size)]--;
	  (char*)source++;
	}
      }
    }
  }
  return bytesCopied;
}

void countOccur(){
  int count[255] = {0};
  std::string s = "mamma";

  for(int i = 0;i<s.size();i++){
    count[s[i]]++;
  }

  for(int i = 0;i<255;i++){
    if(count[i] > 0){
      std::cout<<"i:"<<i<<" num:"<<count[i]<<std::endl;
    }
  }
}

int main(){
  MinHeap heap(10);

  heap.insertValue(10);
  std::cout<<"min:"<<heap.poll()<<std::endl;
  
  heap.insertValue(5);
  heap.insertValue(3);
  heap.insertValue(4);
  heap.insertValue(7);

  std::cout<<"Heap:";
  heap.printHeap();
  std::cout<<std::endl;
  
  std::cout<<"min:"<<heap.poll()<<std::endl;
  std::cout<<"min:"<<heap.poll()<<std::endl;
  std::cout<<"min:"<<heap.poll()<<std::endl;
  
  std::cout<<"Heap:";
  heap.printHeap();
  std::cout<<std::endl;

  int arr[] = {5,4,8,2,6,14,9};
  //  selectionSort(arr,7);

  //  bubbleSort(arr,7);

  std::vector<int> A{1,20,3,4};
  std::cout<<"Sol:"<<solution(A)<<std::endl;

  std::string a = "hello";
  std::string b = "       ";

  int bytescopy = copyStrings(const_cast<char*>(a.c_str()),const_cast<char*>(b.c_str()),a.size(),3);
  std::cout<<bytescopy<<b<<std::endl;

  countOccur();
}
