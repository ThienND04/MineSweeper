#include"Game.h"

Game::Game(int _nRow, int _nCol, int _numberOfMines) {
	setNCol(_nCol);
	setNRow(_nRow);
	numMines = _numberOfMines;
	reset();
}

Game::~Game(){
	for(std::vector<CellType> e: board) e.clear();
	board.clear();
	for(std::vector<CellStatus> e: boardStatus) e.clear();
	boardStatus.clear();
}

void Game::reset() {
	started = false;
	gameStatus = GameStatus::GAME_RUNNING;
	numFlag = numMines;
	board = std::vector<std::vector<CellType>>(nRow, std::vector<CellType>(nCol, EMPTY_CELL));
	boardStatus = std::vector<std::vector<CellStatus>>(nRow, std::vector<CellStatus>(nCol, CLOSED));
	// randomize({0, 0});
}

// randomize board with first open cell, around it does not have any mines.
void Game::randomize(Position firstOpen) {
	std::vector<Position>tmp;
	for (int r = 0; r < nRow; r ++) {
		for (int c = 0; c < nCol; c ++) {
			if (std::max(abs(r - firstOpen.row), abs(c - firstOpen.col)) > 1) {
				tmp.push_back({r, c});
			}
			// tmp.push_back({r, c});
		}
	}
	printf ("TMP size: %d\n", tmp.size());
	std::shuffle(tmp.begin(), tmp.end(), std::default_random_engine(time(0)));
	printf("Mines: \n");
	for (int i = 0; i < numMines; i ++) {
		printf("    %d %d\n", tmp[i].row, tmp[i].col);
		setCellType(tmp[i], CellType::MINE_CELL);
	}
}

// open all cell around current cell if player mask enough flag
void Game::autoOpen(Position pos) {
	if (getCellStatus(pos) != CellStatus::OPENDED) return;
	int cnt = 0;
	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			int x2 = pos.row + i;
			int y2 = pos.col + j;
			Position pos2 = {x2, y2};
			if (isValidPos(pos2) && getCellStatus(pos2) == CellStatus::MASKED) {
				cnt ++;
			}
		}
	}

	// khong du dieu kien
	if (cnt != getNumber(pos)) return;
	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			int x2 = pos.row + i;
			int y2 = pos.col + j;
			Position pos2 = {x2, y2};
			if (isValidPos(pos2) && getCellStatus(pos2) == CellStatus::CLOSED) {
				openCell(pos2);
			}
		}
	}
}

// Mở một ô nếu không bị cắm cờ. 
void Game::openCell(Position pos) {
	// invalid position case
	if (pos.col < 0 || pos.row < 0 || pos.col >= nCol || pos.row >= nRow) {
		return;
	}
	if (getCellStatus(pos) == CellStatus::CLOSED) {
		if (! started) {
			printf ("Game start!");
			started = true;
			randomize(pos);
		}
		setCellStatus(pos, CellStatus::OPENDED);
		if (getNumber(pos) == 0) {
			for (int i = -1; i <= 1; i ++) {
				for (int j = -1; j <= 1; j ++) {
					if (i != 0 || j != 0) {
						int x2 = pos.row + i;
						int y2 = pos.col + j;
						openCell({x2, y2});
					}
				}
			}
		}
		// if chua item 
	}
}

// Đánh dấu một ô nếu chưa bị đánh dấu và ngược lại. 
void Game::maskCell(Position pos) {
	if (getCellStatus(pos) == CellStatus::CLOSED) {
		if (numFlag > 0) {
			setCellStatus(pos, CellStatus::MASKED);
			numFlag --;
		}
	} else if (getCellStatus(pos) == CellStatus::MASKED) {
		setCellStatus(pos, CellStatus::CLOSED);
		numFlag ++;
	}
}

void Game::updateGameStatus() {
	// printf("Row, Col: %d %d\n", nRow, &nCol);
	int cntOpen = 0;
	for (int r = 0; r < nRow; r ++) {
		for (int c = 0; c < nCol; c ++) {
			Position pos = {r, c};
			if (getCellStatus(pos) == CellStatus::OPENDED) {
				cntOpen ++;
				if (getCellType(pos) == CellType::MINE_CELL) {
					setGameStatus(GameStatus::GAME_OVER);
				} 
			}
			// if (getCellStatus(pos) == CellStatus::OPENDED) {
			// 	int tp = getCellType(pos);
			// 	printf("%d %d: %d\n", r, c, tp);
			// }
		}
	}
	if (cntOpen >= nRow * nCol - numMines) gameStatus = GameStatus::GAME_WON;
}

int Game::getNumber(Position pos) {
	int cnt = 0;
	int x = pos.row, y = pos.col;
	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			int x1 = x + i, y1 = y + j;
			if (x1 >= 0 && x1 < nRow
				&& y1 >= 0 && y1 < nCol) {
					if (this->getCellType({x1, y1}) == CellType::MINE_CELL) {
						cnt ++;
					}
				} 
		}
	}
	return cnt;
}