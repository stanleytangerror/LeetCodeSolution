// LeetCode regular-expression-matching
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (s == p) return true;
		if (*p == '\0') return (*s == '\0');
		if (*(p + 1) == '*') {
			if (*p == '*') return false;
				while (*p == *s || (*s != '\0' && *p == '.')) {
					if (isMatch(s, p + 2)) return true;
					++s;
				}
				return isMatch(s, p + 2);
		}
		else {
			if (*p == '*') return false;
			if (*s == *p || (*s != '\0' && *p == '.'))
				return isMatch(s + 1, p + 1);
			else return false;
		}
	}
};

#define LEN 100
char str[LEN];
char pat[LEN];

int main() {
	freopen("in.txt", "r", stdin);
	while (true) {
		memset(str, 0, LEN * sizeof(char));
		memset(pat, 0, LEN * sizeof(char));
		if (!(cin >> str >> pat)) break;
		cout << Solution().isMatch(str, pat) << endl;
	}
	return 0;
}