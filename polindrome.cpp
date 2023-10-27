#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void legendre(double x, double P[], int n) {  /* function that calculates first n elements of legendre polynomials for given x +and assign them to an array*/
    P[0] = 1;
    P[1] = x;
    for (int i = 2; i < n; i++) {
        P[i] = ((2 * i - 1) / (double) i) * x * P[i-1] - ((i - 1) / (double) i) * P[i-2];    /*  determines each elements */
    }
}

double legendre2(int n, double x)  /* function which returns the n th elemenrs of legendre polynomial for x value */
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
        return ((2 * n - 1) / (double) n) * x * legendre2(n - 1, x) - ((n - 1) / (double) n) * legendre2(n - 2, x);  /*  determines n th element  */
}
double magnitude(double D[]){    /*  function that calculates the magnitude of a vector*/

  double sum;
  sum= sqrt(pow(D[0],2)+pow(D[1],2)+pow(D[2],2));  /*  calculates the magnitude */

  return sum;
}

double inversedistance(double A[], double B[]){   /*  function that calculates and returns the inverse distance between two vectors*/

  double inv;
  double C[3];
    if(magnitude(A)>magnitude(B)){       /* checks if vector A is greater than vector B or not */
    for (int i = 0; i < 3; i++){
     C[i]=A[i]-B[i];                     /*  determines x y z components */
}
    inv=(1.0/sqrt(pow(C[0],2)+pow(C[1],2)+pow(C[2],2)));   /*  calculates the inverse distance */
}
    else{                                                    /*  if vector A is not  greater than vector B function returns 0 */
    printf("Magnitude of vector1 is smaller than vector2"); 
     inv=0;
}
   return inv;
}
 /* function main begins program execution */
 int main (){
    
    int i;
    double P[10];
    double b;     /* number of elements */
    
    printf("Enter a number between -1 and 1: ");  /* Read input from user */
    scanf("%lf",&b);
     if( b<-1 || b>1 ){                          /* checks if b is between -1 and 1 */
       printf("Number is not between -1 and 1");
       return 0;
}
    legendre(b, P, 10);  /*executes legendre function for b value */
    
    printf("\nFor x=0.8\n\n"); 
    double x = 0.8;
    double A[50];
    legendre(x, A, 50);  /*executes legendre function for given x value */
   
    printf ("Legendre Polynomials:\n\n");
    for( i=0; i<10; i++){  /* loop 10 times for printing first 10 value */
        printf("%f ", A[i]);   
        printf("\n");
    }
   
    double sum = 0;
    for( i=0; i<10; i++){ /* loop 10 times for collecting  first 10 value */
        sum += A[i];
    }
    printf("\n");
    printf("Sum = %f",sum);
    printf("\n\n");
   
   
   
    printf("50th number of Legendre Polynomial is %f\n",A[49]);
   
    double y;
    double error;
   
    y= (sqrt(2/(M_PI*50*sin(acos(x)))))*(cos((50+0.5)*(acos(x))-(M_PI/4)));  /* asymptotic expansion of 50th value of legendre polynomials for x  */
    error = fabs(y-A[49]);  /* absolute error value between asymptotic expansion and the 50th value   */
   
    printf( "The asymptotic expansion of Legendre Polynomial is %f\n", y);
    printf("The error between them is: %f\n\n",error);
   
    double B[100000];
    legendre(x, B, 100000);  /*executes legendre function for given x value for creating array with 1000 elements */
   
    int j;
    for(j=0; j<100000; j++){  /* loop 100000 times for checking error is less than 0.0001 */
     y= (sqrt(2/(M_PI*j*sin(acos(x)))))*(cos((j+0.5)*(acos(x))-(M_PI/4)));  /* asymptotic expansion */
     error = (fabs(y-B[j]));
     if (error<0.0001)
     break;
 
}

   printf("The appropriate n value that makes the absolute error is less then 10-4 is:%d\n",j);
   printf("The error is: %f\n\n",error);

  double R1[3] = {3.2, 4.0, 7.5};    /* vevtor 1 */
  double R2[3] = {-2.1, 3.3, -4.9};  /* vector 2 */
  double invd;
  double h=0.0;
   x=-0.532;  /*Since I found the desired x as a result of long-term iteration by running the program before, I assigned x to -0.532 so that the program would run faster, 
                   I would normally assign it to -1 and the same value can be found as a result of long-term iteration.*/
    
  

  invd=inversedistance(R1,R2);   /*  calls the function ,calculates the inversedistance between vectors and assigns the value to invd*/
  
  
  while(1){  /* infinite loop until h=invd */
   h=0.0;  /* assign h to 0 for each x value */
    for(i=0; i<100000; i++){  /* loop 10000 times */
      double term = (pow(magnitude(R2)/magnitude(R1), i)/magnitude(R1))*legendre2(i, x);  /*  calculates the nth term (i=n) */
      h = h + term ;
        if(fabs(term)<0.0000001)  /*  when term values become really small and do not effect h value significantly breakks the for loop  */
         break;          
  }
   if(fabs(h-invd)<0.0000001)   /*  h come close to invd adequatly loop ends */
     break;
    x = x + 0.00001;   /* increases the x value at the end of for loop */
}
     
  printf("cos0 = %f\n",x); 

     double radian, degree, sum1, O[100];
     
     /*calculates the degree for cos0=x value */
     radian = acos(-1) / 180.0;
     degree = acos(x) / radian;
    
	 sum1 = 0;
     
     printf("The angle is: %f\n",degree);
     printf("Inverse distance is: %f\n\n",invd);
     
     legendre(x,O,100);    /*executes legendre function for cos0 value */
     
     for(j=0; j<100000; j++){ /* loop 10000 times for finding the value which makes the error less than 0.0001 */
     y= (sqrt(2/(M_PI*j*sin(acos(x)))))*(cos((j+0.5)*(acos(x))-(M_PI/4)));
     error = (fabs(y-O[j]));
     if (error<0.0001)
     break;
 
}
     printf("The appropriate n value that makes the absolute error is less then 10-4 is:%d\n",j);
     printf("The error is: %f\n\n",error);
     
     i=j; /* assign i to the number of an element which makes the error less than 0.0001 */
     
	 for(; j>0; j--){       /* loop for calculating sum until the element which makes error less than 0.0001 */
      printf("%f\n",O[j]);
      sum1 += O[j];
    }
   printf("\nSum of first %d terms of Legendre Polynomial for x=%f  is %f",i,x,sum1); 
     return 0;
}




