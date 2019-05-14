#include <iostream>
#include <list>

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


int main(){
  Graph g(4);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);

  g.BFS(2);

}
