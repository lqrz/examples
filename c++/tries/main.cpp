#include <iostream>
#include <vector>
#include <map>
#include "data_reader.h"
#include "trie.h"

using namespace std;

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
