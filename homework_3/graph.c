#include<stdio.h>
#include<stdlib.h>


#define MAXVEX 100
#define true 1
typedef char VertexType;        //定义图节点值得类型，可随意更换
typedef int EdgeType;        
int visited[MAXVEX]={0};   
typedef struct EdgeNode         //定义边表节点
{
    int adjvex;                 //存储顶点下标
    EdgeType weight;            //权重值
    struct EdgeNode* next;      //边指针
}EdgeNode;
typedef struct VertexNode   /*顶点表节点*/
{
    VertexType data;
    EdgeNode* firstedge;
}VertexNode;

typedef struct
{
    VertexNode adjList[MAXVEX];
    int numVertexes,numEdges;
}GraphAdjList;

void CreatGraph(GraphAdjList *g)
{
    int i,j,k;
    EdgeNode *e;
    scanf("%d%d",&g->numVertexes,&g->numEdges);//获取顶点数和边数
    char c;
    //gettchar();
    for(i=0;i<g->numVertexes;i++)
    {
        while((c=getchar())=='\n'||c==' ');//排除空格和换行符
        g->adjList[i].data = c;            //获取顶点值，
        g->adjList[i].firstedge = NULL;    //将边表置为空
    }
    for(k=0;k<g->numEdges;k++)
    {
        scanf("%d%d",&i,&j);               //输入i,j 在图中有i-->j
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = g->adjList[i].firstedge;   //头插法建立边表
        g->adjList[i].firstedge= e;
      
                e=(EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex = i;
                e->next = g->adjList[j].firstedge;
                g->adjList[j].firstedge= e;
    }
}

void DFS(GraphAdjList *g,int i)
{
        EdgeNode *p;
        visited[i]=true;
        printf("%c ",g->adjList[i].data);
        p = g->adjList[i].firstedge;
        while(p)
        {
                if(visited[p->adjvex]==0)
                        DFS(g,p->adjvex);
                p=p->next;
        }
}
void  main()
{
  GraphAdjList g;
  CreatGraph(&g);
  DFS(&g,0);
 // return 0;
}
}GraphAdjList;