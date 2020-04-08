#ifndef _GAMELIB_H_
#define _GAMELIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 81
#define STRIKES 3

void StartGame(char []);
void CheckPhrase(char *);
int GuessALetter(char [], char [] ,char []);
void DashIt(char *, char []);

#endif


