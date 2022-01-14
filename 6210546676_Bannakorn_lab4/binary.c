#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

struct node* insert(struct node* node, int data) {
  // 1. If the tree is empty, return a new, single node
  if (node == NULL) {
    return(newNode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}

void printTree(struct node* root, int level ) {
  int i;
  if (root != NULL) {
    printTree(root->right, level+1);
    for (i=0; i<level; i++) printf("  ");
    printf("%d", root->data);
    printf("\n");
    printTree(root->left, level+1);
  }
}



int search(int x, struct node *root){
    if (root == NULL) 
        return false;
    if (root->data == x) 
        return true;
    else if (root->data > x){
        root = root->left;

        return search(x,root);
    }

    else{
        root = root->right;

        return search(x,root);
    }

    }

int size(struct node* node){
  if ( node == NULL ){
    return 0;
  }
  return size(node->left) + size(node->right) + 1;
}



int maxDepth(struct node* node){
    if ( node == NULL ){
        return 0;
    }
    if (maxDepth(node->left) > maxDepth(node->right)) {
    
    return maxDepth(node->left) + 1;
    }
    else return  maxDepth(node->right) + 1;
}



int minValue(struct node* node){
  if ( node->left == NULL ) {

        return node->data;
  }
  if ( node->left ){

        return minValue(node->left);
  }
  return -1;
}




void printPreOrder(struct node* node){
  if (node != NULL){

    printf("%d ", node->data);

    printPreOrder(node->right);

    printPreOrder(node->left);
  }
}

void printPostorder(struct node* node){
  if (node != NULL){

    printPostorder(node->right);

    printPostorder(node->left);

    printf("%d ", node->data);
  }
}

void printOrder(struct node* node){
  if ( node != NULL ){

    printOrder(node->left);

    printf("%d ", node->data);

    printOrder(node->right);
  }
}

int sameTree(struct node* a, struct node* b){
  if ( a == NULL && b == NULL){
        return true;
  }
  else if (a != NULL && b != NULL) {

    return (a->data == b->data && sameTree(a->left, b->left) && sameTree(a->right, b->right));
    
  }
  return false;
}

int main(int argc, char** argv) {
  FILE *f;
  int i;
  struct node *root, *root2;
  root = NULL;
  root2 = NULL;
  f = fopen(argv[1],"r");
  while (fscanf(f, "%d", &i) != EOF) {
    root = insert(root, i);
  }

  int rand_20[] = {68,35,49,85,36,41,65,2,7,61,93,81,49,81,25,79,58,94,52,58};
  for(int i = 0; i < 20; i++){
    root2 = insert(root2, rand_20[i]);
  }

  printf("root : \n");
  printTree(root, 0);

  printf("\n");

  printf("root2 : \n");
  printTree(root2, 0);

  printf("\n");



  printf("search(%d,root) = %s \n", 0, search(0,root) ? "True" : "False");
  printf("search(%d,root) = %s \n", 50, search(50,root) ? "True" : "False");
  

  printf("size(root) = %d\n", size(root));
  printf("size(root2) = %d\n", size(root2));


  printf("maxDepth(root) = %d \n", maxDepth(root));
  printf("maxDepth(root2) = %d \n", maxDepth(root2));


  printf("minValue(root) = %d \n", minValue(root));
  printf("minValue(root2) = %d \n", minValue(root2));


  printf("printPreOrder(root) = ");
  printPreOrder(root);

  printf("\n");

  printf("printPreOrder(root2) = ");
  printPreOrder(root2);

  printf("\n");


  printf("printPostorder(root) = ");
  printPostorder(root);

  printf("\n");

  printf("printPostorder(root2) = ");
  printPostorder(root2);

  printf("\n");

  printf("printOrder(root) = ");
  printOrder(root);

  printf("\n");

  printf("printOrder(root2) = ");
  printOrder(root2);

  printf("\n");


  printf("sameTree(root,root2) = %s\n" ,sameTree(root,root2) ? "true" : "false");
  printf("\n");
  printTree(root, 0);

  return 0;
}
