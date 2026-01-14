#include <stdio.h>
#include<math.h>

int digits(int n){
    int count = 0;
    while (n>0){
        count ++;
        n /=10;
    }
    return count;
}

int karatsuba (int A, int B){
    if (A<10 || B<10){
        return A *B;
    }

    int n = digits(A);
    if (digits(B)>n){
        n= digits(B);
    }
    int m = n/2;
    int p = pow(10, m);
    //split
    int a = A/p;
    int b = A% p;
    int c = B/p;
    int d = B%p;
    int ac = karatsuba(a,c);
    int bd = karatsuba(b,d);
    int ad_bc= karatsuba (a+b, c+d)- ac-bd;
    return ac * pow(10, 2 * m) + ad_bc * p + bd;
}

int main(){
    int A, B;
   printf("Enter first number: ");
   scanf("%d", &A);
   printf("Enter second number: ");
   scanf("%d", &B);
   int result = karatsuba(A,B);
   printf("Result of %d x %d : %d ", A,B, result);
   return 0;
}
