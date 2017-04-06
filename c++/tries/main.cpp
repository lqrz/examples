#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

struct node{
	char value;
	map<char, node* > children;
};

vector<vector<char> > read_file(){
	ifstream f;
	f.open("../dict.txt");
	
	vector<vector<char> > words;
	
	if (f.is_open()){
		string line;
		while(getline(f, line)){
			vector<char> letters;
			for(unsigned int i=0; i<line.length(); i++){
				letters.push_back(line[i]);
			};
//			for(int i=0; i<letters.size(); i++) cout << letters[i] << ' ';
//			cout << endl;
			words.push_back(letters);
//			for(int i=0; i<words.size(); i++) cout << words[i];
		}
		f.close();
	}
	return words;
}

void print_node(node *n){
	cout << "Node value: " << n->value << endl;
	
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
				last_node->children[words[i][j]] = n;
				cout << last_node->children[words[i][j]] << endl;
			}else{
				cout << "Found " << words[i][j] << " under " << last_node->value << endl;
				n = last_node->children[words[i][j]];
			};
			last_node = n;
		};
			
		cout << endl;
	};
	
	return root;
}

int main(int argc, char **argv)
{
//	read toy dictionary file
	vector<vector<char> > words = read_file();
	
//	construct the trie tree
	node *root = construct_trie(words);
	
//	visualize the tree
	print_tree(root);
	
	return 0;
}
