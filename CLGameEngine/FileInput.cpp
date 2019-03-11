#include "FileInput.h"
#include <iterator>
#include <string>
#include <cstring>
#include <sstream>

//Load the scores in the file to a vector<int> and allow the developer to interperet the data as they need.
vector<int> file::loadScores(string file)
{
	//Tell the user/developer this is happening.
	cout << "Loading score file " << file << endl;
	//Create objects to make looping easier.
	ifstream scFile;
	scFile.open(file);
	string line;
	vector<int> out = vector<int>();

	//Read the file.
	while (getline(scFile, line)) { //Loop for each line.
		cout << "Line read " << line << endl;
		stringstream lineIn(line); //A stringstream makes getting the int value from the string possible.
		int buff;
		lineIn >> buff; //Getting the int value from the string.
		out.push_back(buff); //Then store it into the array slot.
	}
	//Then close it.
	scFile.close();
	cout << "File loaded successfuly." << endl; //And tell us it worked.
	return out;
}

//Allows the developer to save high scores after placing them into a vector<int>
//The order scores are saved in is up to the developer.
void file::saveScores(string file, vector<int> scores)
{
	//Tell the user/developer what file is being saved.
	cout << "Saving score file " << file << endl;
	//Create the file object and open it
	ofstream scFile;
	scFile.open(file);
	//For each score we are told to write
	for (unsigned int i = 0; i < scores.size(); i++) {
		scFile << scores[i] << "\n"; //Write it to a new line in the file.
	}
	scFile << endl; //The endl causes the buffer to be flushed.
	scFile.close(); //Then close the file and tell the user.
	cout << "File saved successfuly." << endl;
}
