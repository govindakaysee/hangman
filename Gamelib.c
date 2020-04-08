#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include "Gamelib.h"


void StartGame(char ChosenPhrase[MAX_INPUT])
{
	#include "PhraseBank.txt"

	char DashPhrase[MAX_INPUT] = {};
	int i=0;int j =0;
	int choice = 0;
	printf("Welcome to 3 STRIKES - YOU'RE OUT- the CSE version");
	printf(" Please pick a phrase from the following menu");
	while (PhraseBank[i]!= "")
	{
		CheckPhrase(PhraseBank[i]);
		DashIt(PhraseBank[i],DashPhrase);
		printf("%d. %s\n",i+1,DashPhrase);
		i++;
	
	}

	printf(" Enter choice : ");
	scanf("%d",&choice);
	while(choice <=0 || choice > i)
	{
		printf("the number is out of range. Please re-enter");
		scanf("%d", &choice);
	}
	
	strcpy(ChosenPhrase, PhraseBank[choice-1]);

}

void CheckPhrase( char *Phrase)
{
	int i =0;
	char ch = '-';
	  char *FirstOccur= strchr(Phrase,ch);
	if (FirstOccur != NULL)
	{
		while(*(Phrase+i) != ch)
		{
			i++;

		}
		printf("%s contains a dash in position %d",Phrase, i+1);
		exit(0);

	}

}

int GuessALetter(char Phrase[MAX_INPUT], char DashPhrase[MAX_INPUT] ,char UpperPhrase[MAX_INPUT])
{
	char Guess;
	char *FindGuess;
	char UpperCaseCopy [MAX_INPUT];
	int FoundALetter = 0;
	char UPGuess;
	//int STRIKES = 0;

	strcpy( UpperCaseCopy, UpperPhrase);
	printf(DashPhrase);
	printf("\nGuess a letter :" );
	scanf(" %c", &Guess);
	UPGuess = toupper(Guess);

	FindGuess = strchr(UpperCaseCopy,UPGuess);
	while (FindGuess != NULL)
	{
	 	FoundALetter = 1;
	 	DashPhrase[FindGuess- UpperCaseCopy] = Phrase[FindGuess- UpperCaseCopy];
	 	*FindGuess = '-';
	 	FindGuess= strchr(UpperCaseCopy,UPGuess);


	}
	

	 	
	return FoundALetter;


}
void DashIt(char *Phrase, char DashPhrase[MAX_INPUT])
{

char *FirstOccur = NULL;
int i=0;
int j = 0;

for ( i = 0; i<(strlen(Phrase)); i++)
	{
		DashPhrase[i] = toupper(Phrase[i]);
		
	}

DashPhrase[strlen(Phrase)] = '\0';
FirstOccur = strpbrk(DashPhrase,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
while(FirstOccur!= NULL)
	{
		*FirstOccur ='-';
		FirstOccur = strpbrk(DashPhrase,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	}


}
