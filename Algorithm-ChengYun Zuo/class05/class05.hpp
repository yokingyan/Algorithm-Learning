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
#include <unordered_set>
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

//判断是否为满二叉树
class Info{
public:
    int height;
    int nodeNum;
    
    Info(int height, int nodeNum):height(height), nodeNum(nodeNum) {}
    
    static bool isFull(binaryNode* head);
    static Info process(binaryNode* head);
};

//判断是否为平衡二叉树
class IsBalancedTree{
public:
    bool isB;
    int height;
    
    IsBalancedTree(bool isB, int height):isB(isB), height(height) {};
    
    static bool isBalanced(binaryNode* head);
    static IsBalancedTree process(binaryNode* head);
};

//给定两个二叉树节点node1和node2，找到他们的最低公共祖先节点
class LowestCommonAncestor{
public:
    static binaryNode* lowestCommonAncestor1(binaryNode* head, binaryNode* o1, binaryNode* o2);
    static void process(binaryNode* head, unordered_map<binaryNode*, binaryNode*>& fatherMap);
    static binaryNode* lowestCommonAncestor2(binaryNode* head, binaryNode* o1, binaryNode* o2);
};

//在二叉树中找到一个节点的后继节点
//SuccessorNode
struct nodeS{
    int value;
    nodeS* left;
    nodeS* right;
    nodeS* parent;
    
    nodeS(int value):value(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SuccessorNode{
public:
    static nodeS* getSuccessorNode(nodeS* head);
    static nodeS* getLeftMost(nodeS* head);
};

//SerializeAndReconstructTree
class SerializeAndReconstructTree{
public:
    
};

//PaperFolding
class PaperFolding{
public:
    
};


#endif /* class05_hpp */
