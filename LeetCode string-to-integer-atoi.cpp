// LeetCode string-to-integer-atoi
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

#define is_d(ch)	((ch) >= '0' && (ch) <= '9')
#define is_s(ch)	((ch) == '-' || (ch) == '+')
#define is_b(ch)	((ch) == ' ')
#define get_d(ch)	((ch) - '0')

class Solution {
public:
	int atoi(string str) {
		if(str.length() == 0)
			return 0;
		int i = 0;
		int len = str.length();
		for (; i < len && is_b(str[i]); ++i);
		if (i == len - 1 && !is_d(str[i]))
			return 0;
		int flag = 1;
		if (is_s(str[i])) {
			flag = (str[i] == '-') ? -1 : 1;
			++i;
		}
		int result = 0;
		int temp = 0;
		while (is_d(str[i]) && i < len) {
			int last = get_d(str[i]);
			if (flag == 1) {
				if ((INT_MAX - last) / 10 < result)
					return INT_MAX;
				result = result * 10 + last;
			}
			else {
				if ((INT_MIN + last) / 10 > -result)
					return INT_MIN;
				result = result * 10 + last;
			}
			++i;
		}
		//if (i < len && !is_d(str[i]) && !is_b(str[i]))
		//	return 0;
		return result * flag;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	Solution solution;
	cout << solution.atoi("1") << endl;
	cout << solution.atoi(" -123423 ") << endl;
	cout << solution.atoi(" b11228552307 ") << endl;
	return 0;
}