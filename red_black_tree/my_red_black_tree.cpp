#include "my_red_black_tree.h"
#include <iostream>

red_black_node* add_node(red_black_node* ptr, int key);
void delete_all(red_black_node* &ptr);
void flip_color(red_black_node* ptr);
red_black_node* rotate_left(red_black_node* ptr);
red_black_node* rotate_right(red_black_node* ptr);
int size_of_subarray(red_black_node* ptr);
bool isRed(red_black_node* ptr);

//constructor
red_black_tree::red_black_tree(){
	root = nullptr;
}
//desctructor
red_black_tree::~red_black_tree(){
	clear();
}
//insert a new node
void red_black_tree::insert(int key){
	root = add_node(root, key);
	root->color = BLACK;	//set root->color to black
}
//clear the whole tree
void red_black_tree::clear(){
	delete_all(root);
}
//print the whole tree
void red_black_tree::print(){
	if(root == nullptr)	std::cout << "The tree is empty";
	else print(root);
}
//helper function to print
void red_black_tree::print(red_black_node* ptr){
	if(ptr == nullptr)	return;	//don't print nullptr
	std::cout << "\nKey   : " << ptr->key
		      << "\nleft  : ";
	if(ptr->left == nullptr) std::cout << "null";
	else	std::cout << ptr->left->key;
	std::cout << ((isRed(ptr->left))? " Red\n" : "\n")
			  << "right : ";
	if(ptr->right== nullptr) std::cout << "null";
	else	std::cout << ptr->right->key;
	std::cout << ((isRed(ptr->right))? " Red\n" : "\n");
	print(ptr->left);
	print(ptr->right);
}
//helper function to recursively delete all nodes
void delete_all(red_black_node* &ptr){
	if(ptr == nullptr)	return;
	
	//delete left, right then itself
	delete_all(ptr->left);
	delete_all(ptr->right);
	delete ptr;	//delete itself
	//set it self to nullptr
	ptr = nullptr;
}

//helper function to recursively insert a new node
red_black_node* add_node(red_black_node* ptr, int key){
	if(ptr == nullptr)	return (new red_black_node(key, RED));	//end of recursion
	
	if(ptr->key < key)		ptr->right = add_node(ptr->right, key);
	else if(ptr->key > key) ptr->left  = add_node(ptr->left, key);
	else return ptr;	//if equal, then nothing happens
	
	//3 checks
	if(!isRed(ptr->left) && isRed(ptr->right))		ptr = rotate_left(ptr);
	if(isRed(ptr->left) && isRed(ptr->left->left))	ptr = rotate_right(ptr);
	if(isRed(ptr->left) && isRed(ptr->right))		flip_color(ptr);
	
	ptr->n = 1 + size_of_subarray(ptr->left) + size_of_subarray(ptr->right);	//add size
	
	return ptr;
}

//helper function to flip color
void flip_color(red_black_node* ptr){
	ptr->color = RED;
	ptr->left->color  = BLACK;
	ptr->right->color = BLACK;
}
//helper function to perform rotate left
red_black_node* rotate_left(red_black_node* ptr){
	//exchange position
	red_black_node* x = ptr->right;
	ptr->right = x->left;	//x->left, move to ptr->right, while ptr->left, and x->right are constant
	x->left = ptr;	//x is now parent of ptr
	//correct color
	x->color = ptr->color;	//NOTE: not necessarily to be black 
	ptr->color = RED;
	//correct new n (size of the subarray)
	ptr->n = 1 + size_of_subarray(ptr->left) + size_of_subarray(ptr->right);
	x->n   = 1 + size_of_subarray(x->left) + size_of_subarray(x->right);
	//return new parent
	return x;
}
//helper function to perform rotate right
red_black_node* rotate_right(red_black_node* ptr){
	//exchange position
	red_black_node* x = ptr->left;
	ptr->left = x->right;	//ptr->left, and x->right are constant
	x->right = ptr;	//x is now parent of ptr;
	//correct color
	x->color = ptr->color;
	ptr->color = RED;
	//correct new n(size of the subarray)
	x->n = ptr->n;
	ptr->n = 1 + size_of_subarray(ptr->left) + size_of_subarray(ptr->right);
	//return new parent
	return x;
}
//return size of subarray of given node pointer
int size_of_subarray(red_black_node* ptr){
	if(ptr == nullptr)	return 0;
	return ptr->n;
}
//return true if is red else false
bool isRed(red_black_node* ptr){
	if(ptr == nullptr || ptr->color == BLACK)	return false;
	return true;
}
