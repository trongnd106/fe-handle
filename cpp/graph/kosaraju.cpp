// #include<bits/stdc++.h>
// using namespace std;

// using ll = long long;

// const int maxn = 1001;
// int n,m;
// vector<int> adj[maxn], r_adj[maxn];
// bool used[maxn];
// stack<int> st;

// void inp(){
//     cin >> n >> m;
//      for(int i = 0; i < m; i++){
//         int x,y; cin >> x >> y;
//         adj[x].push_back(y);
//         r_adj[y].push_back(x);
//      }
// }

// void dfs1(int u){
//     used[u] = true;
//     for(int v : adj[u]){
//         if(!used[v]){
//             dfs1(v);
//         }
//     }
//     // da duyet xong u
//     st.push(u);
// }

// void dfs2(int u){
//     used[u] = true;
//     cout << u << " ";
//     for(int v : r_adj[u]){
//         if(!used[v]){
//             dfs2(v);
//         }
//     }
// }

// void SCC(){
//     memset(used, false, sizeof(used));
//     for(int i = 1; i <= n; i++){
//         if(!used[i]){
//             dfs1(i);
//         }
//     }
//     cout << endl;
//     memset(used, false, sizeof(used));
//     while(!st.empty()){
//         int u = st.top(); st.pop();
//         if(!used[u]){
//             dfs2(u);
//             cout << endl;
//         }
//     }
// }

// int main(){
//     inp();
//     SCC();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
vector<int> adj[maxn], r_adj[maxn];
bool used[maxn];

void inp(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

void dfs1(int u){
    used[u] = true;
    for(int v : adj[u]){
        if(!used[v]){
            dfs1(v);
        }
    }
}

void dfs2(int u, vector<bool>& inComponent){
    used[u] = true;
    inComponent[u] = true;

    for(int v : r_adj[u]){
        if(!used[v]){
            dfs2(v, inComponent);
        }
    }
}

void printSCC(int queryVertex){
    memset(used, false, sizeof(used));
    dfs1(queryVertex);

    vector<bool> inComponent(maxn, false);

    memset(used, false, sizeof(used));
    dfs2(queryVertex, inComponent);

    cout << "Cac dinh cung thanh phan lien thong manh voi " << queryVertex << " la: ";
    for(int i = 1; i <= 1000; i++) {
        if(inComponent[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    inp();
    int queryVertex;
    cin >> queryVertex;
    printSCC(queryVertex);
    return 0;
}
