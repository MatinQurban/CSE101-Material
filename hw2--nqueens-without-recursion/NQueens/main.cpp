#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct State
{
	vector<vector<string>>board;
	int col;
};

bool isSafe(int col, int row, const vector<vector<string>>& board)
{
	int n = board.size();
	for(int i = 0; i < col; ++i)
	{
		if(board[row][i] == "Q") return false;
	}

	for(int i = 1; i <= col; i++)
	{ //checking diagonals
		int rowCheckUp = row - i;
		int rowCheckDown = row + i;
		int colCheck = col - i;

		if(colCheck < 0) break;
		if(rowCheckUp >= 0 && board[rowCheckUp][colCheck] == "Q") return false;
		if(rowCheckDown < n && board[rowCheckDown][colCheck] == "Q") return false;
	}

	return true;
}

bool solveBoard(vector<vector<string>>board, vector<pair<int,int>>& solution)
{
	int n = board.size();
	stack<State> s;
	s.push({board, 0});

	while(!s.empty())
	{
		State curr = s.top();
		s.pop();

		vector<vector<string>> curBoard = curr.board;
		int col = curr.col;
		if(col == n)
		{
			solution.clear(); // clear in case multiple are in stack
			for(int colC = 0; colC < n; colC++)
			{
				for(int row = 0; row < n; row++)
				{
					if(curBoard[row][colC] == "Q")
					{
						solution.emplace_back(colC+1, row+1); // add one because it starts at 1 not 0
						break;
					}
				}
			}

			return true;
		}

		int presetRow = -1;
		for(int rowC = 0; rowC < n; rowC++) if(curBoard[rowC][col] == "Q")
		{
			presetRow = rowC;
			break;
		}
		if(presetRow >= 0)
		{
			if(!isSafe(col, presetRow, curBoard)) continue;

			s.push({curBoard, col+1});
			continue;
		}

		for(int rowC = 0; rowC < n; rowC++)
		{
			if(isSafe(col, rowC, curBoard))
			{
				curBoard[rowC][col] = "Q";
				s.push({curBoard, col+1});
				curBoard[rowC][col] = ".";
			}
		}
	}

	return false;
}



int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cerr << "Incorrect arg count, try again: " << argv[0] <<" <input-file> <output-file>" << endl;
		return -1;
	}

	ifstream inf(argv[1]);
	ofstream outf(argv[2]);

	string line;
	while(getline(inf, line))
	{
		vector<int> input;
		istringstream iss(line);
		int x;
		while(iss >> x) input.push_back(x);
		if(input.empty()) continue;
		int n = input[0];

		vector<pair<int,int>> queens;
		for(int i = 1; i+1 < (int)input.size(); i+=2)
		{
			int col = input[i];
			int row = input[i+1];
			queens.push_back({col, row});
		}

		//cout << "n = " << n << endl;

		if(n <= 3)
		{
			outf << "No solution\n";
			continue;
		}

		bool invalidInput = false;
		set<int> usedCols;
		set<int> usedRows;
		for(int i = 0; i < (int)queens.size(); ++i)
		{
			int c = queens[i].first;
			int r = queens[i].second;

			if(c < 1 || c > n || r < 1 || r > n)
			{
				invalidInput = true;
				break;
			}

			if(usedCols.count(c) || usedRows.count(r))
			{
				invalidInput = true;
				break;
			}

			// check diagonals conflict
			for(int j = 0; j < i; ++j)
			{
				int c2 = queens[j].first;
				int r2 = queens[j].second;
				if(abs(c-c2) == abs(r-r2))
				{
					invalidInput = true;
					break;
				}
			}
			if(invalidInput) break;
			usedCols.insert(c);
			usedRows.insert(r);
		}
		if(invalidInput)
		{
			outf << "No solution\n";
			continue;
		}

		vector<vector<string>> board(n, vector<string>(n, "."));

		for(pair<int,int> &q : queens)
		{
			int curCol = q.first - 1;
			int curRow = q.second -1 ;
			board[curRow][curCol] = "Q";
		}

		vector<pair<int,int>> solution;
		bool ok = solveBoard(board, solution);
		if(!ok)
		{
			outf << "No solution\n";
		}
		else
		{
			for(int i = 0; i < (int)solution.size(); i++)
			{
				outf <<solution[i].first << " " << solution[i].second;
				if( (i+1) < (int)solution.size()) outf << " ";
			}
			outf << "\n";
		}
	}

	return 0;
}