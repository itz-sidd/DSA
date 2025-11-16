#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>& s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return ; 
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return ;
}

void sort(stack<int>& s){
    if(s.size()==1){
        return ;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s,temp);
    return ;
}