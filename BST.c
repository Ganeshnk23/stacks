#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inOrderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        inOrderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inOrderTraversal(root->right, file);
    }
}

void preOrderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preOrderTraversal(root->left, file);
        preOrderTraversal(root->right, file);
    }
}

void postOrderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        postOrderTraversal(root->left, file);
        postOrderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

int main() {
    Node* root = NULL;

    int numNodes;
    int minRange, maxRange;

    FILE* inputFile = fopen("input.txt", "r");  // Open the input file in read mode
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Read the number of nodes, minimum range, and maximum range from the input file
    fscanf(inputFile, "%d", &numNodes);
    fscanf(inputFile, "%d", &minRange);
    fscanf(inputFile, "%d", &maxRange);

    fclose(inputFile);  // Close the input file
int i;
    // Generate random numbers within the specified range and insert them into the binary search tree
    srand(time(0));  // Seed the random number generator
    for ( i = 0; i < numNodes; i++) {
        int randomNumber = (rand() % (maxRange - minRange + 1)) + minRange;
        root = insertNode(root, randomNumber);
    }

    FILE* outputFile = fopen("output.txt", "w");  // Open the output file in write mode
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }

    fprintf(outputFile, "In-order traversal: ");
    inOrderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Pre-order traversal: ");
    preOrderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Post-order traversal: ");
    postOrderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fclose(outputFile);  // Close the output file

    printf("Output saved to the file 'output.txt'.\n");

    // Open the input file for viewing
    #ifdef _WIN32
        system("start notepad input.txt");
    #elif __APPLE__
        system("open -t input.txt");
    #elif __linux__
        system("xdg-open input.txt");
    #endif

    return 0;
}



