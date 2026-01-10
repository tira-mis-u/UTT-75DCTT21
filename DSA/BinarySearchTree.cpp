#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
};
typedef struct Node node;

node *makeNode(int x) {
    node *newNode = new Node();
    newNode->data = x;
    newNode->right = newNode->left = NULL;
    return newNode;
}

// Thêm node vào trái hoặc phải (đệ quy)
void pushNode(node*&head, int x) {
    if(head == NULL) {
        head = makeNode(x);
        return;
    }
    if(x < head->data) pushNode(head->left, x);
    else pushNode(head->right, x);
}

// Duyệt theo thứ tự NLR
void preOrder(node*&head) {
    if(head == NULL) return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

// Duyệt theo thứ tự LNR
void inOrder(node*&head) {
    if(head == NULL) return;
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

// Duyệt theo thứ tự LRN
void postOrder(node*&head) {
    if(head == NULL) return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

// Tìm node trái nhất của cây con
void findReplacement(node*&a, node*&b) {
    if(b->left != NULL) {
        findReplacement(a, b->left);
    } else {
        a->data = b->data;
        node *temp = b;
        b = b->right;
        delete temp;
    }
}

// Xoá 1 node con x trong cây
void deleteNode(node*&head, int x) {
    if(head == NULL) return;
    if(x > head->data){
        deleteNode(head->right, x);
    } else if(x < head->data){
        deleteNode(head->left, x);
    } else { // Nếu node x có 0, 1, 2 con
        node *temp = head;
        if(head->right == NULL) {
            head = head->left;
        } else if(head->left == NULL) {
            head = head->right ;
        } else {
            findReplacement(head, head->right);
            return;
        }
        delete temp;
        return;
    }
}

// Toàn bộ bên dưới là hàm test chương trình:

void menu() {
    cout << "\n\n[ DEMO CAY NHI PHAN TIM KIEM (BST) ]\n";
    cout << "--------------------------------------------------\n";
    cout << "1. Them phan tu vao BST\n";
    cout << "2. Xoa phan tu o trong BST\n";
    cout << "3. Duyet BST theo N-L-R (Pre-order Traversal)\n";
    cout << "4. Duyet BST theo L-N-R (In-order Traversal)\n";
    cout << "5. Duyet BST theo L-R-N (Post-order Traversal)\n";
    cout << "0. Thoat\n";
    cout << "--------------------------------------------------\n";
    // cout << "# Danh sach hien tai co " << n << " phan tu\n";
    cout << "\n> Nhap lua chon: ";
}

int main() {
    node *head = NULL;
    bool run = true;
    while(run) {
        menu();
        int n; cin >> n;
        string text = "> Nhap doi so: ";
        switch(n) {
            case 1:
                int x1; cout << text; cin >> x1;
                pushNode(head, x1);
                cout << "Da them node {" << x1 << "} vao BST";
                break;
            case 2:
                int x2; cout << text; cin >> x2;
                deleteNode(head, x2);
                cout << "Da xoa node {" << x2 << "} khoi BST";
                break;
            case 3:
                cout << "Ket qua khi duyet theo N-L-R la: " << (head == NULL ? "Empty" : "");
                preOrder(head);
                break;
            case 4:
                cout << "Ket qua khi duyet theo L-N-R la: ";
                inOrder(head);
                break;
            case 5:
                cout << "Ket qua khi duyet theo L-R-N la: ";
                postOrder(head);
                break;
            case 0:
                run = false;
                break;
            default:
                cout << "Lua chon khong họp le!\n";
                break;
        }
    }
    return 0;
}