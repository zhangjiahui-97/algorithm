#include<iostream>
using namespace std;
#include<string>

struct Node {
    int key;
    Node *left, *right, *parent;
};

Node *root, *NIL;

Node* find(Node *x, int k) { 
    if (x == NIL) 
        return 0;
    while(x != NIL) {
        if (x->key == k) {
            return x;
        } else if(x->key > k) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return NIL;
}

void del(Node *u, int k, int flag = 0) {
    // find k
    Node *d;
    if (flag) {
        d = u;
    } else {
        d = find(u, k);
    }
    if (d->left == NIL && d->right == NIL) {
        if (d == root) {
            delete d;
            return;
        }
        if (d->parent->left == d) {
            d->parent->left = NIL;
        } else {
            d->parent->right = NIL;
        }
        delete d;
    } else if (d->left != NIL && d->right == NIL) {
        if (d == root) {
            root = root->left;
            delete d;
            return;
        }
        if (d->parent->left == d) {
            d->parent->left = d->left;
        } else {
            d->parent->right = d->left;
        delete d; 
        }
    } else if (d->left == NIL && d->right != NIL) {
        if (d == root) {
            root = root->right;
            delete d;
            return;
        }
        if (d->parent->left == d) {
            d->parent->left = d->right;
        } else {
            d->parent->right = d->right;
        }
        delete d; 
    } else {
        Node *temp = d->right;
        Node *y;
        while(temp) {
            y = temp;
            temp = temp->left;
        }
        int tmp;
        tmp = y->key;
        y->key = d->key;
        d->key = tmp;
        cout << endl;
        del(y, k, 1);
    }
}

void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void preorder(Node *u) {
    if (u == NIL) return;
    printf("%d ", u->key);
    preorder(u->left);
    preorder(u->right);
}

void inorder(Node *u) {
    if (u == NIL) return;
    inorder(u->left);
    printf("%d ", u->key);
    inorder(u->right);
}

int main()
{
    freopen("in", "r", stdin);
    int n, i, x;
    string com;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        cin >> com;
        if (com == "insert") {
            scanf("%d", &x);
            insert(x);
        } else if (com == "print") {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        } else if (com == "find") {
            scanf("%d", &x);
            if (find(root, x) != NIL) 
                printf("can find\n");
            else 
                printf("not find\n");
        } else if (com == "delete") {
            scanf("%d", &x);
            del(root, x);
        }
    }
}