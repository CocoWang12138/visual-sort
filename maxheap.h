#ifndef MAXHEAP_H
#define MAXHEAP_H
#include<iostream>

using namespace std;
//异常类声明
class OutOfBounds
{
public:
OutOfBounds(){}
};
class NoMem
{
public:
NoMem(){}
};
//最大堆排序类
class MaxHeap{
    public:
        MaxHeap(int MaxHeapSize=10);    //构造函数，数据量为10
        ~MaxHeap(){delete []heap;}  //析构函数
        int Size() const{return CurrentSize;}
        int Max(){
            if(CurrentSize==0) throw OutOfBounds();
            return heap[1];
              }
        MaxHeap& Insert(const int& x);
        MaxHeap& DeleteMax(int& x);
        void Initialize(int a[],int size,int ArraySize);
        void Deactivate(){heap=0;}

        int CurrentSize,MaxSize;
        int *heap;//元素数组
};



#endif // MAXHEAP_H
