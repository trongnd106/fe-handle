
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
#define FOR(a,b,k) for (int i = (a); i <= (b); i += k)
bool visited[12][12][12] = {false};
int prevStep[1000];
struct adj{
    int x, y, z;
};
adj getVer[1000];
int count = 0;

bool validStep(adj v) {
    if (v.x >= 0 && v.x <= 10 && v.y >= 0 && v.y <= 7 && v.z >= 0 && v.z <= 4)
        return true;
    return false;
}

void dfs(adj v, int prevIndex) {
    prevStep[0] = 0;
    visited[v.x][v.y][v.z] = true;
    vector<adj> nextAdj = {
        {10, v.y - (10 - v.x), v.z}, {10, v.y, v.z - (10 - v.x)},       // binh1 full
        {v.x - (7 - v.y), 7, v.z}, {v.x, 7, v.z - (7 - v.y)},           // binh2 full
        {v.x - (4 - v.z), v.y, 4}, {v.x, v.y - (4 - v.z), 4},           // binh3 full
        {0, v.y + v.x, v.z}, {0, v.y, v.z + v.x},                       // binh1 empty
        {v.x + v.y, 0, v.z}, {v.x, 0, v.z + v.y},                       // binh2 empty
        {v.x + v.z, v.y, 0}, {v.x, v.y + v.z, 0},                       // binh3 empty
    };
    for (adj a : nextAdj) {
        if (validStep(a)) {
            if (!visited[a.x][a.y][a.z]) {
                count++;
                getVer[count] = a;
                prevStep[count] = prevIndex;
                if (a.y == 2 || a.z == 2)
                    return;
                dfs(getVer[count], count);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    getVer[0] = {0,7,4};
    dfs(getVer[0], 0);
    #ifndef ONLINE_JUDGE
        freopen("watered.dot", "w", stdout);
    #endif
    cout << "digraph water{\n";
    FOR(0,count,1) {
        cout << i;
        if(getVer[i].y == 2 || getVer[i].z == 2)
            cout << "[fillcolor=green,style=filled,label= \"" 
                 << getVer[i].x << "," << getVer[i].y << "," << getVer[i].z << "\"] \n";
        else
            cout << "[label= \""<< getVer[i].x << "," << getVer[i].y << "," << getVer[i].z << "\"] \n";
        
    }
    FOR(1,count,1)
        cout << prevStep[i] << " -> " << i << endl;
    cout << "}";
    return 0;
}

// for (int i = 0; i <= count; i++)
