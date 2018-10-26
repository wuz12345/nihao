#include<iostream>
#define MAX 6
int zhongshu=0;
int chongshu=0;
using namespace std;
int MidCount(int a[],int low ,int high)
{
   int mid=(low+high)/2;
   int num=0;
   for(int i=low;i<high;i++){
      if(a[mid]==a[i]){
        num++;
    }
   }
   return num;
}
int MidIndex(int a[],int low ,int high)
{
   int index=0;
   for(int i=low;i<high;i++)
  {
      if(a[i]==a[(low+high)/2])
      {
        index=i;
        break;
    }
  }
}

void  GetZhongShu(int a[],int low ,int high){
   int mid=(low+high)/2;
   int mid_num=MidCount(a,low,high);
   int left=MidIndex(a,low,high);
   if(mid_num>chongshu){
     zhongshu=a[mid];
     chongshu=mid_num;
   }
   if(high-(left+mid_num)>chongshu){
   GetZhongShu(a,left+mid_num , high);
  }
   if(left>chongshu)
  {
       GetZhongShu(a,low,left);
  }
}
int main()
{
  int a[MAX]={1,2,2,2,3,5};
  GetZhongShu(a,0,MAX);
    cout<<"众数="<<zhongshu<<"      "<<"重数="<<chongshu<<endl;
  return 0;
}
