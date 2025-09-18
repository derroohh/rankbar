#include "script.h"
#include "keyboard.h"
#include <time.h>   // portable srand seed

int rankBar;
bool loaded = false;

void loadRankBar() {
    if (!loaded) {
        rankBar = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_RANK_BAR");
        if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(rankBar)) {
            loaded = true;
        }
    }
}

void showRankBar(int curRank, int curXP, int nextXP, int oldXP) {
    if (!loaded) return;

    GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD_WITH_NUMBER(
        rankBar,
        "SET_RANK_SCORES",
        (float)curRank,   // current rank
        (float)curXP,     // current XP
        (float)nextXP,    // XP required for next rank
        (float)oldXP,     // old XP (before gain)
        -1.0              // unused
    );
}

void drawRankBar() {
    if (loaded) {
        GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(rankBar, 255, 255, 255, 255, 0);
    }
}

void main() {
    while (true) {
        loadRankBar();

        // F7 to trigger
        if (IsKeyJustUp(VK_F7)) {
            showRankBar(25, 1500, 3000, 1000); // Example: rank 25
        }

        drawRankBar();
        WAIT(0);
    }
}

void ScriptMain() {
    srand((unsigned int)time(NULL)); // portable random seed
    main();
}
