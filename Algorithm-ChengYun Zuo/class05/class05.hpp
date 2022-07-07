//
//  class05.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/7/4.
//

#ifndef class05_hpp
#define class05_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <queue>


using namespace std;

//二叉树数据结构
struct binaryNode{
    int value;
    binaryNode* left;
    binaryNode* right;
    
    binaryNode(int value):value(value), left(nullptr), right(nullptr) {}
};

//二叉树的遍历
class PreInPosTraversal{
public:
    //
    static void preOrderRecur(binaryNode* head);
    static void inOrderRecur(binaryNode* head);
    static void posOrderRecur(binaryNode* head);
    static void preOrderUnRecur(binaryNode* head);
    static void inOrderUnRecur(binaryNode* head);
    static void posOrderUnRecur1(binaryNode* head);
    static void posOrderUnRecur2(binaryNode* head);
};

//打印二叉树
class PrintBinaryTree{
public:
    static void printTree(binaryNode* head);
    static void printInOrder(binaryNode* head, int height, string to, int len);
    static string getSpace(int num);
};

//TreeMaxWidth
class TreeMaxWidth{
public:
    static int getMaxWidth(binaryNode* head);
};

//IsBST
class IsBST{
public:
    static int preValue;
    static bool isBST1(binaryNode* head);
    static bool isBST2(binaryNode* head);
    static void process(binaryNode* head, vector<binaryNode*>& inOrderList);
    static bool isBST3(binaryNode* head);
    
};

class IsCBT{
public:
    static bool isCBT(binaryNode* head);
};




#endif /* class05_hpp */
