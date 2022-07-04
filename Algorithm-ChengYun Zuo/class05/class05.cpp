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
