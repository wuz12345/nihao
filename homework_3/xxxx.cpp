#include<iostream>
#include "graph.h"
using namespace std;

int main(){
  Graph G;
  int v,E;
  cout<<"输入顶点与边数(顶点数小于10):";
  cin>>v>>E;
  G.CreatGraph(v,E);
  G.InsertEdge();
  cout<<"您添加的图的邻接链表表示如下："<<endl;
  G.show_adjlist();
  int i;
  cout<<"请输入深度优先的起始顶点:";
  cin>>i;
  cout<<"*******深度优先******"<<endl;
  G.dfs(i);
  cout<<endl;
  int j;
  cout<<"请输入广度优先的起始顶点:";
  cin>>j;
  cout<<"*******广度优先******"<<endl;  
  G.bfs(j);
  cout<<endl;
  int k;
  cout<<"请输入D_search的起始顶点:";
  cin>>k;
  cout<<"********D_search*********"<<endl;
  G.D_search(k);
  cout<<endl;
}