#include <iostream>

struct node {
    int val;
    node *left;
    node *right;
};

struct Queue {
    node *t[100];
    int front;
    int rear;
};

Queue queue;

void enqueue(node *n) { queue.t[queue.rear++] = n; }
node *dequeue() { return (queue.t[queue.front++]); } 


// membuat fungsi untuk memasukkan value
void Insert(node *n, int x) {
    if (x < n->val) {
        if (n->left == NULL) {
            node *temp = new node;
            temp->val = x;
            temp->left = NULL;
            temp->right = NULL;
            n->left = temp;
        } else {
            Insert(n->left, x);
        }
    } else {
        if (n->right == NULL) {
            node *temp = new node;
            temp->val = x;
            temp->left = NULL;
            temp->right = NULL;
            n->right = temp;
        } else {
            Insert(n->right, x);
        }
    }
}

int floatMaxInLeftST(node *n) {
    while (n->right != NULL) {
        n = n->right;
    }
    return n->val;
}

// membuat fungsi untuk remove
void Remove(node *p, node *n, int x) {
    if (n->val == x) {
        if (n->right == NULL && n->left == NULL) {
            if (x < p->val) {
                p->left = NULL;
            } else {
                p->right = NULL;
            }
        } else if (n->right == NULL) {
            if (x < p->val) {
                p->left = n->left;
            } else {
                p->right = n->left;
            }
        } else if (n->left == NULL) {
            if (x < p->val) {
                p->left = n->right;
            } else {
                p->right = n->right;
            }
        } else {
            int y = floatMaxInLeftST(n->left);
            n->val = y;
            Remove(n, n->left, y);  // perbaikan disini
        }
    } else if (x < n->val) {
        Remove(n, n->left, x);
    } else {
        Remove(n, n->right, x);
    }
}

void BFT(node *n) {
    if (n != NULL) {
        std::cout << n->val << " ";
        if (n->left != NULL) enqueue(n->left);
        if (n->right != NULL) enqueue(n->right);
        if (queue.front != queue.rear) {
            node *next = dequeue();
            BFT(next);
        }
    }
}

void Pre(node *n) {
    if (n != NULL) {
        std::cout << n->val << " ";
        Pre(n->left);
        Pre(n->right);
    }
}

void In(node *n) {
    if (n != NULL) {
        In(n->left);
        std::cout << n->val << " ";
        In(n->right);
    }
}

void Post(node *n) {
    if (n != NULL) {
        Post(n->left);
        Post(n->right);
        std::cout << n->val << " ";
    }
}

int main() {
    queue.front = 0;
    queue.rear = 0;
    int value;
    int ch;
    node *root = new node;
    std::cout << "\nMasukkan root value: ";
    std::cin >> value;
    root->val = value;
    root->left = NULL;
    root->right = NULL;

    do {
        std::cout << "\n1. Insert"
                  << "\n2. Delete"
                  << "\n3. Breadth First"
                  << "\n4. Preorder depth first"
                  << "\n5. Inorder depth first"
                  << "\n6. Postorder depth first"
                  << "\nPilih menu: ";
        std::cin >> ch;
        int x;
        switch (ch) {
            case 1:
                std::cout << "\nmasukkan value: ";
                std::cin >> x;
                Insert(root, x);
                break;
            case 2:
                std::cout << "\nmasukkan value untuk dihapus: ";
                std::cin >> x;
                Remove(root, root, x);
                break;
            case 3:
                BFT(root);
                break;
            case 4:
                Pre(root);
                break;
            case 5:
                In(root);
                break;
            case 6:
                Post(root);
                break;
        }
    } while (ch != 0);

    return 0;
}
