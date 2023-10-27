#include <stdio.h>
# include <math.h>

void generate(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            if(i==0)
            printf("%3d",n);
            else if(j<=i && n-(j-1)>0 && i<=n)
            printf("%3d",n-(j-1));
            else if(j>i && j<=2*n-i)
            printf("%3d",n-i+1);
            else if(j>i && j>2*n-i && i<=n)
            printf("%3d",j-n+1); 
        }
        printf("\n"); 
    }
    for (int i = n-1; i>0; i-- ){
       for (int j = 1; j <= 2 * n - 1; j++) {
            if(i==0)
            printf("%3d",n);
            else if(j<=i && n-(j-1)>0 && i<=n)
            printf("%3d",n-(j-1));
            else if(j>i && j<=2*n-i)
            printf("%3d",n-i+1);
            else if(j>i && j>2*n-i && i<=n)
            printf("%3d",j-n+1); 

    }
    printf("\n"); 
}
}

/*double pol ( double ); 
double dpol ( double );

double iterate ( double a){
 while(1){
    if( pol(a) == 0)
      break;
    double a_new;
    a_new = a - ( pol(a)/ dpol(a));
    if (a_new - a < 0.00000001){
        a = a_new;
        break;
    }
    a = a_new;
 }

return a;
}*/
int main(){ 
    
    int n;
    printf("Input a number: ");
    scanf("%d", &n);
    generate(n);
}
