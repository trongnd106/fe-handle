// DYNAMIC PROGRAMMING

// EX1: Dãy con tăng dài nhất (Longest Increasing Subsequence)

// thuat toan co dpt: O(N^2)   -> cai tien len O(logN)
// L[i]: độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i 
// idea: L[i] = max(L[i], L[j]+1) if a[i] > a[j]

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;
using ll = long long;
#define FOR(a,b,k) for (int i = a; i < b; i += k)

void solve(){
    int n; cin >> n;
    vector<int> a(n);
        FOR(0,n,1) cin >> a[i];
    vector<int> L;
    FOR(0,n,1) L.push_back(1);   // tránh lỗi vector<int> L(n,1)
        FOR(0,n,1){
            for(int j = 0; j < i; j++){
                if (a[i] > a[j])
                    L[i] = max(L[i], L[j] + 1);
            }
        }
    cout << *max_element(L.begin(), L.end()) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
*/

//EX2: Bài toán xếp balo 



