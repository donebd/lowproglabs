#include "stree.h"
#include <stdio.h>

void tests() {
    Tree tree = create(10);
    Node *child0 = addNode(55, tree.root);

    if (tree.root->down == child0) printf("Test init tree complete.\n");//test add
    else {
        printf("!!!Test init tree incorrect!!!");
        return;
    }

    if (findParent(child0, &tree) == tree.root) printf("Test find parent complete.\n");//test find parent
    else {
        printf("!!!Test find parent incorrect!!!");
        return;
    }

    if (calcChild(tree.root) == 1 && calcChild(child0) == 0) printf("Test calc child complete.\n");//test calc child
    else {
        printf("!!!Test calc child incorrect!!!");
        return;
    }

    addNode(15, child0);

    if (findParent(findNode(15, &tree), &tree) == child0) printf("Test find with parameter complete.\n");//test find with par
    else {
        printf("!!!Test find with parameter incorrect!!!");
        return;
    }

    if (findParent(tree.root, &tree) == NULL) printf("Test find incorrect parent complete.\n");//test find incorrect parent
    else {
        printf("!!!Test find incorrect parent incorrect!!!");
        return;
    }

    if (findNode(228, &tree) == NULL) printf("Test find incorrect node complete.\n");//test find incorrect node
    else {
        printf("!!!Test find incorrect node incorrect!!!");
        return;
    }

    addNode(1337, child0);
    addNode(1488, child0);
    addNode(65, child0);
    addNode(798787979, child0);

    if (findMax(&tree) == findNode(798787979, &tree)) printf("Test find max node complete.\n");//test find max node
    else {
        printf("!!!Test find max node incorrect!!!");
        return;
    }

    addNode(45, findNode(798787979, &tree));

    if (findParent(findParent(findNode(45, &tree), &tree), &tree) == child0)
        printf("Test nested search complete.\n");//test nested search
    else {
        printf("!!!Test nested search incorrect!!!");
        return;
    }

    if (calcChild(child0) == 5) printf("Test calc children complete.\n");//test calc child
    else {
        printf("!!!Test calc children incorrect!!!");
        return;
    }

    removeNode(findNode(798787979, &tree), &tree);

    if (findNode(45, &tree) == NULL && findNode(798787979, &tree) == NULL && calcChild(child0) == 4 &&
        findMax(&tree)->data == 1488)
        printf("Test remove node complete.\n");//test remove node
    else {
        printf("!!!Test remove node incorrect!!!");
        return;
    }

    printf("All test passed /'0'/ \n");
}

int main(){
    tests();
    return 0;
}

