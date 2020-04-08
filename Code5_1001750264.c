#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gamelib.h"


int main()
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int NumStk;
	
	StartGame(Phrase);
	DashIt(Phrase,DashedPhrase);
	int Guess = 0;int i;
	int strikes = 0;
	
	for ( i = 0; i<strlen(Phrase);i++)
	{
		UpperPhrase[i] = toupper(*(Phrase+i));
	}
	
do
{
	Guess = GuessALetter(Phrase,DashedPhrase ,UpperPhrase);
	
	if (Guess==0)
	{
		int x = strikes++;
		printf("Strike %d",x);

	}
}
while ( !(strchr(DashedPhrase,'-')== NULL) && strikes<STRIKES);
if ( strikes<STRIKES)
{
	printf( "You figured it out!!\n");
	printf("The phrase was \n %s",Phrase);
	printf("\nYOU WIN!!!" );
}
else 
{
	printf( "\n3 STRIKES - YOU'RE OUT!!");
	printf("\nGame over");

}

return 0;
}









// do 
	// {

	//  	if (UPGuess!= Phrase);
	//  {
	//  	printf("Strike %d", STRIKES++ );


	// }
	// while(STRIKES>3);

	// if (STRIKES = 3)
	// {
	// 	printf( "Strike %d", STRIKES);
	// 	printf(" 3 STRIKES- YOU'RE OUT!!\n Game Over");
	// }



