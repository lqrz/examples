#include <fstream>
#include <vector>
#include "data_reader.h"

using namespace std;

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
			words.push_back(letters);
		}
		f.close();
	}
	return words;
}