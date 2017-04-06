#include <iostream>
#include <vector>
#include <map>
#include "trie.h"

using namespace std;

void print_node(node *n){
	cout << "Node value: " << n->value << endl;
	cout << "Ending: " << n->ending << endl;
	
	if (!n->children.size()){
		cout << "No children" << endl;
	}else{
		cout << "Children:";
	
		for(map<char, node* >::iterator it = n->children.begin(); it!=n->children.end(); it++){
			cout << " "<< it->first;
		};
		cout << endl;
	};
	cout << endl;
}

int print_tree(node *n){
	if(!n){
		return 0;
	}
	
	print_node(n);
	
	if (n->children.size()){
		cout << "+ ";
	
		for(map<char, node* >::iterator it = n->children.begin(); it!=n->children.end(); it++){
			print_tree(it->second);
		};
		cout << endl;
	};
	
	return 0;
}

node* construct_trie(vector<vector<char> > words){
	node *root = new node; //its gonna return a pointer
	root->value = '*';
	
	node *last_node;
	
	for(unsigned int i=0; i<words.size(); i++){
		last_node = root;
		for(unsigned int j=0; j<words[i].size(); j++){
			node *n;
			map<char, node* >::iterator it = last_node->children.find(words[i][j]);
			if (it == last_node->children.end()){
				cout << "Inserting " << words[i][j] << " under: " << last_node->value << endl;
				n = new node;
				n->value = words[i][j];
				n->ending = false;
				last_node->children[words[i][j]] = n;
				cout << last_node->children[words[i][j]] << endl;
			}else{
				cout << "Found " << words[i][j] << " under " << last_node->value << endl;
				n = last_node->children[words[i][j]];
			};
			last_node = n;
		};
		last_node->ending = true;	
		cout << endl;
	};
	
	return root;
}