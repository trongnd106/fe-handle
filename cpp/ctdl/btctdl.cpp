//EX 1: two digits
/*
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solution(int n){
        int sum = 0;
        while (n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
};
int main(){
    int n; cin >> n;
    Solution s; cout << s.solution(n);
    return 0;
}
*/

//EX 2: sum array
/*  
n = int(input())
a = [int(x) for x in input().split()]
sum = 0
for i in a:
    sum += i
print(sum)
*/

//EX 3: Sum 2 integers
//CPP 
/*
#include <bits/stdc++.h> 
using namespace std;

class Solution {
    public:
        int charToNum(char c){
            return c - '0';
        }
    
        char numToChar(int n){
            return (char)(n+48);
        }
        
        void standard(string &a, string &b){
            int l1 = a.length(), l2 = b.length();
            if (l1 >= l2){
                b.insert(0,l1-l2,'0');
            } else
                a.insert(0,l2-l1,'0');
        }
        
        string sum(string a, string b){
            standard(a,b);
            string result = "";
            int l = a.length();
            int temp = 0;
            for (int i = l-1; i >= 0; i--){
                temp += charToNum(a[i]) + charToNum(b[i]);
                result.insert(0,1,numToChar(temp%10));
                temp /= 10;
            }
            if (temp > 0){
                result.insert(0,1,numToChar(temp));
            }
            return result;
        }
};

int main(){ 
    string a,b;
    cin >> a >> b;
    Solution s;
    cout << s.sum(a,b);
    return 0;
}
*/

//EX 4 
//CPP 
/*
#include <bits/stdc++.h> 
using namespace std;

int main(){ 
    int n; cin >> n;
    int a[n], s[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    s[0] = a[0];
    int result = s[0];
    for (int i = 1; i < n; i++){
        if (s[i-1] > 0)
            s[i] = s[i-1] + a[i];
        else s[i] = a[i];
        if (result < s[i]){
            result = s[i];
        }
    }
    cout << result;
    return 0;
}
*/

// #include <bits/stdc++.h> 
// using namespace std;

// int main(){ 
//     int n; cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++) cin >> a[i];
//     long long result = -99999999;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for (int j = i; j < n; j++){
//             sum += a[j];
//             if (sum > result) result = sum;
//         }
//     }
//     cout << result << endl;
//     return 0;
// }


//EX 5 :
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    long k, n; cin >> n >> k;
    int a[n];
    long result;
    for(int i=0; i < n; i++) cin >> a[i];
    for(int i=0; i < n; i++){
        long long sum = 0;
        for (int j = i; j < i+k-1; j++){
            sum += a[j];
        }
        if (sum % 2 == 0){
            result = sum;
            break;
        }
    }
    cout << result;
    return 0;
}*/
