//
//  class01.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/17.
//

#include "class01.hpp"
#include <vector>
#include <algorithm>


using namespace std;


void printArr(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectSort(vector<int>& arr){
    if(arr.size() < 2){
        return;
    }else{
        for(int i = 0;i < arr.size() - 1;i++){
            int minIndex = i;
            for(int j = i + 1;j < arr.size();j++){
                //minIndex = arr[j] < arr[i] : j ? minIndex;
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }else{
                    minIndex = minIndex;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
}

void bubbleSort(vector<int>& arr){
    if(arr.size() < 2){
        return;
    }else{
        for(int i = arr.size()-1;i > 0;i--){
            for(int j = 0;j < arr.size() - 1;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
}

void printOddTimesNum1(vector<int> arr){
    int eor = 0;
    for(int cur : arr){
        eor ^= cur;
    }
    cout<<eor<<endl;
}

void printOddTimesNum2(vector<int> arr){
    int eor = 0;
    for(int curNum : arr){
        eor ^= curNum;
    }
    //eor = a^b
    int rightOne = eor & (~eor + 1);
    
    int onlyOne = 0;
    for(int cur : arr){
        if((cur & rightOne) == 0){
            onlyOne ^= cur;
        }
    }
    cout<<"the first number: "<<onlyOne<<" "<<"the second number: "<<(eor^onlyOne)<<endl;;
}

void insertSort(vector<int>& arr){
    for(int i = 1;i < arr.size();i++){
        for(int j = i-1;j >= 0 && arr[j] > arr[j+1];j--){
            swap(arr[j], arr[j+1]);
        }
    }
}

bool BSExist(vector<int> sortedArr, int num){
    if(sortedArr.size() == 0){
        return false;
    }else{
        int L = 0;
        int R = sortedArr.size() - 1;
        int mid = 0;
        while (L < R) {
            mid = L + ((R - L) >> 1);
            if(sortedArr[mid] == num){
                return true;
            }else if (sortedArr[mid] > num){
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        return sortedArr[L] == num;
    }
}

int BSNearLeft(vector<int> sortedArr, int value){
    // 在arr上，找满足>=value的最左位置
    int L = 0;
    int R = sortedArr.size() - 1;
    int index = -1;
    while(L < R){
        int mid = L + ((R - L) >> 1);
        if(sortedArr[mid] >= value){
            index = mid;
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    return index;
}

int FindOneLessValueIndex(vector<int> arr){
    if(arr.size() == 0){
        return -1;
    }else if (arr.size() == 1 || arr[0] < arr[1]){
        return 0;
    }else if (arr[arr.size()-1] < arr[arr.size()-2]){
        return arr.size()-1;
    }else{
        int left = 1;
        int right = arr.size()-2;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if(arr[mid] > arr[mid-1]){
                right = mid - 1;
            }else if (arr[mid] > arr[mid+1]){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return left;
    }
}

int process(vector<int> arr, int left, int right){
    if(left == right){//base case
        return arr[left];
    }else{
        int mid = left + ((right-left)>>1);
        int leftMax = process(arr, left, mid);
        int rightMax = process(arr, mid+1, right);
        return max(leftMax, rightMax);
    }
}

int getMax(vector<int> arr){
    return process(arr, 0, arr.size()-1);
}



