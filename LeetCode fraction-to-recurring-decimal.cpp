// LeetCode fraction-to-recurring-decimal
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
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[LEN1][LEN2];

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long numerator_l = numerator, denominator_l = denominator;
		string result;
		if (denominator_l == 0)
			return NULL;
		if (numerator_l % denominator_l == 0)
			return to_string(numerator_l / denominator_l);
		if ((numerator_l < 0 && denominator_l > 0) || (numerator_l > 0 && denominator_l < 0))
			result += "-";
		numerator_l *= (numerator_l < 0) ? -1 : 1;
		denominator_l *= (denominator_l < 0) ? -1 : 1;
		result += to_string(numerator_l / denominator_l) + ".";
		numerator_l %= denominator_l;
		string frac;
		vector<long long> reminder;
		reminder.push_back(numerator);
		while (numerator_l != 0) {
			numerator_l *= 10;
			frac += to_string(numerator_l / denominator_l);
			numerator_l %= denominator_l;
			bool repeat = false;
			int i = 0;
			for (; i < reminder.size(); ++i) {
				if (reminder[i] == numerator_l) {
					repeat = true;
					break;
				}
			}
			reminder.push_back(numerator_l);
			if (repeat) {
				int j = 1, repeat_len = frac.length() - i;
				for (; i - j >= 0; ++j) {
					if (frac[i - j] != frac[i - j + repeat_len])
						break;
				}
				--j;
				//cout << i << endl;
				result += frac.substr(0, i - j);
				result += "(" + frac.substr(i - j, repeat_len) + ")";
				return result;
			}
		}
		return result += frac;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	Solution solution;
	cout << solution.fractionToDecimal(-1, 8) << endl;
	cout << solution.fractionToDecimal(-50, 8) << endl;
	cout << solution.fractionToDecimal(22, 7) << endl;
	cout << solution.fractionToDecimal(1, 6) << endl;
	cout << solution.fractionToDecimal(1, 17) << endl;
	cout << solution.fractionToDecimal(1, 3) << endl;
	return 0;
}