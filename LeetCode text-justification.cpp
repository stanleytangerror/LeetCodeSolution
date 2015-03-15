// LeetCode text-justification
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define LEN1 1005
#define LEN2 1005
#define max(a, b)	((a) > (b) ? (a) : (b))
#define min(a, b)	((a) < (b) ? (a) : (b))

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		if (words.size() == 0 || L == 0) {
			result.push_back("");
			return result;
		}
		vector<vector<string> > medium;
		vector<string> current;
		for (int i = 0; i < words.size(); ++i) {
			if (current.size() == 0) {
				current.push_back(words[i]);
			}
			else if (vec_str_len(current) + current.size() + words[i].length() <= L) {
				current.push_back(words[i]);
			}
			else {
				medium.push_back(current);
				current.clear();
				current.push_back(words[i]);
			}
		}
		if (current.size() > 0)
			medium.push_back(current);

		for (int i = 0; i < medium.size() - 1; ++i) {
			current = medium[i];
			int l = L - vec_str_len(medium[i]);
			int vol = current.size() - 1;
			string str;
			str.insert(0, current.back());
			current.pop_back();
			while (!current.empty()) {
				str.insert(0, current.back() + string(l / vol, ' '));
				current.pop_back();
				l -= l / vol;
				--vol;
			}
			result.push_back(str);
		}
		for (int i = 0; i < medium.size() - 1; ++i)
			if (result[i].length() < L)
				result[i].insert(result[i].length(), string(L - result[i].length(), ' '));
		/* last line */
		string str;
		for (int i = 0; i < medium.back().size(); ++i) {
			str += medium.back()[i] + " ";
		}
		if (str.length() < L)
			str += string(L - str.length(), ' ');
		else
			str = str.substr(0, L);
		result.push_back(str);
		return result;
	}

	int vec_str_len(vector<string> & strs) {
		int sum = 0;
		for (int i = 0; i < strs.size(); ++i) {
			sum += strs[i].length();
		}
		return sum;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	Solution solution;
	// vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> input = { "a" };
	vector<string> output = solution.fullJustify(input, 1);
	for (int i = 0; i < output.size(); ++i)
		cout << output[i] << endl;
	return 0;
}