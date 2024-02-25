#include <iostream>
#include <stack>

using namespace std;

int n,e;
stack<int> adj[1001];
bool visited[1001];

void input(){
    cin >> n >> e; 
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x); // neu la do thi co huong thi bo lenh nay
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u){
    cout << u << " ";
    // u da  duoc tham 
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v])
            dfs(v);
    }
}

int main(){
    input();
    dfs(1);
    return 0;
}


// input for vo huong, neu co huong thi phai nhap kieu u->v
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
// => 1 2 4 3 6 7 9 8 5




/*
#include <stdio.h>
#define MAX 1000

typedef struct {
    int x, y, z;
} Step;

int stepCount = 0;
int visited[11][11][11] = {0};
Step steps[MAX];
int prevStep[MAX] = {0};

int isValidStep(Step s) {
    if (s.x >= 0 && s.x <= 10 && s.y >= 0 && s.y <= 7 && s.z >= 0 && s.z <= 4)
        return 1;
    return 0;
}

void explore(Step s, int prevStepIndex) {
    visited[s.x][s.y][s.z] = 1;
    Step possibleSteps[12] = {
        {s.x - (7 - s.y), 7, s.z}, {s.x - (4 - s.z), s.y, 4},
        {10, s.y - (10 - s.x), s.z}, {s.x, s.y - (4 - s.z), 4},
        {10, s.y, s.z - (10 - s.x)}, {s.x, 7, s.z - (7 - s.y)},
        {0, s.y + s.x, s.z}, {0, s.y, s.z + s.x},
        {s.x + s.y, 0, s.z}, {s.x, 0, s.z + s.y},
        {s.x + s.z, s.y, 0}, {s.x, s.y + s.z, 0}  
    };
    for (int i = 0; i < 12; i++) {
        if (isValidStep(possibleSteps[i])) {
            if (visited[possibleSteps[i].x][possibleSteps[i].y][possibleSteps[i].z] == 0) {
                stepCount++;
                steps[stepCount] = possibleSteps[i];
                prevStep[stepCount] = prevStepIndex;
                if (steps[stepCount].y == 2 || steps[stepCount].z == 2)
                    return;
                explore(steps[stepCount], stepCount);
            }
        }
    }
}

void displayGraphviz() {
    FILE *f=fopen("donuoc.dot","w");
    fprintf(f,"digraph water_jug {\n");
    for (int i = 0; i <= stepCount; i++) {
        fprintf(f,"%d ", i);
        if(steps[i].y == 2 || steps[i].z == 2){
            fprintf(f,"[fillcolor=yellow,style=filled,label= \"(%d,%d,%d)\"] \n", steps[i].x, steps[i].y, steps[i].z);
        }else{
        fprintf(f,"[label= \"(%d,%d,%d)\"] \n", steps[i].x, steps[i].y, steps[i].z);
        }
    }
    for (int i = 1; i <= stepCount; i++) {
        fprintf(f,"%d -> %d\n", prevStep[i], i);
    }
    fprintf(f,"}");
    fclose(f);
}

int main() {
    steps[0].x = 0, steps[0].y = 7, steps[0].z = 4;
    explore(steps[0], 0);
    displayGraphviz();
    return 0;
}
*/
