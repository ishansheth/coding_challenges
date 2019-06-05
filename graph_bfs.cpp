#include <iostream>
#include <list>
#include <vector>

class Graph{

  int v;
  std::list<int>* adj;

public:
  Graph(int v);

  void addEdge(int v,int w);

  void BFS(int s);
};

Graph::Graph(int v){
  this->v = v;
  adj = new std::list<int>[v];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

// traverse the graph using BFS algorithm
void Graph::BFS(int s){
  bool* visited = new bool[v];
  for(int i = 0;i<v;i++)
    visited[i] = false;

  std::list<int> queue;

  visited[s] = true;
  queue.push_back(s);


  std::list<int>::iterator i;

  while(!queue.empty()){
    s = queue.front();
    std::cout<<s<<" ";

    queue.pop_front();

    for(i = adj[s].begin(); i != adj[s].end();++i){
      if(!visited[*i]){
	visited[*i] = true;
	queue.push_back(*i);
      }
    }
  }
}


// prints the level of each node in a graph. Its a distance of each node
// from the start node x
// v is number of nodes, x is the starting point
void printLevel(std::vector<int> graph[],int v,int x){
	std::vector<int> level(v);
	std::vector<bool> visited(v);

	level[x] = 0;

	for(int i = 0;i<v;i++)
		visited[i] = false;

	visited[x] = true;
	std::list<int> queue;
	queue.push_back(x);
	while(!queue.empty()){
		int node = queue.front();
		queue.pop_front();
		for(auto& ele:graph[node]){
			if(!visited[ele]){
				level[ele] = level[node] + 1;
				visited[ele] = true;
				queue.push_back(ele);
			}
		}		
	}
	for(auto& i: level)
	  std::cout<<i<<" ";	
}

struct test1{
  unsigned int x: 5;
  unsigned int y: 33;
};

struct test2{
  unsigned int x: 5;
  unsigned int: 0;
  unsigned int y: 8;
};


struct S{
  unsigned int b:3;
};

union test 
{ 
    int x; 
    char arr[4]; 
    int y; 
}; 

// count the number of disjointed trees in the graph,
// edges in array of vectors, v is number of nodes 
int countTrees(std::vector<int> adj[],int v){
  unsigned noOfTrees = 0;
  std::vector<bool> visited(v,false);
  std::list<int> queue;

  for(unsigned i = 0;i<visited.size();){
    if(!visited[i]){
      noOfTrees++;
      unsigned sn = i;
      visited[sn] = true;
      queue.push_back(sn);
      while(!queue.empty()){
	auto ss = queue.front();
	queue.pop_front();
	for(auto& ele:adj[ss]){
	  if(!visited[ele]){
	    queue.push_back(ele);
	    visited[ele] = true;
	  }
	}
      }     
    }else{
      i++;
    }
  }
  return noOfTrees;
}

void recusrionBFS(std::vector<int> adj[],int v,int s){
}

int main(){
  Graph g(4);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);

  g.BFS(2);
	
  int v = 8;
  std::vector<int> graph[v];
  
  graph[0].push_back(1);
  graph[0].push_back(2);
  graph[1].push_back(3);
  graph[1].push_back(4);
  graph[1].push_back(5);
  graph[2].push_back(6);
  graph[6].push_back(7);
  
  std::cout<<"levels of nodes"<<std::endl;
  printLevel(graph,v,0);

  printf("\nSize of test1: %lu",sizeof(test1));
  printf("\nSize of test2: %lu",sizeof(test2));
  printf("\nSize of test2: %lu",sizeof(unsigned int));
  printf("\nSize of test2: %lu",sizeof(S));

  union test t; 
  t.x = 0; 
  t.arr[1] = 'G'; 
  printf("%s", t.arr); // nothing will be printed
  

  std::vector<int> forestGraph[11];
  forestGraph[0].push_back(1);
  forestGraph[0].push_back(2);
  forestGraph[2].push_back(3);
  forestGraph[2].push_back(4);
  
  forestGraph[5].push_back(6);
  forestGraph[6].push_back(7);

  forestGraph[7].push_back(8);
  forestGraph[8].push_back(9);
  forestGraph[8].push_back(10);

  int nooftree = countTrees(forestGraph,11);
  std::cout<<"\nNo of trees:"<<nooftree<<std::endl;

  std::cout<<"recursive BFS Nodes"<<std::endl;
  recusrionBFS(forestGraph,11,0);
  return 0; 

}

