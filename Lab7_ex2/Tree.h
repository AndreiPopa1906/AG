#pragma once
#include <iostream>
#include <algorithm>

template <class T>
class node
{
public:
	int allocated = 5;
	int grow = 10;
	int index = 0;
	T data = 0;
	node<T>** child = new node<T>*[allocated]();
};

template<class T>
class Tree 
{
	node<T>* root;
public:
	//node<T>* result = nullptr;
	Tree() {
		root = new node<T>();
		root->index = 0;
		root->allocated = 5;
		root->grow = 10;
		root->data = T();
		root->child = new node<T>*[root->allocated];
		for (int i = 0; i < root->allocated; i++) {
			root->child[i] = nullptr;
		}
	}
	node<T>* dfs(node<T>* current_node, T value) {
		if (current_node->data == value) {
			return current_node;
		}
		for (int i = 0; i < current_node->index; i++) {
			node<T>* result = dfs(current_node->child[i], value);
			if (result != nullptr) {
				return result;
			}
		}
		return nullptr;
	}
	int find_number_nodes(node<T>* current_node)
	{
		if (current_node == nullptr) return 0;
		else
		{
			int sum = 0;
			for (int i = 0; i < current_node->index; i++)
				sum += find_number_nodes(current_node->child[i]);
			return sum + current_node->index;
		}
	}

	node<T>* add_node(node<T>* parent, T data) {
		if (parent)
		{
			node<T>* new_node = new node<T>();
			new_node->data = data;

			if (parent->allocated == parent->index) {
				parent->allocated += parent->grow;
				node<T>** new_child = new node<T>*[parent->allocated]();
				for (int i = 0; i < parent->index; i++) {
					new_child[i] = parent->child[i];
				}
				delete[] parent->child;
				parent->child = new_child;
			}

			parent->child[parent->index] = new_node;
			parent->index++;

			return new_node;
		}
		else
		{
			root->data = data;

			return root;
		}

	}
	node<T>* get_node(node<T>* parent, int index) {
		if (parent == nullptr) return root;
		else return parent->child[index];
	}
	void delete_node(node<T>* parent, int index) {
		if (parent == nullptr) {
			if (index < root->index) delete_node(root, index);
		}
		else if (index < parent->index) {
			node<T>* node_delete = parent->child[index];
			parent->index--;
			for (int i = index; i < parent->index; i++) {
				parent->child[i] = parent->child[i + 1];
			}
			parent->child[parent->index] = nullptr;
			delete node_delete;
		}
	}
	node<T>* find(T value) {
		node<T>* current_node = root;
		return dfs(current_node, value);;
	}
	void insert(node<T>* parent,int index, T value)
	{
		node<T>* new_node = new node<T>();
		new_node->data = value;

		if (parent){
			node<T>* aux = parent->child[index];
			parent->child[index] = new_node;
			new_node->child[0] = aux;
			new_node->index++;
		}
		else
		{
			node<T>* aux = root->child[index];
			root->child[index] = new_node;
			new_node->child[0] = aux;
			new_node->index++;
		}
	}
	void sort(node<T>* parent, bool (*compare)(T, T)) {
		for(int i = 0; i < parent->index - 1; i++)
			for (int j = i + 1; j < parent->index; j++)
				if(compare(parent->child[i]->data, parent->child[j]->data) == false)
				{
					std :: swap(parent->child[i]->data, parent->child[j]->data);
				}
	}
	int count(node<T>* current_node) {
		if(current_node == nullptr) return 1 + find_number_nodes(root);
		else return 1 + find_number_nodes(current_node);
	}
	void print_root() {
		std::cout << root->data << std::endl;
	}
};
