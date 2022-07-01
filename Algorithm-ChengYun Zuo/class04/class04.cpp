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
class SmallerEqualBigger{
public:
    //
};
