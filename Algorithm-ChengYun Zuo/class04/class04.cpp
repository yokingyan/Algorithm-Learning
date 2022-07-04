//
//  class04.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/28.
//

#include "class04.hpp"

//=====hash表和顺序表=====
void HashAndTree::testForUnorderedSet(){
    cout<<"============1============="<<endl;
    cout<<"==test for unordered_set=="<<endl;
    cout<<"=========================="<<endl;
    cout<<endl;
    // hashSet1的key是基础类型->int类型
    unordered_set<int> hashSet1;
    hashSet1.insert(3);
    hashSet1.insert(4);
    hashSet1.insert(5);
    hashSet1.insert(1);
    hashSet1.insert(2);
    HashAndTree::printSet(hashSet1);
    auto res1 = hashSet1.find(3);
    HashAndTree::printSetResult(hashSet1 ,res1);
    auto res2 = hashSet1.find(1);
    HashAndTree::printSetResult(hashSet1, res2);
    hashSet1.erase(3);
    auto res3 = hashSet1.find(3);
    HashAndTree::printSetResult(hashSet1, res3);
    cout<<endl;
    //hashSet2的key是非基础类型->Node类型（c++ 不知道行不行。。。。）
//    Test stu1("yan liang", 21, 1);
//    Test stu2("wang bo", 24, 4);
    //（to be continue....）
}

void HashAndTree::testForUnorderedMap(){
    
    cout<<"============2============="<<endl;
    cout<<"==test for unordered_map=="<<endl;
    cout<<"=========================="<<endl;
    cout<<endl;
    //hashMap1的key是基础类型->String类型
    unordered_map<string, int> hashMap1;
    string str1 = "key1";
    string str2 = "key2";
    hashMap1.insert(make_pair(str1, 001));
    hashMap1.insert(make_pair(str2, 002));
    HashAndTree::printMap(hashMap1);
    auto ans1 = hashMap1.find(str2);
    HashAndTree::printMapResult(hashMap1, ans1);
    hashMap1.erase(str1);
    HashAndTree::printMap(hashMap1);
    hashMap1.insert(make_pair("key3", 003));
    //hashMap2的key是非基础类型->Node类型(to be continue...)
    cout<<endl;
}

void HashAndTree::testForOrderedSet(){
    
    cout<<"============3============="<<endl;
    cout<<"===test for ordered_set==="<<endl;
    cout<<"=========================="<<endl;
    cout<<endl;
    //treeSet1的key是基础类型->int类型
    set<int> treeSet1;
    treeSet1.insert(2);
    treeSet1.insert(1);
    treeSet1.insert(5);
    treeSet1.insert(4);
    treeSet1.insert(3);
    HashAndTree::printSet(treeSet1);
    treeSet1.erase(2);
    HashAndTree::printSet(treeSet1);
    cout<<endl;
    //treeSet2的key是非基础类型->Test类型
    Test test1("yan", 21, 001);
    Test test2("wang", 23, 002);
    Test test3("he", 26, 003);
    set<Test> test;
    test.insert(test1);
    test.insert(test2);
    test.insert(test3);
    Test::printTest(test);
    test.erase(test2);
    Test::printTest(test);
    
}

void HashAndTree::testForOrderedMap(){
    cout<<"============4============="<<endl;
    cout<<"===test for ordered_map==="<<endl;
    cout<<"=========================="<<endl;
    cout<<endl;
    //-----treeMap1的key是基础类型->int类型-----
    map<string, int> treeMap1;
    treeMap1.insert(make_pair("one", 111));
    treeMap1.insert(make_pair("two", 222));
    treeMap1.insert(make_pair("three", 333));
    treeMap1.insert(make_pair("four", 444));
    treeMap1.insert(make_pair("five", 555));
    HashAndTree::printMap(treeMap1);
    //使用系统的compare谓词
    map<string, int, greater<string>> treeMap2;
    treeMap2.insert(make_pair("one", 111));
    treeMap2.insert(make_pair("two", 222));
    treeMap2.insert(make_pair("three", 333));
    treeMap2.insert(make_pair("four", 444));
    treeMap2.insert(make_pair("five", 555));
    HashAndTree::printMap(treeMap2);
    //自定义compare谓词
    map<string, int, CmpByKeyLength> treeMap3;
    treeMap3.insert(make_pair("oooooo", 111));
    treeMap3.insert(make_pair("tw", 222));
    treeMap3.insert(make_pair("thr", 333));
    treeMap3.insert(make_pair("four", 444));
    treeMap3.insert(make_pair("fivee", 555));
    //
    cout<<"content: \n";
    for(auto&p : treeMap3){
        cout<<" "<<p.first<<" => "<<p.second<<"\n";
    }
    //
    //compare by value/need to use a vector
    
    //-----treeMap4的key是非基础类型->StudentTestForClass04类型-----
    map<StudentTestForClass04, int> treeMap4;
    StudentTestForClass04 stu1("yanliangliang", 3);
    StudentTestForClass04 stu2("wangaobo", 2);
    StudentTestForClass04 stu3("hezhaopu", 1);
    treeMap4.insert(make_pair(stu1, 100));
    treeMap4.insert(make_pair(stu2, 90));
    treeMap4.insert(make_pair(stu3, 60));
    //
    cout<<"content: \n";
    for(auto&p : treeMap4){
        cout<<"Name: "<<p.first.name<<" => "<<p.second<<"\n";
    }
    //
}

template<typename T1, typename T2>
void HashAndTree::printSetResult(T1 dataset, T2 result){
    cout<<"-find the value which you insert just now"<<endl;
    if(dataset.empty()){
        cout<<"The dataset is empty...."<<endl;
        return;
    };
    if (result != dataset.end()) {
        cout<<"The value "<<*result<<" is in the dataset"<<endl;
    }else{
        cout<<"The value is not in the dataset"<<endl;
    }
}

template<typename T>
void HashAndTree::printSet(T dataset){
    cout<<"content: \n";
    for(auto it = dataset.begin(); it != dataset.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T1, typename T2>
void HashAndTree::printMap(unordered_map<T1, T2> m){
    cout<<"content: \n";
    for(auto&p : m){
        cout<<" "<<p.first<<" => "<<p.second<<"\n";
    }
}

template<typename T1, typename T2>
void HashAndTree::printMap(map<T1, T2> m){
    cout<<"content: \n";
    for(auto&p : m){
        cout<<" "<<p.first<<" => "<<p.second<<"\n";
    }
}

template<typename T1, typename T2>
void HashAndTree::printMap(map<T1, T2, greater<string>> m){
    cout<<"content: \n";
    for(auto&p : m){
        cout<<" "<<p.first<<" => "<<p.second<<"\n";
    }
}

template<typename T1, typename T2>
void HashAndTree::printMapResult(T1 dataset, T2 result){
    cout<<"-find the value which you insert just now"<<endl;
    if(dataset.empty()){
        cout<<"The dataset is empty...."<<endl;
        return;
    };
    if (result != dataset.end()) {
        cout<<"The key "<<result->first<<" is "<<result->second<<" in the dataset"<<endl;
    }else{
        cout<<"The value is not in the dataset"<<endl;
    }
}

bool Test::operator<(const Test& test) const{
    if(this->id == test.id){
        return false;
    }else{
        if(this->age != test.age){
            return this->age > test.age;
        }else{
            return this->id > test.id;
        }
    }
}

template<typename T>
void Test::printTest(T test){
    for(auto it : test){
        cout<<"Name: "<<it.name<<", id: "<<it.id<<", age: "<<it.age<<endl;
    }
    cout<<endl;
}

bool StudentTestForClass04::operator<(const StudentTestForClass04 &stu)const{
    if(this->id < stu.id){
        return true;
    }
    if(this->id == stu.id){
        return this->name.compare(stu.name);
    }
    return false;
}

//=====链表=====
//print Linked list
void ReverseList::printLinkedList(Node* head){
    cout<<"Linked List: ";
    while (head != NULL) {
        cout<<head->val<<" => ";
        head = head->next;
    }
    cout<<"null"<<endl;
}

void ReverseList::printDoubleLinkedList(DoubleNode *head){
    cout<<"Double Linked List: ";
    DoubleNode* end = nullptr;
    while (head) {
        cout<<head->val<<" => ";
        end = head;
        head = head->next;
    }
    cout<<"null"<<" | ";
    
    while (end) {
        cout<<end->val<<" => ";
        end = end->pre;
    }
    cout<<"null"<<endl;
}

//反转单链表
/*
    1->2->3->4->5->null ==> null<-1<-2<-3<-4<-5
 */
Node* ReverseList::reverseList(Node* head){
    Node* next = nullptr;
    Node* pre = nullptr;
    //Node* cur = head;
    
    while (head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

//反转双链表
DoubleNode* ReverseList::reverseList(DoubleNode* head){
    DoubleNode* pre = nullptr;
    DoubleNode* next = nullptr;
    
    while (head) {
        next = head->next;
        head->next = pre;
        head->pre = next;
        pre = head;
        head = next;
    }
    return pre;
}

//打印公共部分
void PrintCommonPart::printCommonPart(Node* head1, Node* head2){
    cout<<"Common Part: ";
    while (head1 && head2) {
        if(head1->val < head2->val){
            head1 = head1->next;
        }else if(head1->val > head2->val){
            head2 = head2->next;
        }else{
            cout<<head1->val<<" => ";
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    cout<<"null"<<endl;
}

//回文链表
//need n extra space
bool IsPalindromeList::isPalindromeList1(Node* head){
    stack<Node*> helpStack;
    Node* cur = head;
    //进栈
    while (cur) {
        helpStack.push(cur);
        cur = cur->next;
    }
    while (head) {
        if(head->val != helpStack.top()->val){
            return false;
        }
        helpStack.pop();
        head = head->next;
    }
    return true;
}

//need n/2 extra space
bool IsPalindromeList::isPalindromeList2(Node* head){
    if(head == nullptr || head->next == nullptr){
        return true;
    }
    Node* right = head->next;
    Node* cur = head;
    //提取链表后半部分
    while (cur->next && cur->next->next) { //find mid node
        right = right->next;
        cur = cur->next->next;
    }
    stack<Node*> helper;
    while (right) {
        helper.push(right);
        right = right->next;
    }
    while (!helper.empty()) {
        if (head->val != helper.top()->val) {
            return false;
        }
        helper.pop();
        head = head->next;
    }
    return true;
}

bool IsPalindromeList::isPalindromeList3(Node* head){
    if (!head || !head->next) {
        return true;
    }
    Node* n1 = head;
    Node* n2 = head;
    while (n2->next && n2->next->next) { //find mid node
        n1 = n1->next;
        n2 = n2->next->next;
    }
    //reverse the right part
    n2 = n1->next;
    n1->next = nullptr;//mid->next = null
    Node* n3 = nullptr;
    while (n2) {       // right part convert
        n3 = n2->next; //n3 -> save next node
        n2->next = n1; //next of right node convert
        n1 = n2;    //move
        n2 = n3;    //move
    }//rusult: n1->last node
    n3 = n1;  //n3 -> save the last node
    n2 = head; // n2 -> save the first node
    bool res = true;
    while (n1 && n2) { // check palindrome
        if(n1->val != n2->val){
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    //recover the linked list
    n1 = n3->next;
    n3->next = nullptr;
    while (n1) {
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
}

//SmallerEqualBigger
//机试写法
Node* SmallerEqualBigger::listPartition1(Node*& head, int pivot){
    //
    if (head == nullptr) {
        return head;
    }
    //find the length of list
    Node* cur = head;
    int i = 0;
    while (cur) {
        i++;
        cur = cur->next;
    }
    vector<Node*> nodeArr(i, 0);
    i = 0;
    cur = head;
    //convert to arr
    for (i = 0; i < nodeArr.size(); i++) {
        nodeArr[i] = cur;
        cur = cur->next;
    }
    //partition in arr
    arrPartition(nodeArr, pivot);
    //convert to linkedlist
    for (i = 1; i != nodeArr.size(); i++) {
        nodeArr[i - 1]->next = nodeArr[i];
    }
    nodeArr[i - 1]->next = nullptr;
    return nodeArr[0];
}

void SmallerEqualBigger::arrPartition(vector<Node*>& nodeArr, int pivot){
    int small = -1;
    int big = nodeArr.size();
    int index = 0;
    while (index != big) {
        if (nodeArr[index]->val < pivot) {
            swap(nodeArr[++small], nodeArr[index++]);
        }else if (nodeArr[index]->val == pivot) {
            index++;
        }else{
            swap(nodeArr[--big], nodeArr[index++]);
        }
    }
}

//面试写法
Node* SmallerEqualBigger::listPartition2(Node *head, int pivot){
    // 6个指针
    Node* smallHead = nullptr;
    Node* smallTail = nullptr;
    Node* equalHead = nullptr;
    Node* equalTail = nullptr;
    Node* bigHead = nullptr;
    Node* bigTail = nullptr;
    //save next node
    Node* next = nullptr;
    // every node distributed to three lists
    while (head) {
        next = head->next;
        head->next = nullptr;
        if (head->val < pivot) {
            if (smallHead == nullptr) {
                smallHead = head;
                smallTail = head;
            }else{
                smallTail->next = head;
                smallTail = head;
            }
        }else if (head->val == pivot) {
            if (equalHead == nullptr) {
                equalHead = head;
                equalTail = head;
            }else{
                equalTail->next = head;
                equalTail = head;
            }
        }else {
            if (bigHead == nullptr) {
                bigHead = head;
                bigTail = head;
            }else {
                bigTail->next = head;
                bigTail = head;
            }
        }
        head = next;
    }
    //small and equal reconnect
    if (smallTail) {
        smallTail->next = equalHead;
        equalTail = equalTail == nullptr ? smallTail : equalTail;
    }
    if (equalTail) {
        equalTail->next = bigHead;
    }
    return smallHead ? smallHead : equalHead ? equalHead : bigHead;
}

//CopyListWithRandom
void CopyListWithRandom::printRandLinkedList(RandomNode *head){
    RandomNode* cur = head;
    cout<<"Order: ";
    while (cur) {
        cout<<cur->val<<" => ";
        cur = cur->next;
    }
    cout<<"null"<<endl;
    cur = head;
    cout<<"Rand: ";
    while (cur) {
        if (cur->rand) {
            cout<<cur->val<<" => "<<cur->rand->val<<" // ";
        }else{
            cout<<"- ";
        }
        cur = cur->next;
    }
    cout<<endl;
}

//copy with hashMap
RandomNode* CopyListWithRandom::copyListWithRandom1(RandomNode *head){
    unordered_map<RandomNode*, RandomNode*> helpMap;
    RandomNode* cur = head;
    while (cur) {
        helpMap.insert(make_pair(cur, new RandomNode(cur->val)));
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        helpMap[cur]->next = helpMap[cur->next];
        helpMap[cur]->rand = helpMap[cur->rand];
        cur = cur->next;
    }
    return helpMap[head];
}

//unuse hashMap(xiu!!!)
RandomNode* CopyListWithRandom::copyListWithRandom2(RandomNode *head){
    if (head == nullptr) {
        return head;
    }
    RandomNode* cur = head;
    RandomNode* next = nullptr;
    // copy node and link to every node
    //1 -> 2 ==> 1 -> 1` -> 2
    while (cur) {
        next = cur->next;
        cur->next = new RandomNode(cur->val);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    RandomNode* curCopy = nullptr;
    // set copy node rand
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand ? cur->rand->next : nullptr;//太妙了
        cur = next;
    }
    //split
    RandomNode* res = head->next;
    cur = head;
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->next = next ? next->next : nullptr;
        cur = next;
    }
    return res;
}

//FindFirstIntersectNode
//怎么判断有环还是无环，有环怎么找出第一个无环节点。
/*
 1. 两个链表都无环
 2. 一个有环一个无环（不可能相交）
 3. 两个都有环
    1) 不共用环->不相交
    2) 相交点在环外
    3) 相交点在环上
 */

//find the first loop node
Node* FindFirstIntersectNode::getLoopNode(Node *head){
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }
    //faster and slower pointer
    Node* n1 = head->next; //slower
    Node* n2 = head->next->next; //faster
    while (n1 != n2) {
        if (n1->next == nullptr || n2->next->next == nullptr) {
            return nullptr;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    //keep slower pointer, let faster pointer to head
    n2 = head; // n2 -> walk again from head
    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

//无环情况
Node* FindFirstIntersectNode::noLoop(Node *head1, Node *head2){
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* cur1 = head1;
    Node* cur2 = head2;
    int n = 0;
    //caculate the distance of head1 and head2
    while (cur1->next) {
        n++;
        cur1 = cur1->next;
    }
    while (cur2->next) {
        n--;
        cur2 = cur2->next;
    }
    //cur1 and cur2 point their tail
    if (cur1 != cur2) {
        return nullptr;
    }
    //let longer linkedlist walk first
    //let cur1 be the longer list and cur2 the shorter
    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;
    n = abs(n);
    while (n) {
        n--;
        cur1 = cur1->next;
    }
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

//均有环情况
Node* FindFirstIntersectNode::bothLoop(Node *head1, Node *loop1, Node *head2, Node *loop2){
    Node* cur1 = nullptr;
    Node* cur2 = nullptr;
    //情况1:交点在环外
    //just like no loop
    if (loop1 == loop2) {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }else {//情况2:交点在环内
        cur1 = loop1->next;
        while (cur1 != loop1) {
            if (cur1 == loop2) {
                return loop1;
            }
            cur1 = cur1->next;
        }
        return nullptr;
    }
}

//mian function
Node* FindFirstIntersectNode::getIntersectNode(Node *head1, Node *head2){
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* loop1 = getLoopNode(head1);
    Node* loop2 = getLoopNode(head2);
    if (loop1 == nullptr && loop2 == nullptr) {
        return noLoop(head1, head2);
    }else if (loop1 && loop2) {
        return bothLoop(head1, loop1, head2, loop2);
    }else {
        return nullptr;
    }
}
