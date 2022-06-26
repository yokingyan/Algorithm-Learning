//
//  class02.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/18.
//

#ifndef class02_hpp
#define class02_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class MergeSort{
public:
    static void mergeSort(vector<int>& arr);
    static void mergeSort(vector<int>& arr, int l, int r);
    static void merge(vector<int>& arr, int l, int m, int r);
};

class SmallSum{
public:
    static int smallSum(vector<int>& arr);
    static int mergeSort(vector<int>& arr, int l, int r);
    static int merge(vector<int>& arr, int l, int m, int r);
};

class NetherlandsFlag{
public:
    static vector<int> partition(vector<int>& arr, int l, int r, int p);
};

class QuickSort{
public:
    static void quickSort(vector<int> &arr, int L, int R);
    static vector<int> partition(vector<int> &arr, int L, int R);
};

//堆排序
/*
 @@完全二叉树
 1.i位置 左孩子-2*i+1 右孩子-2*i+2 父-（i-1）/2
 @@堆
 1.
 大根/顶堆-每一颗子树最大值都是头节点的值
 小根/顶堆-每一颗子树最小值都是头节点的值
 2.
 优先级队列结构就是堆结构
 */
class HeapSort{
public:
    static void heapInsert(vector<int>& arr, int index);
    static void heapify(vector<int>& arr, int index, int heapSize);
    static void heapSort(vector<int>& arr);
};

//堆排序扩展题目
class SortArrayDistanceLessK{
public:
    //c++ 默认大根堆
    static void sortArrayDistanceLessK(vector<int>& arr, int k);
};


#endif /* class02_hpp */
