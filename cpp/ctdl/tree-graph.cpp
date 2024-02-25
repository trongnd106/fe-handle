// TREE

// PRINT TREE =>
/*
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    char value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char val): value(val), left(nullptr), right(nullptr){}
};

void printTree(TreeNode *node, int level){
    if(node == NULL){
        return;
    }
    printTree(node->right, level+1);
    for(int i = 0; i < level; i++){
        cout << "    ";
    }
    cout << node->value << endl;
    printTree(node->left,level+1);
}

int main(){
    TreeNode *root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('E');
    root->left->right = new TreeNode('F');
    root->right->right = new TreeNode('K');
    root->right->right->left = new TreeNode('H');
    printTree(root,0);
    return 0;
}
*/

// =============== THUẬT TOÁN TÌM KIẾM THEO CHIỀU SÂU =================
// 1. Pre-order 
/*
void preorderDfs(TreeNode *node){
    if (node == nullptr){
        return;
    }
    cout << node->val << endl;
    preorderDfs(node->left);
    preorderDfs(node->right);
}
*/
// 2. In-order 
/*
void inorderDfs(TreeNode *node){
    if (node == nullptr){
        return;
    }
    inorderDfs(node->left);
    cout << node->val << endl;
    inorderDfs(node->right);
}
*/
// 3. Post-order
/*
void postorderDfs(TreeNode *node){
    if (node == nullptr) {
        return;
    }
    postorderDfs(node->left);
    postorderDfs(node->right);
    cout << node->value << endl;
}
*/

// =================================================================================================
// khai báo node 
/*
struct node {
    int data;
    node *left;
    node *right;
};

node *makeNode(int val){
    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int maxDepth(node *node){
    if (node == NULL){
        return 0;
    }
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    if (lDepth > rDepth) 
        return (lDepth + 1);
    else 
        return (rDepth + 1);
}
*/

// ======================== BST (Cây nhị phân tìm kiếm) ============================
// Khởi tạo 1 BST
/*
struct node_t {
    int data;
    node_t *left;
    node_t *right;
};  */


/* Giải phóng dữ liệu: Xoá 1 cây con = cách cung cấp nốt root
   Trình tự xoá:
    1. Gọi đệ quy xoá cây con bên trái
    2. Gọi đệ quy xoá cây con bên phải
    3. Giải phóng vùng nhớ cho con trỏ hiện tại
*/
// void Free(node_t *root){
//     if (root == NULL){
//         return;
//     }
//     Free(root->left);
//     Free(root->right);
//     free(root);
// }

// ===== THÊM PHẦN TỬ + TÌM KIẾM TRÊN BST =====

/* Hàm điều hướng của cây: phục vụ quá trình Thêm phần tử + Tìm kiếm 
NOTE: Không cho phép thêm phần tử trùng lặp */
// int LeftOf(const int value, const node_t *root){
//     return value < root->data;
// }
// int RightOf(const int value, const node_t *root){
//     return value > root->data;
// }

// // -------- thêm phần tử vào BST --------
// node *Insert(node *root, const int value){
//     if(root == NULL){
//         node_t *node = new node_t;   // node *node = (node *)malloc(sizeof(node));
//         node->left = node->right = NULL;
//         node->data = value;
//         return node;
//     }
//     if (LeftOf(value,root)){
//         root->left = Insert(root->left,value);   // root = root->left
//     } else if (RightOf(value,root)){
//         root->right = Insert(root->right,value);
//     }
//     return root;
// }

// -------- tìm kiếm trên BST --------
/*Quy trình tìm kiếm: 
    1. Nếu node hiện tại = giá trị cần tìm => trả về True, kết thúc
    2. Nếu node hiện tại > giá trị cần tìm => gọi đệ quy cây con bên trái
    3. Nếu node hiện tại < giá trị cần tìm => gọi đệ quy cây con bên phải
    4. Nếu tìm đến hết cây (node đó = NULL) mà không xảy ra (1) => trả về False, kết thúc
*/

// bool Search(const node_t *root, int value){
//     if (root == NULL)
//         return false;
//     if (root->data == value)
//         return true;
//     else if (LeftOf(value,root))
//         return Search(root->left,value);
//     else if (RightOf(value,root))
//         return Search(root->right,value);
// }



// --------- LẤY GIÁ TRỊ CON TRÁI NHẤT ----------
/* duyệt theo con trỏ trỏ tới cây con bên trái tới chừng nào không còn cây con bên trái nữa 
   thì đó là cây con trái nhất */

// int leftMostValue(const node_t *root){
//     while (root->left != NULL){
//         root = root->left;
//     }
//     return root->value;
// }



// --------- XOÁ MỘT NODE TRONG BST ---------
/* Chia làm 3 trường hợp:
    1. Node cần xoá là node lá (không có child)   => chỉ cần giải phóng bộ nhớ là được
    2. Node cần xoá có 1 child    => con duy nhất sẽ liên kết với cha 
    3. Node cần xoá đủ 2 childs 
        . Tìm node của con trái nhất (leftMost) của cây con bên phải node cần xoá
        . Cập nhật giá trị node cần xoá = giá trị của node leftMost
        . Gọi đệ quy hàm Delete xoá node leftMost khỏi BST
*/

/*
node_t* Delete(node_t *root, int value){
    if (root == NULL)
        return root;
    if (LeftOf(value,root))
        root->left = Delete(root->left, value);
    else if (RightOf(value,root))
        root->right = Delete(root->right, value);
    else {
        // root->data = value   => delete node này
        if (root->left == NULL){
            node_t* newRoot = root->right;
            free(root);
            return newRoot;
        }
        if (root->right == NULL){
            node_t* newRoot = root->left;
            free(root);
            return newRoot;
        }
        root->data = leftMostValue(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}
*/


#include<iostream>
#include<cstring>

using namespace std;

struct node_t {
    int data;
    node_t *left;
    node_t *right;
};

int LeftOf(const int value, const node_t *root){
    return value < root->data;
}
int RightOf(const int value, const node_t *root){
    return value > root->data;
}

node_t *Insert(node_t *root, const int value){
    if (root == nullptr){
        node_t *node = new node_t;
        node->left = node->right = nullptr;
        node->data = value;
        return node;
    }
    if (LeftOf(value,root)){
        root->left = Insert(root->left, value);
    }
    else if (RightOf(value,root)){
        root->right = Insert(root->right, value);
    }
    return root;
}

void preOrder(node_t *node){
    if (node == nullptr){
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main(){
    string x;
    int n;
    node_t *root = nullptr;
    while (true){
        cin >> x;
        if (x == "insert"){
            cin >> n;
            root = Insert(root,n);
        }
        else if (x == "#"){
            break;
        }
    }
    preOrder(root);
    return 0;
}

