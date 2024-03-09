#include <iostream>
#include "Tree.h"

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    Tree<int> tree;
    node<int>* node1 = tree.add_node(nullptr, 1);
    node<int>* node2 = tree.add_node(node1, 2);
    node<int>* node3 = tree.add_node(node1, 3);
    node<int>* node4 = tree.add_node(node2, 4);
    node<int>* node5 = tree.add_node(node3, 5);
    node<int>* node6 = tree.add_node(node4, 6);
    node<int>* node7 = tree.add_node(node4, 7);


    //node<int>* node8 = tree.add_node(nullptr, 10);

    // Afisare valorile nodurilor adaugate
    std::cout << "Noduri adaugate: " << std::endl;
    std::cout << node1->data << std::endl;
    std::cout << node2->data << std::endl;
    std::cout << node3->data << std::endl;
    std::cout << node4->data << std::endl;
    std::cout << node5->data << std::endl;
    std::cout << node6->data << std::endl;
    std::cout << node7->data << std::endl;
    tree.delete_node(node1, 0);
    tree.print_root();
    std::cout << tree.get_node(node1,0)->data << std::endl;
    std::cout << tree.count(tree.get_node(nullptr,0)) << std :: endl;
    tree.insert(nullptr, 0, 99);
    std::cout << tree.get_node(nullptr, 0)->data << std::endl;
    tree.sort(node4, compare);
    //std::cout << tree.find(2)->data;
    return 0;

}
