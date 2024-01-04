/**

Name: Smitkumar Saraiya

UCID: 30151834

CPSC 359 Computing Machinery 2 WINTER 2023 

Assignment 3 & 4

*/


#include "gpio.h"
#include "uart.h"
#include "snes.h"
#include "image.h"
#include "framebuffer.h"
#include "level.h"
#define GPIO_BASE 0xFE200000

int main(){


//unsigned int level[22][40];




void printf(char *str) {
	uart_puts(str);
}

	printf("\nCreator: Smitkumar Saraiya\n\nUCID: 30151834\n\nCPSC 359 Computing Machinery 2\n\nAssignment 3\n\nSNES Device Drivers\n");
	void (*functions[5])() = {drawLevel1, drawLevel2, drawLevel3, drawLevel4, drawLevel5};
	// initialise SNES lines for I/O
	init_snes_lines();
	// Temp varibale to store the previous input.
	int back[5] = {fence, grass, water, fence, water};
	unsigned int lastResult = 0;
	int background = back[0];
	init_framebuffer();
	fillScreen(0x00000000);
	unsigned int *game_start = (unsigned int *) CLK_REG;
	unsigned int game_end = *game_start +(120 * 1000000);
	map.lives = 4;
	map.currentLevel = 0;
	if(!(MainScreen())){
		(*functions[map.currentLevel])();
		initLevel(map.currentLevel);
		copyObjects();
		drawObjects(map.currentLevel);
	}else{
		fillScreen(0x00000000);
		drawImage(1, 1, &tilemap.images[homescreen]);
		drawImage(640,360, &tilemap.images[quit]);
		return 1;
	}
	// Call the first level function
	// Set the starting coordinates of dk which are automatically set when the functoin call is made

	int i_s = map.starti;
	int j_s = map.startj;

	printf("Press a button to display output. Press START to terminate. \n");

	// read from SNES controller to a sampling register
	unsigned int result = read_snes();
		drawImage(96, 96, &tilemap.images[4]);

		/**
			The following if statements compare result with the hex values declared in snes.h which are accessible
			because snes.h is included here.

			If result matches with the hex value of the button it is being compared with then corresponding print statement 
			is printed.
		 */
			if(result == B){
				printf("B pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == Y){
				printf("Y pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");

			}
			if(result == SELECT){
				printf("Select pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");

			}
			if(result == START){
				printf("Start pressed.\n");
			}
			if(result == UP){
				printf("Up pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == DOWN){
				printf("Down pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == LEFT){
				printf("Left pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == RIGHT){
				printf("Right pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == A){
				printf("A pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == X){
				printf("X pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == L){
				printf("L pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == R){
				printf("R pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}

	printf("\n");
	// Wait 200 microseconds
	sleep_microseconds(200);

	while (1) {
		// Store last result in temp lastResult variable
		unsigned int *ctime = (unsigned int *) CLK_REG;
		unsigned int currentTime = *ctime;
		unsigned int time_left = ((game_end)-(currentTime))/1000000;
		   // time
		int MAX_SIZE = 8;
    	char buff[MAX_SIZE];
    	buff[0] = '\0';
    	unsigned int value = time_left;
    	int i,j, rem;
    	char temp = '\0';

    	i = 0;
    	rem = value % 10;
    	char letter_rem = (char) rem + 48;
    	buff[i] = letter_rem;
    	i++;
    	while(value > 0){
        	rem = value%10;
        	value = value / 10;
        	letter_rem = (char) rem + 48;
        	buff[i] = letter_rem;
        	i++;
    	}
    	buff[i] = '\0';
    	i = 0;
    	j = i - 1;
    	while(i<j){
        	buff[i] = temp;
        	buff[i] = buff[j];
        	buff[j] = temp;
        	i++;
        	j--;
    	}
    printf("\n");
	printf(buff);
    printf("\n");
	
		// Store last result
		lastResult = result;
		// Read new input from SNES
		result = read_snes();
		if(result != lastResult && result != MASK){
			printf("\n");
			/**
			The following if statements compare result with the hex values declared in snes.h which are accessible
			because snes.h is included here.

			If result matches with the hex value of the button it is being compared with then corresponding print statement 
			is printed.
			*/
			if(result == B){
				printf("B pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == Y){
				printf("Y pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == SELECT){
				printf("Select pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			// If START is pressed then call the paused() method
			if(result == START){
				printf("Start pressed.\n");
					drawImage(528, 204, &tilemap.images[pausedscreen]);
					drawImage(528, 324, &tilemap.images[continuescreen]);
					drawImage(528, 444, &tilemap.images[quit]);
					int val = paused();
					// if paused() = 1 then go to MainScreen
					if(val){
						fillScreen(0x00000000);
						// reset
						reset();
						background = back[0];
						i_s = map.starti;
						j_s = map.startj;
						if(!MainScreen()){
							(*functions[map.currentLevel])();
							initLevel(map.currentLevel);
							drawObjects(map.currentLevel);
							drawImage(j_s, i_s, &tilemap.images[kong]);
							continue;
						}else{
							reset();
							fillScreen(0x00000000);
							drawImage(1, 1, &tilemap.images[homescreen]);
							drawImage(640,360, &tilemap.images[gameover]);
							return 1;
						}
					}else{ // If paused() = 0 then display current level
						copyObjects();
						(*functions[map.currentLevel])();
						drawObjects(map.currentLevel);
						drawImage(j_s, i_s, &tilemap.images[kong]);
						continue;
					}
			}
			if(result == UP){
				printf("Up pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
				if((map.mapper[(i_s/32) - 1][j_s/32] == 1)){
					continue;
				}else{
				drawImage(j_s, i_s-32, &tilemap.images[kong]);
				drawImage(j_s, i_s, &tilemap.images[background]);
				i_s -=32;
				if(	(map.mapper[i_s/32][j_s/32]) == food){
					map.bananas++;
					map.score += 5;
					map.mapper[i_s/32][j_s/32] = 0;
					continue;
				}
				if((map.mapper[i_s/32][j_s/32]) == fire){
					map.lives--;
					if(map.lives == 0){
						drawImage(490, 170, &tilemap.images[lose]);
						reset();
						fillScreen(0x00000000);
						drawImage(1, 1, &tilemap.images[homescreen]);
						drawImage(640,360, &tilemap.images[gameover]);
						return 1;
					}
					drawImage(j_s, i_s, &tilemap.images[fire]);
					i_s = map.starti;
					j_s = map.startj;
					drawImage(j_s, i_s, &tilemap.images[kong]);
					for(int i = 0; i< 4; i++){
						drawImage(0, i*32, &tilemap.images[background]);
					}
	
					for(int i = 0; i < (map.lives - 1); i++){
						drawImage(0, i*32, &tilemap.images[heart]);
					}
					lives(background);
					continue;
				}
				if((i_s == map.endi) & (j_s == map.endj)){
					if(map.currentLevel == 4){
						drawEnd();
						map.score += (map.lives * 5);
					}
					map.currentLevel = map.currentLevel + 1;
					initLevel(map.currentLevel);
					(*functions[map.currentLevel])();
					initLevel(map.currentLevel);
					drawObjects(map.currentLevel);
					i_s = map.starti;
					j_s = map.startj;
					background = back[map.currentLevel];
					drawImage(j_s, i_s, &tilemap.images[kong]);
					continue;
				}
				}
			}
			if(result == DOWN){
				printf("Down pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
				if((map.mapper[(i_s/32) + 1][j_s/32] == 1)){
					continue;
				}else{
				drawImage(j_s, i_s+32, &tilemap.images[kong]);
				drawImage(j_s, i_s, &tilemap.images[background]);
				i_s +=32;
				if(	(map.mapper[i_s/32][j_s/32]) == food){
					map.bananas++;
					map.score += 5;
					map.mapper[i_s/32][j_s/32] = 0;
					continue;
				}
				if((map.mapper[i_s/32][j_s/32]) == fire){
					map.lives--;
					if(map.lives == 0){
						drawImage(490, 170, &tilemap.images[lose]);
						reset();
						fillScreen(0x00000000);
						drawImage(1, 1, &tilemap.images[homescreen]);
						drawImage(640,360, &tilemap.images[gameover]);
						return 1;
					}
					drawImage(j_s, i_s, &tilemap.images[fire]);
					i_s = map.starti;
					j_s = map.startj;
					drawImage(j_s, i_s, &tilemap.images[kong]);
					for(int i = 0; i< 4; i++){
						drawImage(0, i*32, &tilemap.images[background]);
					}
	
					for(int i = 0; i < (map.lives - 1); i++){
						drawImage(0, i*32, &tilemap.images[heart]);
					}
					lives(background);
					continue;
				}
				// DOWN END CHECK
				if((i_s == map.endi) & (j_s == map.endj)){
					if(map.currentLevel == 4){
						drawEnd();
						map.score += (map.lives * 5);
					}
					map.currentLevel = map.currentLevel + 1;
					initLevel(map.currentLevel);
					(*functions[map.currentLevel])();
					initLevel(map.currentLevel);
					drawObjects(map.currentLevel);
					i_s = map.starti;
					j_s = map.startj;
					background = back[map.currentLevel];
					drawImage(j_s, i_s, &tilemap.images[kong]);
					continue;
				}
				}
			}
			if(result == LEFT){
				printf("Left pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
				
				if((map.mapper[i_s/32][(j_s/32) - 1] == 1)){
					continue;
				}else{
				drawImage(j_s-32, i_s, &tilemap.images[kong]);
				drawImage(j_s, i_s, &tilemap.images[background]);
				j_s -=32;
				if(	(map.mapper[i_s/32][j_s/32]) == food){
					map.bananas++;
					map.score += 5;
					map.mapper[i_s/32][j_s/32] = 0;
					continue;
				}
				if((map.mapper[i_s/32][j_s/32]) == fire){
					map.lives--;
					if(map.lives == 0){
						drawImage(490, 170, &tilemap.images[lose]);
						reset();
						fillScreen(0x00000000);
						drawImage(1, 1, &tilemap.images[homescreen]);
						drawImage(640,360, &tilemap.images[gameover]);
						return 1;
					}
					drawImage(j_s, i_s, &tilemap.images[fire]);
					i_s = map.starti;
					j_s = map.startj;
					drawImage(j_s, i_s, &tilemap.images[kong]);
					for(int i = 0; i< 4; i++){
						drawImage(0, i*32, &tilemap.images[background]);
					}
	
					for(int i = 0; i < (map.lives - 1); i++){
						drawImage(0, i*32, &tilemap.images[heart]);
					}
					lives(background);
					continue;
				}
				if((i_s == map.endi) & (j_s == map.endj)){
					if(map.currentLevel == 4){
						drawEnd();
						map.score += (map.lives * 5);
					}
					map.currentLevel = map.currentLevel + 1;
					initLevel(map.currentLevel);
					(*functions[map.currentLevel])();
					initLevel(map.currentLevel);
					drawObjects(map.currentLevel);
					i_s = map.starti;
					j_s = map.startj;
					background = back[map.currentLevel];
					drawImage(j_s, i_s, &tilemap.images[kong]);
					continue;
				}
				}
			}
			if(result == RIGHT){
				printf("Right pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
				if((map.mapper[i_s/32][(j_s/32)+1] == 1)){
					continue;
				}else{
				drawImage(j_s+32, i_s, &tilemap.images[kong]);
				drawImage(j_s, i_s, &tilemap.images[background]);
				j_s +=32;
				if(	(map.mapper[i_s/32][j_s/32]) == food){
					map.bananas++;
					map.score += 5;
					map.mapper[i_s/32][j_s/32] = 0;
					continue;
				}
				if((map.mapper[i_s/32][j_s/32]) == fire){
					map.lives--;
					if(map.lives == 0){
						drawImage(490, 170, &tilemap.images[lose]);
						reset();
						fillScreen(0x00000000);
						drawImage(1, 1, &tilemap.images[homescreen]);
						drawImage(640,360, &tilemap.images[gameover]);
						return 1;
					}
					drawImage(j_s, i_s, &tilemap.images[fire]);
					i_s = map.starti;
					j_s = map.startj;
					drawImage(j_s, i_s, &tilemap.images[kong]);
					for(int i = 0; i< 4; i++){
						drawImage(0, i*32, &tilemap.images[background]);
					}
	
					for(int i = 0; i < (map.lives - 1); i++){
						drawImage(0, i*32, &tilemap.images[heart]);
					}
					lives(background);
					continue;
				}
				if((i_s == map.endi) & (j_s == map.endj)){
					if(map.currentLevel == 4){
						drawEnd();
						map.score += (map.lives * 5);
					}
					map.currentLevel = map.currentLevel + 1;
					initLevel(map.currentLevel);
					(*functions[map.currentLevel])();
					initLevel(map.currentLevel);
					drawObjects(map.currentLevel);
					i_s = map.starti;
					j_s = map.startj;
					background = back[map.currentLevel];
					drawImage(j_s, i_s, &tilemap.images[kong]);
					continue;
				}
				}
				
			}
			if(result == A){
				printf("A pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == X){
				printf("X pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == L){
				printf("L pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
			if(result == R){
				printf("R pressed.\n");
				printf("\nPress a button to display output. Press START to terminate. \n");
			}
		}
		sleep_microseconds(200);
	}

	sleep_microseconds(200);

	// Terminate program.
    printf("\nProgram is terminating\n");

    return 0;
}
