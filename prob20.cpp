#include <algorithm>
#include <vector>
#include <iostream>

//https://www.hackerrank.com/challenges/3d-surface-area/problem

int surfaceArea(std::vector<std::vector<int>> A){
  int area = 0;
  for(unsigned i = 0; i<A.size();i++){
    for(unsigned j = 0;j<A[0].size();j++){
      area += (A[i][j] * 4) + 2;
      if(j+1 < A[0].size())
	area -= std::min(A[i][j],A[i][j+1])*2;
      if(i+1 < A.size())
	area -= std::min(A[i+1][j],A[i][j])*2;
    }
  }
  return area;
}


int main(){

  std::vector<std::vector<int>> grid{{1,3,4},
                                     {2,2,3},
				     {1,2,4}};

  int area = surfaceArea(grid);

  std::cout<<"area:"<<area<<std::endl;
}
