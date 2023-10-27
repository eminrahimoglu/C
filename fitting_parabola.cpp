#include <stdio.h>
#define N 4 /* number of data points */
#define M 3 /* number of coefficients in the parabolic function */

  void transpose(double m1[N][M], double transposed[M][N]){  /* function for transposing 4x3 arrays */
	
	int i;
	int j;
	/* loop for transpose */
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			transposed[j][i] = m1[i][j];
		}
		
	}
	
	
}

void matrix_multiplication( int rows_A, int cols_A, int rows_B, int cols_B, double A[rows_A][cols_A], double B[rows_B][cols_B], double result[rows_A][cols_B]) {  /* function for multiplying arrays */
     /* checks if  matrices can be multiplied or not*/    
	if (cols_A != rows_B) {
        printf("Cannot multiply matrices\n");
        return;
    }

    int i, j, k;
    /* loop for multiplying */
	for (i = 0; i < rows_A; i++) {
        for (j = 0; j < cols_B; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols_A; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

  int main(){
    
    int i,j;
	double x[N] = {-1, 1, 2, 3}; // x-coordinates of data points
    double y[N] = {0.5, -1, -0.5, 2}; // y-coordinates of data points  	
  	
  	// Construct the linear equation system
    double A[N][M];
    double B[N][1];
    /* loop for defining elements */
	for (i = 0; i < N; i++) {
        A[i][0] = x[i] * x[i]; 
        A[i][1] = x[i];
        A[i][2] = 1;
        B[i][0] = y[i];  /* assigns y values to b vector */
        printf("%.0fa + %.0fb + %.0fc = %.1f\n", A[i][0], A[i][1], A[i][2], B[i][0]);
  }
  	
  	printf("\nMatris A:\n");
  	 /* loop for printing matrix A */
  	for( i=0; i<4; i++){
		for( j=0; j<3; j++){
		  printf("%.0f ",A[i][j]);
}
     printf("\n");
	}
  	
  	double transposedA[3][4];  /* defines a matrix for transposed A*/
  	transpose(A,transposedA);  /* calls the transpose function */
  	
  	/* loop for printing transposed A */
  	printf("\nTransposed A is:\n");
  	for(int k=0; k<3; k++){
		for(int j=0; j<4; j++){
		  printf("%.0f ",transposedA[k][j]);
  }
     printf("\n");
}

     double ATA[3][3]; /* defines the result of AT*A arrays */
     matrix_multiplication(3,4,4,3,transposedA,A,ATA);  /* calls the multiplication function */
     
     /* loop for printing AT*A array */
     printf("\nATA is:\n");
     for(i=0; i<3; i++){
		for( j=0; j<3; j++){
		  printf("%.0f ",ATA[i][j]);
  }
     printf("\n");
}
    double ATB[3][1]; /* defines the result of AT*b arrays */
    matrix_multiplication(3,4,4,1,transposedA,B,ATB); /* calls the multiplication function */
    
    /* loop for printing AT*B array */
    printf("\nATB is:\n");
     for( i=0; i<3; i++){
		for( j=0; j<1; j++){
		  printf("%.1f ",ATB[i][j]);
}
     printf("\n");
}
   /* computing the determinant of ATA*/
   double det;
   det = ATA[0][0] * (ATA[1][1] * ATA[2][2] - ATA[1][2] * ATA[2][1]) -
          ATA[0][1] * (ATA[1][0] * ATA[2][2] - ATA[1][2] * ATA[2][0]) +
          ATA[0][2] * (ATA[1][0] * ATA[2][1] - ATA[1][1] * ATA[2][0]);


 
    double cofacATA[3][3]; /* defines a matris for cofactor of A */
    /* loop for creating cofactor A*/  
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cofacATA[i][j] = ATA[(i+1)%3][(j+1)%3] * ATA[(i+2)%3][(j+2)%3] - ATA[(i+1)%3][(j+2)%3] * ATA[(i+2)%3][(j+1)%3]; /* calculates each eleement of  cofactorA and assigns each value to the cofactorA array*/
                
        }
    } 
   double invATA[3][3]; /* defines a matris for inverse of ATA */
   
   /* loop for Computing the inverse of ATA */
   for(i=0;i<3;i++){
        for(j=0;j<3;j++){
         invATA[i][j]= (1/det)*cofacATA[i][j];    /* calculates each eleement of invATA */
        	
      }
   }
   printf("\ninvATA is:\n");
   /* loop for printing the inverse ATA matrix */
   for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          printf("%.15f  ",invATA[i][j]);	
       }
     printf("\n");  
   }
   
   double X[3][1]; /* array for coefficients of  parabola*/
   
   matrix_multiplication(3,3,3,1,invATA,ATB,X); /* Calls function to multiply 3x3 and 3x1 matrices and finds the coefficients*/
   
   printf("\nX is:\n");
   /* loop for printing  (ATA)^-1*(ATB) matrix */
   for(i=0;i<3;i++){
        for(j=0;j<1;j++){
          printf("%.15f  ",X[i][j]);	
       }
     printf("\n");  
   }
   printf("\nThe equation of the parabola is: %.15fx^2 %.15fx %.15f", X[0][0], X[1][0], X[2][0]);  /* Prints the best fitting parabola */
  return 0;  	
}

