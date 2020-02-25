/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2020-02-12 by Nova Andersson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;
int i = 0; //variabel f�r tick r�knaren
int timeoutcount = 0;
int prime = 1234567;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
    if( IFS(0) & (1 << 8)) {
        timeoutcount ++;
        IFSCLR(0) = ( 1 << 8); // clear counter
        if (timeoutcount == 10){
            time2string(textstring, mytime);
            display_string(3, textstring);
            display_update();
            tick(&mytime);
            timeoutcount = 0;
        }
    }

   /* if (INTCON & (1 << 2)) {
        PORTE++;
        INT & 0xff7f;
    }*/
}
/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int * trise = (volatile int *) 0xbf886100;
  *trise = *trise & 0xff00;
  TRISD &= 0xffe0;
  TMR2 = 0;
  T2CON = 0x70; //256bit period
  PR2 = (80000000/256/10); //perioden
  IFS(0) = 0x0000; //nolst�ller flaggan
  IECSET(0) = (1 << 8); //enable interrupts
  IPCSET(2) = 4; //priority
  T2CONSET = (1 << 15); //starta klockan
  enable_interrupt();

  PORTE = 0;
  IPCSET(1) = 4;


}

/* This function is called repetitively from the main program */
void labwork( void ){
    prime = nextprime(prime);
    display_string(0, itoaconv(prime));
    display_update();
}
