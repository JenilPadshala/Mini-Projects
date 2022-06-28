/*
	Author: Jenil Padshala| AP21110010064
	Project Title: The 4 Queens Problem
*/
/*
	Pre: The user enters number of queens
	Post: All the possible solutions of N-Queen Problem are displayed
	Uses: Functions - Qplace, Qconflict, and Qprint
*/
#include <stdio.h>
#include <math.h>

int board[20],	//Array to store respective column positions of Queen in ith(index) row.
	count;		//No. of Solutions

void Qplace(int row, int n);
int Qconflict(int row, int column);
void Qprint(int n);


int main()
{
	int n, i, j;

	printf(" - N Queens Problem Using Backtracking -");
	printf("\n\nEnter number of Queens:");
	scanf("%d", &n);
	Qplace(1, n);
	return 0;
}

// function to check for proper positioning of queen
void Qplace(int row, int n)
{
	int column;
	for (column = 1; column <= n; column++)
	{
		if (Qconflict(row, column))
		{
			board[row] = column; // no conflicts so place queen
			if (row == n)		 // dead end
				Qprint(n);		 // printing the board configuration
			else				 // try queen with next position
				Qplace(row + 1, n);
		}
	}
}

/*funtion to check conflict of position
return 1 ---> no conflict
return 0 ---> conflict of position*/
int Qconflict(int row, int column)
{
	int i;
	for (i = 1; i <= row - 1; i++)
	{
		// checking column and digonal conflicts
		if (board[i] == column)
			return 0;
		else if (abs(board[i] - column) == abs(i - row))
			return 0;
	}

	return 1; // no conflicts
}

// function to print the solutions
void Qprint(int n)
{
	int i, j;
	printf("\n\nSolution %d:\n\n", ++count);

	for (i = 1; i <= n; ++i)
	{
		printf("\n\n");
		for (j = 1; j <= n; ++j) // for nxn board
		{
			if (board[i] == j)
				printf("\tQ"); // queen at i,j position
			else
				printf("\t-"); // empty slot
		}
	}
}