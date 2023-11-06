#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int ht;
};

struct node *rotateright(struct node *x) {
    struct node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

struct node *rotateleft(struct node *x) {
    struct node *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

struct node *RR(struct node *T) {
    T = rotateleft(T);
    return (T);
}

struct node *LL(struct node *T) {
    T = rotateright(T);
    return (T);
}

struct node *LR(struct node *T) {
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return (T);
}

struct node *RL(struct node *T) {
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return (T);
}

struct node *insert(struct node *T, int x) {
    if (T == NULL) {
        T = (struct node *)malloc(sizeof(struct node));
        T->data = x;
        T->left = NULL;
        T->right = NULL;
    } else if (x > T->data) {
        T->right = insert(T->right, x);
        if (BF(T) == -2)
            if (x > T->right->data)
                T = RR(T);
            else
                T = RL(T);
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2)
            if (x < T->left->data)
                T = LL(T);
            else
                T = LR(T);
    }
    T->ht = height(T);
    return (T);
}

struct node *Delete(struct node *T, int x) {
    struct node *p;
    if (T == NULL) {
        return NULL;
    } else if (x > T->data) {
        T->right = Delete(T->right, x);
        if (BF(T) == 2)
            if (BF(T->left) >= 0)
                T = LL(T);
            else
                T = LR(T);
    } else if (x < T->data) {
        T->left = Delete(T->left, x);
        if (BF(T) == -2)
            if (BF(T->right) <= 0)
                T = RR(T);
            else
                T = RL(T);
    } else {
        if (T->right != NULL) {
            p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = Delete(T->right, p->data);
            if (BF(T) == 2)
                if (BF(T->left) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
        } else
            return (T->left);
    }
    T->ht = height(T);
    return (T);
}

int height(struct node *T) {
    if (T == NULL)
        return -1;
    else
        return T->ht;
}

int BF(struct node *T) {
    int lh, rh;
    if (T == NULL)
        return (0);
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    return (lh - rh);
}

void preorder(struct node *T) {
    if (T != NULL) {
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(struct node *T) {
    if (T != NULL) {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

struct node *search(struct node *T, int x) {
    if (T == NULL) {
        return NULL; // Node not found
    }
    if (x == T->data) {
        return T; // Node found
    }
    if (x < T->data) {
        return search(T->left, x); // Search in the left subtree
    }
    return search(T->right, x); // Search in the right subtree
}

int main() {
    struct node *root = NULL;
    int x, n, i, op;
    struct node *result; // To store the result of the search

    do {
        printf("\n1)Create:");
        printf("\n2)Insert:");
        printf("\n3)Delete:");
        printf("\n4)Search:");
        printf("\n5)Print:");
        printf("\n6)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEnter no. of elements:");
                scanf("%d", &n);
                printf("\nEnter tree data:");
                root = NULL;
                for (i = 0; i < n; i++) {
                    scanf("%d", &x);
                    root = insert(root, x);
                }
                break;
            case 2:
                printf("\nEnter a data:");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 3:
                printf("\nEnter a data:");
                scanf("%d", &x);
                root = Delete(root, x);
                break;
            case 4:
                printf("\nEnter a data to search:");
                scanf("%d", &x);
                result = search(root, x);
                if (result != NULL) {
                    printf("Found: %d\n", result->data);
                } else {
                    printf("Not Found\n");
                }
                break;
            case 5:
                printf("\nPreorder sequence:\n");
                preorder(root);
                printf("\n\nInorder sequence:\n");
                inorder(root);
                printf("\n");
                break;
        }
    } while (op != 6);

    return 0;
}

