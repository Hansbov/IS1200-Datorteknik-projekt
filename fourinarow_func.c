#include <pic32mx.h>
#include <stdint.h>
#include "mipslab.h"

void curser (int sw, int bt){
hor_prev = hor;
vert_prev = vert;


if(sw >= 8)
{
    if (bt == 2)
        {
        vert_prev = vert;
        vert++;
        }
    else if (bt == 4)
        {
        vert_prev = vert;
        vert--;
        }
}
else
{
    if (bt == 2)
    {
       hor_prev = hor;
        hor++;
    }
    else if (bt== 4)
    {
       hor_prev = hor;
        hor--;
    }
}

if (vert>4)
    vert=0;

if (vert<0)
    vert=4;

if (hor>4)
    hor=0;

if (hor<0)
    hor=4;



switch(vert)
{case 0:
    {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 62;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 34;

        }
        break;
    }
case 1:
    {
        int i = 1;
        for(i; i<6; i++){
            icon[hor*6 + i] = icon[hor*6 + i] + 128;
        }
        i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 15;
            if(i == 2 || i == 3 || i == 4)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 8;

        }
        break;
    }
case 2:
    {
        int i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                 icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 224;
            if(i == 2 || i == 3 || i == 4)
                 icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 32;
        }
        i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 3;
            if(i == 2 || i == 3 || i == 4)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 2;

        }
        break;
    }
case 3:
 {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 248;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 136;

        }
        break;
    }
case 4:
 {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 62;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 34;

        }
        break;
    }

}
/////////////////////////////////////////////////////////////////////////////////////
switch(vert_prev)
{case 0:
    {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 62;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 34;

        }
        break;
    }
case 1:
    {
        int i = 1;
        for(i; i<6; i++){
            icon[hor_prev*6 + i] = icon[hor_prev*6 + i] - 128;
        }
        i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 15;
            if(i == 2 || i == 3 || i == 4)
                icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 8;

        }
        break;
    }
case 2:
    {
        int i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                 icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 224;
            if(i == 2 || i == 3 || i == 4)
                 icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 32;
        }
        i = 1;
        for(i; i<6; i++){
            if(i == 1 || i == 5)
                icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 3;
            if(i == 2 || i == 3 || i == 4)
                icon[hor_prev*6 + vert_prev*32 + i] = icon[hor_prev*6 + vert_prev*32 + i] - 2;

        }

        break;
    }
case 3:
 {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 248;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 136;

        }
        break;
    }
case 4:
 {
        int i = 1;
        for(i; i<6; i++){
                if(i == 1 || i == 5)
                    icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 62;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor_prev*6 + (vert_prev-1)*32 + i] = icon[hor_prev*6 + (vert_prev-1)*32 + i] - 34;

        }
        break;
    }

}

}


void ichooseyou (void){
if (playboard[vert][hor] == 0){

    if(player == 1){
        switch(vert) //kryss
        {case 0:
            {
                int i = 2;
                for(i; i<5; i++){
                        if(i == 2 || i == 4)
                            icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 20;
                        if(i == 3)
                            icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 8;

                }
                break;
            }
        case 1:
            {
                int i = 2;
                for(i; i<5; i++){
                    if(i == 2 || i == 4)
                        icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 5;
                    if(i == 3)
                        icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 2;

                }
                break;
            }
        case 2:
            {
                int i = 2;
                for(i; i<5; i++){
                    if(i == 2 || i == 4)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 64;
                    if(i == 3)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 128;
                }
                i = 1;
                for(i; i<5; i++){
                    if(i == 2 || i == 4)
                        icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 1;

                }
                break;
            }
        case 3:
        {
            int i = 2;
            for(i; i<5; i++){
                    if(i == 2 || i == 4)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 80;
                    if(i == 3)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 32;

        }
        break;
    }
        case 4:
        {
            int i = 2;
            for(i; i<5; i++){
                    if(i == 2 || i == 4)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 20;
                    if(i == 3)
                        icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 8;

        }
        break;
    }

}


        playboard[vert][hor] = 1;

        display_string(0, "Player 2:");
        display_string(1, "you are o");
        display_update();
}



    if(player == 2){
switch(vert)
{case 0:
    {
        int i = 2;
        for(i; i<5; i++){
                if(i == 2 || i == 4)
                    icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 28;
                if(i == 3)
                    icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 20;

        }
        break;
    }
case 1:
    {
        int i = 2;
        for(i; i<5; i++){
            if(i == 2 || i == 4)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 7;
            if(i == 3)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 5;

        }
        break;
    }
case 2:
    {
        int i = 2;
        for(i; i<5; i++){
            if(i == 2 || i == 4)
                 icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 224192;
            if(i == 3)
                 icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 64;
        }
        i = 2;
        for(i; i<5; i++){
            if(i == 2 || i == 4)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 1;
            if(i == 3)
                icon[hor*6 + vert*32 + i] = icon[hor*6 + vert*32 + i] + 1;

        }
        break;
    }
case 3:
 {
        int i = 2;
        for(i; i<5; i++){
                if(i == 2 || i == 4)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 112;
                if(i == 3)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 80;

        }
        break;
    }
case 4:
 {
        int i = 2;
        for(i; i<5; i++){
                if(i == 2 || i == 4)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 28;
                if(i == 3)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 20;

        }
        break;
    }

}

        playboard[vert][hor] = 20;

        display_string(0, "Player 1:");
        display_string(1, "you are x");
        display_update();

}

switch (player)
{
    case 1:
        player++;
        break;

    case 2:
        player--;
        break;
}
}}


int checkBoard (void){
int i = 0;
int winner = 0;
//kolla horisontella
for(i; i<5; i++){ //vilken rad
    int j= 0;
     for(j; j<5; j++){ //vart i rad
        if (playboard[i][j] == playboard[i][j+1]){ //om två siffror lika
                winner = winner + playboard[i][j]; //sätt vinnare

                if(playboard[i][j+2]!= playboard[i][j+1]) // ta med sista vinnare
                    winner = winner + playboard[i][j+1];

                if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;

        }
     }
     winner = 0;
}
winner =0;
//kolla vertikala
i = 0;
for(i; i<5; i++){ //vilken rad
    int j= 0;
     for(j; j<5; j++){ //vart i rad
        if (playboard[j][i] == playboard[j+1][i]){ //om två siffror lika
                winner = winner + playboard[j][i]; //sätt vinnare

                if(playboard[j+2][i]!= playboard[j+1][i]) // ta med sista vinnare
                    winner = winner + playboard[j+1][i];

                if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;
        }
     }
     winner = 0;
}

/*
//kolla diagonala åt höger ner
i = 0;
winner = diagonalR(0,0);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner= 0;

winner = diagonalR(0,1);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner=0;

winner = diagonalR(1,0);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner= 0;
//kolla diagonala åt vänster ner

winner = diagonalL(0,3);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner=0;

winner = diagonalL(0,4);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner=0;

winner = diagonalL(1,4);
if((winner == 4) || (winner == 80)) //om vinnare klar, bra
    return winner;
winner =0;*/

winner = 0;

if (playboard[0][0] == playboard[1][1] &&
    playboard[1][1] == playboard[2][2] &&
    playboard[2][2] == playboard[3][3] )
{
    winner = playboard[0][0]*4;
    return winner;
}

if (playboard[1][1] == playboard[2][2] &&
    playboard[2][2] == playboard[3][3] &&
    playboard[3][3] == playboard[4][4] )
    {
    winner = playboard[1][1]*4;
    return winner;
}

if (playboard[0][1] == playboard[1][2] &&
    playboard[1][2] == playboard[2][3] &&
    playboard[2][3] == playboard[3][4] )
    {
    winner = playboard[0][1]*4;
    return winner;
}

if (playboard[1][0] == playboard[2][1] &&
    playboard[2][1] == playboard[3][2] &&
    playboard[3][2] == playboard[4][3] )
    {
    winner = playboard[1][0]*4;
    return winner;
}

if (playboard[0][4] == playboard[1][3] &&
    playboard[1][3] == playboard[2][2] &&
    playboard[2][2] == playboard[3][1] )
    {
    winner = playboard[0][4]*4;
    return winner;
}

if (playboard[1][3] == playboard[2][2] &&
    playboard[2][2] == playboard[3][1] &&
    playboard[3][1] == playboard[4][0] )
    {
    winner = playboard[1][3]*4;
    return winner;
}

if (playboard[0][3] == playboard[1][2] &&
    playboard[1][2] == playboard[2][1] &&
    playboard[2][1] == playboard[3][0] )
    {
    winner = playboard[0][3]*4;
    return winner;
}

if (playboard[1][4] == playboard[2][3] &&
    playboard[2][3] == playboard[3][2] &&
    playboard[3][2] == playboard[4][1] )
    {
    winner = playboard[1][4]*4;
    return winner;
}
return winner;
}


int diagonalR(int i, int j){
int winner = 0;
for(i; i<5; i++){ //vilken rad

      //vart i rad
        if (playboard[i][j] == playboard[i+1][j+1]){ //om två siffror lika
                winner = winner + playboard[i][j]; //sätt vinnare

                if(playboard[i+2][j+2]!= playboard[i+1][j+1]) // ta med sista vinnare
                    winner = winner + playboard[i+1][j+1];

                if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;
        }
     j++;
     if (j > 4)
        break;
}
return winner;
}

int diagonalL(int i, int j){
int winner = 0;

for(i; i<5; i++){ //vilken rad
     //vart i rad
        if (playboard[i][j] == playboard[i+1][j-1]){ //om två siffror lika
                winner = winner + playboard[i][j]; //sätt vinnare


                if(playboard[i+2][j-2]!= playboard[i+1][j-1]) // ta med sista vinnare
                    winner = winner + playboard[i+1][j-1];

                if((winner == 4) || (winner == 80)) //om vinnare klar, bra
                    return winner;
        }

    j--;
    if (j < 0)
        break;
}
return winner;
}


void emptyBoard(int b[5][5]){
int i = 0;
howmany = 0;
for(i; i<5; i++){
    int j= 0;
     for(j; j<5; j++){
        b [i][j] = 0;
     }

}
}

void game (void){
display_image(96, icon);
delay(1000);
while(1)
    {
if(getbtns() == 1)
{
    ichooseyou();
    howmany++;
}


if (getbtns() != 0)
    curser(getsw(),getbtns());

display_image(96, icon);
delay(500);
if (checkBoard()== 4){
    display_image2(0,black);
    display_string(0,"The winner:");
    display_string(1,"player 1!");
    display_update();
    display_image(96, trophy);
    break;
}

if (checkBoard()== 80){
    display_image2(0,black);
    display_string(0,"The winner:");
    display_string(1,"player 2!");
    display_update();
    display_image(96, trophy);
    break;
}

if (get4btns() == 1)
    break;

if (howmany == 25){
    display_string(0,"it's a draw!");
    display_string(1, "");
    display_update();
    delay(500);
    break;

}

/* //oavgjort som inte fungerar
int i = 0;
int j = 0;
int bla = 0;
for(i; i<5; i++){
    for(j; j<5; j++){
        if(playboard[j][i] == 0){
        bla++;
        }
    }
}

if (bla == 0 ){
    display_string(0,"it's a draw!");
    display_string(1, "");
    display_update();
    delay(500);
    break;
}
*/

}

}

void newGame(void){

emptyBoard(playboard);
int i = 0;
for(i; i<128; i++){
    icon[i] = icon_original[i];
}
vert = 0;
hor = 0;

display_image2(0, black);
display_string(0, "Player 1:");
display_string(1, "you are x");
display_update();

player = 1;
game();
delay(2000);

//lägg till hoppa tillbaka till meny
}


void resumeGame (void){

if (player == 1){
display_image2(0, black);
display_string(0, "Player 1:");
display_string(1, "you are x");
display_update();

game();
delay(2000);
}
else if (player == 2){
display_image2(0, black);
display_string(0, "Player 2:");
display_string(1, "you are o");
display_update();

game();
delay(2000);
}


}

void tutorial (void){
display_image2(0, black);
display_string(1, "btn3: right/down");
display_string(0, "btn4: left/up");
display_string(2, "btn2: select");
display_string(3, "sw4:  direction");
display_update();

while(1){

if (get4btns() == 1)
    break;
}
display_string(0, "");
display_string(1, "");
display_string(2, "");
display_string(3, "");
display_update();
}

