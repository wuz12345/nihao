#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<malloc.h>
using namespace std;

const int maxvex = 100;
const int infinity = 65535;   //无穷大
bool visited[maxvex] = {0};

void initvisited()
{
    for(int i = 0; i < maxvex; i++)
        visited[i] = 0;
}



//-------------邻接链表-------------------------------------------

//边表结点
struct EdgeNode{
    int adjvex; //邻接点域，储存该顶点对应的下标
    int weight; //权值
    struct EdgeNode * next;
};
//顶点表结点
struct VertexNode{
    char data;
    EdgeNode * firstedge;
};

struct GraphAdjList{
    VertexNode vertex[maxvex];
    int numvertexes, numedges;
};

//建立图的邻接表结构
void createALGraph(GraphAdjList * g)
{
    int i, j, k;
    EdgeNode * e;
    cout<<"输入顶点数和边数：";
    cin>> g->numvertexes>> g->numedges;

    for(i = 0; i < g->numvertexes; i++)
    {
        cout<<"输入顶点.data";
        cin>>g->vertex[i].data;
        g->vertex[i].firstedge = NULL;
    }

    for(k = 0; k < g->numedges; k++)//建立边表
    {
        cout<<"输入边（vi, vj）上的顶点序号";
        cin>>i >>j;

      
        e=new EdgeNode;
        e -> adjvex = j-1;
     
        e -> next = g->vertex[i-1].firstedge;  //头插
        g -> vertex[i-1].firstedge = e;


        e=new EdgeNode;     
    
        e ->adjvex = i-1;
        e->next = g->vertex[j-1].firstedge;  //头插
        g->vertex[j-1].firstedge = e;
        delete e;
    }
}


void dfs_2(GraphAdjList g, int i)
{
    EdgeNode *p;
    visited[i] = 1;
    cout<<g.vertex[i].data<<" ";
    p = g.vertex[i].firstedge;
    while(p != NULL)
    {
        if(!visited[p->adjvex])
            dfs_2(g, p->adjvex);
        p = p->next;
    }
}

/*void dfstraverse_2(GraphAdjList g)
{
    int i = 0;

    initvisited();

    for(i = 0; i < g.numvertexes; i++)
    {
        if(!visited[i]) dfs_2(g, i);
    }
}*/
int main()
{

    cout<<"邻接链表建立图，并进行深度优先遍历"<<endl;
    GraphAdjList g2;
    createALGraph(&g2);
    dfs_2(g2,0);

    return 0;
}

