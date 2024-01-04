#include "image.h"
#include "framebuffer.h"
#include "level.h"
#include "snes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// LEVEL 1 DRAW METHOD
void drawLevel1(){

	map.currentLevel = 0;
	for( int k = 0; k<22;k++){
		for(int j = 0; j<40;j++){
			drawImage(j*32, k*32, &tilemap.images[fence]);
			map.mapper[k][j] = 0;
		}
	}


	for(int i = 0; i < 3;i++){
		for(int j = 0; j<40; j++){
		drawImage(j*32, i*32, &tilemap.images[tile]);
		map.mapper[i][j] = 1;
		}
	}
	for(int i = 0; i < 22;i++){
		for(int j = 38; j<40; j++){
			drawImage(j*32, i*32, &tilemap.images[tile]);
			map.mapper[i][j] = 1;
		}
	}
	for(int i = 0; i < 21;i++){
		for(int j = 0; j<3; j++){
			drawImage(j*32, i*32, &tilemap.images[tile]);
			map.mapper[i][j] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		drawImage(i*32, 64, &tilemap.images[tile]);
		map.mapper[2][i] = 1;
	}

	int j = 21;
	for(int i = 0; i < 40;i++){
		drawImage(i*32, j*32, &tilemap.images[tile]);
		map.mapper[j][i] = 1;
		drawImage(i*32, (j-1)*32, &tilemap.images[tile]);
		map.mapper[j-1][i] = 1;
	}
	for(j = 25; j< 38;j++){
		drawImage(j*32, (19*32), &tilemap.images[fire]);
		map.mapper[19][j] = fire;
	}

	for(int j = 0; j < (map.lives); j++){
		drawImage(0, j*32, &tilemap.images[heart]);
	}

	// DRAW PLATFORMS

	map.starti = 3*32;
	map.startj = 3*32;
	for(int j = 3; j < 15; j++){
		drawImage(j*32, (4)*32, &tilemap.images[tile]);
		map.mapper[4][j] = 1;
	}

	for(int j = 3; j < 20; j++){
		drawImage(j*32, (7)*32, &tilemap.images[tile]);
		map.mapper[7][j] = 1;

	}

	for(int j = 12; j< 39; j++){
		drawImage(j*32, (10)*32, &tilemap.images[tile]);
		map.mapper[10][j] = 1;

	}

	for(int j = 3; j< 17; j++){
		drawImage(j*32, (13)*32, &tilemap.images[tile]);
		map.mapper[13][j] = 1;
	}

	for(int j = 13; j< 38; j++){
		drawImage(j*32, (16)*32, &tilemap.images[tile]);
		map.mapper[16][j] = 1;
	}

	for(int j = 3; j< 25; j++){
		drawImage(j*32, (19)*32, &tilemap.images[tile]);
		map.mapper[19][j] = 1;
	}


	map.endi = 18*32;
	map.endj = 24*32;
	drawImage(576, 1, &tilemap.images[level1]);
	drawImage(map.endj, map.endi + 32, &tilemap.images[pointer]);
}

// LEVEL 2 DRAW METHOD
void drawLevel2(){

	map.currentLevel = 1;
	for( int k = 0; k<22;k++){
		for(int j = 0; j<40;j++){
			drawImage(j*32, k*32, &tilemap.images[grass]);
			map.mapper[k][j] = 0;
		}
	}


	for(int i = 0; i < 3;i++){
	for(int j = 0; j<40; j++){
		drawImage(j*32, i*32, &tilemap.images[water]);
		map.mapper[i][j] = 1;
	}
	}
	for(int j = 38; j < 40;j++){
		for(int i = 0; i<22; i++){
			drawImage(j*32, i*32, &tilemap.images[water]);
			map.mapper[i][j] = 1;
		}
	}
	for(int i = 0; i < 3;i++){
		for(int j = 0; j<21; j++){
			drawImage(i*32, j*32, &tilemap.images[water]);
			map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		drawImage(i*32, 64, &tilemap.images[water]);
		map.mapper[2][i] = 1;
	}

	for(int j = 25; j< 38;j++){
		drawImage(j*32, (19*32), &tilemap.images[water]);
		map.mapper[19][j] = 1;
	}

	for(int j = 0; j< (map.lives);j++){
		drawImage(0, j*32, &tilemap.images[heart]);
	}

	int j = 21;
	for(int i = 0; i < 40;i++){
		drawImage(i*32, j*32, &tilemap.images[water]);
		map.mapper[j][i] = 1;
		drawImage(i*32, (j-1)*32, &tilemap.images[water]);
		map.mapper[j-1][i] = 1;
	}

	// DRAW PLATFORMS

	map.starti = 3*32;
	map.startj = 24*32;
	for(int j = 3; j < 25; j++){
		drawImage(j*32, (4)*32, &tilemap.images[water]);
		map.mapper[4][j] = 1;
	}

	for(int j = 20; j < 38; j++){
		drawImage(j*32, (7)*32, &tilemap.images[water]);
		map.mapper[7][j] = 1;

	}

	for(int j = 12; j< 38; j++){
		drawImage(j*32, (10)*32, &tilemap.images[water]);
		map.mapper[10][j] = 1;

	}

	for(int j = 3; j< 18; j++){
		drawImage(j*32, (13)*32, &tilemap.images[water]);
		map.mapper[13][j] = 1;
	}

	for(int j = 3; j< 27; j++){
		drawImage(j*32, (16)*32, &tilemap.images[water]);
		map.mapper[16][j] = 1;
	}

	for(int j = 3; j< 38; j++){
		drawImage(j*32, (19)*32, &tilemap.images[water]);
		map.mapper[19][j] = 1;
	}

	map.endi = 18*32;
	map.endj = 36*32;
	drawImage(576, 1, &tilemap.images[level2]);
	drawImage(map.endj, map.endi + 32, &tilemap.images[pointer]);

}

// LEVEL 3 DRAW METHOD
void drawLevel3(){

	map.currentLevel = 2;
	for( int k = 0; k<22;k++){
		for(int j = 0; j<40;j++){
			drawImage(j*32, k*32, &tilemap.images[water]);
			map.mapper[k][j] = 0;
		}
	}

	for(int i = 0; i < 3;i++){
	for(int j = 0; j<22; j++){
		drawImage(i*32, j*32, &tilemap.images[fence]);
		map.mapper[j][i] = 1;
	}
	}
	for(int i = 38; i < 40;i++){
		for(int j = 0; j<22; j++){
			drawImage(i*32, j*32, &tilemap.images[fence]);
			map.mapper[j][i] = 1;
		}
	}
	for(int i = 0; i < 3;i++){
		for(int j = 0; j<21; j++){
			drawImage(i*32, j*32, &tilemap.images[fence]);
			map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 38;i++){
		for(int j = 0; j<3;j++){
		drawImage(i*32, j*32, &tilemap.images[fence]);
		map.mapper[j][i] = 1;
		}
	}

	for(int i = 0; i < 39;i++){
		drawImage(i*32, 21*32, &tilemap.images[fence]);
		map.mapper[21][i] = 1;
		drawImage(i*32, 20*32, &tilemap.images[fence]);
		map.mapper[20][i] = 1;
	}


	for(int j = 0; j< (map.lives);j++){
		drawImage(0, j*32, &tilemap.images[heart]);
	}

	for(int j = 3; j< 23; j++){
		drawImage(j*32, 19*32, &tilemap.images[fire]);
		map.mapper[19][j] = fire;
	}
	// DRAW PLATFORMS

	map.starti = 3*32;
	map.startj = 25*32;
	for(int j = 25; j < 38; j++){
		drawImage(j*32, (4)*32, &tilemap.images[tile]);
		map.mapper[4][j] = 1;
	}


	for(int j = 3; j < 26; j++){
		drawImage(j*32, (7)*32, &tilemap.images[tile]);
		map.mapper[7][j] = 1;

	}

	for(int j = 12; j< 38; j++){
		drawImage(j*32, (10)*32, &tilemap.images[tile]);
		map.mapper[10][j] = 1;

	}

	for(int j = 3; j< 20; j++){
		drawImage(j*32, (13)*32, &tilemap.images[tile]);
		map.mapper[13][j] = 1;
	}

	for(int j = 3; j< 27; j++){
		drawImage(j*32, (16)*32, &tilemap.images[tile]);
		map.mapper[16][j] = 1;
	}

	for(int j = 23; j< 38; j++){
		drawImage(j*32, (19)*32, &tilemap.images[tile]);
		map.mapper[19][j] = 1;
	}

	map.endi = 18*32;
	map.endj = 37*32;
	drawImage(576, 1, &tilemap.images[level3]);
	drawImage(map.endj, map.endi + 32, &tilemap.images[pointer]);

}

// LEVEL 4 DRAW METHOD
void drawLevel4(){

	map.currentLevel = 3;
	for( int k = 0; k<22;k++){
		for(int j = 0; j<40;j++){
			drawImage(j*32, k*32, &tilemap.images[fence]);
			map.mapper[k][j] = 0;
		}
	}

	for(int i = 0; i < 3;i++){
	for(int j = 0; j<22; j++){
		drawImage(i*32, j*32, &tilemap.images[water]);
		map.mapper[j][i] = 1;
	}
	}
	for(int i = 38; i < 40;i++){
		for(int j = 0; j<22; j++){
			drawImage(i*32, j*32, &tilemap.images[water]);
			map.mapper[j][i] = 1;
		}
	}
	for(int i = 0; i < 3;i++){
		for(int j = 0; j<21; j++){
			drawImage(i*32, j*32, &tilemap.images[water]);
			map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		for(int j = 0; j < 3; j++){
		drawImage(i*32, j*32, &tilemap.images[water]);
		map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		for(int j = 20; j < 22; j++){
		drawImage(i*32, j*32, &tilemap.images[water]);
		map.mapper[j][i] = 1;
		}
	}


	// for(int i = 0; i < 39;i++){
	// 	drawImage(i*32, 21*32, &tilemap.images[fire]);
	// 	map.mapper[21][i] = 1;
	// }

	for(int j = 0; j< (map.lives);j++){
		drawImage(0, j*32, &tilemap.images[heart]);
	}

	// DRAW PLATFORMS

	map.starti = 3*32;
	map.startj = 25*32;

	for(int j = 25; j < 38; j++){
		drawImage(j*32, (4)*32, &tilemap.images[grass]);
		map.mapper[4][j] = 1;
	}

	for(int j = 3; j < 26; j++){
		drawImage(j*32, (7)*32, &tilemap.images[grass]);
		map.mapper[7][j] = 1;

	}

	for(int j = 12; j< 38; j++){
		drawImage(j*32, (10)*32, &tilemap.images[grass]);
		map.mapper[10][j] = 1;

	}

	for(int j = 7; j< 38; j++){
		drawImage(j*32, (13)*32, &tilemap.images[grass]);
		map.mapper[13][j] = 1;
	}

	for(int j = 3; j< 27; j++){
		drawImage(j*32, (16)*32, &tilemap.images[grass]);
		map.mapper[16][j] = 1;
	}

	for(int j = 23; j< 38; j++){
		drawImage(j*32, (19)*32, &tilemap.images[grass]);
		map.mapper[19][j] = 1;

	}

	for(int j = 3; j< 23; j++){
		drawImage(j*32, 19*32, &tilemap.images[fire]);
		map.mapper[19][j] = fire;
	}
	map.endi = 18*32;
	map.endj = 37*32;
	drawImage(576, 1, &tilemap.images[level4]);
	drawImage(map.endj, map.endi + 32, &tilemap.images[pointer]);


}

// LEVEL 5 DRAW METHOD
void drawLevel5(){

	map.currentLevel = 4;
	for( int k = 0; k<22;k++){
		for(int j = 0; j<40;j++){
			drawImage(j*32, k*32, &tilemap.images[water]);
			map.mapper[k][j] = 0;
		}
	}

	for(int i = 0; i < 3;i++){
	for(int j = 0; j<22; j++){
		drawImage(i*32, j*32, &tilemap.images[tile]);
		map.mapper[j][i] = 1;
	}
	}
	for(int i = 38; i < 40;i++){
		for(int j = 0; j<22; j++){
			drawImage(i*32, j*32, &tilemap.images[tile]);
			map.mapper[j][i] = 1;
		}
	}
	for(int i = 0; i < 3;i++){
		for(int j = 0; j<21; j++){
			drawImage(i*32, j*32, &tilemap.images[tile]);
			map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		for(int j = 0; j <3; j++){
		drawImage(i*32, j*32, &tilemap.images[tile]);
		map.mapper[j][i] = 1;
		}
	}

	for(int i = 1; i < 39;i++){
		for(int j = 20; j <22; j++){
		drawImage(i*32, j*32, &tilemap.images[tile]);
		map.mapper[j][i] = 1;
		}
	}

	for(int j = 0; j< (map.lives);j++){
		drawImage(0, j*32, &tilemap.images[heart]);
	}

	// DRAW PLATFORMS

	// initialize start coordinates of current level
	map.starti = 3*32;
	map.startj = 25*32;
	for(int j = 5; j < 38; j++){
		drawImage(j*32, (4)*32, &tilemap.images[grass]);
		map.mapper[4][j] = 1;
	}

	for(int j = 3; j < 26; j++){
		drawImage(j*32, (7)*32, &tilemap.images[grass]);
		map.mapper[7][j] = 1;

	}

	for(int j = 12; j< 38; j++){
		drawImage(j*32, (10)*32, &tilemap.images[grass]);
		map.mapper[10][j] = 1;

	}

	for(int j = 3; j< 14; j++){
		drawImage(j*32, (13)*32, &tilemap.images[grass]);
		map.mapper[13][j] = 1;
	}

	for(int j = 3; j< 27; j++){
		drawImage(j*32, (16)*32, &tilemap.images[grass]);
		map.mapper[16][j] = 1;
	}

	for(int j = 3; j< 38; j++){
		drawImage(j*32, (19)*32, &tilemap.images[grass]);
		map.mapper[19][j] = 1;
	}

	// initialize end coordinates of current level
	map.endi = 18*32;
	map.endj = 10*32;
	drawImage(map.endj - 32, map.endi, &tilemap.images[kong]);
	map.mapper[(map.endi/32)][(map.endj/32) -1] = 1;
	drawImage(map.endj - 32, map.endi - 32, &tilemap.images[kong]);
	map.mapper[(map.endi/32) - 1][(map.endj/32) - 1] = 1;
	drawImage(map.endj - 64, map.endi - 32, &tilemap.images[kong]);
	map.mapper[(map.endi/32) - 2][(map.endj/32) - 1] = 1;
	drawImage(576, 1, &tilemap.images[level5]);
	drawImage(map.endj, map.endi + 32, &tilemap.images[pointer]);

}

/*
Mehtod to interact with the pause menu when the START button input is read from GPIO.

Returns 0 to CONTINUE or 1 to QUIT.
*/
int paused (){

	// Coordiantes to refer to for where the CONTINUE and QUIT images are printed.
	int x = 486;
	int y = 374;

	// var to read from snes
	unsigned int result;

	// var to indicate quit or continue. Initialise to 0 to indicate quit.
	int quitstat = 0;

	// pointer is blue indicating current selecting and pointer 2 is black indicationg alternate selection.
	drawImage(x, y, &tilemap.images[pointer]);
	drawImage(x, y+120, &tilemap.images[pointer2]);

	while(1){
		result = read_snes();
		// If A is read from GPIO then a value is returned depending on the state of quitstat
		if((result == A) & (quitstat  == 0)){
			return 0;
		}else if((result == A) & (quitstat == 1)){
			return 1;
		}

		if(result == DOWN){
			if(y == 374){
				drawImage(x, y, &tilemap.images[pointer2]);
				y += 120;
				drawImage(x, y, &tilemap.images[pointer]);
				drawImage(528, 324, &tilemap.images[continuescreen]);
				quitstat = 1;
				continue;
			}
		}

		if(result == UP){
			if(y == 494){
				drawImage(x, y, &tilemap.images[pointer2]);
				y -= 120;
				drawImage(x, y, &tilemap.images[pointer]);
				drawImage(528, 444, &tilemap.images[quit]);
				quitstat = 0;
				continue;
			}
		}

		if(result == START){
			return 0;
		}

	}	
}

/*
Mehtod to interact with the main screen so that we can decide to start a new game or to exit the game.

Return 1 for QUIT or 0 to START new game
*/
int MainScreen(){
	drawImage(33, 32, &tilemap.images[homescreen]);
	drawImage(528, 400, &tilemap.images[start]);
	drawImage(528, 520, &tilemap.images[quit]);
	drawImage(640, 1, &tilemap.images[instruct]);

	int x = 486;
	int y = 450;
	unsigned int result;
	int quitstat = 0;
	drawImage(x, y, &tilemap.images[pointer]);
	drawImage(x, y+120, &tilemap.images[pointer2]);

	while(1){
	result = read_snes();

	if((result == A) & (quitstat  == 0)){
		return 0;
	}else if((result == A) & (quitstat == 1)){
		return 1;
	}

	if(result == DOWN){
		if(y == 450){
			drawImage(x, y, &tilemap.images[pointer2]);
			y += 120;
			drawImage(x, y, &tilemap.images[pointer]);
			quitstat = 1;
			continue;
		}
	}

	if(result == UP){
		if(y == 570){
			drawImage(x, y, &tilemap.images[pointer2]);
			y -= 120;
			drawImage(x, y, &tilemap.images[pointer]);
			quitstat = 0;
			continue;
		}
	}

	}
}

/*
The following method resets the current map to the level 1 map.
*/
void reset(){
	map.currentLevel = 0;
	map.lives = 4;

	map.starti = 3*32;
	map.startj = 3*32;

	map.endi = 18*32;
	map.endj = 24*32;

	map.bananas = 0;
	map.mapper[3][14] = food;
	map.mapper[6][6] = food;
	map.mapper[9][12] = food;
	map.mapper[12][16] = food;
	map.mapper[15][37] = food;
	map.mapper[18][20] = food;
	map.score = 0;

}

/**
The following method takes parameter input of level number and initializes locations on the map for the level number that is passed in which is (level_number - 1)

i.e If level is level 5 then the parameter is 5-1 which is 4.

*/
void initLevel(int level){


	if(level == 0){//L1
		//WATER
		map.mapper[3][14] = food;
		map.mapper[6][6] = food;
		map.mapper[9][12] = food;
		map.mapper[12][16] = food;
		map.mapper[15][37] = food;
		map.mapper[18][20] = food;
		
		// FIRE
		map.mapper[6][10] = fire;
		map.mapper[9][14] = fire;
		map.mapper[12][12] = fire;
		map.mapper[15][29] = fire;
		map.mapper[18][15] = fire;
		map.lives = 4;
		map.score = 0;
	}
	if(level == 1){//L2
		//WATER
		map.mapper[3][10] = food;
		map.mapper[6][20] = food;
		map.mapper[9][20] = food;
		map.mapper[12][17] = food;
		map.mapper[15][12] = food;
		map.mapper[18][35] = food;
		
		// FIRE
		map.mapper[6][23] = fire;
		map.mapper[9][24] = fire;
		map.mapper[12][12] = fire;
		map.mapper[15][15] = fire;
		map.mapper[18][30] = fire;
		copyObjects();
	}
	if( level == 2){//L3
		//WATER
		map.mapper[3][30] = food;
		map.mapper[6][17] = food;
		map.mapper[9][17] = food;
		map.mapper[9][15] = food;
		map.mapper[12][11] = food;
		map.mapper[15][11] = food;
		map.mapper[18][36] = food;
		
		// FIRE
		map.mapper[6][20] = fire;
		map.mapper[9][24] = fire;
		map.mapper[9][23] = fire;
		map.mapper[9][22] = fire;
		map.mapper[12][13] = fire;
		map.mapper[15][13] = fire;
		map.mapper[18][34] = fire;
		copyObjects();
	}
	if(level == 3){//L4
		//WATER
		map.mapper[3][30] = food;
		map.mapper[6][17] = food;
		map.mapper[9][17] = food;
		map.mapper[9][15] = food;
		map.mapper[12][11] = food;
		map.mapper[15][11] = food;
		map.mapper[18][36] = food;
		
		// FIRE
		map.mapper[6][20] = fire;
		map.mapper[9][24] = fire;
		map.mapper[9][23] = fire;
		map.mapper[9][22] = fire;
		map.mapper[12][13] = fire;
		map.mapper[15][13] = fire;
		map.mapper[18][34] = fire;
		copyObjects();
	}
	if(level == 4){//L5
		//WATER
		map.mapper[3][30] = food;
		map.mapper[6][17] = food;
		map.mapper[9][17] = food;
		map.mapper[9][15] = food;
		map.mapper[12][11] = food;
		map.mapper[15][11] = food;
		map.mapper[18][36] = food;
		
		// FIRE
		map.mapper[6][20] = fire;
		map.mapper[9][24] = fire;
		map.mapper[9][23] = fire;
		map.mapper[9][22] = fire;
		map.mapper[12][13] = fire;
		map.mapper[15][13] = fire;
		map.mapper[18][34] = fire;
		copyObjects();
	}
}

/*
Method to draw the objects of the level passed as a parameter.
*/
void drawObjects(int level){

	/*
	The following code will decide which level to draw game objects for. Such as the banana and the fire whenever called.
	
	*/

	if(level == 0){
		for(int i = 0; i < 22; i++){
			for(int j = 0; j< 40; j++){
				if(map.copymap[i][j] == food){
					drawImage(j*32, i*32, &tilemap.images[food]);
					map.mapper[i][j] = food;
				}
				if(map.copymap[i][j]== fire){
					drawImage(j*32, i*32, &tilemap.images[fire]);
					map.mapper[i][j] = fire;
				}
			}
		}
	}
	if(level == 1){
		for(int i = 0; i < 22; i++){
			for(int j = 0; j< 40; j++){
				if(map.copymap[i][j] == food){
					drawImage(j*32, i*32, &tilemap.images[food]);
					map.mapper[i][j] = food;
				}
				if(map.copymap[i][j]== fire){
					drawImage(j*32, i*32, &tilemap.images[fire]);
					map.mapper[i][j] = fire;
				}
			}
		}
	}
	if(level == 2){
		for(int i = 0; i < 22; i++){
			for(int j = 0; j< 40; j++){
				if(map.copymap[i][j] == food){
					drawImage(j*32, i*32, &tilemap.images[food]);
					map.mapper[i][j] = food;
				}
				if(map.copymap[i][j]== fire){
					drawImage(j*32, i*32, &tilemap.images[fire]);
					map.mapper[i][j] = fire;
				}
			}
		}
	}
	if(level == 3){
		for(int i = 0; i < 22; i++){
			for(int j = 0; j< 40; j++){
				if(map.copymap[i][j] == food){
					drawImage(j*32, i*32, &tilemap.images[food]);
					map.mapper[i][j] = food;
				}
				if(map.copymap[i][j]== fire){
					drawImage(j*32, i*32, &tilemap.images[fire]);
					map.mapper[i][j] = fire;
				}
			}
		}
	}
	if(level == 4){
		for(int i = 0; i < 22; i++){
			for(int j = 0; j< 40; j++){
				if(map.copymap[i][j] == food){
					drawImage(j*32, i*32, &tilemap.images[food]);
					map.mapper[i][j] = food;
				}
				if(map.copymap[i][j]== fire){
					drawImage(j*32, i*32, &tilemap.images[fire]);
					map.mapper[i][j] = fire;
				}
			}
		}
	}
}

/*
Method to update the lives displayed on the screen.
The paramter passed is the background so that the background is changed according to the current level
*/
void lives(int background){
	for(int i = 0; i< 4; i++){
		drawImage(0, i*32, &tilemap.images[background]);
	}
	
	for(int i = 0; i < (map.lives); i++){
		drawImage(0, i*32, &tilemap.images[heart]);
	}

		
}

/*
Method to copy the object locations of the main map array to tthe copy array
*/

void copyObjects(){
	for(int i = 0; i < 22; i++){
		for(int j = 0; j < 40; j++){
			map.copymap[i][j] = map.mapper[i][j];
		}
	}
}

/*
Method to draw the ending title screen after finish the game.
*/
void drawEnd(){
	fillScreen(0xff0000);
	drawImage(490, 170, &tilemap.images[win]);
	drawImage(490, 500, &tilemap.images[button]);
	while(1){
		unsigned int result = read_snes();
		//Waits for any button press to break out of infinite loop and return to main Menu.
		if(result != MASK){
			break;
		}
	}
}