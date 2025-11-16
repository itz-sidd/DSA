#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s,int ele){
    if(s.size()==0){
        s.push(ele);
        return ;
    }
    int temp = s.top();
    s.pop();
    insert(s,ele);
    s.push(temp);
    return ;
}

void reverse(stack<int> &s){
    if(s.size()==1){
        return ;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
    return ;
}