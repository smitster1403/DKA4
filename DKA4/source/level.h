struct GameState{

    // Main coordinates map that has integer values indicationg different game objects
    int mapper[22][40];
    // Copy of main coordinates map.
    int copymap[22][40];

    // Vars to store the current location of donkey kong on the screen
    int starti;
    int startj;

    // store lives
    int lives;
    // store currentLevel
    int currentLevel;
    // store number of bananas picked up
    int bananas;

    int ci;
    int cj;
    // Player score
    int score;

    // End coordinates of current level.
    int endi;
    int endj;
};

// Game state struct to access in execution of the game.
struct GameState map;

// FUNCTION DECLARATIONS FOR THOSE IN level.c

void drawLevel1();

void drawLevel2();

void drawLevel3();

void drawLevel4();

void drawLevel5();

int paused();

int MainScreen();

void reset();

void initLevel(int level);

void drawObjects(int level);

void lives(int background);

void drawEnd();

void copyObjects();