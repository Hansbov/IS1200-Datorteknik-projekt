
#define COLUMNS 5
int thisMany = 0;





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


int main(){

int playboard[5][5];
emptyBoard(playboard);

playboard [0][3] = 20;

playboard [1][3] = 20;

playboard [2][3] = 20;

playboard [3][3] = 20;

playboard [4][3] = 20;

printBoard(playboard);
printf("%d", checkBoard(playboard));

}
