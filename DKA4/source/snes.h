// BIT MASKS TO USE IN ORDER TOP FIGURE OUT WHICH BUTTONS HAVE BEEN PRESSED
#define B 0x000007FF
#define Y 0X00000BFF
#define SELECT 0x00000DFF
#define START 0x00000EFF
#define UP 0x00000F7F
#define DOWN 0x00000FBF
#define LEFT 0x00000FDF
#define RIGHT 0x00000FEF
#define A 0x000000FF7
#define X 0x00000FFB
#define L 0x00000FFD
#define R 0x00000FFE
#define CLK_REG 0xFE003004
#define MASK 0x00000FFF


// FUNCTION DECLARATIONS FOR THOSE IN snes.c

void init_gpio(int pin, int func);
void write_gpio(int pin_number, int val);
int read_gpio(int pin_number);
unsigned read_snes();
void init_snes_lines();
void sleep_microseconds(int ms);
void printmessage(unsigned int result);
