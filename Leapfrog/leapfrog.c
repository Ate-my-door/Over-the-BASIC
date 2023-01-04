// Leapfrog
// Original BASIC version by Beam Software

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void playGame();
void displayBoard(const char []);
void getMove(const char b[], int*, int*);
bool playAgain();

int main()
{
	bool gameIsRunning = true;

	while (gameIsRunning)
	{
		playGame();

		if (!playAgain())
		{
			gameIsRunning = false;
		}
	}

	return 0;
}

void playGame()
{
	char board[] = " XXXX OOOO";
	int from, to;
	int count = 0;

	while (strcmp(board, " OOOO XXXX"))
	{
		displayBoard(board);
		getMove(board, &from, &to);
		board[to] = board[from];
		board[from] = ' ';
		++count;
		putchar('\n');
	}

	displayBoard(board);
	printf("%s %d %s\n", "You did it in", count, "moves.");
}

void displayBoard(const char b[])
{
	for (int i = 1; b[i] != '\0'; i++)
	{
		putchar(b[i]);
		printf("  ");
	}

	putchar('\n');
	printf("1  2  3  4  5  6  7  8  9\n");
}

void getMove(const char b[], int* f, int *t)
{
	int fTmp, tTmp;
	char fromTo[3], ch;

	while (true)
	{
		printf("%s", "Please enter your move: ");
		scanf("%2s", fromTo);

		while ((ch = getchar()) != '\n')
		{
			continue;
		}

		if (!isdigit(fromTo[0]) || !isdigit(fromTo[1]))
		{
			continue;
		}

		*f = fTmp = fromTo[0] - '0';
		*t = tTmp = fromTo[1] - '0';

		if ((fTmp >= 1) && (fTmp <= 9) && (tTmp >= 1) && (tTmp <= 9))
		{
			if ((b[fTmp] != b[tTmp]) && (b[fTmp] != ' ') && (b[tTmp] == ' '))
			{
				if (abs(tTmp - fTmp) <= 2)
				{
					break;
				}
			}
		}
	}
}

bool playAgain()
{
	printf("Another go? (yes/no) ");

	char r, ch;

	r = getchar();

	while ((ch = getchar()) != '\n')
	{
		continue;
	}

	return (tolower(r) == 'y');
}
