#include<iostream>
#include<vector>
#include<set>
#include<cstring>

using namespace std;
#define max 10000
#define FOR(i, start, end, k) for(int i = start; i < end; i += k)
vector<set<int>> connect;
vector<pair<int,int>> edge;
int color[max];
int n,m;

void input(){
    int u, v;
    cin >> n >> m;
    connect.resize(max, set<int>());
    FOR(i,0,m,1){
        cin >> u >> v;
        edge.push_back(make_pair(u,v));
        connect[u].insert(v);           
        connect[v].insert(u);
    }
    memset(color,0,sizeof(color));
}
// vertice u with color c ?
bool check(int u, int c){
    for(int v : connect[u]){   // check friend
        if (color[v] == c) return false;
    }
    return true;
}
// max_vertices can be colored by 1 color;
int fillColor(int c){
    int ans = 0;
    FOR(i,1,n+1,1){
        if(!color[i] && check(i,c)){
            color[i] = c;
            ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("dothi.txt", "r", stdin);
        freopen("dothitomau.dot", "w", stdout);
    #endif
    input();
    int res = 0, col = 1;
    string color_real[max];
    while (res < n){
        res += fillColor(col++);
    }
    FOR(i,1,n+1,1){      // em để tạm 10 màu ạ T.T
        switch(color[i]) {
            case 1: color_real[i] = "green";
                    break;
            case 2: color_real[i] = "red";
                    break;
            case 3: color_real[i] = "blue";
                    break;
            case 4: color_real[i] = "brown";
                    break;
            case 5: color_real[i] = "white";
                    break;
            case 6: color_real[i] = "black";
                    break;
            case 7: color_real[i] = "pink";
                    break;
            default: break;
        }
    }
    cout << "graph dothi \n{\n";
    FOR(i,1,n+1,1){
        cout << i << " [fillcolor=" << color_real[i] << ", style=filled];\n";
    }
    FOR(i,0,m,1){
        cout << edge[i].first << " -- " << edge[i].second << ";\n";
    }
    cout << "}";
    return 0;
}


// connect[1] = {2,5,4}
// connect[2] = {1,3}
// connect[4] = {1,3}
// connect[3] = {2,4}
// connect[5] = {1}


            // case 8: color_real[i] = "yellow";
            //         break;
            // case 9: color_real[i] = "orange";
            //         break;
            // case 10: color_real[i] = "violet";
            //         break;
            // case 11: color_real[i] = "gray";
            //         break;
            // case 12: color_real[i] = "purple";
            //         break;
            // case 13: color_real[i] = "bright red";
            //         break;
            // case 14: color_real[i] = "dark brown";
            //         break;
            // case 15: color_real[i] = "dark blue";
            //         break;
            // case 16: color_real[i] = "rubine";
            //         break;
            // case 17: color_real[i] = "carrot";
            //         break;
            // case 18: color_real[i] = "sunshine";
            //         break;
            // case 19: color_real[i] = "salmon";
            //         break;
            // case 20: color_real[i] = "chocolate";
            //         break;
            // case 21: color_real[i] = "forest";
            //         break;
            // case 22: color_real[i] = "flamingo";
            //         break;
            // case 23: color_real[i] = "lavender";
            //         break;
            // case 24: color_real[i] = "navy";
            //         break;
            // case 25: color_real[i] = "dark grey";
            //         break;
            // case 26: color_real[i] = "neon green";
            //         break;
            // case 27: color_real[i] = "olive";
            //         break;
            // case 28: color_real[i] = "plum";
            //         break;
            // case 29: color_real[i] = "caramel";
            //         break;
            // case 30: color_real[i] = "beige";
            //         break;
















