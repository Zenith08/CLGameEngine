#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

namespace file {
	extern map<string, char[5][5]> textures;
	extern map<string, string> scores;

	void loadTextures(string file);
	vector<int> loadScores(string file);
	void saveScores(string file, vector<int> scores);
}