#include "FileInput.h"
#include <iterator>
#include <string>
#include <cstring>
#include <sstream>

map<string, char[5][5]> file::textures = map<string, char[5][5]>();

void file::loadTextures(string file)
{

}

vector<int> file::loadScores(string file)
{
	cout << "Loading score file " << file << endl;
	ifstream scFile;
	scFile.open(file);
	string line;
	vector<int> out = vector<int>();
	//Run the file.
	while (getline(scFile, line)) {
		cout << "Line read " << line << endl;
		stringstream lineIn(line);
		int buff;
		lineIn >> buff;
		out.push_back(buff);
	}
	//Then close it.
	scFile.close();
	cout << "File loaded successfuly." << endl;
	return out;
}

void file::saveScores(string file, vector<int> scores)
{
	cout << "Saving score file " << file << endl;
	ofstream scFile;
	scFile.open(file);
	for (unsigned int i = 0; i < scores.size(); i++) {
		scFile << scores[i] << "\n";
	}
	scFile << endl;
	scFile.close();
	cout << "File saved successfuly." << endl;
}
