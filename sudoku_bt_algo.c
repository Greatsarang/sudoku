#include<stdio.h>

#define N 9 //Row and Column width

//Rule 1: in 9x9 there will be 1 to 9 digits in a row or column or in subset
//Rule 2: In a row no digit will repeat, every digit is unique
//Rule 3: In a column no digit will repeat, every digit is unique
//Rule 4: In a subset 3x3 matrix every digit is unique
//Rule 5: sum will be 45 in a row, column and subset matrix of 3x3.


void printMatrix(int arr[N][N]){
	int c, r;
    	printf("\n");
	for (c=0; c<N; c++) {
		for (r=0; r<N; r++) { 
			printf("%d ", arr[c][r]);
		}

		printf("\n");
	}
	return;
}

#if 0
//This function not using.
// Find empty space and possible number to be place
int checkAndPlaceNumber(int arr[N][N], int c, int r) {
	int num = 0;
	int repeat = 0;
	int r2, c2;
	//Check untile unique number placed in empty spot
	//do {
	if (num=1, num < N, num ++) {
		repeat = 0;
		//Decide number to be place, start with 1 till 9
		num++;
		//Check if in same column number is not repeated
		for (int c1=0; c1<N; c1++) {
			if ((arr[c1][r] == num) && (c1 != c)){
				//printf("\n Found num:%d reapted with column a[%d][%d]:%d, ", num, c1, r, arr[c1][r]);
				repeat=1;
			}
		}
		//Check if the number is not repeated in the same column
		for (int r1=0; r1<N; r1++) {
			if((arr[c][r1] == num) && (r1 != r)) {
				//printf("\n Found num%d, repeated with row a[%d][%d]:%d, ", num, c, r1, arr[c][r1]);
				repeat=1;
			}
		}
		//Check if the number is not repeated in subset of 3x3
		//Reset to 0,0 column,row subset matrix of 3x3
		c2 = c-c%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 
		r2 = r-r%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 
		for (int s=0 ; s<3; s++) {
			//Check in all coloumns of Subset matrix of 3x3
			if((arr[c2+s][r2] == num) && ((c2!=c) && (r2!=r))) {
				//printf("\n Found num%d, repeated in Subset column a[%d][%d]:%d, ", num, c2+s, r2, arr[c2+s][r2]);
				repeat=1; 
				break;
			}
			//Check in all rows of Subset matrix of 3x3
			if((arr[c2][r2+s] == num) && ((c2!=c) && (r2!=r))) {
				//printf("\n Found num%d, repeated in Subset row a[%d][%d]:%d, ", num, c2, r2+s, arr[c2][r2+s]);
				repeat=1;
				break;
			}
		}

		//Check if number is not repeated as per all 3 rules then place number in the emplty spot
		if(repeat == 0){
			//printf("\nStoring num:%d into a[%d][%d]:%d, ", num, c, r, arr[c][r]);
			arr[c][r] = num;
			num=0;
		}
	//Check till num not repeated
	} //while((repeat == 1) && (num < N));
	

	//Check now backtracking required
	//if((repeat == 1) && (c >= N) &&(r >= N-1)){
	if((repeat == 1) && (num >= N)){
		//printf("Backtracking required \n");
		return 1;
	}

	return 0;
}
#endif

int findPlace(const int arr[N][N], int x, int y, const int num)
{
	int i, j, x0, y0;

	for (i = 0; i < N; ++i)
		if (arr[y][i] == num)
			return 0;

  	for (i = 0; i < N; ++i)
		if (arr[i][x] == num)
			return 0;

	//Check if the number is not repeated in subset of 3x3
	//Reset to 0,0 column,row subset matrix of 3x3
	x0 = x-x%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 
	y0 = y-y%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			if ((arr[y0+i][x0+j] == num)
			    && ((x0 != x) && (y0 != y))) 
				return 0;
	
	/*	
	for (int s=0 ; s<3; s++) {
		//Check in all coloumns of Subset matrix of 3x3
		if((arr[y0+s][x0] == num) && ((x!=x0) && (y!=y0))) 
			return 0;
		//Check in all rows of Subset matrix of 3x3
		if((arr[y0][x0+s] == num) && ((x!=x0) && (y!=y0))) 
			return 0;
	}
	*/
	return 1;
}


//int solveSudoku(int arr[N][N], int c, int r) {
void solveSudoku(int arr[N][N]) {
	int y, x, num;

	for (y = 0; y < N; ++y)
		for (x = 0; x < N; ++x)
			//Check empty space
			if (arr[y][x] == 0)
			{
				for (num = 1; num <= N; ++num)
				{
					const int x1 = x;
					const int y1 = y;
					//Check for possible available space 
					if (findPlace(arr, x, y, num))
					{
						arr[y][x] = num; //Set possible number
						solveSudoku(arr);//Return if Backtracking
						arr[y][x] = 0; //reset earlier possible values to 0
					}
				} //end of 'for' till N
				return; //Backtracking
			}//end of 'if' emply space

	//Print solved Sudoku problem
	printMatrix(arr);
}


int main() {
	// 0 means unassigned cells
	int matrix[N][N] = { 
			{ 4, 1, 9, 0, 8, 0, 0, 0, 0 },
                       	{ 5, 0, 8, 0, 0, 0, 0, 0, 6 },
                       	{ 0, 0, 0, 5, 0, 0, 0, 0, 0 },
                       	{ 0, 9, 0, 6, 0, 0, 0, 0, 4 },
                       	{ 0, 4, 0, 0, 0, 0, 0, 0, 3 },
                       	{ 6, 0, 0, 2, 9, 0, 0, 8, 0 },
                       	{ 0, 0, 2, 3, 0, 1, 0, 0, 0 },
                       	{ 0, 0, 0, 0, 0, 9, 2, 5, 0 },
                       	{ 0, 7, 0, 0, 0, 0, 0, 0, 0 } 
		      };
	//Sample 2
	int matrix2[N][N] = 
		{
			{7, 0, 0, 0, 0, 1, 0, 0, 3},
			{0, 0, 3, 0, 0, 2, 6, 0, 0},
			{0, 2, 0, 7, 0, 8, 0, 0, 5},
			{0, 6, 0, 0, 1, 0, 3, 7, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 5, 0, 7, 0, 0, 6, 0},
			{3, 0, 0, 2, 0, 4, 0, 5, 0},
			{0, 0, 8, 5, 0, 0, 7, 0, 0},
			{5, 0, 0, 1, 0, 0, 0, 0, 9},
		};

	//Sample 3
	int matrix1[N][N] =  {
			{3, 0, 6, 5, 0, 8, 4, 0, 0},
			{5, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 0, 0, 0, 3, 1},
			{0, 0, 3, 0, 1, 0, 0, 8, 0},
			{9, 0, 0, 8, 6, 3, 0, 0, 5},
			{0, 5, 0, 0, 9, 0, 6, 0, 0},
			{1, 3, 0, 0, 0, 0, 2, 5, 0},
			{0, 0, 0, 0, 0, 0, 0, 7, 4},
			{0, 0, 5, 2, 0, 6, 3, 0, 0}
		};

	//Print input Sudoku problem
	printMatrix(matrix);

	printf("\n");
	//if (1 == checkValidSudoku(matrix, 0, 0, matrix[0][0])) 
	//		printf("Sudoku problem is not correct\n");

	solveSudoku(matrix);

	return 0;
}
