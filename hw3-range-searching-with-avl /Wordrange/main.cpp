#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bst.h"

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
		return 1;
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);

	if(!input.is_open() || !output.is_open())
	{
		cerr << "Error: could not open files." << endl;
		return 1;
	}

	AVLTree myTree;
	string line;

	while(getline(input, line))
	{
		if(line.empty()) continue;
		
		stringstream ss(line);
		char command;
		ss >> command;

		if(command == 'i')
		{
			string val;
			ss >> val;
			myTree.insert(val);
			//cout << "Insert complete" << endl;
		} else if(command == 'r'){
			string low, high;
			ss >> low >> high;
			//cout << "range: " << low << ", " << high << endl;
			output << myTree.rangeQuery(low, high) << endl;
		}
	}

	input.close();
	output.close();

	return 0;
}