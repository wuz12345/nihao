#include<iostream>
#define MAX 10
using namespace std;
int merge(int *A,int left,int mid,int right){
    int *temp=new int[right-left+1];
    int num=0;
    int i=left;
    int j=mid+1;
    int k;
    int index=0;
    for(;i<=mid&&j<=right;){
        if(A[i]>A[j]){
            num+=mid-i+1;
            temp[index]=A[j];
            j++;
        }
        else{
            temp[index]=A[i];
            i++;
        }
        index++;
    }
    //i=mid的时候，A[i]位置的数还未填充到数组temp中
    //因此判断条件包含等于号
    if(i<=mid)
        for(;i<=mid;i++){
            temp[index]=A[i];
            index++;
        }
    if(j<=right)
        for(;j<right;j++){
            temp[index]=A[j];
            index++;
        }
    for(k=0;k<right-left+1;k++)
        A[left+k]=temp[k];

    delete []temp;
    return num;
}
int inversion(int *A,int left,int right){
    if(left>=right)
        return 0;
    int mid=(left+right)/2;
    int num1=inversion(A,left,mid);
    int num2=inversion(A,mid+1,right);
    return num1+num2+merge(A,left,mid,right); 
}
int main()
{
    int A[MAX]={2,3,1,-9,-8,-20,8,7,9,10};
    cout<<"*****before sort*********"<<endl;
         for(int i=0;i<MAX;i++)
            cout<<A[i]<<"  ";
         cout<<endl;        
    cout<<inversion(A,0,MAX-1)<<endl;
    //cout<<9/2;
     
}
