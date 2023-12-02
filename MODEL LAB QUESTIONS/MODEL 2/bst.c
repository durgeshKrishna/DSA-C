#include <stdio.h>
#include <stdlib.h>

struct bnode {
    int data;
    struct bnode *left;
    struct bnode *right;
};

struct bnode *root = NULL;

struct bnode *newnode(int data) {
    struct bnode *node = (struct bnode *)malloc(sizeof(struct bnode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct bnode *insert(struct bnode *root, int data) {
    if (root == NULL) {
        root = newnode(data);
        return root;
    } else if (root->data == data) {
        printf("\nDuplicate element is not allowed");
        return root;
    } else if (root->data > data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct bnode *min(struct bnode *root) {
    if (root == NULL)
        return root;
    else if (root->left == NULL)
        return root;
    else
        return min(root->left);
}

struct bnode *deletenode(struct bnode *root, int ele) {
    if (root == NULL) {
        printf("\nNull");
        return root;
    } else if (root->data > ele) {
        root->left = deletenode(root->left, ele);
    } else if (root->data < ele) {
        root->right = deletenode(root->right, ele);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root;
        } else if (root->left == NULL) {
            struct bnode *temp = root;
            root = root->right;
            free(temp);
            return root;
        } else if (root->right == NULL) {
            struct bnode *temp = root;
            root = root->left;
            free(temp);
            return root;
        } else {
            struct bnode *temp = min(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
            return root;
        }
    }
}

void display(struct bnode *root) {
    if (root == NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main() {
    int ele, ch;
    while (1) {
        printf("\n1->Insert\n2->Delete\n3->Display\n4->Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data to be inserted in the BST: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Enter the element to delete in the BST: ");
                scanf("%d", &ele);
                root = deletenode(root, ele);
                break;
            case 3:
                printf("BST Contents: ");
                display(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("\nINVALID OPTION");
        }
    }
    return 0;
}

