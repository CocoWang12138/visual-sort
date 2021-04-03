#include "MaxHeap.h"

MaxHeap::MaxHeap(int MaxHeapSize)
{//构造函数
  MaxSize=MaxHeapSize;
  heap=new int[MaxSize+1];
  CurrentSize=0;
}
MaxHeap& MaxHeap::Insert(const int&x)
{//把x插入到最大堆中
  if(CurrentSize==MaxSize)
    throw NoMem();//没有足够的空间
  //为x寻找应插入位置
  //从新的叶节点开始，并沿着树上升
  int i=++CurrentSize;
  while(i!=1&&x>heap[i/2]){
    //不能把x放入heap[i]
    heap[i]=heap[i/2];//将元素下移
    i/=2;//移向父节点
  }
  heap[i]=x;
  return *this;
}
MaxHeap& MaxHeap::DeleteMax(int& x)
{//将最大元素放入x,并从堆中删除最大元素
  //检查堆是否为空
  if(CurrentSize==0)
     throw OutOfBounds();
  x=heap[1];//最大元素
  //重构堆
  int y=heap[CurrentSize--];//最后一个元素
  //从根开始，为y寻找合适的位置
  int i=1,//堆的当前节点
      ci=2;//i的孩子
  while(ci<=CurrentSize){
    //heap[ci]应是i的较大的孩子
     if(ci<CurrentSize&&heap[ci]<heap[ci+1])
        ci++;
     //能把y放入heap[i]吗？
     if(y>=heap[ci]) break;//能
     //不能
     heap[i]=heap[ci];//将孩子上移
     i=ci;
     ci*=2;
  }
  heap[i]=y;
  return *this;
}
void MaxHeap::Initialize(int a[],int size,int ArraySize)
{//把最大堆初始化为数组a
  delete []heap;
  heap=a;
  CurrentSize=size;
  MaxSize=ArraySize;
  //产生一个最大堆
  for(int i=CurrentSize/2;i>=1;i--){
     int y=heap[i];//子树的根
     //寻找放置y的位置
     int c=2*i;//c的父节点是y的目标位置
     while(c<=CurrentSize){
        //heap[c]应是较大的同胞节点
         if(c<CurrentSize&&heap[c]<heap[c+1])  c++;
         //能把y放入heap[c/2]吗？
         if(y>=heap[c])  break;//能
         //不能
         heap[c/2]=heap[c];//将孩子上移
         c*=2;//下移一层
     }
     heap[c/2]=y;
  }
}

