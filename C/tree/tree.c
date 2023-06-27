#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree tree;
// Create a tree
tree *create_tree(int data){
    tree *t = (tree *)malloc(sizeof(tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

// Insert a node in the tree
tree *insert(tree *t, int data){
    if (t == NULL){
        return create_tree(data);
    }
    else if (data < t->data){
        t->left = insert(t->left, data);
    }
    else if (data > t->data){
        t->right = insert(t->right, data);
    }
    return t;
}

// Search a node in the tree
tree *search(tree *t, int data){
    if (t == NULL){
        return NULL;
    }
    else if (data < t->data){
        return search(t->left, data);
    }
    else if (data > t->data){
        return search(t->right, data);
    }
    else{
        return t;
    }
}   

int main(){
    tree *t = create_tree(5);
    insert(t, 3);
    insert(t, 7);
    insert(t, 1);
    insert(t, 4);
    insert(t, 6);
    insert(t, 8);
    tree *n = search(t, 4);
    printf("%d \n", n->data);
    return 0;
}