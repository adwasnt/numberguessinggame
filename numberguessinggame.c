//Number Guessing Game by Joseph Graves in C on XCode updated on 4/20/23
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome(void);
//Description: Displays intstructions to the user
//Preconditions: none
//Postconditions: prints information to the screen

int getDifficulty(void);
//Description: Gets the difficulty of the game
//Preconditions: none
//Postconditions: Returns a numeric value to determine difficulty

int generateRandomNumber(int);
//Description: Generates a random number for the user to guess
//Preconditions: mode must have an initalized mode other than 0
//Postconditions: Returns a random number for the user to guess

int userGuess (int, int);
//Description: Gets the guess of the user and determines the game state
//Preconditons: Mode and random number must be initialized
//Postconditions: Returns the user's guess to see if the user guessed the correct number

int main(void)
{
    int num, guess = 0, mode, tries = 3;
    
    welcome(); //calls welcome / info screen
    mode = getDifficulty(); //gets the difficulty for the guessing game
    num = generateRandomNumber(mode); //generates a random number based on the game's difficulty
    while(guess != num && tries > 0) //will continue to loop if the player did not guess the correct number.
    {
        guess = userGuess(num, mode); //gets the guess from the user to determine game state
        tries--;
    }
    printf("The number was %d\n", num); //Display number at the end of the game
    return 0;
}

void welcome(void)
{
    printf("%s\n%s\n%s\n",
           "Number Guessing Game",
           "You have 3 tries to correctly guess a number",
           "Press ENTER to continue");
    getchar();
}

int getDifficulty(void)
{
    int mode = 0, userInput;
    
    do {
        printf("Pick from 3 dificulties\n|\nType 1 for Easy\n|\nType 2 for Medium\n|\nType 3 for Hard\n");
        userInput = scanf("%d", &mode);
        if(userInput != 1) //checks to see if scanf has correct input
        {
            fflush(stdin); //if not, flush the input a reloop
        }
    }while(mode < 1 || mode > 3);
    
    return mode;
}

int generateRandomNumber(int mode)
{
    int num, guessMax = 0;
    
    switch(mode) //switch case determines a max generating number based on difficulty
    {
        case 1:
            guessMax = 5; //easy
            break;
        case 2:
            guessMax = 10; //normal
            break;
        case 3:
            guessMax = 30; //hard
            break;
    }
    
    srand(time(NULL));
    
    num = rand() % guessMax + 1; //generates random number from range 1 to what the max number is set to
    
    return num;
}

int userGuess(int num, int mode)
{
    int guess, guessMax = 0, userInput;
    
    switch(mode)
    {
        case 1:
            guessMax = 5;
            break;
        case 2:
            guessMax = 10;
            break;
        case 3:
            guessMax = 30;
            break;
    }
    
    do {
    printf("Guess a number from 1 to %d: ", guessMax);
        userInput = scanf("%d", &guess);
        if(userInput != 1) //checks to see if scanf has correct input
        {
            fflush(stdin); //if not, flush the input a reloop
        }
    }while(guess < 0 || guess > guessMax || userInput != 1); //will reloop if the user inputted a number below or above range or the input is                                                           incorrect.
    
    if(guess == num)
    {
        printf("That's correct :D\n\n");
    }
    else
    {
        printf("That's not correct :(\n\n");
    }
    
    return guess;
}

