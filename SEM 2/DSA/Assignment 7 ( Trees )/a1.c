#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *createTree(Node *root, int n)
{
    int data;
    printf("Enter %d values to insert:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int countLeaf(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    Node *root = NULL;
    int choice, value, n;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Pre-Order Traversal\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter how many numbers to insert: ");
            scanf("%d", &n);
            root = createTree(root, n);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
            {
                printf("Value %d found in the tree.\n", value);
            }
            else
            {
                printf("Value %d not found in the tree.\n", value);
            }
            break;
        case 3:
            printf("In-Order Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-Order Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Pre-Order Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 6:
            printf("Number of leaf nodes: %d\n", countLeaf(root));
            break;
        case 7:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
