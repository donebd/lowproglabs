#include "stree.h"
#include <stdio.h>

void tests() {
    Tree tree = create(10);
    Node *child0 = addNode(55, tree.root);

    if (tree.root->down == child0) printf("Test 1 complete.\n");//test add
    else {
        printf("!!!Test 1 incorrect!!!");
        return;
    }

    if (findParent(child0, &tree) == tree.root) printf("Test 2 complete.\n");//test find parent
    else {
        printf("!!!Test 2 incorrect!!!");
        return;
    }

    if (calcChild(tree.root) == 1 && calcChild(child0) == 0) printf("Test 3 complete.\n");//test calc child
    else {
        printf("!!!Test 3 incorrect!!!");
        return;
    }

    addNode(15, child0);

    if (findParent(findNode(15, &tree), &tree) == child0) printf("Test 4 complete.\n");//test find with par
    else {
        printf("!!!Test 4 incorrect!!!");
        return;
    }

    if (findParent(tree.root, &tree) == NULL) printf("Test 5 complete.\n");//test find incorrect parent
    else {
        printf("!!!Test 5 incorrect!!!");
        return;
    }

    if (findNode(228, &tree) == NULL) printf("Test 6 complete.\n");//test find incorrect node
    else {
        printf("!!!Test 6 incorrect!!!");
        return;
    }

    addNode(1337, child0);
    addNode(1488, child0);
    addNode(65, child0);
    addNode(798787979, child0);

    if (findMax(&tree) == findNode(798787979, &tree)) printf("Test 7 complete.\n");//test find max node
    else {
        printf("!!!Test 7 incorrect!!!");
        return;
    }

    addNode(45, findNode(798787979, &tree));

    if (findParent(findParent(findNode(45, &tree), &tree), &tree) == child0)
        printf("Test 8 complete.\n");//test nested search
    else {
        printf("!!!Test 8 incorrect!!!");
        return;
    }

    if (calcChild(child0) == 5) printf("Test 9 complete.\n");//test calc child
    else {
        printf("!!!Test 9 incorrect!!!");
        return;
    }

    removeNode(findNode(798787979, &tree), &tree);

    if (findNode(45, &tree) == NULL && findNode(798787979, &tree) == NULL && calcChild(child0) == 4 &&
        findMax(&tree)->data == 1488)
        printf("Test 10 complete.\n");//test remove node
    else {
        printf("!!!Test 10 incorrect!!!");
        return;
    }

    printf("All test passed /'0'/ \n");
}

int main(){
    tests();
    return 0;
}

