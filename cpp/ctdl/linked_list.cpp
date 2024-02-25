// Danh sách liên kết đơn
/*
#include<bits/stdc++.h>
using namespace std;

struct LinkedListNode {
    int value;
    LinkedListNode* next;
    LinkedListNode(int val): value(val), next(nullptr) {}
};

int main(){
    LinkedListNode* one = new LinkedListNode(100);
    LinkedListNode* two = new LinkedListNode(200);
    LinkedListNode* three = new LinkedListNode(300);
    one->next = two;
    two->next = three;
    LinkedListNode* head = one;
    cout << head->value << endl;
    cout << head->next->value << endl;
    cout << head->next->next->value << endl;
    return 0;
}
*/

// Danh sách liên kết đôi
/*
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int val): value(val), next(nullptr), prev(nullptr) {}
};

ListNode* head;
ListNode* tail = new ListNode(-1);

void addNode(ListNode* nextNode, ListNode* nodetoAdd) {
    ListNode* prevNode = nextNode->prev;
    nodetoAdd->next = nextNode;
    nodetoAdd->prev = prevNode;
    prevNode->next = nodetoAdd;
    nextNode->prev = nodetoAdd;
}
void deleteNode(ListNode* node){
    ListNode* prevNode = node->prev;
    ListNode* nextNode = node->next;
    nextNode->prev = prevNode;
    prevNode->next = nextNode;
}
void addtoEnd(ListNode* nodetoAdd){
    nodetoAdd->next = tail;
    nodetoAdd->prev = tail->next;
    tail->prev->next = nodetoAdd;
    tail->prev = nodetoAdd;
}
void removefromEnd(){
    if (head->next == tail){
        return;
    }
    ListNode* nodetoRemove = tail->prev;
    nodetoRemove->prev->next = tail;
    tail->prev = nodetoRemove->prev;
}
void addtoStart(ListNode* nodetoAdd){
    nodetoAdd->prev = head;
    nodetoAdd->next = head->next;
    head->next->prev = nodetoAdd;
    head->next = nodetoAdd;
}
void removefromStart(){
    if (tail->prev == head){
        return;
    }
    ListNode* nodetoRemove = head->next;
    nodetoRemove->next->prev = head;
    head->next = nodetoRemove->next;
}

int main(){
    ListNode* one = new ListNode(100);
    ListNode* two = new ListNode(200);
    ListNode* three = new ListNode(300);
    ListNode* four = new ListNode(500);
    // ListNode* tail = new ListNode(99999);
 // point   
    head = one;
    head->next = two;
    two->prev = head;
    two->next = tail;
    tail->prev = two;

    addNode(two, three);   //three between one and two
    addtoEnd(four);    // one three two four tail
    // removefromEnd();
    // addtoStart(four);
    // removefromStart();
    
    cout << head->value << endl;
    cout << head->next->value << endl;
    cout << head->next->next->value << endl;
    cout << head->next->next->next->value << endl;
    cout << head->next->next->next->next->value << endl;
    return 0;
}
*/

// Tạo dslk đơn
/*
#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

int main(){
	int n, x;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	printList(l);
	return 0;
}
*/

// duyệt dslk
/*
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;    // cấp phát bộ nhớ động cho con trỏ
    temp->next = NULL;    // truyền vào
    temp->data = x;       // truyền vào
    return temp;
}

void printList(node *l){
    node *p = l;     // dummpy pointers
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

node *addElement(node *p, int x){
    node *temp = createNode(x);      // tạo node
    p->next = temp;           // tham chiếu tới phần tử dc tạo
    return temp;              // trả về 1 node hoàn chỉnh
}

node *getNode(node *l, int k){
	node *p = l;
	for (int i = 0; i < k; i++){
		p = p->next;                    // next cho tới chỉ số k
	}
	return p;       // trả về chỉ số
}

int main(){
	int n, x, k;
	cin >> n;       // số phần tử
	cin >> x;       // x của node đầu tiên
	node *l = createNode(x);      // tạo node đầu tiên
	node *p = l;          // đặt con trỏ rỗng vào
	for (int i = 1; i < n; i++){
		cin >> x;                      // nhập x để tạo các node tiếp
		p = addElement(p, x);          // tạo các nốt tiếp, lấy chính p để tự gán next
	}
	cin >> k;             // nhập chỉ số cần tìm
	p = getNode(l, k);        // nhận về con trỏ
	cout << p->data;          // in value tại chỉ số đó
	return 0;
}
*/

// thay thế 
/*
#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node *addElement(node *p, int x) {
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
// cach 1 
// void changeData(node *l, int k, int m, int n) {
//     node *p = l;
//     for (int i = 0; i < n; i++){
//         if (p->data == k){
//             p->data = m;
//         }
//         p = p->next;
//     }
// }
// cach 2
node *convertData(node *l, int a, int b) {
    node *p = l;
    while (p != NULL){
        if (p->data == a){
            p->data = b;      //thay doi dl
        }
        p = p->next;
    }
    return l;
}

int main(){
    int n,x,k,m;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++){
        cin >> x;
        p = addElement(p,x);
    }
    cin >> k >> m;
//    getNode(l,k,m,n);
    l = convertData(l,k,m);
    printList(l);
    return 0;
}
*/

// thêm phần tử vào danh sách
/*
#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

node *addHead(node *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->next = l;
	l = temp;
	return l;
}

node *addAt(node *l, int k, int x){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	
	return l;
}

node *addTail(node *l, int x){
	node *p = l;
	while (p->next != NULL){
		p= p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cin >> k >> x;
	if (k == 0){
		l = addHead(l, x);	
	} else if (k == n){
		l = addTail(l, x);
	} else{
		l = addAt(l, k, x);
	}
	printList(l);
	return 0;
}
*/

// xoá phần tử khỏi danh sách
/*
#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;
};

node *createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node *addElement(node *p, int x) {
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

node *deleteHead(node *l){
    node *p = l;
    p = p->next;
    delete(l);
    return p;
}

node *deleteTail(node *l){
    node *p = l;
    while (p->next->next != NULL){
        p = p->next;
    }
    delete(p->next);
    p->next = NULL;
    return l;
}

node *deleteAt(node *l, int k){
    node *p = l;
    for(int i = 0; i < k-1; i++){    // next k-1 lần
        p = p->next;      // đến vị trí k-1
    }
    node *temp = p->next;
    p->next = p->next->next;
    delete(temp);
    return l;
}
*/

// xoá nhiều phần tử khỏi danh sách
//cach 1
/*
#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode (int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node *addElement(node *p, int x){
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void printList(node *l){
    node *p = l;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

node *deleteHead(node *l){
    node *p = l;
    p = p->next;
    delete(l);
    return p;
}

node *deleteTail(node *l){
    node *p = l;
    while (p->next->next != NULL){
        p = p->next;
    }
    delete(p->next);
    p->next = NULL;
    return l;
}

node *deleteMid(node *l, int k){
    node *p = l;
    for (int i = 0; i < k-1; i++){
        p = p->next;
    }
    node *temp = p->next;
    p->next = p->next->next;
    delete(temp);
    return l;
}

int main(){
    int n, x;
    cin >> n; 
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++){
        cin >> x;
        p = addElement(p,x);
    }

    int k;
    cin >> k;
    node *m = l;
    node *a = l;
    for (int i = 0; i < k; i++){
        m = m->next;
    }
    int val = m->data;
    
    for (int i = 0; i < n; i++){
        if (a->data > val){
            if (k == 0) {
                l = deleteHead(l);
            } 
            else if (k == n){
                l = deleteTail(l);
            }
            else l = deleteMid(l,i);
        }
        a = a->next;
    }
    printList(l);
    return 0;
}
*/

// cach 2:
/*
#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

node *addTail(node *l, int x){
	node *p = l;
	while (p->next != NULL){
		p= p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

node *deleteBigger(node *l, int k){
	node *p = l;
	node *ans = new node;
	while (p != NULL){
		if (p->data <= k){
			ans = createNode(p->data);
			p = p->next;
			break;
		}
		p = p->next;
	}
	while (p != NULL){
		if (p->data <= k){
			ans = addTail(ans, p->data);
		}
		p = p->next;
	}
	return ans;
}

node *getNode(node *l, int k){
	node *p = l;
	for (int i = 0; i < k; i++){
		p = p->next;
	}
	return p;
}

int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cin >> k;
	l = deleteBigger(l, getNode(l, k)->data);
	printList(l);
	return 0;
}
*/

// T Ạ O    D A N H    S Á C H    L I Ê N    K Ế T    Đ Ô I
// Problem: Set up 1 double linked list bằng cách nhập vào 1 số n, list tự động tạo
//          được có dạng: n  n-1  n-2 ... 1 ... n-2  n-1  n
// VD: N = 7  => DLL: 7 6 5 4 3 2 1 2 3 4 5 6 7
/*
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct douList{
    node *head;
    node *tail;
};

douList *createList(int x){
    douList *l = new douList;
    l->head = new node;
    l->head->data = x;
    l->head->next = NULL;
    l->head->prev = NULL;
    l->tail = l->head;
    return l;
}

douList *addHead(douList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = l->head;
    l->head->prev = temp;
    l->head = temp;
    return l;
}

douList *addTail(douList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = l->tail;
    l->tail->next = temp;
    l->tail = temp;
    return l;
}
// duyệt dslk đôi theo phần tử đầu
void printdouListH(douList *l){
    node *p = l->head;
    while (p->next != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
// duyệt dslk đôi theo phần tử cuối
// void printdouListT(douList *l){
//     node *p = l->tail;
//     while (p->prev != NULL){
//         cout << p->data << endl;
//         p = p->prev;
//     }
// }

int main(){
    int n;
    cin >> n;
    douList *l = createList(1);   // tạo node 1 ở giữa
    for (int i = 2; i <= n; i++){   
        l = addHead(l,i);
        l = addTail(l,i);
    }
    printdouListH(l);
    return 0;               
}
*/

// chèn phần tử vô :D
/*
#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

struct douList {
    node *head;
    node *tail;
};

douList *createList (int x){
    douList *l = new douList();
    l->head = new node;
    l->head->data = x;
    l->head->next = NULL;
    l->head->prev = NULL;
    l->tail = l->head;
    return l;
}

douList *addHead (douList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = l->head;
    l->head->prev = temp;
    l->head = temp;
    return l;
}

douList *addTail (douList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = l->tail;
    l->tail->next = temp;
    l->tail = temp;
    return l;
}

douList *addMid(douList *l, int k, int a){
    node *p = l->head;
    for (int i = 0; i < k-1; i++){
        p = p->next;
    }
    node *temp = new node;
    temp->data = a;
    // node *nextNode = p->next;
    // temp->next = nextNode;
    // temp->prev = p;
    // p->next = temp;
    // nextNode->prev = temp;
    temp->prev = p;
    temp->next = p->next;
    p->next->prev = temp;
    p->next = temp;
    return l;
}

void printdouList (douList *l){
    node *p = l->head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    int n, x;
    cin >> n;
    cin >> x;
    douList *l = createList(x);
    for (int i = 0; i < n-1; i++){
        cin >> x;
        l = addTail(l, x);
    }
    // begin: nhập yêu cầu
    int k,a;
    cin >> k >> a;
    if (k <= 0){
        l = addHead(l,a);
    }
    else if (k >= n){
        l = addTail(l,a);
    } 
    else l = addMid(l,k,a);
    printdouList(l);
    return 0;
}
*/


// SET UP cấu trúc dữ liệu vòng
// nhập 1 số k, in ra phần tử từ k đến n-1, sau đó quay trở lại in từ 0 đến k-1
/*
#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode (int x){
    node *temp = new node;
    temp->next = temp;
    temp->data = x;
    return temp;
}

void printList (node *l, int k){
    node *p = l;
    for (int i = 0; i < k; i++){
        p = p->next;
    }
    cout << p->data << " ";
    node *p2 = p->next;
    while (p2 != p){
        cout << p2->data << " ";
        p2 = p2->next;
    }
}

node *addTail(node *l, int x){
    node *p = l;
    while (p->next != l){
        p = p->next;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = l;
    p->next = temp;
    return l;
}

int main(){
    int n,x,k;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 0; i < n; i++){
        cin >> x;
        l = addTail(l,x);
    }
    cin >> k;
    printList(l,k);
    return 0;
}
*/

// Tâm điểm của danh sách
/*
#include<bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode *addElement(ListNode*p, int x)
{
	ListNode *temp = new ListNode(x);
	p->next = temp;
	return temp;
}
int main() 
{
  string input;
  getline(cin, input);
  istringstream iss(input);
  int temp;
  bool flag = true;
  ListNode *head, *p;

  while(iss >> temp) 
  {
    if (flag) 
    {
      head = new ListNode(temp);
      p = head;
      flag = false;
    }
    else 
    {
      p = addElement(p, temp);
    }
  }
 
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) 
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  cout << slow->val;
  
  return 0;
}
*/

// ĐẢO NGƯỢC DANH SÁCH 
#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

ListNode *reverseList(ListNode *head){
    ListNode *prev = nullptr;     
    ListNode *curr = head;
    while (curr != nullptr){
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
