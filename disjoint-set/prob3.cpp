// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int leader[N];

// DSU find with path compression
int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

// Merge: a steps down, b becomes leader
void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    // যদি একই গ্রুপে থাকে, তাহলে কিছু করো না
    if (rootA == rootB) return;

    // a-এর গ্রুপকে b-এর গ্রুপে attach করো
    parent[rootA] = rootB;

    // নতুন গ্রুপের leader হবে b-এর গ্রুপের leader
    leader[rootA] = leader[rootB];
}

// a becomes leader of its group
void makeLeader(int a) {
    int root = find(a);
    leader[root] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialization: প্রতিটি soldier নিজেই তার parent এবং leader
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        leader[i] = i;
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        } else if (type == 2) {
            int a;
            cin >> a;
            makeLeader(a);
        } else if (type == 3) {
            int a;
            cin >> a;
            int root = find(a);
            cout << leader[root] << '\n';
        }
    }

    return 0;
}