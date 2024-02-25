// ĐƯỜNG ĐI TRÊN ĐỒ THỊ KHÔNG TRỌNG SỐ
/*
#include<bits/stdc++.h>

using namespace std;

int n,m,s,t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                parent[x] = v;
                bfs(x);
            }
        }
    }
}

void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);       // bfs(x)
    if(!visited[t]){
        cout << "Khong co duong di!";
    }
    else {
        vector<int> path;
        // bat dau tu dinh t
        while (t != s){
            path.push_back(t);
            // lan nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path){
            cout << x << " ";
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> t;
    Path(s,t);
    return 0;
}

// test
// 10 8 
// 1 2
// 2 3
// 2 4
// 3 6
// 3 7
// 6 7
// 5 8
// 8 9
// 1 7     => 1 2 3 6 7  (dfs)
//         => 1 2 3 7    (bfs)   -> tối ưu hơn.

*/





// ỨNG DỤNG BFS - DFS TRÊN LƯỚI Ô VUÔNG
// Bài toán 1: Đếm số thành phần liên thông trên lưới 

//     1 2 3 4 5 6
//   1 x x x . . .      
//   2 . . x . . .
//   3 . x x x x .         => 4 tp liên thông
//   4 . . . . . x
//   5 x x . x . x
//   6 x . x x . x

// Input:
//    6 6 
//    xxxooo
//    ooxooo
//    oxxxxo
//    ooooox
//    xxoxox
//    xoxxox
// Output: 4

#include<bits/stdc++.h>

using namespace std;

int n,m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void dfs(int i, int j){
    visited[i][j] = true;
    // duyet cac dinh ke
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 'x' && !visited[i1][j1]){
            dfs(i1,j1);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    }
    memset(visited, false, sizeof(visited));
    int count = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 'x' && visited[i][j] == false){
                dfs(i,j);
                count++;
            }
        }
    }
    cout << count << endl;
}

int main(){
    solve();
    return 0;
}