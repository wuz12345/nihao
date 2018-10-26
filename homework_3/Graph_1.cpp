#include<iostream>
//#include"queue.h"
#include <queue>
#include <assert.h>
#include<stack>
#define MAXVEX 10
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
//图的邻接表
struct GraphAdjList  
{
  VertexNode AdjList[MAXVEX]; //节点的链表数组
  int numVertexes,numEdges;  //节点数和边数

};
//创建图
void CreatGraph(GraphAdjList *g)
{
  int i,j,k;  

  cout<<"输入顶点数和边数"<<endl;
  cin>> g->numVertexes>>g->numEdges;
 
  for(i=0;i<g->numVertexes;i++)
  {

    cout<<"第"<<i+1<<"个顶点的值为：";
    cin>>g->AdjList[i].data;
    g->AdjList[i].firstedge = NULL;
  }
//向图中插入边 边的顶点为 v1 v2
  int v1,v2;
  EdgeNode *e;
  for(k=0;k<g->numEdges;k++)
  {
    cout<<"第"<<k+1<<"条边顶点为：";
    cin>>v1>>v2;
    e = new EdgeNode;
    e->adjvex=v2-1;
    e->next = g->AdjList[v1-1].firstedge;
    g->AdjList[v1-1].firstedge=e;
 
    e = new EdgeNode;
    e->adjvex=v1-1;
    e->next = g->AdjList[v2-1].firstedge;
    g->AdjList[v2-1].firstedge=e;    
    
  }
}
void PrintfGraphAdjList(GraphAdjList G)
{
    for(int i = 0; i < G.numVertexes; i++)
    {
        EdgeNode *p = G.AdjList[i].firstedge;
        cout << G.AdjList[i].data << '\t';
        while(p)
        {
            cout << p->adjvex+1 << ' ' <<'\t';
            p = p->next;
        }
        cout << endl;
    }
}


void DFS(GraphAdjList *g,int i)
{
  EdgeNode *p;
  visited[i]=1;
  cout<<g->AdjList[i].data<<"->";
  p = g->AdjList[i].firstedge;
  while(p)
  {
    if(visited[p->adjvex]==0)
    DFS(g,p->adjvex);
    p=p->next;
  }  
}

void BFS(GraphAdjList *g,int i){
  for(int j=0;j<MAXVEX;j++){
   visited[j]=0;
  }
 queue <int> q;
  visited[i]=1;
  q.push(i);
  int u=i;
   while(q.size()>0){
 EdgeNode *p  =g->AdjList[u].firstedge;
 cout<<g->AdjList[u].data<<"->";
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

void D_search(GraphAdjList *g,int i){
 for(int j=0;j<MAXVEX;j++){
   visited[j]=0;
  }
 stack <int> s;
  visited[i]=1;
  s.push(i);
  int u=i;
   while(s.size()>0){
 EdgeNode *p  =g->AdjList[u].firstedge;
 cout<<g->AdjList[u].data<<"->";
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
int main()
{
  GraphAdjList g;
  CreatGraph(&g);
  cout<<"邻接表"<<endl;
  PrintfGraphAdjList(g);
  cout<<endl;
  cout<<"深度度优先遍历"<<endl;
  DFS(&g,0);
  cout<<endl;
  cout<<"广度优先遍历"<<endl;
  BFS(&g,0);
  cout<<endl;
  cout<<"D_search遍历"<<endl;
  D_search(&g,0);
  cout<<endl;
}