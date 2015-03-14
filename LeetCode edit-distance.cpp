// LeetCode edit-distance
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define LEN1 1005
#define LEN2 1005
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[LEN1][LEN2];

int minDistance(char *word1, char *word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	for (int i = 0; i <= len1; ++i) {
		for (int j = 0; j <= len2; ++j) {
			if (i == 0 && j == 0)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = max(i, j);
			else {
				int temp = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				if (i <= len1 && j <= len2 && word1[i - 1] == word2[j - 1])
					temp = min(temp, dp[i - 1][j - 1]);
				else
					temp = min(temp, dp[i - 1][j - 1] + 1);
				dp[i][j] = temp;
			}
		}
	}
	return dp[len1][len2];
}

int main() {
	freopen("in.txt", "r", stdin);
	printf("%d\n", minDistance("ab", "a"));
	return 0;
}