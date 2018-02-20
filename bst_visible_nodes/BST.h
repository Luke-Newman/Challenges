//
// Created by luken on 19/02/2018.
//

#ifndef TREE_BST_H
#define TREE_BST_H

#include <iostream>
#include <memory>
#include <iomanip>
#include <vector>

template <class T>
class BST
{
    struct NODE;
    typedef std::unique_ptr<NODE> spNODE;
private:
    struct NODE
    {
        T data;
        spNODE left;
        spNODE right;
        explicit NODE(const T &value):data(value),left(nullptr),right(nullptr){}
    };

    spNODE root;
    void _print(const spNODE &node, int level) const;
    void _inOrder(const spNODE &p) const;
    void _preOrder(const spNODE &p) const;
    void _postOrder(const spNODE &p) const;
    void _markVisibleNodesPredecessor(const spNODE &p, std::vector<int> &nodes,
                                      int highest) const;
    void _markVisibleNodesParent(const spNODE &p, std::vector<int> &nodes,
                                      int parent) const;

public:
    BST() { root = nullptr; }
    void insert(const T & ref);
    void print_BST()const;
    bool tree_empty() const { return root == nullptr; }
    void print_inOrder();
    void print_preOrder();
    void print_postOrder();
    void getVisibleNodesPredecessor() const;
    void getVisibleNodesParent() const;


};

template<class T>
void BST<T>::insert(const T & ref) {
    std::unique_ptr<NODE> node(new NODE(ref));

    if (root == nullptr)
        root = std::move(node);
    else {
        NODE* tmp = root.get();
        NODE* prev = root.get();

        /* move down tree from root until we reach empty child */
        while (tmp != nullptr)
        {
            prev = tmp;
            if (tmp->data < ref)
                tmp = tmp->right.get();
            else
                tmp = tmp->left.get();
        }

        if (prev->data < ref)
            prev->right = std::move(node);
        else
            prev->left = std::move(node);
    }
}

template<class T>
void BST<T>::print_BST()const
{
    _print(root, 0);
}

template<class T>
void BST<T>::_print(const spNODE &node, int level) const
{
    int i;

    /* Very basic print out of tree */

    if (node) {
        _print(node->right, level + 1);

        std::cout << "Level: " << std::setw(3) << level;

        for (i = 0; i <= level; i++)
            std::cout << "....";

        std::cout << std::setw(3) << node->data << std::setw(3) << '\n';

        _print(node->left, level + 1);
    }
}

template<class T>
void BST<T>::print_inOrder()
{
    if (tree_empty()) return;
    _inOrder(root);
}

template<class T>
void BST<T>::_inOrder(const spNODE &p) const
{
    /*
        1. Traverse the left subtree, i.e., call Inorder(left-subtree)
        2. Visit the root.
        3. Traverse the right subtree, i.e., call Inorder(right-subtree)
    */

    if(p->left) _inOrder(p->left);
    std::cout << " " << p->data << " ";
    if(p->right) _inOrder(p->right);
}

template<class T>
void BST<T>::print_preOrder() {
    if (tree_empty()) return;
    _preOrder(root);
}

template<class T>
void BST<T>::_preOrder(const spNODE &p) const
{
    /*
        1. Visit the root.
        2. Traverse the left subtree, i.e., call preOrder(left-subtree)
        3. Traverse the right subtree, i.e., call _preOrder(right-subtree)
     */

    std::cout << " " << p->data << " ";
    if (p->left) _preOrder(p->left);
    if (p->right) _preOrder(p->right);
}

template<class T>
void BST<T>::print_postOrder() {
    if (tree_empty()) return;
    _postOrder(root);
}

template<class T>
void BST<T>::_postOrder(const spNODE &p) const
{
    /*
        1. Traverse the left subtree, i.e., call postOrder(left-subtree)
        2. Traverse the right subtree, i.e., call _postOrder(right-subtree)
        3. Visit the root.
     */

    if (p->left) _postOrder(p->left);
    if (p->right) _postOrder(p->right);
    std::cout << " " << p->data << " ";
}

template<class T>
void BST<T>::getVisibleNodesPredecessor() const
{
    /* Parent is referering to the immediate parent of child node */
    std::vector<int> nodes_list;

    if (tree_empty()) return;

    std::cout << "\n\nList of visible nodes higher than the parent\nwhere "
            "parent "
                 "is referring to the predecessor with the highest value:\n";

    _markVisibleNodesPredecessor(root, nodes_list, root->data);

    for (int i : nodes_list)
        std::cout << i << " ";

    printf("\n");
}

template<class T>
void BST<T>::_markVisibleNodesPredecessor(const BST::spNODE &p, std::vector<int>
&nodes, int highest) const
{
    if (p->data > highest)
    {
        highest = p->data;
        nodes.push_back(highest);
    }

    /* Could get away with only checking right for my tree, but this will also
       will work if the tree prioritises highest to left*/
    if (p->left) _markVisibleNodesPredecessor(p->left, nodes, highest);
    if (p->right) _markVisibleNodesPredecessor(p->right, nodes, highest);
}

template<class T>
void BST<T>::getVisibleNodesParent() const
{
    /* Parent is referering to the immediate parent of child node */
    std::vector<int> nodes_list;

    if (tree_empty()) return;

    std::cout << "\nList of visible nodes higher than parent,\nwhere parent "
            "is referring to the immediate parent of two child nodes:\n";

    _markVisibleNodesParent(root, nodes_list, root->data);

    for (int i : nodes_list)
        std::cout << i << " ";

    printf("\n");
}

template<class T>
void
BST<T>::_markVisibleNodesParent(const BST::spNODE &p, std::vector<int> &nodes,
                                int parent) const
{
    if (p->data > parent)
        nodes.push_back(p->data);

    if (p->left) _markVisibleNodesParent(p->left, nodes, p->data);
    if (p->right) _markVisibleNodesParent(p->right, nodes, p->data);
}

#endif //TREE_BST_H
