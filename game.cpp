#include"game.h"

Game::Game(int _width, int _height, int _numberOfMines) : 
        width(_width), height(_height), 
		board(std::vector<std::vector<CellType>>(_height, std::vector<CellType>(width, EMPTY_CELL))),
		boardStatus(std::vector<std::vector<CellStatus>>(_height, std::vector<CellStatus>(width, CLOSED))),
		numMines(_numberOfMines)
{
}

void Game::nextStep(){
	player.getInput();
	Request playerRequest = player.getRequest();

	if(playerRequest.rt == OPEN_CELL){
		openCell(playerRequest.pos);
	}
	else if(playerRequest.rt == MASK_CELL){
		maskCell(playerRequest.pos);
	}
	else if(playerRequest.rt == SCAN_CELL){
		autoMaskCells(playerRequest.pos);		
	}

	updateGameStatus();
}

Game::~Game(){
    board.clear();
}

void Game::restart(){
	numFlag = numMines;
	numScanner = 1;
	setGameStatus(GAME_RUNNING);

	for(int y = 0; y < height; y ++){
		for(int x = 0; x < width; x ++){
			setCellStatus({x, y}, CLOSED);
		}
	}

	for(int y = 0; y < height; y ++){
		for(int x = 0; x < width; x ++){
			setCellType({x, y}, NONE_CELL);
		}
	}

	// randomMinesPositions();
}

bool Game::isGameContinue(){
	bool answer = (gameStatus == GAME_RUNNING);
	return answer;
}

void Game::openCell(Position pos){
	if(pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height){
		if(getCellStatus(pos) == OPENDED || getCellStatus(pos) == MASKED) return;
		// check first open
		bool isFirstOpen = true;

		for(int y = 0; y < height; y ++){
			for(int x = 0; x < width; x ++){
				if(getCellStatus({x, y}) == OPENDED) isFirstOpen = false;
			}
		}

		if(isFirstOpen){
			int radius = 3;
			for(int dy = -radius; dy <= radius; dy ++){
				for(int dx = -radius; dx <= radius; dx ++){
					if(abs(dx) + abs(dy) <= radius) {
						setCellType({pos.x + dx, pos.y + dy}, EMPTY_CELL);
					}
				}
			}
			randomBoard();
		}

		if(getCellType(pos) == SCANER_CELL) numScanner ++;
		setCellStatus(pos, OPENDED);

		if(getCellNumber(pos) == 0){
			for(int dx = -1; dx <= 1; dx ++){
				for(int dy = -1; dy <= 1; dy ++){
					openCell({pos.x + dx, pos.y + dy});
				}
			}
		}
	}
}

void Game::maskCell(Position pos){
	if(getCellStatus(pos) == MASKED){
		numFlag ++;
		setCellStatus(pos, CLOSED);
	}
	else if(getCellStatus(pos) == CLOSED && numFlag > 0){
		numFlag --;
		setCellStatus(pos, MASKED);
	}
}

void Game::autoMaskCells(Position pos){
	if(numScanner > 0){
		numScanner --;

		for(int dy = -1; dy <= 1; dy ++){
			for(int dx = -1; dx <= 1; dx ++){
				int x = pos.x + dx, y = pos.y + dy;
				if(x >= 0 && x < width && y >= 0 && y < height){
					if(getCellType({x, y}) == MINE_CELL){
						maskCell({x, y});
					}
				}
			}
		}
	}
}

bool Game::checkWin(){
	bool answer = true;
	
	for(int y = 0; y < height; y ++){
		for(int x = 0; x < width; x ++){
			if(getCellType({x, y}) != MINE_CELL && getCellStatus({x, y}) == CLOSED){
				answer = false;
			}
		}
	}

	return answer;
}

void Game::randomBoard(){
	srand(time(0));
	for(int i = 0; i < numMines; i ++){
		do{
			int x = rand() % width;
			int y = rand() % height;

			if(getCellType({x, y}) == NONE_CELL){
				setCellType({x, y}, MINE_CELL);
				break;
			}

		}while(true);
	}

	for(int i = 0; i < numScanner; i ++){
		do{
			int x = rand() % width;
			int y = rand() % height;

			if(getCellType({x, y}) == NONE_CELL){
				setCellType({x, y}, SCANER_CELL);
				numScanner --;
				break;
			}

		}while(true);
	}

	for(int y = 0; y < height; y ++){
		for(int x = 0; x < width; x ++){
			if(getCellType({x, y}) == NONE_CELL){
				setCellType({x, y}, EMPTY_CELL);
			}
		}
	}
}

CellType Game::getCellType(Position pos){
	return board[pos.y][pos.x];
}

void Game::setCellType(Position pos, CellType cellType){
	if(pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height){
		board[pos.y][pos.x] = cellType;
	}
}

int Game::getCellNumber(Position pos){
	int ans = 0;

	for(int dy = -1; dy <= 1; dy ++){
		for(int dx = -1; dx <= 1; dx ++){
			int x = pos.x + dx, y = pos.y + dy;
			if(x >= 0 && x < width && y >= 0 && y < height){
				if(getCellType({x, y}) == MINE_CELL){
					ans ++;
				}
			}
		}
	}

	return ans;
}

void Game::setCellStatus(Position pos, CellStatus cellStatus){
	if(pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height){
		boardStatus[pos.y][pos.x] = cellStatus;
	}
}

CellStatus Game::getCellStatus(Position pos){
	return boardStatus[pos.y][pos.x];
}

void Game::updateGameStatus(){
	for(int x = 0; x < width; x ++){
		for(int y = 0; y < height; y ++){
			if(getCellStatus({x, y}) == OPENDED && getCellType({x, y}) == MINE_CELL){
				setGameStatus(GAME_OVER);
				return ;
			}
		}
	}
	if(checkWin()) setGameStatus(GAME_WON);
}