// Number Reversal
// Original BASIC version by Beam Software

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

void playGame();
bool playAgain();
void shuffle(int[], const unsigned);
void reverse(int arr[], const unsigned);
void printNumbers(const int[], const unsigned);
int getNumber(const unsigned);
bool checkIfSolved(const int [], const unsigned);

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
	const unsigned arrSize = 10;
	int a[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		a[i] = i;
	}

	srand((unsigned)time(0));
	shuffle(a, arrSize);
	printNumbers(a, arrSize);

	int count = 0;
	bool solved = false;

	while (!solved)
	{
		unsigned howMany = getNumber(arrSize);

		if (!howMany)
		{
			break;
		}

		printf("%s %d %s\n", "Reversing", howMany, "numbers.");
		++count;
		reverse(a, howMany);
		printNumbers(a, arrSize);

		solved = checkIfSolved(a, arrSize);

		if (solved)
		{
			printf("%s %d %s\n", "You did it in", count, "moves.");
		}
	}
}

bool playAgain()
{
	printf("Do you want to play again? (yes/no)\n");
	char ch = getchar();

	if (tolower(ch) == 'y')
	{
		while ((ch = getchar()) != '\n')
		{
			continue;
		}

		return true;
	}

	return false;
}

void shuffle(int arr[], const unsigned sz)
{
	for (unsigned i = (sz - 1); i >= 2; i--)
	{
		int swap = 1 + rand() % (sz - 1);
		int temp = arr[i];
		arr[i] = arr[swap];
		arr[swap] = temp;
	}
}

void reverse(int arr[], const unsigned n)
{
	for (int i = 1; i <= n / 2; i++)
	{
		int temporary = arr[i];
		int mirror = n - i + 1;
		arr[i] = arr[mirror];
		arr[mirror] = temporary;
	}
}

void printNumbers(const int arr[], const unsigned sz)
{
	for (unsigned i = 1; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int getNumber(const unsigned arrSz)
{
	int num;
	char ch;

	while (true)
	{
		printf("How many numbers do you wish to reverse? ");
		scanf("%d", &num);

		while ((ch = getchar()) != '\n' )
		{
			continue;
		}

		if ((num >= 0) && (num < arrSz))
		{
			break;
		}
		else
		{
			printf("%d is the maximum that can be swapped.\n", arrSz - 1);
		}
	}

	return num;
}

bool checkIfSolved(const int arr[], const unsigned arrSz)
{
	for (int i = 1; i < arrSz; i++)
	{
		if (arr[i] != i)
		{
			return false;
		}
	}

	return true;
}
