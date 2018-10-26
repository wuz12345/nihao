//*************************************************************************
//***--最大间隙问题。给定 n 个实数x1,x2,…,xn，求这n个实数在数轴上相邻2个数之间的最大差值
//***--假设对任何实数的下取整函数耗时O(1), 设计解最大间隙问题的线性时间算法          
//***--算法输入:
//***--输入数据由文件名input.txt的文本提供。文件的第一行有一个正整数n，接下来有n个实数。 
//***--算法输出：                                                            
//***--将找到的最大间隙输出到文件output.txt中                                    
//**************************************************************************
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
#define  MAX 11
using namespace std;
ifstream infile;   //输入流
ofstream outfile;   //输出流
struct Bucket   //用于存放数据的桶
{
   float min_Num; //桶的下界
   float max_Num; //桶的上界
   //float data[MAX-2]={0};    //桶的数据
   int num; //数据个数
};
void FindMaxGap( float *a,int num)//遍历一遍数组找到最大值和最小值，返回其差即可
{
// 首先查找数组的最大值与最小值
  float min_num=0xffff;
  float max_num=-0xffff;
  int min_Index; //最大值下标
  int max_Index; //最小值下标
  for(int i=0;i<MAX;i++){
    if(a[i]>max_num)
     {
       max_num=a[i];
       max_Index=i;
    }
    if(a[i]<min_num)
    {
     min_num=a[i];
      min_Index=i;
    }
  }
// cout<<"最大值在第"<< max_Index+1<<"个；"<<"最小值在"<< min_Index+1<<"个"<<endl;
//造n-1个桶 (本例中为9个)
   Bucket  bucket[MAX-1];
//每个桶的大小
   float len = (max_num-min_num)/(float(MAX-1));
//初始化桶数组
   for(int i=0;i<MAX-1;i++){
   bucket[i].min_Num=max_num;
   bucket[i].max_Num=min_num;
   bucket[i].num=0;
  }

//改变桶的下界
 for(int i=0;i<MAX;i++)
 {  //每个桶的数据
    int num_bucket=(int)((a[i]-min_num)/len);
   // bucket[num_bucket].num++;
    if(num_bucket==MAX-1)
       num_bucket--;
    if(a[i]<bucket[num_bucket].min_Num){
     bucket[num_bucket].min_Num=a[i];
    }
    if(a[i]>bucket[num_bucket].max_Num){
         bucket[num_bucket].max_Num=a[i];
        }    
    bucket[num_bucket].num++;
 }


float temp=0;
float left=bucket[0].max_Num;

for(int i=0;i<MAX-1;i++)
{
   if(bucket[i].num)
   {
      if(bucket[i].min_Num-left>temp)
          temp=bucket[i].min_Num-left;
      left=bucket[i].max_Num;
   }
}
 outfile.open("output.txt");   
     if(!outfile.is_open ())
         cout << "Open file failure" << endl;
     outfile<<"最大间隙为："<<temp<<endl;
     outfile.close();
   
  cout<<"最大间隙为："<<temp<<endl;

}
int main()
{
    float v;
    int i=0;
    float cost[12];
  
    infile.open("data.txt"); 
    if(!infile.is_open ())
        cout << "Open file failure" << endl;
    string line;        
    while (getline(infile,line))            
    {
       stringstream linestream;
       linestream << line;
       linestream >>v;    
       cost[i]=v;
       i++;      
    }
    cout<<"i=="<<i<<endl;
    
    float a[i-1];
    for(int j=0;j<i-1;j++)
    {  
        a[j]=cost[j+1];
    }
    cout<<"********Input Is***********"<<endl;
    for(int i=0;i<MAX;i++)
       cout<<a[i]<<"  ";
    cout<<endl;
    FindMaxGap(a,MAX);
}