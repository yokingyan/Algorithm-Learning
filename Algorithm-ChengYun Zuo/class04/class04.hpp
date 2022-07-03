//
//  class04.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/28.
//

#ifndef class04_hpp
#define class04_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>


using namespace std;

//=====hash表和顺序表=====
class HashAndTree{
public:
    //Test for unordered_set
    static void testForUnorderedSet();
    static void testForUnorderedMap();
    static void testForOrderedSet();
    static void testForOrderedMap();
    
    template<typename T1, typename T2>
    static void printSetResult(T1 dataset, T2 result);
    
    template<typename T>
    static void printSet(T dataset);
    
    template<typename T1, typename T2>
    static void printMap(unordered_map<T1, T2>);
    
    template<typename T1, typename T2>
    static void printMap(map<T1, T2> m);
    
    template<typename T1, typename T2>
    static void printMap(map<T1, T2, greater<string>> m);
    
    template<typename T1, typename T2>
    static void printMapResult(T1 dataset, T2 result);
};

//special data struct
struct Test{
    string name;
    int age;
    int id;
    Test(string name, int age, int id):name(name), age(age), id(id) {}
    
    //运算符<重载
    bool operator<(const Test& test) const;
    
    template<typename T>
    static void printTest(T test);
};

//compare谓词 by key
struct CmpByKeyLength{
    bool operator() (const string& key1, const string& key2) const{
        return key1.length() > key2.length();
    }
};

//compare谓词 by value
typedef pair<string, int> PAIR;

//bool cmpByValue(const PAIR& v1, const PAIR& v2) {
//    return v1.second < v2.second;
//}

struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs){
        return lhs.second < rhs.second;
    };
};

class StudentTestForClass04{
public:
    string name;
    int id;
    
    StudentTestForClass04(string name, int id):name(name), id(id) {}
    
    bool operator < (StudentTestForClass04 const& stu) const;//重载
    //仿函数
    //bool operator() (StudentTestForClass04 const& stu1, StudentTestForClass04 const& stu2) const;
};

//=====链表=====

struct Node{
    int val;
    Node* next;
    
    Node(int val):val(val), next(NULL) {}
};

struct DoubleNode{
    int val;
    DoubleNode* pre;
    DoubleNode* next;
    
    DoubleNode(int val):val(val), pre(NULL), next(NULL) {}
};


class ReverseList{
public:
    //print
    static void printLinkedList(Node* head);
    static void printDoubleLinkedList(DoubleNode* head);
    //reverse
    static Node* reverseList(Node* head);
    static DoubleNode* reverseList(DoubleNode* head);
    
};

class PrintCommonPart{
public:
    static void printCommonPart(Node* head1, Node* head2);
};

class IsPalindromeList{
public:
    static bool isPalindromeList1(Node* head);
    static bool isPalindromeList2(Node* head);
    static bool isPalindromeList3(Node* head);
};

class SmallerEqualBigger{
public:
    //机试写法
    static Node* listPartition1(Node*& head, int pivot);
    static void arrPartition(vector<Node*>& nodeArr, int pivot);
    //面试写法
    static Node* listPartition2(Node* head, int pivot);
};

struct RandomNode{
    int val;
    RandomNode* next;
    RandomNode* rand;
    
    RandomNode(int val): val(val), next(nullptr), rand(nullptr) {}
};

class CopyListWithRandom{
public:
    static RandomNode* copyListWithRandom1(RandomNode* head);
    static RandomNode* copyListWithRandom2(RandomNode* head);
    
    static void printRandLinkedList(RandomNode* head);
};

class FindFirstIntersectNode{
public:
    static Node* getIntersectNode(Node* head1, Node* head2);
    static Node* getLoopNode(Node* head);
    static Node* noLoop(Node* head1, Node* head2);
    static Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2);
};


#endif /* class04_hpp */
