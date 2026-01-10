#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node node;

// Tạo ra 1 node mới
node *makeNode(int x) {
    node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Duyệt danh sách từ đầu đến cuối
void duyetNode(node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Đếm tất cả các node có trong danh sách
int countNode(node *head) {
    int cnt = 0;
    while(head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// Chèn node vào đầu danh sách
void pushFront(node **head, int x) {
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

// Chèn node vào cuối danh sách
void pushBack(node **head, int x) {
    node *newNode = makeNode(x);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Chèn node vào giữa danh sách
void insert(node **head, int x, int k) {
    int n = countNode(*head);
    if(k < 1 || k > n + 1) return;
    if(k == 1) {
        pushFront(head, x);
        return;
    }
    node *newNode = makeNode(x), *temp = *head;
    for(int i = 1; i <= k - 2; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xoá node ở đầu danh sách
void popFront(node **head) {
    if(*head == NULL) return;
    node *temp = *head;
    *head = (*head)->next;
    delete temp;
}

// Xoá node ở cuối danh sách
void popBack(node **head) {
    node *temp = *head;
    if(*head == NULL) return;
    if(temp->next == NULL) {
        *head = NULL;
        delete temp;
        return;
    }
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    delete last;
}

// Xoá node ở giữa danh sách
void erase(node **head, int k){
    int n = countNode(*head);
    if(k < 1 || k > n) return;
    if(k == 1) {
        popFront(head);
        return;
    }
    node *temp = *head;
    for(int i = 1; i <= k - 2; i++) {
        temp = temp->next;
    }
    node *current = temp->next;
    temp->next = current->next;
    delete current;
}


// Toàn bộ bên dưới là hàm test chương trình:

void menu(node *head, int n) {
    cout << "\n[ DEMO DANH SACH LIEN KET ]\n";
    cout << "------------------------------\n";
    cout << "1. Them phan tu o dau tien\n";
    cout << "2. Them phan tu o giua\n";
    cout << "3. Them phan tu o cuoi cung\n";
    cout << "4. Xoa phan tu o dau tien\n";
    cout << "5. Xoa phan tu o giua\n";
    cout << "6. Xoa phan tu o cuoi cung\n";
    cout << "0. Thoat\n";
    cout << "------------------------------\n";
    cout << "# Danh sach hien tai co " << n << " phan tu\n";
    cout << "# Linked list: " << (n <= 0 ? "Empty" : "");
    duyetNode(head);
    cout << "\n> Nhap lua chon: ";
}

int main() {
    node *head = NULL;
    bool run = true;
    while(run) {
        menu(head, countNode(head));
        int n; cin >> n;
        string text = "> Nhap doi so: ";
        switch(n) {
            case 1:
                int x1; cout << text;
                cin >> x1;
                pushFront(&head, x1);
                break;
            case 3:
                int x3; cout << text;
                cin >> x3;
                pushBack(&head, x3);
                break;
            case 2:
                int x2, k; cout << text;
                cin >> x2 >> k;
                insert(&head, x2, k);
                break;
            case 4:
                popFront(&head);
                break;
            case 5:
                int l; cout << text; cin >> l;
                erase(&head, l);
                break;
            case 6:
                popBack(&head);
                break;
            case 0:
                run = false;
                break;
            default: break;
        }
    }
    return 0;
}