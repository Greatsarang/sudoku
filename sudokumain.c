#include<stdio.h>

#define N 9 //Row and Column

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
			printf("%d, ", arr[c][r]);
		}

		printf("\n");
	}
	return;
}

int check(int arr[0][0], int c, int r) {
	return 0;
}

int solveSudoku(int arr[N][N]) {
	int repeat=0;
	int num=0;
	//Next Column
	for (int c=0; c<N; c++) {
		//Next Row
		for (int r=0; r<N; r++) {
			//Check is the empty or 0 spot
			if(arr[c][r] == 0) {
				num = 0;
				//Check untile unique number placed in empty spot
				do {
					repeat = 0;
					//Decide number to be place, start with 1 till 9
					num++;
					//Check if in same column number is not repeated
					for (int c1=0; c1<N; c1++) {
						if ((arr[c1][r] == num) && (c1 != c)){
							printf("\n Found num:%d reapted with column a[%d][%d]:%d, ", num, c1, r, arr[c1][r]);
							repeat=1;
						}
					}
					//Check if the number is not repeated in the same column
					for (int r1=0; r1<N; r1++) {
						if((arr[c][r1] == num) && (r1 != r)) {
							printf("\n Found num%d, repeated with row a[%d][%d]:%d, ", num, c, r1, arr[c][r1]);
							repeat=1;
						}
					}
					//Check if the number is not repeated in subset of 3x3
					//Reset to 0,0 column,row subset matrix of 3x3
					int r2, c2;
					c2 = c-c%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 
					r2 = r-r%3; //0-0%3=0, 1-1%1=0, 2-2%3=0, 3-3%3=3, 4-4%3=3, 5-5%3=3, 6-6%3=6, 
					for (int s=0 ; s<3; s++) {
						//Check in all coloumns of Subset matrix of 3x3
						if((arr[c2+s][r2] == num) && ((c2!=c) && (r2!=r))) {
							printf("\n Found num%d, repeated in Subset column a[%d][%d]:%d, ", num, c2+s, r2, arr[c2+s][r2]);
							repeat=1;
							break;
						}
						//Check in all rows of Subset matrix of 3x3
						if((arr[c2][r2+s] == num) && ((c2!=c) && (r2!=r))) {
							printf("\n Found num%d, repeated in Subset row a[%d][%d]:%d, ", num, c2, r2+s, arr[c2][r2+s]);
							repeat=1;
							break;
						}
					}

					printf("a[%d][%d]:%d, ", c, r, arr[c][r]);
					//Check if number is not repeated as per all 3 rules then place number in the emplty spot
					if(repeat == 0){
						printf("\nStoring num:%d into (a[c][r]) a[%d][%d]:%d, ", num, c, r, r);
						arr[c][r] = num;
						num=0;
						//break;
					}
				} while((repeat == 1) && (num < N));
			}
		}
	}

				
	return 1;
}


int main() {
    // 0 means unassigned cells
    int matrix[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    printMatrix(matrix);

    printf("\n");
    //if (solveSudoku(grid, 0, 0)==1)
    if (solveSudoku(matrix)==1)
    	printMatrix(matrix);
        //printf("%d ",matrix[0][0]);
    else
        printf("No solution exists");

  return 0;
  printf("My first program\n");
}
