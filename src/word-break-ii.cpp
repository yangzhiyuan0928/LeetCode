#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		dict.insert(wordDict.cbegin(), wordDict.cend());
		return wordBreak(s);
	}
private:
	unordered_set<string> dict;
	unordered_map<string, vector<string>> map;

	vector<string> wordBreak(string s) {
		if (map.find(s) != map.end()) return map[s];
		vector<string> sentences;
		for (int pos = s.size() - 1; pos >= 0; --pos) {
			string word = s.substr(pos);
			if (dict.find(word) != dict.end()) {
				if (pos == 0) sentences.push_back(word);// base case of recursion
				else {
					vector<string> subSentences = wordBreak(s.substr(0, pos));
					for (auto subSentence : subSentences)
						sentences.push_back(subSentence + " " + word);
				}
			}
		}
		map[s] = sentences;
		return sentences;
	}
};
