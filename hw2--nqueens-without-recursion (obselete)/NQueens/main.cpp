#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct State
{
	vector<vector<string>> board;
	int col;
};

bool isSafeForCol(const vector<vector<string>>& board, int row, int col) {
	int n = board.size();
	// check same row on left side (previous columns)
	for (int c = 0; c < col; ++c) if (board[row][c] == "Q") return false;
	// check upper-left and lower-left diagonals
	for (int c = 1; c <= col; ++c) {
		int r1 = row - c;
		int r2 = row + c;
		int cc = col - c;
		if (cc < 0) break;
		if (r1 >= 0 && board[r1][cc] == "Q") return false;
		if (r2 < n && board[r2][cc] == "Q") return false;
	}
	return true;
}

// Non-recursive solver that fills one queen per column (columns from 0..n-1)
// Respects any pre-placed queens already present on the board.
bool solveNonRecursive(vector<vector<string>> board, vector<pair<int,int>>& solution) {
	int n = board.size();
	stack<State> s;
	s.push({board, 0});
	while (!s.empty()) {
		State cur = s.top(); s.pop();
		auto curBoard = cur.board; // copy
		int col = cur.col;
		if (col == n) {
			// extract solution as (col,row) 1-based
			solution.clear();
			for (int c = 0; c < n; ++c) {
				for (int r = 0; r < n; ++r) {
					if (curBoard[r][c] == "Q") {
						solution.emplace_back(c+1, r+1); 
						break;
					}
				}
			}
			return true;
		}

		// If there is already a queen in this column, find it and validate
		int presetRow = -1;
		for (int r = 0; r < n; ++r) if (curBoard[r][col] == "Q") { presetRow = r; break; }
		if (presetRow != -1) {
			if (!isSafeForCol(curBoard, presetRow, col)) continue;
			s.push({curBoard, col+1});
			continue;
		}

		// try placing queen in each row of this column
		for (int r = 0; r < n; ++r) {
			if (isSafeForCol(curBoard, r, col)) {
				curBoard[r][col] = "Q";
				s.push({curBoard, col+1});
				curBoard[r][col] = ".";
			}
		}
	}
	return false;
}

int main(int arc, char* argv[])
{
	if (arc < 3) {
		cerr << "Usage: " << argv[0] << " <input-file> <output-file>\n";
		return 1;
	}
	string inputPath = argv[1];
	string outputPath = argv[2];
	ifstream inputFile(inputPath);
	ofstream outputFile(outputPath);
	if (!inputFile.is_open()) {
		cerr << "Cannot open input file\n";
		return 1;
	}
	if (!outputFile.is_open()) {
		cerr << "Cannot open output file\n";
		return 1;
	}

	string line;
	while (getline(inputFile, line)) {
		// parse integers
		vector<int> tokens;
		istringstream iss(line);
		int x;
		while (iss >> x) tokens.push_back(x);
		if (tokens.empty()) continue;
		int n = tokens[0];
		// gather given queens (column,row) pairs
		vector<pair<int,int>> givens;
		for (size_t i = 1; i + 1 < tokens.size(); i += 2) {
			int col = tokens[i];
			int row = tokens[i+1];
			givens.emplace_back(col, row);
		}

		// validate givens -----------------
		bool invalid = false;
		set<int> usedCols, usedRows;
		for (size_t i = 0; i < givens.size(); ++i) {
			int c = givens[i].first;
			int r = givens[i].second;
			if (c < 1 || c > n || r < 1 || r > n) { invalid = true; break; }
			if (usedCols.count(c) || usedRows.count(r)) { invalid = true; break; }
			// diagonal conflicts with previous givens
			for (size_t j = 0; j < i; ++j) {
				int c2 = givens[j].first;
				int r2 = givens[j].second;
				if (abs(c - c2) == abs(r - r2)) { invalid = true; break; }
			}
			if (invalid) break;
			usedCols.insert(c);
			usedRows.insert(r);
		}
		if (invalid) {
			outputFile << "No solution\n";
			continue;
		}
		// ---------------------------------

		// prepare board n x n with dots
		vector<vector<string>> board(n, vector<string>(n, "."));
		for (auto &p : givens) {
			int c = p.first - 1;
			int r = p.second - 1;
			board[r][c] = "Q";
		}

		vector<pair<int,int>> solution;
		bool ok = solveNonRecursive(board, solution);
		if (!ok) {
			outputFile << "No solution\n";
		} else {
			// ensure sorted by column
			sort(solution.begin(), solution.end());
			for (size_t i = 0; i < solution.size(); ++i) {
				outputFile << solution[i].first << " " << solution[i].second;
				if (i + 1 < solution.size()) outputFile << " ";
			}
			outputFile << "\n";
		}
	}

	return 0;
}