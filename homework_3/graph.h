#ifndef GRAPH_H
#define GRAPH_H

#define MAXVEX 10
#include <queue>
#include <assert.h>
#include<stack>
using namespace std;
//访问
int visited[MAXVEX]={0};
struct EdgeNode   //边表
{
  int adjvex;
  EdgeNode *next;
};
struct VertexNode //顶点表
{
  char data;
  EdgeNode *firstedge;
};

class Graph{
  VertexNode AdjList[MAXVEX]; //节点的链表数组
  int numVertexes;
  int numEdges;  //节点数和边数
public :
  Graph(){}
  ~Graph(){}
  void CreatGraph(int x,int y);
  void InsertEdge();
  void dfs(int i);
  void bfs(int i);
  void D_search(int i)  ;
  void show_adjlist();
};
void Graph::CreatGraph(int x,int y){
   this->numVertexes=x;
   this->numEdges =y;
   for(int i=0;i<this->numVertexes;i++)
    {
      cout<<"第"<<i+1<<"个顶点的值为：";
      cin>>this->AdjList[i].data;
      this->AdjList[i].firstedge = NULL;
    }
}

void Graph::InsertEdge(){
  int v1,v2;
  EdgeNode *e;
    for(int k=0;k<this->numEdges;k++)
    {
      cout<<"第"<<k+1<<"条边顶点为：";
      cin>>v1>>v2;
      e = new EdgeNode;
      e->adjvex=v2-1;
      e->next = this->AdjList[v1-1].firstedge;
      this->AdjList[v1-1].firstedge=e;
   
      e = new EdgeNode;
      e->adjvex=v1-1;
      e->next = this->AdjList[v2-1].firstedge;
      this->AdjList[v2-1].firstedge=e;    
    }  
}
 void Graph::dfs(int i){
 EdgeNode *p;
   visited[i]=1;
   cout<<this->AdjList[i].data<<"->";
   p = this->AdjList[i].firstedge;
   while(p)
   {
     if(visited[p->adjvex]==0)
     dfs(p->adjvex);
     p=p->next;
   }   
}

void Graph::bfs(int i){
 for(int j=0;j<MAXVEX;j++){
   visited[j]=0;
  }
 queue <int> q;
  visited[i]=1;
  q.push(i);
  int u=i;
   while(q.size()>0){
 EdgeNode *p  =this->AdjList[u].firstedge;
 cout<<this->AdjList[u].data<<"->";
   while(p){
      if(visited[p->adjvex]==0){
         q.push(p->adjvex);
        visited[p->adjvex]=1;   
     }
     p=p->next;
    }
    q.pop();
    u=q.front();
  }
  
}

void  Graph::D_search(int i){
 for(int j=0;j<MAXVEX;j++){
   visited[j]=0;
  }
 stack <int> s;
  visited[i]=1;
  s.push(i);
  int u=i;
   while(s.size()>0){
 EdgeNode *p  =this->AdjList[u].firstedge;
 cout<<this->AdjList[u].data<<"->";
   while(p){
      if(visited[p->adjvex]==0){
         s.push(p->adjvex);
        visited[p->adjvex]=1;   
     }
     p=p->next;
    }
    u=s.top();
    s.pop();
  } 
}

void Graph::show_adjlist()
{
    for(int i = 0; i < this->numVertexes; i++)
    {
        EdgeNode *p = this->AdjList[i].firstedge;
        cout << this->AdjList[i].data << '\t';
        while(p)
        {
            cout << p->adjvex+1 << ' ' <<'\t';
            p = p->next;
        }
        cout << endl;
    }
}
#endif
