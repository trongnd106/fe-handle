// #include<iostream>
// #include<cstring>

// using namespace std;

// struct node {
//     int value;
//     node *next;
// };

// node *createNode(int x){
//     node *temp = new node;
//     temp->value = x;
//     temp->next = NULL;
//     return temp;
// }

// void printList(node *h){
//     node *p = h;
//     while (p != NULL){
//         cout << p->value << " ";
//         p = p->next;
//     }
// }

// node *addElement(node *p, int x){
//     node *temp = createNode(x);
//     p->next = temp;
//     return temp;
// }

// bool checkElement(node *h, int x){
//     node *p = h;
//     while (p != NULL){
//         if (p->value == x)
//             return true;
//         p = p->next;
//     }
//     return false;
// }

// node *index(node *h, int x){
//     node *p = h;
//     while (p != NULL){
//         if (p->value == x)
//             return p;
//         p = p->next;
//     }
//     return NULL;
// }

// node *prev(node *h, node *p){
//     node *q = h;
//     while (q != NULL){
//         if (q->next == p) return q;
//         q = q->next;
//     }
//     return NULL;
// }

// node *addLast(node *h, int x){
//     node *temp = createNode(x);
//     bool check = checkElement(h,x);
//     if (check == false){
//         if (h == NULL){
//             return temp;
//         }
//         node *p = h;
//         while (p->next != NULL){
//             p = p->next;
//         }
//         p->next = temp;
//     }
//     return h;
// }

// node *addFirst(node *h, int x){
//     node *temp = new node;
//     temp->value = x;
//     bool check = checkElement(h,x);
//     if(check == false){
//         if (h == NULL){
//             return temp;
//         }
//         temp->next = h;
//         h = temp;
//     }
//     return h;
// }

// node *addAfter(node *h, int u, int v){
//     bool check1 = checkElement(h,v);
//     bool check2 = checkElement(h,u);
//     if (check1 == true && check2 == false){
//         node *p = index(h,v);
//         node *temp = new node;
//         temp->value = u;
//         temp->next = p->next;
//         p->next = temp;
//     }
//     return h;
// }

// node *addBefore(node *h, int u, int v){
//     bool check1 = checkElement(h,v);
//     bool check2 = checkElement(h,u);
//     if (check1 == true && check2 == false){
//         node *p = index(h,v);
//         node *pp = prev(h,p);
//         if (pp == NULL && p != NULL) 
//             return h;
//         node *temp = createNode(u); 
//         if (pp == NULL){
//             if (h == NULL) 
//                 return temp;
//             temp->next = h;
//             return temp;
//         }
//         temp->next = p;
//         pp->next = temp;
//     }
//     return h;  
// }

// node *remove(node *h, int x){
//     node *p = index(h,x);
//     if (h == NULL || p == NULL) return h;
//     if (h == p){
//         h = h->next;
//         delete p;
//         return h;
//     } else {
//         h->next = remove(h->next,x);
//         return h;
//     }
// }

// node *reverse(node *h){
//     node *prev = nullptr;
//     node *curr = h;
//     while(curr != nullptr){
//         node *nextNode = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nextNode;
//     }
//     return prev;
// }

// int main(){
//     int n,x,k,m;
//     cin >> n >> x;
//     node *h = createNode(x);
//     node *p = h;
//     for (int i = 1; i < n; i++){
//         cin >> x;
//         p = addElement(p,x);
//     }
//     while(true){
//         string op;
//         cin >> op;
//         if (op == "addlast"){
//             cin >> k;
//             h = addLast(h,k);
//         }
//         else if (op == "addfirst"){
//             cin >> k;
//             h = addFirst(h,k);
//         }
//         else if (op == "addafter"){
//             cin >> k >> m;
//             h = addAfter(h,k,m);
//         }
//         else if (op == "addbefore"){
//             cin >> k >> m;
//             h = addBefore(h,k,m);
//         }
//         else if (op == "remove"){ 
//             cin >> k;
//             h = remove(h,k);
//         }
//         else if (op == "reverse"){
//             h = reverse(h);
//         }
//         else if (op == "#")
//             break;           
//     }
//     printList(h);
//     return 0;
// }





/*
#include<bits/stdc++.h>

using namespace std;

int precedence(char op){
    if (op == '+' || op == '-')
       return 1;
    if (op == '*' || op == '/')
       return 2;
    return 0;
}
int applyOp(int a, int b, char op){
    switch(op){
       case '+': return a + b;
       case '-': return a - b;
       case '*': return a * b;
       case '/': return a / b;
    }
}
int evaluate(string tokens){
    int i;
    stack<int> values;
    stack<char> ops;
    for (i = 0; i < tokens.length(); i++){
        if(tokens[i] == '('){
           ops.push(token[i]);
        }
        else if(isdigit(tokens[i])){
            int val = 0;
            for (int j = i; i < tokens.length(); j++){
                if (isdigit(tokens[j]))
                    val = (val*10) + (tokens[j] - '0');
            }
            values.push(val);
        }
        else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();                
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1,val2,op));
            }
            if(!ops.empty()){
                ops.pop();
            }
        }
        else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1,val2,op));
            }
            ops.push(tokens[i]);
        }
    }
    while(! ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1,val2,op));        
    }
    return values.top();
}

int main(){
    string exp = "";
    cin >> exp;
    cout << evaluate(exp);
    return 0;
}

*/






/*
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int coefficient;
    int exponent;
    Node* next;
};
class PolynomialManager {
private:
    unordered_map<int, Node*> polynomials;

public:
    PolynomialManager() {}

    void create(int poly_id) {
        if (polynomials.find(poly_id) == polynomials.end()) {
            polynomials[poly_id] = nullptr;
        }
    }

    void addTerm(int poly_id, int coef, int exp) {
        Node* newNode = new Node{coef, exp, nullptr};
        if (polynomials.find(poly_id) == polynomials.end()) {
            polynomials[poly_id] = newNode;
        } else {
            Node* current = polynomials[poly_id];
            Node* prev = nullptr;

            while (current != nullptr && current->exponent > exp) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                newNode->next = current;
                polynomials[poly_id] = newNode;
            } else {
                prev->next = newNode;
                newNode->next = current;
            }
        }
    }

    void evaluatePoly(int poly_id, int variable_value) {
        int result = 0;
        Node* current = polynomials[poly_id];

        while (current != nullptr) {
            result += current->coefficient * pow(variable_value, current->exponent);
            current = current->next;
        }

        cout << result << endl;
    }

    // Implement other functions as needed: AddPoly, PrintPoly, Destroy
};
int main() {
    PolynomialManager pm;

    // Read commands and perform operations
    string command;
    while (cin >> command) {
        if (command == "Create") {
            int poly_id;
            cin >> poly_id;
            pm.create(poly_id);
        } else if (command == "AddTerm") {
            int poly_id, coef, exp;
            cin >> poly_id >> coef >> exp;
            pm.addTerm(poly_id, coef, exp);
        } else if (command == "EvaluatePoly") {
            int poly_id, variable_value;
            cin >> poly_id >> variable_value;
            pm.evaluatePoly(poly_id, variable_value);
        }
        // Implement other command handling here

        // Terminate if * is encountered
        if (command == "*") {
            break;
        }
    }

    return 0;
}
*/
