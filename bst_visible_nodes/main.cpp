#include "BST.h"

int main() {
  BST<int> bst;
  bst.insert(4);
  bst.insert(3);
  bst.insert(5);
  bst.insert(1);
  bst.insert(8);
  bst.insert(7);
  bst.insert(3);
  bst.insert(9);
  bst.insert(5);
  bst.insert(4);
  bst.print_BST();

  printf("\nIn Order:\n");
  bst.print_inOrder();
  printf("\nPre Order:\n");
  bst.print_preOrder();
  printf("\nPost Order:\n");
  bst.print_postOrder();

  bst.getVisibleNodesPredecessor();
  bst.getVisibleNodesParent();

  bst.getMaxHeight();

  return 0;
}
