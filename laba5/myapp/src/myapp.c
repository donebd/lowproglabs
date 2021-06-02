#include "stdio.h"
#include "stree.h"
#include "stdlib.h"
#include "time.h"

void demo1() {
    srand(time(NULL));
    printf("Test creating tree\n");
    printf("Enter root of tree: ");
    int root;
    scanf("%d", &root);
    Tree tree = create(root);
    int nodes;
    printf("How many nodes: ");
    int node;
    int a;
    scanf("%d", &nodes);
    for (int i = 0; i < nodes; i++) {
        tprint(&tree);
        printf("Where connect next node?");
        scanf("%d", &node);
        a = rand();
        addNode(a, findNode(node, &tree));
    }
    tprint(&tree);
}

void demo2() {
    printf("\nTest remove node\n");
    Tree newtree = create(10);
    addNode(228, newtree.root);
    addNode(69, findNode(228, &newtree));
    addNode(98, findNode(69, &newtree));
    addNode(12, findNode(69, &newtree));
    addNode(47, findNode(228, &newtree));
    addNode(137, newtree.root);
    addNode(55, findNode(137, &newtree));
    addNode(224, findNode(55, &newtree));
    tprint(&newtree);
    printf("Max element = %d \n", findMax(&newtree)->data);
    printf("How many nodes want to delete: ");
    int node;
    int nodes;
    scanf("%d", &nodes);
    for (int i = 0; i < nodes; i++) {
        printf("Removing element: ");
        scanf("%d", &node);
        removeWith(node, &newtree);
        tprint(&newtree);
        if (newtree.root == NULL) {
            printf("Test over\n");
            return;
        }
        printf("Max element = %d \n", findMax(&newtree)->data);
    }
}

int main( void ) {
    demo1();
    demo2();
    return 0;
}
