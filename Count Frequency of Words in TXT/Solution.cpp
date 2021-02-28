#include "WordFreq.h"
#include <vector>
#include<fstream>
#include<map>
#include<algorithm>
#include <iterator>
#include <iostream>
using namespace std;

///-----------------------------------------------------------------
/// Process the given text file and return the most frequent "k" words
///
bool sortByVal(const pair<string, int>& a,
	const pair<string, int>& b)
{
	return (a.second > b.second);
}
vector<WordFreq> GetMostFrequentKWords(string filename, int k)
{
	vector<WordFreq> result;
	map<string, int>wordsCount;
	// Fill this in
	string temp;
	ifstream file;
	file.open(filename);
	int i = 0;
	while (!file.eof())
	{
		file >> temp;
		temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end());
		temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());
		//std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp.length() >= 3)
		{

			if (wordsCount.find(temp) == wordsCount.end())
				wordsCount[temp] = 1;
			else
				wordsCount[temp]++;

		}

	}
	vector<pair<string, int>> vec;
	map<string, int> ::iterator it2;
	for (it2 = wordsCount.begin(); it2 != wordsCount.end(); it2++)
	{
		vec.push_back(make_pair(it2->first, it2->second));
	}
	sort(vec.begin(), vec.end(), sortByVal);
	//reverse(vec.begin(), vec.end());
	map<string, int>::iterator itr;
	for (int i = 0; i <k; i++)
	{
		result.push_back(vec[i].first);
		result[i].freq=vec[i].second;
	}
	return result;
} //end-GetMostFrequentKWords