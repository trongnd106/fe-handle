#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge{
    int u,v;
    int w;
};

const int maxn = 1000;
int n,m;
int parent[maxn], size[maxn];
vector<edge> ed;

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v){
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) 
        return false;
        
    if(size[a] > size[b]) swap(a,b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}

void inp(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y,w; 
        cin >> x >> y >> w;
        edge e; e.u = x; e.v = y; e.w = w;
          // edge e = edge(x,y,w);
        ed.push_back(e);
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    // tạo cây khung cực tiểu rỗng
    vector<edge> mst;
    int d = 0;    // trọng số
    sort(ed.begin(), ed.end(), cmp);
    // lặp
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        edge e = ed[i];
        if(Union(e.u, e.v)){    // nếu gộp được ? (ko tạo chu trình)
            mst.push_back(e);
            d += e.w;    // tăng trọng số
        }
    }
    // return kết quả
    if (mst.size() != n - 1)
        cout << "Do thi khong lien thong!" << endl;
    else {
        cout << "MST: " << d << endl;
        for(auto it : mst){
            cout << it.u << " " << it.v << " " << it.w << endl;
         }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    inp();
    make_set();
    kruskal();
    return 0;
}