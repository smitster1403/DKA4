#pragma once 

// CONSTANTS TO USE AS REFERNCES WHEN PRINTING IMAGES.
#define water 0
#define grass 1
#define tile 2
#define fence 3
#define kong 4
#define heart 5
#define pointer 6
#define food 7
#define fire 8
#define start 9
#define continuescreen 10
#define gameover 11
#define startover 12
#define pausedscreen 13
#define quit 14
#define pointer2 15
#define homescreen 16
#define win 17
#define lose 18
#define button 19
#define level1 20
#define level2 21
#define level3 22
#define level4 23
#define level5 24
#define instruct 25

struct Image{
    int width; // columns
    int height; // rows
    unsigned int *data;
};

struct Tilemap{
    int count;
    struct Image images[];
};

extern struct Tilemap tilemap;
