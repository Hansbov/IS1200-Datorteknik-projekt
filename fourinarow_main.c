#include <stdint.h>
#include <pic32mx.h>
#include <stdio.h>
#include "mipslab.h"


int hor = 0;
int vert = 0;
int hor_prev = 0;
int vert_prev = 0;
int playboard[5][5];
int player = 1;
int menu = 0;
int howmany = 0;




/*
void printBoard (int b[5][5]){
int i = 0;
for(i; i<5; i++){
    int j= 0;
     for(j; j<5; j++){
        printf("%10d ", b[i][j]);         // prints the number with 10 spaces before

        thisMany ++;                // adds to counter of how many of the columns that have been printed

        if (thisMany == COLUMNS){   // if thisMany is equal to the number of columns
            printf("\n");           // changes row
            thisMany = 0;           // sets thisMany to zero
            }
        }
    }
}
*/

int main(void){
            /*
	  This will set the peripheral bus clock to the same frequency
	  as the sysclock. That means 80 MHz, when the microcontroller
	  is running at 80 MHz. Changed 2017, as recommended by Axel.
	*/
	SYSKEY = 0xAA996655;  /* Unlock OSCCON, step 1 */
	SYSKEY = 0x556699AA;  /* Unlock OSCCON, step 2 */
	while(OSCCON & (1 << 21)); /* Wait until PBDIV ready */
	OSCCONCLR = 0x180000; /* clear PBDIV bit <0,1> */
	while(OSCCON & (1 << 21));  /* Wait until PBDIV ready */
	SYSKEY = 0x0;  /* Lock OSCCON */

	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;

	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;

	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);

	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
    SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;

	display_init();
    display_string(0, "new game <-");
    display_string(1, "resume");
    display_string(2, "tutorial");
    display_update();

    while(1){
    delay(500);
    if (getbtns() == 2)
        menu++;

    if(getbtns() == 4)
        menu--;

    if(menu>2)
        menu = 2;

    if(menu<0)
        menu = 0;

    switch(menu){
    case 0:
        display_string(0, "new game <-");
        display_string(1, "resume");
        display_string(2, "tutorial");
        display_update();
        break;

    case 1:
    display_string(0, "new game");
    display_string(1, "resume   <-");
    display_string(2, "tutorial");
    display_update();
    break;

    case 2:
    display_string(0, "new game");
    display_string(1, "resume ");
    display_string(2, "tutorial <-");
    display_update();
    break;
    }

    if (getbtns() == 1)
    {
        switch (menu)
        {
        case 0:
            display_string(0, "");
            display_string(1, "");
            display_string(2, "");
            display_string(3, "");
            display_update();
            newGame();
            break;

        case 1:
            display_string(0, "");
            display_string(1, "");
            display_string(2, "");
            display_string(3, "");
            display_update();
            resumeGame();
            break;

        case 2:
            display_string(0, "");
            display_string(1, "");
            display_string(2, "");
            display_string(3, "");
            display_update();
            tutorial();
            break;
        }
    }

    }



return 0;
}
