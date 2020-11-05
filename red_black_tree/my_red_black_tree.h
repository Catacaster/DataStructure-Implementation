#ifndef	MY_RED_BLACK_TREE_H
#define	MY_RED_BLACK_TREE_H


#define RED   true
#define BLACK false


struct red_black_node{
	int key;
	bool color;	//true is red, and false is black
	int n;		//number of nodes in this subtree
	red_black_node* left, *right;
	
	red_black_node(int Key, bool Color){
		key = Key;
		color = Color;
		n = 1;
		left = nullptr;
		right = nullptr;
	}
};

class red_black_tree{
private:
	red_black_node* root;
	void print(red_black_node* ptr);
public:
	red_black_tree();	//constructor
	~red_black_tree();	//destructor
	void insert(int key);
	void clear();			//clear whole tree, root = nullptr
	void print();
};




#endif
