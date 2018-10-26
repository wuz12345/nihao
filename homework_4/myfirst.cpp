#include<iostream>
using namespace std;
int merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//左部分区间的数据元素的个数
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    int num=0;
    while(left_index < start + left_length && right_index < end+1)
    {
        //对分别已经排好序的左区间和右区间进行合并
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            { 
               result[result_index] = data[right_index];
               num=num+left_length-left_index;
               result_index++;
               right_index++;
            }
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
    return num;
}
int  merge_sort(int *data, int start, int end, int *result)
{
    int num1,num2,num3;
    if(1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
            return 1;
        }
        else
          return 0;
    }
    else if(0 == end - start)//如果只有一个元素，则不用排序
        return 0;
    else
    {
        //继续划分子区间，分别对左右子区间进行排序
        num1 = merge_sort(data,start,(end-start+1)/2+start,result);
       num2 = merge_sort(data,(end-start+1)/2+start+1,end,result);
        //开始归并已经排好序的start到end之间的数据
         num3 =merge(data,start,end,result);
        //把排序后的区间数据复制到原始数据中去
        for(int i = start;i <= end;++i)
            data[i] = result[i];
            
    }
    return num1+num2+num3;
}
int main()
{
    int data[] = {2,6,3,4,5,1};
    const int length = 6;
    int result[length];
    cout << "Before sorted:" << endl;
    for(int i = 0;i < length;++i)
        cout << data[i] << "  ";
    cout << endl;
    cout << "After sorted:" << endl;
   int num= merge_sort(data,0,length-1,result);
    for(int i = 0;i < length;++i)
        cout << data[i] << "  ";
    cout << endl;
    cout<<"逆序数"<<endl;
    cout<<num;
    return 0;
}


