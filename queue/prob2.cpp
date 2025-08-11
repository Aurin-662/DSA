#include<bits/stdc++.h>
using namespace std;

int main(){
        vector<int> v={1,2,3,4,5};
        int n=v.size();
        int mid=n/2;
        vector<int> v2;
        v2.assign(v.begin(),v.begin()+mid);
        cout<<v2.front();

    return 0;
}