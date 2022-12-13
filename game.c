#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//declaring the used functions
int compare(char s[] , char *words[]);
int validate(char s[] , char *words[]);

//definining some colors 
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

int main(void){

    char s[9];
    char *words[] = {"ROCK" , "PAPER" , "SCISSORS"};
    printf(GREEN"Welcome to the ROCK PAPER SCISSORS GAME"RESET);
    printf("\n");
    printf("In order to start the game you must choose one of the following options:\n ");
    printf("1) ROCK\n 2) PAPER\n 3) SCISSORS\n");
    printf("Please enter a number from 1 to 3 or manually type your option: ");
    scanf("%s" , s); 

    while(!validate(s , words)){

        printf("Choose again: \n");
        scanf("%s" ,s);
    }
    if(strlen(s) == 1)
        strcpy(s , words[atoi(s) - 1]); 

    // Making the computer pick a random string
    srand(time(NULL));
    char *random = words[rand() % 3];

    printf("The game picked %s\n" , random);

    // Printing the game's result
    if(!strcmp(random , s)){

        printf(YELLOW"Tie"RESET);
        printf("\n");
        return 0;
    }

    if(!strcmp(s , "ROCK") || !strcmp(s , "rock")){

        if(!strcmp(random , "SCISSORS")){

            printf(GREEN"Congratulations, you won!"RESET);
            printf("\n");
            return 0;
        }
        else{
            
            printf(RED"You lost, good luck next time!"RESET);
            printf("\n");
            return 0;
        }
    }

    if(!strcmp(s , "PAPER") || !strcmp(s , "paper")){

        if(!strcmp(random , "ROCK")){

            printf(GREEN"Congratulations, you won!"RESET);
            printf("\n");
            return 0;
        }
        else{
            
            printf(RED"You lost, good luck next time!"RESET);
            printf("\n");
            return 0;
        }
    }

    if(!strcmp(s , "SCISSORS") || !strcmp(s , "scissors")){

        if(!strcmp(random , "PAPER")){

            printf(GREEN"Congratulations, you won!"RESET);
            printf("\n");
            return 0;
        }
         else{
            
            printf(RED"You lost, good luck next time!"RESET);
            printf("\n");
            return 0;
        }
    }

}

// Checking if the introduced string matches a word from the game
int compare(char s[] , char *words[]){

    for(int i = 0  ; i < strlen(s) ; i++)
        if(islower(s[i]))
            s[i] -= 32;

    for(int i = 0 ; i < 3 ; i++){

        if(!strcmp(words[i] , s)){
            
            return 1;
            break;
        }
     }
    return 0;
}

// Checking if the string / value is valid
int validate(char s[] , char *words[]){

    if(strlen(s) == 1){

        if(atoi(s) == 1 || atoi(s) == 2 || atoi(s) == 3)
            return 1;
        }
    else if(compare(s , words))
        return 1;
    return 0;
}
