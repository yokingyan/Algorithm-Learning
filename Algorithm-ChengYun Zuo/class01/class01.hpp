//
//  class01.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/17.
//

#ifndef class01_hpp
#define class01_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


void selectSort(vector<int>& arr);
void printArr(vector<int> arr);
void bubbleSort(vector<int>& arr);
void printOddTimesNum1(vector<int> arr);
void printOddTimesNum2(vector<int> arr);
void insertSort(vector<int>& arr);
bool BSExist(vector<int> arr, int num);
int BSNearLeft(vector<int> arr, int value);
int FindOneLessValueIndex(vector<int> arr);
int process(vector<int> arr, int left, int right);
int getMax(vector<int> arr);

#endif /* class01_hpp */
