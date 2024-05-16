#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[6];
    struct Node* parent;
}Node;

int main() {
    int t;
    scanf("%d", &t);

    int n;
    for(int i = 0 ; i < t ; i++) {
        scanf("%d", &n);
        Node** tree = (Node*)malloc(sizeof(Node) * n);
        // root
        Node* root = (Node*)malloc(sizeof(Node));
        root->parent = NULL;
        tree[0] = root;
        // input directory structure
        int parent;
        int index;
        for(int j = 1 ; j < n ; j++) {
            scanf("%d %d", &parent, &index);
            Node* node = (Node*)malloc(sizeof(Node));
            node->parent = tree[parent-1];
            tree[index-1] = node;
        }
        // input directory name
        char name[6];
        for(int j = 0 ; j < n ; j++) {
            scanf("%s", name);
            strcpy(tree[j]->name, name);
        }
        // print result (length of path)
        for(int j = 0 ; j < n ; j++) {
            Node* node = tree[j];
            int length = 0;
            // recursively follow the parent node
            while(node != NULL) {
                length += strlen(node->name);
                node = node->parent;
                length++; // '/' of the path
            }
            length--; // remove last '/'
            printf("%d\n", length);
        }

        // memory deallocation
        for(int j = 0 ; j < n ; j++) {
            free(tree[j]);
        }
        free(tree);
    }
}