// LeetCode sudoku-solver
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		vector< pair <int, int> > fillpoint;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				if (board[i][j] == '.')
					fillpoint.push_back(pair<int, int>(i, j));
		}
		search(board, fillpoint, 0);
		//for (int i = 0; i < 9; ++i) {
		//	for (int j = 0; j < 9; ++j)
		//		cout << board[i][j];
		//	cout << endl;
		//}
	}

	bool search(vector<vector<char> > &board, vector< pair <int, int> > &fillpoint, int num) {
		if (num == fillpoint.size()) {
			// check 
			if (isValidSudoku(board)) {
				//cout << "get" << endl;
				//for (int i = 0; i < 9; ++i) {
				//	for (int j = 0; j < 9; ++j)
				//		cout << board[i][j];
				//	cout << endl;
				//}
				return true;
			}
			else return false;
		}
		bool isEnd = false;
		for (char val = '1'; val <= '9'; ++val) {
			put(board, fillpoint[num], val);
			if (isValidSudoku(board))
				if (search(board, fillpoint, num + 1))
					return true;
			rem(board, fillpoint[num]);
		}
		return false;
	}

	void put(vector<vector<char> > &board, pair<int, int> pos, char val) {
		board[pos.first][pos.second] = val;
	}

	void rem(vector<vector<char> > &board, pair<int, int> pos) {
		board[pos.first][pos.second] = '.';
	}

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
		for (int m = 0; m < 3; ++m) {
			for (int n = 0; n < 3; ++n) {
				mark = 0;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; j++)
						if (board[i + m * 3][j + n * 3] != '.' && !setBit(mark, board[i + m * 3][j + n * 3] - '0'))
							return false;
				}
			}
		}
		return true;
	}

	bool getBit(unsigned int &mark, int bit) {
		return (mark & (1 << (bit - 1)));
	}

	bool setBit(unsigned int &mark, int bit) {
		if (getBit(mark, bit)) return false;
		else return (mark |= (1 << (bit - 1)));
	}

	//bool resetBit(unsigned int &mark, int bit) {
	//	if (!getBit(mark, bit)) return false;
	//	else return (mark &= (~(1 << (bit - 1))) & 0x1ff);
	//}
};

int main() {
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
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
	Solution().solveSudoku(board);
	return 0;
}