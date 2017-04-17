#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    node *left;
    node *right;
    
};

node* construct_tree(){
	
//	root node
	node *root = new node;
	root->data = 3;
	root->left = new node;
	root->right = new node;
	
//	1st level. Left child
	root->left->data = 5;
	root->left->left = new node;
	root->left->right = new node;
	
//	1st level. Right child
	root->right->data = 2;
	root->right->right = NULL;
	root->right->left = new node;
	
//	2nd level. Right Left
	root->left->left->data = 6;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	
//	2nd level. Left Left
	root->left->left->data = 1;
	root->left->left->left = NULL;
	root->left->left->right = NULL;

//	2nd level. Left Right
	root->left->right->data = 4;
	root->left->right->left = NULL;
	root->left->right->right = NULL;
	
	return root;
}

bool checkBST(node* root, int min, int max){
    if (root == NULL || root->data >= max || root->data <= min){
        // assert BST condition
        return false;
    };

    if (root->left == NULL && root->right == NULL){
        // leafs satisfy the condition
        return true;
    };

    bool left_subtree_condition = true;

    if (root->left != NULL){
        // update the max condition value
        left_subtree_condition = checkBST(root->left, min, root->data);
    };

    bool right_subtree_condition = true;

    if (root->right != NULL){
		// update the min condition value
		right_subtree_condition = checkBST(root->right, root->data, max);
    };

    return right_subtree_condition && left_subtree_condition;
}

bool checkBST(node* root) {
//	0 <= data <= 100000
    return checkBST(root->left, -1, root->data) && checkBST(root->right, root->data, 1000000);

}

int main(int argc, char **argv)
{
	node *root = construct_tree();
	cout << ((checkBST(root)) ? "Tree is BST": "Tree is not BST!") << endl;
	return 0;
}
