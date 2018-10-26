#include<iostream>
#define MAX 10
using namespace std;
int  merge(int *A,int p,int q,int r){
  int num=0;
  int n1=q-p+1;
  int n2=r-q;
  int L[n1+1]={0};
  int R[n2+1]={0};
  for(int i=0;i<n1;i++)
     L[i]=A[p+i];
  for(int j=0;j<n2;j++)
     R[j]=A[q+1+j];
  L[n1]=0xFFFFF;
  R[n2]=0xFFFFF;
  int i=0;
  int j=0;
  int k=p;
  while(i < n1 && j < n2)
  {
    if(L[i]<=R[j])
        A[k++]=L[i++];
    else{ A[k++]=R[j++];num+=n1-i;}
  }
  for(;i<n1;i++)
      A[k++]=L[i];
  for(;j<n2;j++)
      A[k++]=R[j];
  return num;
}
int  merge_sort(int *A,int p,int r){
  if(p<r){
    int q=(p+r)/2;
    int num1= merge_sort(A,p,q);
    int num2=merge_sort(A,q+1,r);
    return num1+num2+merge(A,p,q,r);
  }else 
   return 0;
}
int main()
{
    int A[MAX]={10,9,8,7,6,5,4,3,2,1};
    
    for(int i=0;i<MAX;i++)
       cout<<A[i]<<"  ";
    cout<<endl;
  
    int num=merge_sort(A,0,MAX-1);
   
    cout<<"逆序数为"<<endl;
    cout<<num<<endl;    
}
