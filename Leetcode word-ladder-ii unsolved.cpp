// LeetCode word-ladder-ii
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		queue < pair <string, int> > looklist;
		map < string, vector <string> > traces;

		looklist.push(pair<string, int>(start, 0));
		int ladderlen = -1;
		while (!looklist.empty()) {
			pair<string, int> current = looklist.front();
			looklist.pop();
			// check path
			if (current.first == end) {
				if (ladderlen == -1) ladderlen = current.second;
			}
			if (ladderlen >= 0 && ladderlen < current.second) {
				break;
			}
			string next;
			for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
				next = *it;
				if (isNeighbor(current.first, next) && current.second + 1 <= ) {
					looklist.push(pair<string, int>(next, current.second + 1));
				}
			}
		}
	}

	bool isNeighbor(const string & s1, const string & s2) {
		if (s1.length() != s2.length()) return false;
		int count = 0;
		for (int i = 0; i < s1.length(); ++i) {
			if (s1[i] != s2[i]) count++;
		}
		if (count == 1) return true;
		else return false;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	return 0;
}