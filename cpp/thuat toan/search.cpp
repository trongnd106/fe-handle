// TÌM KIẾM NHỊ PHÂN

// BT1: Tìm trong mảng A có bao nhiêu cặp (ai,aj) tm: ai + aj = b
/*
    IDEA: 
        PA1_O(n^2): vét cạn với 2 vòng for
        PA2_O(nlogn):
            sắp xếp mảng = sx trộn O(nlogn)
            aj = b - ai đã được tính khi duyệt i, thực hiện tìm kiếm aj 
            trên phần còn lại của mảng(kể từ vị trí i)
        PA3*_O(n): 
            kĩ thuật 2 con trỏ 
            curr = a[l] + a[r]
            nếu curr = b thì r--,l++, curr > b thì r--, curr < b thì l++
*/

// CÂY NHỊ PHÂN TÌM KIẾM (BST)
/*
    Khoá mỗi nút lớn hơn khoá của tất cả các nút cây con bên trái,
    nhỏ hơn khoá của tất cả các nút cây con bên phải
        struct Node {
            int key;
            Node *leftChild;
            Node *rightChild;
        }
        Node *root;
*/