#pragma once

#include <cstddef>

struct Node
{
    int item;
    Node * parent = nullptr;
    Node * left = nullptr;
    Node * right = nullptr;
};


class Tree{
private:
    Node * head = nullptr;
    void traverse(void (*operation) (Node * node_p), Node * node_p);
    Node * copy(const Node & copy_from, Node * parent);
public:
    Tree() = default;
    Tree(int * array, size_t array_size);
    Tree(const Tree & copy_from);
    void insert_tree(Node ** came_from, int item, Node * parent);
    void traverse(void (*operation) (Node * node_p));
    ~Tree();
};
