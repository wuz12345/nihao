#ifndef QUEUE_H
#define QUEUE_H
#define MAXSIZE 100
#include<iostream>
using namespace std;
typedef int datatype;

typedef struct 
{
	datatype data[MAXSIZE];
	int front,rear;    //表示队列的头尾位置
}Queue;

//置空队列
bool Set_NULL(Queue &Q);

//判断队列是否为空
bool Is_NULL(Queue Q);

//入队
bool En_Queue(Queue &Q,datatype a);

//出队
bool De_Queue(Queue &Q);

//取队列头元素
datatype front_element(Queue Q);

//显示队列元素
bool show(Queue Q);





//队列状态说明：
//front = -1 rear = -1 空队列
//front = -1 rear != -1 有元素队列
//front != -1 rear != -1 有元素出队列

//置空队列
bool Set_NULL(Queue &Q)
{
	Q.front = -1;
	Q.rear = -1;
	return true;
}

//判断队列是否为空
bool Is_NULL(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;  //队头等于队尾，为空
	}
	return false;
}

//入队
bool En_Queue(Queue &Q,datatype a)
{
	if ((Q.rear - Q.front) >= MAXSIZE-1)
	{
		cout<<"The queue is full~";
		return false;
	}
	Q.rear += 1;
	Q.data[Q.rear] = a;
	return true;
}

//出队
bool De_Queue(Queue &Q)
{
	if (Is_NULL(Q))
	{
		cout<<"The queue is empty~";
		return false;
	}
	Q.front += 1;
	return true;
}

//取队列头元素
datatype front_element(Queue Q)
{
	if (Is_NULL(Q))
	{
		cout<<"The queue is empty~";
		//return NULL;
	}
	return Q.data[Q.rear];
}

//显示队列元素
bool show(Queue Q)
{
	if (Is_NULL(Q))
	{
		cout<<"The queue is empty~";
		return false;
	}
	for (int i = Q.front;i < Q.rear;++i)
	{
		cout<<Q.data[i+1]<<" ";
	}
	return true;
}


#endif