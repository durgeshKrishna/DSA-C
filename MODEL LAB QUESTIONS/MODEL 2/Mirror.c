#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree() {
    struct TreeNode *node;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int element;
    printf("\nEnter the data for the binary tree node (Enter -1 for no child): ");
    scanf("%d", &element);
    if (element == -1) {
        printf("No child is created.");
        return NULL;
    }
    node->data = element;
    printf("\nEnter the left child of the node (%d):", element);
    node->left = createTree();
    printf("\nEnter the right child of the node (%d):", element);
    node->right = createTree();
    return node;
}

struct TreeNode *mirrorTree(struct TreeNode *root) {
    struct TreeNode *temp;
    if (root == NULL) {
        return NULL;
    }
    mirrorTree(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void inorderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode *root = NULL, *mirroredTree;
    root = createTree();
    printf("\nInorder traversal of the original tree: ");
    inorderTraversal(root);

    mirroredTree = mirrorTree(root);

    printf("\nInorder traversal of the mirrored tree: ");
    inorderTraversal(mirroredTree);

    return 0;
}

