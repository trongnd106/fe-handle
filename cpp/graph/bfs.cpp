#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void inp(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x : adj[v]){
            if (!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    inp();
    bfs(1);
    return 0;
}

// 10 11
// 1 2 
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9

/*
procedure bfs(G,s):
    input: G = (V,E) có hướng hoặc vô hướng, 1 đỉnh s thuộc V
    output: Với mỗi đỉnh u đến được từ s:
        dist(u) = khoảng cách từ s tới u

for all v thuộc V:
    dist(u) = vô cùng
dist(s) = 0
Q = [s]                             // hàng đợi Q chỉ chứa s
while Q khác rỗng:
    u = eject(Q)                    // loại bỏ u khỏi hàng đợi
    for all edges (u,v) thuộc E:
        if dist(v) = vô cùng:
            inject(Q,v)             // thêm v vào hàng đợi
            dist(v) = dist(u) + 1 
*/




/*
procedure dijkstra(G,l,s)
    input: đồ thị G = (V,E) có hướng hoặc vô hướng;
            độ dài các cạnh {le, e thuộc E}; đỉnh s thuộc V 
    output: với mỗi đỉnh u đến được từ s 
            dist(u) = khoảng cách từ s tới u

for all u thuộc V:
    dist(u) = inf
    prev(u) = nil       // đỉnh trước u trong đường đi ngắn nhất
dist(s) = 0
H = makequeue(V)       // dùng các giá trị dist làm khoá
while H khác rỗng:
    u = deletemin(H);
    for all edges (u,v) thuộc E:
        if dist(v) > dist(u) + l(u,v):
            dist(v) = dist(u) + l(u,v)
            prev(v) = u           //đỉnh trước v là u 
            decreasekey(H,v)
*/

/*
procedure shortest-paths(G,l,s)
Input: đồ thị có hướng G = (V,E);
       độ dài các cạnh {le: e thuộc E}
       mà không có chu trình âm;
       đỉnh s thuộc V
Output: Với mỗi đỉnh u đến được từ s,
    dist(u) = khoảng cách từ s tới u.

for all u thuộc V:
    dist(u) = inf 
    prev(u) = nil

dist(s) = 0
repeat |V| - 1 times:
    for all edges e thuộc E:
        update(e)
*/

        