#include <vector>
#include <map>

using namespace std;

struct node{
	char value;
	bool ending;
	map<char, node* > children;
};

void print_node(node*);

int print_tree(node*);

node* construct_trie(vector<vector<char> >);