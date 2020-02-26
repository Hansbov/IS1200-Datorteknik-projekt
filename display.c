#include <pic32mx.h>
#include <stdint.h>
#include "mipslab.h"

void curser (int sw, int bt){
hor_prev = hor;
vert_prev = vert;

if ( sw != 8 )
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
else if(sw == 8)
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

        display_string(0, "Player 2");
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
                if(i == 1 || i == 5)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 28;
                if(i == 2 || i == 3 || i == 4)
                    icon[hor*6 + (vert-1)*32 + i] = icon[hor*6 + (vert-1)*32 + i] + 20;

        }
        break;
    }

}

        playboard[vert][hor] = 20;

        display_string(0, "Player 1");

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
