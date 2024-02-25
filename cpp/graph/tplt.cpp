#include<bits/stdc++.h>
using namespace std;

// input : n,m
int n,m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
    visited[u] = true;
    cout << u << " ";
    for (int x : adj[u]){
        if (!visited[x]) 
            dfs(x);
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front(); q.pop();
        cout << v << " ";
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void connectedComponent(){
    int result = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            result++;
            cout << "Cac dinh thuoc thanh phan lien thong thu " << result << " :\n";
            dfs(i);  //bfs(i)
            cout << endl;
        }
    }
    if (result = 1)
        cout << "Do thi lien thong !\n";
    else cout << "Do thi khong lien thong !\n";
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connectedComponent(); 
    return 0;
}

// inp:
// 10 8 
// 1 2
// 2 3
// 2 4
// 3 6
// 3 7
// 6 7
// 5 8 
// 8 9

