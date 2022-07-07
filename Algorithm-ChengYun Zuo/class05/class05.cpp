//
//  class05.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/7/4.
//

#include "class05.hpp"


//=====二叉树的遍历=====
/*
        01
       /  \
      2    3
     / \  / \
    4   56   7
 
 1. 二叉树的递归序
 -> 递归序：1-2-4-4-4-2-5-5-5-2-1-3-6-6-6-3-7-7-7-3-1
 2. 二叉树的先中后序遍历
    1）先序（头左右）：对于递归序第一次访问就打印，二三两次访问什么也不干
    2）中序（左头右）：对于递归序第二次访问才打印，一三两次访问什么也不干
    3）后序（左右头）：对于递归序第三次访问才打印，一二两次访问什么也不干
 */

//二叉树遍历的递归版本
//先序
void PreInPosTraversal::preOrderRecur(binaryNode *head){
    if (head == nullptr) {
        return;
    }else {
        cout<<head->value<<" ";
        preOrderRecur(head->left);
        preOrderRecur(head->right);
    }
}

//中序
void PreInPosTraversal::inOrderRecur(binaryNode *head){
    if (head == nullptr) {
        return;
    }else {
        inOrderRecur(head->left);
        cout<<head->value<<" ";
        inOrderRecur(head->right);
    }
}

//后序
void PreInPosTraversal::posOrderRecur(binaryNode *head){
    if (head == nullptr) {
        return;
    }else {
        posOrderRecur(head->left);
        posOrderRecur(head->right);
        cout<<head->value<<" ";
    }
}

//二叉树遍历的非递归版本
//先序
void PreInPosTraversal::preOrderUnRecur(binaryNode* head){
    cout<<"pre-order: ";
    if (head) {
        stack<binaryNode*> helpStack;
        helpStack.push(head);
        while (!helpStack.empty()) {
            head = helpStack.top();
            helpStack.pop();
            cout<<head->value<<" ";
            if (head->right) {
                helpStack.push(head->right);
            }
            if (head->left) {
                helpStack.push(head->left);
            }
        }
    }
    cout<<endl;
}

//中序
void PreInPosTraversal::inOrderUnRecur(binaryNode *head){
    cout<<"in-order: ";
    if (head) {
        stack<binaryNode*> helpStack;
        while (!helpStack.empty() || head) {
            if (head) {
                helpStack.push(head);
                head = head->left;
            }else {
                head = helpStack.top();
                helpStack.pop();
                cout<<head->value<<" ";
                head = head->right;
            }
        }
    }
    cout<<endl;
}

//后序
//中序遍历先全部压栈，再出栈
void PreInPosTraversal::posOrderUnRecur1(binaryNode *head){
    cout<<"pos-order1: ";
    if (head) {
        stack<binaryNode*> s1;
        stack<binaryNode*> s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->left) {
                s1.push(head->left);
            }
            if (head->right) {
                s1.push(head->right);
            }
        }
        while (!s2.empty()) {
            cout<<s2.top()->value<<" ";
            s2.pop();
        }
    }
    cout<<endl;
}

void PreInPosTraversal::posOrderUnRecur2(binaryNode *head){
    cout<<"pos-order2: ";
    if (head) {
        stack<binaryNode*> helpStack;
        helpStack.push(head);
        binaryNode* cur = nullptr;
        while (!helpStack.empty()) {
            cur = helpStack.top();
            if (cur->left && head != cur->left && head != cur->right) {
                helpStack.push(cur->left);
            }else if (cur->right && head != cur->right) {
                helpStack.push(cur->right);
            }else {
                cout<<helpStack.top()->value<<" ";
                helpStack.pop();
                head = cur;
            }
        }
    }
    cout<<endl;
}

//打印二叉树（需修改。。。。）
void PrintBinaryTree::printTree(binaryNode* head){
    cout<<"Binary Tree: ";
    printInOrder(head, 0, "H", 17);
    cout<<endl;
}

void PrintBinaryTree::printInOrder(binaryNode* head, int height, string to, int len){
    if (head == nullptr) {
        return;
    }
    printInOrder(head->right, height + 1, "v", len);
    string val = to + to_string(head->value) + to;
    int lenM = val.size();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout<<getSpace(height * len)<<val;
    printInOrder(head->left, height + 1, "^", len);
}

string PrintBinaryTree::getSpace(int num){
    char space = ' ';
    stringbuf buf("", ios_base::in | ios_base::out | ios_base::ate);
    for (int i = 0; i < num; i++) {
        buf.sputc(space);
    }
    return buf.str();
}

//求二叉树宽度
int TreeMaxWidth::getMaxWidth(binaryNode *head){
    if (head == nullptr) {
        return 0;
    }
    int maxWidth = 0;
    int curWidth = 0;
    int curLevel = 0;
    unordered_map<binaryNode*, int> levelMap;
    levelMap.insert(make_pair(head, 1));
    queue<binaryNode*> helpQuque;
    helpQuque.push(head);
    binaryNode* node = nullptr;
    binaryNode* left = nullptr;
    binaryNode* right = nullptr;
    while (!helpQuque.empty()) {
        node = helpQuque.front();
        helpQuque.pop();
        left = node->left;
        right = node->right;
        if (left) {
            levelMap.insert(make_pair(left, levelMap[node] + 1));
            helpQuque.push(left);
        }
        if (right) {
            levelMap.insert(make_pair(right, levelMap[node] + 1));
            helpQuque.push(right);
        }
        if (levelMap[node] > curLevel) {
            curWidth = 0;
            curLevel = levelMap[node];
        }else {
            curWidth++;
        }
        maxWidth = max(maxWidth, curWidth);
    }
    return  maxWidth;
}

//二叉搜索树
int IsBST::preValue = INT_MIN;

bool IsBST::isBST1(binaryNode *head){
    if (head == nullptr) {
        return true;
    }
    bool isLeftBst = isBST1(head->left);
    if (!isLeftBst) {
        return false;
    }
    if (head->value <= preValue) {
        return false;
    }else {
        preValue = head->value;
    }
    return isBST1(head->right);
}

bool IsBST::isBST2(binaryNode *head){
    vector<binaryNode*> inOrderList;
    process(head, inOrderList);
    int preValue = INT_MIN;
    for(binaryNode* cur : inOrderList) {
        if (preValue > cur->value) {
            return false;
        }
        preValue = cur->value;
    }
    return true;
}

void IsBST::process(binaryNode* head, vector<binaryNode*>& inOrderList){
    if (head == nullptr) {
        return;
    }
    process(head->left, inOrderList);
    inOrderList.push_back(head);
    process(head->right, inOrderList);
}

bool IsBST::isBST3(binaryNode *head){
    if (head) {
        int preValue = INT_MIN;
        stack<binaryNode*> helpStack;
        while (!helpStack.empty() || head) {
            if (head) {
                helpStack.push(head);
                head = head->left;
            }else {
                head = helpStack.top();
                helpStack.pop();
                //======
                if (head->value <= preValue) {
                    return false;
                }else {
                    preValue = head->value;
                }
                //======
                head = head->right;
            }
        }
    }
    return true;
}

//完全二叉树
bool IsCBT::isCBT(binaryNode *head){
    if (head == nullptr) {
        return true;
    }
    queue<binaryNode*> helpQueue;
    bool leaf = false;
    binaryNode* left = nullptr;
    binaryNode* right = nullptr;
    helpQueue.push(head);
    while (!helpQueue.empty()) {
        head = helpQueue.front();
        helpQueue.pop();
        left = head->left;
        right = head->right;
        if ((leaf && (left != nullptr || right != nullptr)) //表示leaf为true后，之后的节点均需为叶子结点
            || (left == nullptr && right != nullptr)) {
            return false;
        }
        if (left) {
            helpQueue.push(left);
        }
        if (right) {
            helpQueue.push(right);
        }else {
            leaf = true;
        }
    }
    return true;
}
