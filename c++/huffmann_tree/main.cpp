#include <string>
#include <iostream>

using namespace std;

typedef struct node
{
    int freq;
    char data;
    node *left;
    node *right;
    
};

node* construct_tree(){
	
//	root node
	node *root = new node;
	root->data = '*';
	root->right = new node;
	root->left = new node;
	
//	1st level. Right child
	root->right->data = 'A';
	
//	1st level. Left child
	root->left->data = '*';
	root->left->right = new node;
	root->left->left = new node;
	
//	2nd level. Right child
	root->left->right->data = 'C';
	root->left->left->data = 'B';
	
	return root;
}

int parse_string(node *root, string s){
    
    if (root->data != '*'){
        cout << root->data;
        return 0; // i need to return to the root of the tree again.
    };
    
    string s_new = s.substr(1,s.length());
    
    if (s.at(0)=='1'){
        //cout<<"Moving to the right"<<endl;
        return 1 + parse_string(root->right, s_new);
    }else{
        //cout<<"Moving to the left"<<endl;
        return 1 + parse_string(root->left, s_new);
    };
}

void decode_huff(node *root, string s)
{
    while (s.length()>0){
        s = s.substr(0+parse_string(root, s), s.length());
    };
    
    return;
}

int main(){
	string s = "1001011";
	node *root = construct_tree();
	
	decode_huff(root, s);
	
	cout << endl;
	
	return 0;
}