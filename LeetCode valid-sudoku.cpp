// LeetCode valid-sudoku
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		unsigned int mark = 0;
		for (int i = 0; i < 9; ++i) {
			mark = 0;
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.' && !setBit(mark, board[i][j] - '0'))
					return false;
		}
		for (int i = 0; i < 9; ++i) {
			mark = 0;
			for (int j = 0; j < 9; j++)
				if (board[j][i] != '.' && !setBit(mark, board[j][i] - '0'))
					return false;
		}
		for (int m = 0; m < 3; ++m)
			for (int n = 0; n < 3; ++n) {
				mark = 0;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; j++)
						if (board[i + m * 3][j + n * 3] != '.' && !setBit(mark, board[i + m * 3][j + n * 3] - '0'))
							return false;
				}
			}
		return true;
	}

	bool setBit(unsigned int &mark, int bit) {
		if (mark & (1 << (bit - 1))) return false;
		else return (mark |= (1 << (bit - 1)));
	}
};

#define LEN 100
char str[LEN];
char pat[LEN];

int main() {
	freopen("in.txt", "r", stdin);
	vector<vector<char> > board;
	char ch = 0;
	for (int i = 0; i < 9; ++i) {
		vector<char> line;
		for (int j = 0; j < 9; j++) {
			cin >> ch;
			line.insert(line.end(), ch);
		}
		board.insert(board.end(), line);
	}
	cout << Solution().isValidSudoku(board) << endl;
	return 0;
}