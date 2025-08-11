#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> l={10,20,30,40};
    // cout<<l.front()<<endl;
    // cout<<l.back()<<endl;
    // cout<<*l.begin()<<endl;
    // list<int> l2={100,200};
    l.push_back(99);
    l.push_front(88);
   
    list<int>l2;
    l2.assign(l.begin(),l.end());
    // l.push_front(33);
    //  l.pop_front();
    cout<<l2.front();


    return 0;
}