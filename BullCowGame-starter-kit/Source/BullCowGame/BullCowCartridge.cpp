// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
  
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
    //if game over, clearscreen, prompt restart, initgame
    
    if(Input == HiddenWord)
    {
        //bool gameover = true
        PrintLine(TEXT("Good job, you win!"));
        EndGame();
    }
    else
    {      
        if(Input.Len()==HiddenWord.Len())
        {
            PrintLine(TEXT("Right number of letters, wrong word!"));//say the number of letters is right but word wrong
        }
        else
        {
            PrintLine(TEXT("Wrong number of letters!, Word is %i letters long."), HiddenWord.Len());//say number of letter is wrong
        }
        --Lives;
        PrintLine(TEXT("You have %i Lives left!"), Lives);
        if(Lives == 0)
        {
            //bool gameover = true
            PrintLine(TEXT("You lose!"));
            EndGame();
        }
    }
}
void UBullCowCartridge::InitGame()
{
    ClearScreen();
    HiddenWord = TEXT("stick");
    Lives = 5;
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Please guess the word."));
    //anything else
}
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Would you like to play again?"));
}