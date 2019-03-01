#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

namespace file {

	//Loads the specified file and stores each line into the vector<int>. Useful to easily load high scores.
	vector<int> loadScores(string file);
	//Saves the vector<int> to the specified file. Useful to save high scores.
	void saveScores(string file, vector<int> scores);
}