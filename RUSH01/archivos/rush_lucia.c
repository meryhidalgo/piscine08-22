#include <unistd.h>
#include <stdio.h>

const int MAX_FLOOR = 4;

int ALL_POSSIBILITIES [][]= {{1,2,3,4},{1,3,2,4},{2,1,3,4},{2,3,1,4},{3,1,2,4},{3,2,1,4},
{1,2,4,3},{1,4,2,3},{2,1,4,3},{2,4,1,3},{4,1,2,3},{4,2,1,3},
{1,3,4,2},{1,4,3,2},{3,4,1,2},{3,1,4,2},{4,1,3,2},{4,3,1,2},
{4,3,2,1},{4,2,3,1},{3,4,2,1},{3,2,4,1},{2,4,3,1},{2,3,4,1},};

int main(int argc, char *argv[])
{
	int parameters[] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	check(parameters);
}

void check(int parameters[])
{
	int table [MAX_FLOOR][MAX_FLOOR][MAX_FLOOR];
	initTable(table);
	int tableSolved = 0;
	while(tableSolved == 0)
	{
		// Coll up
		int i = 0;
		while (i < 4)
		{
			int possibilities[][] = getPossibiltiesForParam(parameters[i]);
			int possibilitiesPerPosition[][]  = getAllPossibilitiesPerPosition(possibilities, table, 1, i, 0);
			table[i] = possibilitiesPerPosition;
			i++;
		}
		// Coll down
		int j = 4;
		while (j < 8)
		{
			int possibilities[][] = getPossibiltiesForParam(parameters[j]);
			int possibilitiesPerPosition[][]  = getAllPossibilitiesPerPosition(possibilities, table, 1, j - 4, 1);
			table[j - 4] = applyMaskToArray(table[j - 4], possibilitiesPerPosition);
			j++;
		}
		// Row left
		int k = 8;
		while (k < 12)
		{
			int possibilities[][] = getPossibiltiesForParam(parameters[k]);
			int possibilitiesPerPosition[][] = getAllPossibilitiesPerPosition(possibilities, table, 0, k - 8, 0);
			table = applyMaskTo3DArrayWithFixedColumn(table, possibilitiesPerPosition, k - 8);
			k++;
		}

		// Row right
		int l = 12;
		while (l < 16)
		{
			int possibilities[][] = getPossibiltiesForParam(parameters[l]);
			int possibilitiesPerPosition[][]  = getAllPossibilitiesPerPosition(possibilities, table, 0, l - 12, 1);
			table = applyMaskTo3DArrayWithFixedColumn(table, possibilitiesPerPosition, l - 12);
			l++;
		}

		tableSolved = isTableSolved(table);

		if (tableSolved == -1)
		{
			printf("It can't be solved");
		}
	}

	for (int y = 0; y < MAX_FLOOR; y++)
	{
		for (int x = 0; x < MAX_FLOOR; x++)
		{
			printNumber(table[y][x]);
		}
	printf("");
	}
}

void printNumber(int value[])
{
	int i = 0;
	while (i < MAX_FLOOR)
	{
		if (value[i] == 1)
			printf(i + 1);
		i++;
	}
}

int *reverseArray(int array[])
{
	int i = 0;
	int newArray[] = new int[MAX_FLOOR];
	while (i < array.length)
	{
		newArray[i] = array[array.length - i - 1];
		i++;
	}
	return newArray;
}


int isTableSolved(int table[][][])
{
	int i = 0;
	while (i < MAX_FLOOR)
	{
		int j = 0;
		while(j < MAX_FLOOR)
		{
			int k = 0;
			int count = 0;
			while (k < MAX_FLOOR)
			{
				if (table[i][j][k] == 1)
					count++;
				k++;
			}
			if (count == 0)
				return -1;
			if (count > 1)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int ***applyMaskTo3DArrayWithFixedColumn(int table[][][] , int mask[][], int column)
{
	int i = 0;
	while (i < MAX_FLOOR)
	{
		int j = 0;
		while(j < MAX_FLOOR)
		{
			table[i][column][j] = table[i][column][j] == 1 && mask[i][j] == 1 ? 1 : 0;
			j++;
		}
		i++;
	}
	return table;
}

int **applyMaskToArray(int origin[][], int mask[][])
{
	int[][] newArray = new int[MAX_FLOOR][MAX_FLOOR];
	int i = 0;
	while (i < MAX_FLOOR)
	{
		int j = 0;
		while(j < MAX_FLOOR)
		{
			newArray[i][j] = origin[i][j] == 1 && mask[i][j] == 1 ? 1 : 0;
			j++;
		}
	i++;
	}
	return newArray;
}

int **getAllPossibilitiesPerPosition(int possibilitiesPerParam[][] , int table[][][], int rowFixed, int pos, int reversed)
{
	int possibilitiesPerPosition[][] = new int[MAX_FLOOR][MAX_FLOOR];
	int i = 0;
	while (i < possibilitiesPerParam.length)
	{
		int possibilty[] = possibilitiesPerParam[i];
		if (reversed == 1)
			possibilty = reverseArray(possibilty);
		int j = 0;
		int add = 1;
		while (j < possibilty.length)
		{
			if (possibilty[j] == 0)
				break;
			if (rowFixed == 1)
			{
				if (table[pos][j][possibilty[j] - 1] == 0)
				{
					add = 0;
					break;
				}
			}
			else
			{
				if (table[j][pos][possibilty[j] - 1] == 0)
				{
					add = 0;
					break;
				}
			}
			j++;
		}
		if (add == 1)
		{
			j = 0;
			while (j < possibilty.length)
			{
				if (possibilty[j] == 0)
					break;
				possibilitiesPerPosition[j][possibilty[j] - 1] = 1;
				j++;
			}
		}
		i++;
	}
	return possibilitiesPerPosition;
}

int [][]getPossibiltiesForParam(int param)
{
	int possibilities[][]  = ALL_POSSIBILITIES;
	int good[][]  = new int[possibilities.length][MAX_FLOOR];

	int i = 0;
	int j = 0;
	while (i < possibilities.length)
	{
		int ok = doISeeTheExactNumberOfBuildings(param, possibilities[i]);
		if (ok == 1)
		{
			good[j] = possibilities[i];
			j++;
		}
		i++;
	}
	return good;
}

int doISeeTheExactNumberOfBuildings(int param, int column[])
{
	int i = 0;
	int buildingCount = 0;
	int lastMaxFloor = 0;
	while (i < 4)
	{
		if (column[i] > lastMaxFloor)
		{
			lastMaxFloor = column[i];
			buildingCount++;
		}
		i++;
	}
	return buildingCount == param ? 1 : 0;
}


void initTable(int table[][][])
{
	int i = 0;
	while (i < MAX_FLOOR)
	{
		int j = 0;
		while (j < MAX_FLOOR)
		{
			int k = 0;
			while (k < MAX_FLOOR)
			{
				table[i][j][k] = 1;
				k++;
			}
			j++;
		}
		i++;
	}
}

int[][] getAllPossibilitiesForMatrix()
{
	int possibilities[][] = new int[60][4];

	int init[] = {1, 2, 3, 4};
	int x = 0;
	int i = 0;
	while (i < 15)
	{
		int j = 1;
		while (j <= MAX_FLOOR)
		{
			int tmp = init[(j - 1) % MAX_FLOOR];
			init[(j - 1) % MAX_FLOOR] = init[j % MAX_FLOOR];
			init[j % MAX_FLOOR] = tmp;
			copyArray(init, possibilities[x], MAX_FLOOR);
			j++;
			x++;
		}
		i++;
	}
	return possibilities;
}

void copyArray(int from[], int to[], int length)
{
	int i = 0;
	while (i < length)
	{
		to[i] = from[i];
		i++;
	}
}
