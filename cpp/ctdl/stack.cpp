// ---------------- S T A C K ------------------

// 1. Cài đặt NGĂN XẾP sử dụng MẢNG TĨNH
/*
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000
class Stack {
    int top;
    public:
        int a[MAX];        //maximum size of stack
        Stack() {top = -1;}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    if (top >= a[MAX-1]){
        cout << "Stack Overflow" << endl;
        return false;
    }
    else {
        a[++top] = x;
        cout << x << "pushed into Stack\n" << endl;
        return true;
    }
}

int Stack::pop(){
    if (top < 0){
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if (top < 0){
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    // print top element of stack after popping
    cout << "Top element is: " << s.peek() << endl;
    // print all elements in stack:
    cout << "Elements in stack: ";
    while (!s.isEmpty()){
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}
*/


//2. Cài đặt STACK sử dụng DANH SÁCH ĐƯỢC LIÊN KẾT
/*
#include <bits/stdc++.h>

using namespace std;

class StackNode {
    public:
        int data;
        StackNode *next;
};

StackNode *newNode(int data){
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root){
    return !root;
}

void push(StackNode **root, int data){
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}        
int pop(StackNode **root){
    if (isEmpty(*root))
        return INT_MIN;
    //  exp: INT_MIN is a macro that specifies that an integer
    //  variable cannot store any value below this limit. It represents
    //  the minimum value or the upper limit of the integer data type. 
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(StackNode *root){
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}
int main(){
    StackNode *root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    cout << pop(&root) << " popped from stack\n";
    cout << "Top element is: " << peek(root) << endl;
    cout << "Elements present in stack: ";
    while (! isEmpty(root)){
        cout << peek(root) << " ";
        pop(&root);
    }
    return 0;
}
*/


// Ngăn xếp triển khai sẵn
/*
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> stack;
    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.push(13);
    int num = 0;
    stack.push(num);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    stack.push(5);
    if (stack.empty()){
        cout << "Stack is empty!" << endl;
    }
    else cout << "Stack is not empty, top is: " << stack.top() << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000
class Stack {
    int top;
    public:
        int a[MAX];
        Stack() {top = -1;}
        bool push(int x);
        int pop();
        bool isEmpty();
        int peek();
};
bool Stack::push(int x){
    if (top >= (MAX-1)){
        cout << "Stack Overflow" << endl;
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}
int Stack::pop(){
    if(top < 0){
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
bool Stack::isEmpty(){
    return (top < 0);
}
int Stack::peek(){
    if (top < 0) return 0;
    else {
        int x = a[top];
        return x;
    }
}
int main(){
    Stack s;
    int n; cin >> n;
    char reqst[10];
    char s1[10] = "push";
    char s2[10] = "pop";
    for (int i = 0; i < n; i++){
        fflush(stdin);
        fgets(reqst, 10, stdin);
        if (strstr(reqst,s1) != NULL){
            int num = atoi(reqst);
            s.push(num);
        }
        else if (strstr(reqst,s2) != NULL){
            s.pop();
        }
    }
    while (! s.isEmpty()){
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}
*/

/*
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string.h>

using namespace std;

int main(){
    stack<int> stack;
    int n; 
    cin >> n;
    std::cin.ignore(32767, '\n');
    char request[10], rel1[10] = "push", rel2[10] = "pop";
    for (int i = 0; i < n; i++){
        fgets(request, sizeof(request), stdin);
        char res[6]; strncpy(res, request + 4, 5);
        if (strstr(request, rel1) != NULL){
            int num = atoi(res);
            stack.push(num);
        }
        else if (strstr(request, rel2) != NULL)
            stack.pop();
    }
    while (!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    return 0;
}
*/

// ============================= BT CHUỖI CÓ THỂ ÁP DỤNG STACK =============================
// CẦN CÓ KIẾN THỨC VỀ UNORDERED_MAP, MAP;
// NHỮNG ADVANCED STRING METHOD TRONG C++
 
//EX1: CẶP NGOẶC, CHUỖI HỢP LỆ
// chuỗi hợp lệ là: "{[()]}", "{}[]"   chuỗi không hợp lệ: "{[)}"
/*
#include<iostream>
#include<stack>
#include<unordered_map>
#include<cstring>
#include<sstream>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> my_stack;
        // set the corresponding couple of brackets
        unordered_map<char,char> matching {{'(',')'},{'{','}'},{'[',']'}};
        for (char c : s){
            // check for existence of opening bracket (x.first)
            if (matching.find(c) != matching.end()){  
                my_stack.push(c);
            }
            else {
                if (my_stack.empty())     
                    return false;
                // get the top element of stack to check Var =))
                char previousOpening = my_stack.top();  
                if (matching[previousOpening] != c){    //check
                    return false;
                }
                my_stack.pop();   
            }
        }
        return my_stack.empty();
    }
};

int main(){
    Solution st;
    cout << boolalpha << st.isValid("{[()]}");
    return 0;
}
*/


//EX2: XOÁ BẢN SAO(KÝ TỰ TRÙNG LẶP)
//  "abbaca" -> "aaca" -> "ca"  
//  "abccba" -> "abba" -> "aa" -> ""
/*
#include<iostream>
#include<cstring>

using namespace std;
 
class Solution{
public:
    string removeDuplicate(string s){
        string ans = "";
        for (char c : s){
            if (! ans.empty() && ans.back() == c)
                ans.pop_back();
            else 
                ans.push_back(c);
        }
        return ans;
    }
};

int main(){
    Solution st;
    cout << st.removeDuplicate("abccbddae");
    return 0;
}*/


// EX3: SO SÁNH CHUỖI XOÁ LÙI(BACKSPACE) BỞI KÍ TỰ '#' (xoá kí tự ngay trước nó)
// VD: 'ab#c' và 'abd##c' => TRUE và đều = 'ac'
/*
#include<iostream>
#include<cstring>

using namespace std;

class Solution{
public:
    bool backspaceCompare(string s, string t){
        return build(s) == build(t);
    }
    string build(string s){
        string ans = "";
        for (char c : s){
            if (c != '#')
                ans.push_back(c);
            else if (! ans.empty())
                ans.pop_back();
        }
        return ans;
    }
};
int main(){
    Solution st;
    cout << boolalpha << st.backspaceCompare("troe#ng", "tk#rj#onl#g");
    return 0;
}
*/

//EX4: MÃ HOÁ XÂU
// aaabbccccaadd -> a3b2c4a2d2
/*
#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    s += '@';
    stack<char> stack;
    string ans = "";
    for(int i=0; i<s.length(); i++){
        if (stack.empty() || stack.top() == s[i]){
            stack.push(s[i]);
        } else {
            int count = 0;
            ans += stack.top();
            while (! stack.empty()){
                count++;
                stack.pop();
            }
            ans += to_string(count);
            stack.push(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
*/


// EX5: CẶP NGOẶC HỢP LỆ     ((())) , ()()(())
// code này chưa tối ưu
/*
#include<iostream>
#include<stack>

using namespace std;

void Solve(){
    string s; cin >> s;
    stack<char> st;
    for(char x : s){
        if (x == '(')
           st.push(x);
        else {
            if (st.empty()) cout << "INVALID\n";
            else 
                st.pop();
        }
    }
    if (st.empty()) cout << "VALID\n";
    else cout << "INVALID\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        Solve();
    }
    return 0;
}
*/


//EX6: PHẦN TỬ ĐẦU TIÊN LỚN NHẤT BÊN PHẢI (NEXT GREATER ELEMENT)
// VD: mảng   4 2 5 1 6  8 2  3
// -> result: 5 5 6 6 8 -1 3 -1 
//  cách 1
/*
#include<iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++){
        int res = -1;
        for (int j = i +1; j < n; j++){
            if (a[j] > a[i]){
                res = a[j];
                break;
            }
        }
        cout << res << " ";
    }
    return 0;
}
*/

// cách 2: sử dụng stack
/*
#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n], b[n];
    for (int &x : a) cin >> x;
    stack<int> st;
    for (int i = 0; i < n; i++){
        if (st.empty()) 
            st.push(i);
        else{
            while (!st.empty() && a[st.top()] < a[i]){   //lưu ý điều kiện
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while (! st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for (int x : b) cout << x << " ";
    return 0;
}
*/


//EX7: ĐÁNH GIÁ BIỂU THỨC
// nhập xâu (52+10)/2*5  -> trả về số nguyên là kq = 155

// CPP program to evaluate a given expression where
// tokens are separated by spaces
#include<bits/stdc++.h>

using namespace std;

//fuction fo find precedece
//of operators.
int precedence(char op){
    if (op == '+' || op == '-')
       return 1;
    if (op == '*' || op == '/')
       return 2;
    return 0;
}
//function to perform arithmetic operations
int applyOp(int a, int b, char op){
    switch(op){
       case '+': return a + b;
       case '-': return a - b;
       case '*': return a * b;
       case '/': return a / b;
    }
}
//Fuction that return value of 
//expression after evaluation
int evaluate(string tokens){
    int i;
    stack<int> values;
    stack<char> ops;
    for (i = 0; i < tokens.length(); i++){
        // current token is a whitespace, skip it
        if(tokens[i] == ' '){
           continue;
        }
        // current token is an opening brace, put it into ops
        else if(tokens[i] == '('){
           ops.push(token[i]);
        }
        // current token is a number, push it to values
        else if(isdigit(tokens[i])){
            int val = 0;
            // there may be more than one digit in number
            while (i < tokens.length() && isdigit(tokens[i])){
                val = (val*10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            // right now the i points to the character
            // next to the digit, since the for loop also
            // increases the i, we should skip one token
            // position; we need to decrease the value of 
            // i by 1 to correct the offset
            i--;
        }
        // Closing brace encountered, solve entire brace
        else if(tokens[i] == ')'){
            while( !ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();                
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1,val2,op));
            }
            // popping opening brace
            if(!ops.empty()){
                ops.pop();
            }
        }
        // current token is an operator
        else {
            // while top of 'ops' has same or greater 
            // precedence to current token, which is
            // an operator. Apply operator on top of
            // 'ops' to top two elements in values stack
            while(!ops.empty() && precedence(ons.top()) >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1,val2,op));
            }
            // push the current token to ops
            ops.push(tokens[i]);
        }
    }
    // Entire expesssion has been parsed at this
    // point, apply remaining ops to remaining values
    while(! ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1,val2,op));        
    }

    // top of values contains result, return it
    return values.top();
}

int main(){
    string exp = "";
    cin >> exp;
    cout << evaluate(exp);
    return 0;
}



































//EX7: DIỆN TÍCH HÌNH CHỮ NHẬT LỚN NHẤT TRÊN BIỂU ĐỒ
//    ^
//    |
//    |     6
//    |     __    5     5
//    |    |  |   __ 4  __
//    |    |  |  |  |__|  |
//    |    |  |2 |  |  |  |
//    |    |  |__|  |  |  | 1
//    |    |  |  |  |  |  |__
//    |____|__|__|__|__|__|__|___________>
//         .0 . 1. 2. 3. 4. 5.



 







    



