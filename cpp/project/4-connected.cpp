#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;

vector<string> vertical;
map<string,vector<string>> adj;
map<string,vector<string>> connect;
map<string,vector<string>> r_connect;
map<string,bool> visited;
map<string,string> parent;
stack<string> st;

void reset(){
    for(const auto word : vertical){
        visited[word] = false;
    }
}

void readData(vector<string>& data, const string& filename){
    ifstream file(filename);
    string line;

    if(file.is_open()){
        while(getline(file,line)){   
            data.push_back(line);
        }
        file.close();
    } else {
        cerr << "Khong the mo tep!\n";
    }
}

bool haveEdge(const string a, const string b){
    int count = 0;
    if (a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) count++;
        if (count > 1)
            return false;
    }
    return count == 1;
}

bool haveVector(const string u, const string v){
    int count = 0;
    for(int i = 1; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (u[i] == v[j]) count++;
        }
    }
    return count >= 4;
}

void input1(){
    reset();
    for(int i = 0; i < vertical.size(); ++i){
        for(int j = i+1; j < vertical.size(); ++j){
            if (haveEdge(vertical[i], vertical[j])){
                adj[vertical[i]].push_back(vertical[j]);
                adj[vertical[j]].push_back(vertical[i]);
            }
        }
    }
}

void input2(){
    reset();
    for(int i = 0; i < vertical.size(); i++){
        for(int j = i+1; j < vertical.size(); j++){
            if (haveVector(vertical[i], vertical[j]))
                connect[vertical[i]].push_back(vertical[j]);
                r_connect[vertical[j]].push_back(vertical[i]);
        }
    }
}

void dfs1(string u){
    visited[u] = true;
    // cout << u << " ";
    for(string v : adj[u]){
        if(!visited[v])
            dfs1(v);
    }
}

void dfs21(string u){
    visited[u] = true;
    // cout << u << " ";
    for(string v : connect[u]){
        if(!visited[v])
            dfs21(v);
    }
    st.push(u);
}

void dfs22(string u){
    visited[u] = true;
    for(string v : r_connect[u]){
        if(!visited[v])
            dfs22(v);
    }
}

void dfs23(string u, map<string,bool>& inComp){
    visited[u] = true;
    inComp[u] = true;

    for(string v : r_connect[u]){
        if(!visited[v])
            dfs23(v, inComp);
    }
}

void connectedComponent(){
    int result = 0;
    for (int i = 0; i < vertical.size(); i++){
        if(!visited[vertical[i]]){
            result++;
            dfs1(vertical[i]);
        }
    }
    cout << "So thanh phan lien thong la: " << result << endl;
}

void shortestPath(string u, string v) {
    queue<string> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        if (curr == v) {
            vector<string> path;
            while (curr != u) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(u);
            reverse(path.begin(), path.end());
            
            cout << "Duong di ngan nhat tu " << u << " den " << v << " la: ";
            for (string vertex : path) {
                cout << vertex << " ";
            }
            return; // Kết thúc hàm sau khi tìm thấy đường đi ngắn nhất
        }

        for (string neighbour : adj[curr]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = curr;
            }
        }
    }
}

void strongConnected(){
    int result = 0;
    reset();
    for(int i = 0; i < vertical.size(); i++){
        if(!visited[vertical[i]])
            dfs21(vertical[i]);
    }
    reset();
    while(!st.empty()){
        string u = st.top(); st.pop();
        if(!visited[u]){
            result++;
            dfs22(u);
        }
    }
    cout << "\nSo thanh phan lien thong MANH la: " << result << endl;
}

void printSCC(string vertex){
    reset();
    dfs21(vertex);

    map<string,bool> inComp;
    for(int i = 0; i < vertical.size(); i++)
        inComp[vertical[i]] = false;
    reset();
    dfs23(vertex, inComp);

    cout << "Cac dinh thuoc cung 1 tplt manh voi " << vertex << " la: ";
    for(int i = 0; i < vertical.size(); i++){
        if(inComp[vertical[i]]) cout << vertical[i] << " ";
    }
    cout << endl;
}

void shortestPathVector(string u, string v) {
    for(int i = 0; i < vertical.size(); i++){
        parent[vertical[i]] = "";
    }
    queue<string> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        if (curr == v) {
            vector<string> path;
            while (curr != u) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(u);
            reverse(path.begin(), path.end());
            
            cout << "Duong di ngan nhat tu " << u << " den " << v << " la: ";
            for (string vertex : path) {
                if (vertex != v)
                    cout << vertex << "->";
                else cout << v;
            }
            return; // Kết thúc hàm sau khi tìm thấy đường đi ngắn nhất
        }

        for (string neighbour : connect[curr]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = curr;
            }
        }
    }
}

int main(){
    readData(vertical, "sgb-word.txt");
    input1();
    connectedComponent();
    reset();
    string u,v; cin >> u >> v;
    shortestPath(u,v);

    input2();
    strongConnected();
    reset(); 
    string x; cin >> x;
    printSCC(x);
    reset();
    cin >> u >> v;
    shortestPathVector(u,v);
    return 0;
}
