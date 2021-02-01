#include <stdlib.h>
#include <iostream>
#include "board.h"
#include "world.h"

// A utility function to count inversions in given array 'arr[]' 
int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			// Value 0 is used for empty space 
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
	return inv_count;
}

// This function returns true if given 8 puzzle is solvable. 
bool isSolvable(int puzzle[3][3])
{
	// Count inversions in given 8 puzzle 
	int invCount = getInvCount((int *)puzzle);

	// return true if inversion count is even. 
	return (invCount % 2 == 0);
}



int main()
{
	//int puzzle[3][3] = { {8, 6, 7},
	//					{2, 5, 4},  // Value 0 is used for empty space 
	//					{3, 0, 1} };
	//isSolvable(puzzle) ? cout << "Solvable" :
	//	cout << "Not Solvable";

	const char *boardStart;
	
	//boardStart = "8762543_1"; //not solvable
	//boardStart = "013425786"; //solvable
	boardStart = "032871456"; //solvable
	//boardStart = "457812360"; //solvable
	//boardStart = "8672543_1"; //solvable
	

		World world(Board(boardStart).getHash());
		if (!world.solved)
			world.start();


	system("pause");
}