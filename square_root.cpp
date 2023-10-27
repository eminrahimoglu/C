/* finding square root of a positive integer and 0 :) */
#include <stdio.h>

/* function main begins program execution */
int main() {
    
	int a;  /* number which is inputed */
    double x1 = 0, x2 = 0; /* intervals (x1,x2) */
	double fx1 = 0, fx2 = 0;

    /* Read input from user */
    printf("Enter a positive integer for interval search method:");
    scanf("%d", &a);

    /* assign a to end of an interval */
    x2 = a;
       
	    /* this if statement prints the roots if input value is 0 or 1*/     
		if (a == 0 || a==1) {
          printf("Square root of %d for the interval search method: \n%.1f\n", a, x2);
          printf("Square root of %d for the Newton-Raphson method: \n%.1f\n", a, x2);
		  return 0;
}
    
	 /*loop starts*/
	while (1) {
      
	    /* Divide the interval into 10 sections */
        double s = (x2 - x1) / 10.0;
        double x1_new = x1;
        double x2_new = x1 + s;

        /* Check each section to see if the root resides within it */
        int root_found = 0;
        
		/* loop 10 times */
		for (int i = 0; i < 10; i++) {
            /*algebraic expression for finding root*/
			fx1 = x1_new * x1_new - a;
            fx2 = x2_new * x2_new - a;
          
		  if (fx1 * fx2 < 0) {
            /* Root found within this section */
              root_found = 1;
              x2 = x2_new;
              x1 = x1_new;
              break; /* break loop only if fx1 * fx2 < 0*/
}
          
            /* Move to next with new values */
            x1_new = x2_new;
            x2_new += s;
        }

        /* Check if root has been found or not if found ends the loop*/
        if (root_found == 1 && x2 - x1 < 0.00001) {
            printf("Square root of %d for the interval search method: \n%f\n", a, x2);
            break; 
        
        }
    }
      
	   double xi;
       double xi_1;
       
       xi = a;
         
		 while(1) {
         	
        /* Calculate the next estimate of the root */
        xi_1 = xi - (xi * xi - a) / (2 * xi);

        /* Check if programme approached the root or not if found ends the loop*/
        if (xi_1 - xi < 0.0001 && xi_1 - xi > -0.0001) {
            printf("Square root of %d for the Newthon Raphson Formula: \n%f", a, xi_1);
            break;
        }

        /* new estimate of the root */
        xi = xi_1;         	
         	
   }

	return 0;     /* indicate that program ended successfully */

} /* end function main */
