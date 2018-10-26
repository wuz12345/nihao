#include<stdio.h>
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

    delete temp;
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
    int A[5]={9,8,7,6,5};
    cout<<inversion(A,0,4)<<endl;
    
    cout<<9/2;
}
