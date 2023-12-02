#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;
int dataArray[20];
int arrayIndex = 0;

struct TreeNode *createNewNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *insertBST(struct TreeNode *root, int element) {
    if (root == NULL) {
        root = createNewNode(element);
        return root;
    }
    if (root->data > element)
        root->left = insertBST(root->left, element);
    else if (root->data < element)
        root->right = insertBST(root->right, element);
    return root;
}

struct TreeNode *inOrderAndStore(struct TreeNode *root) {
    if (root == NULL)
        return root;
    inOrderAndStore(root->left);
    dataArray[arrayIndex++] = root->data;
    inOrderAndStore(root->right);
}

int findMedian(int arr[]) {
    int middle;
    if (arrayIndex % 2 == 0) {
        middle = arrayIndex / 2;
        return (arr[middle - 1] + arr[middle]) / 2;
    } else {
        middle = arrayIndex / 2;
        return arr[middle];
    }
}

int main() {
    int choice, element, result,j;
    while (1) {
        printf("\n1 -> Create Binary Search Tree\n2 -> Find Median\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted in the Binary Search Tree: ");
                scanf("%d", &element);
                root = insertBST(root, element);
                break;
            case 2:
                inOrderAndStore(root);
                printf("\nArray representation of the BST:\n");
                for ( j = 0; j < arrayIndex; j++) {
                    printf("%d ", dataArray[j]);
                }
                result = findMedian(dataArray);
                printf("\nMedian of the Binary Search Tree: %d\n", result);
                break;
            default:
                printf("\nInvalid option\n");
        }
    }
    return 0;
}

