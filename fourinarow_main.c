#include <stdint.h>
#include <pic32mx.h>
#include <stdio.h>
#include "mipslab.h"


#define COLUMNS 5
int thisMany = 0;

int hor = 0;
int vert = 0;
int hor_prev = 0;
int vert_prev = 0;
int playboard[5][5];
int player = 1;



int checkBoard (int b [5][5]){
int i = 0;
int winner = 0;
//kolla horisontella
for(i; i<5; i++){ //vilken rad
    int j= 0;
     for(j; j<5; j++){ //vart i rad
        if (b[i][j] == b[i][j+1]){ //om två siffror lika
                winner = winner + b[i][j]; //sätt vinnare
                 if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;

                if(b[i][j+2]!= b[i][j+1]) // ta med sista vinnare
                    winner = winner + b[i][j+1];
        }
     }
}
winner = 0;
//kolla vertikala
i = 0;
for(i; i<5; i++){ //vilken rad
    int j= 0;
     for(j; j<5; j++){ //vart i rad
        if (b[j][i] == b[j+1][i]){ //om två siffror lika
                winner = winner + b[j][i]; //sätt vinnare
                 if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;

                if(b[j+2][i]!= b[j+1][i]) // ta med sista vinnare
                    winner = winner + b[j+1][i];
        }
     }
}
//kolla diagonala åt höger ner
i = 0;
winner = 0;
for(i; i<5; i++){ //vilken rad
    int j= 0;
     for(j; j<5; j++){ //vart i rad
        if (b[i][j] == b[i+1][j+1]){ //om två siffror lika
                winner = winner + b[i][j]; //sätt vinnare
                 if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;

                if(b[i+2][j+2]!= b[i+1][j+1]) // ta med sista vinnare
                    winner = winner + b[i+1][j+1];
        }
     }
}

//kolla diagonala åt vänster ner
i = 0;
winner = 0;
for(i; i<5; i++){ //vilken rad
    int j= 4;
     for(j; j>=0; j--){ //vart i rad
        if (b[i][j] == b[i+1][j-1]){ //om två siffror lika
                winner = winner + b[i][j]; //sätt vinnare
                 if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;

                if(b[i+2][j-2]!= b[i+1][j-1]) // ta med sista vinnare
                    winner = winner + b[i+1][j-1];
        }
     }
}

return winner;
}

void emptyBoard(int b[5][5]){
int i = 0;
for(i; i<5; i++){
    int j= 0;
     for(j; j<5; j++){
        b [i][j] = 0;
     }

}
}

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
	/*display_string(0, "KTH/ICT lab");
	display_string(1, "in Computer");
	display_string(2, "Engineering");
	display_string(3, "Welcome!");
	display_update();*/


	display_image2(0, black);
    display_image(50, icon);

	//labinit(); /* Do any lab-specific initialization */

	/*while( 1 )
	{
	  labwork(); /* Do lab-specific things again and again */
	//}



emptyBoard(playboard);

while(1)
    {
if(getbtns() == 1)
    ichooseyou();

if (getbtns() != 0)
    curser(getsw(),getbtns());

display_image(50, icon);
delay(500);
if(checkBoard(playboard) == 4 || checkBoard(playboard) == 80 )
    break;
}
/*playboard [0][4] = 20;

playboard [1][4] = 20;

playboard [2][3] = 20;

playboard [3][2] = 20;

playboard [4][1] = 20;

printBoard(playboard);
printf("%d", checkBoard(playboard));

if (checkBoard(playboard) == 4){
    printf("The winner is Player 1!");
}
else if (checkBoard(playboard) == 80){
     printf("The winner is Player 2!");
*/
return 0;
}
