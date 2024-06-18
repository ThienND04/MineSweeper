#include <Window_Result.h>

// WindowResult *WindowResult::getInstance() {
//     if (instance == NULL) {
//         instance = new WindowResult();
//     }
//     return instance;
// }

WindowResult::WindowResult(Game *game) : 
    Window("Result", WINDOW_RESULT_WIDTH, WINDOW_RESULT_HEIGHT) {

    Text *text = NULL;
    if (game->getGameStatus() | GameStatus::GAME_OVER) {
        text = new Text(this->getRenderer());
        text -> setText("Thua roi haha!", CL_RED);
    }
}