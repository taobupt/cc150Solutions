#include"Header.h"
class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		rows = vector<int>(n, 0);
		cols = vector<int>(n, 0);
		diagnal = 0;
		antiDiagnal = 0;
	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int flag = player == 1 ? 1 : -1, n = rows.size();
		rows[row] += flag, cols[col] += flag;
		if (row == col)antiDiagnal += flag;
		if (row + col + 1 == n) diagnal += flag;
		if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagnal) == n || abs(antiDiagnal) == n)return player;
		return 0;
	}
private:
	vector<int>rows, cols;
	int diagnal, antiDiagnal;
};