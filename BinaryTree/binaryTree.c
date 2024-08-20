#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct node *insert(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

struct node *search(struct node *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

struct node *min_value_node(struct node *node) {
  struct node *current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

struct node *delete(struct node *root, int data) {
  if (root == NULL) {
    return root;
  } else if (data < root->data) {
    root->left = delete (root->left, data);
  } else if (data > root->data) {
    root->right = delete (root->right, data);
  } else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = min_value_node(root->right);
    root->data = temp->data;
    root->right = delete (root->right, temp->data);
  }
  return root;
}

void inorder_traversal(struct node *root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}




int main() {
  struct node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  printf("Deleting 20: ");
  root = delete (root, 20);
  inorder_traversal(root);
  printf("\n");

  printf("Deleting 30: ");
  root = delete (root, 30);
  inorder_traversal(root);
  printf("\n");

  printf("Deleting 50: ");
  root = delete (root, 50);
  inorder_traversal(root);
  printf("\n");

  return 0;
}
