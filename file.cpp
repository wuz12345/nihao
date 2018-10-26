#include<iostream>
#include <string>
#include<sstream>
//#include <vector>
#include <fstream>  
using namespace std;
 
float *cost=new float [] ;
 
int main()
{  
    float v, w, weight;
    ifstream infile;   //输入流
    ofstream outfile;   //输出流
    int i=0;
    infile.open("data.txt", ios::in); 
    if(!infile.is_open ())
        cout << "Open file failure" << endl;
    string line;        
    while (getline(infile,line))            // 若未到文件结束一直循环
    {
    stringstream linestream;
        linestream << line;
        
        linestream >>v;    
       cost[i]=v;
    i++;      
      //cout<<v<<endl;                
    }
    infile.close();   //关闭文件
   
    for(int j=0;j<i;j++)
      cout<<cost[j]<<"  ";
}