//WAP to find the sum of two fractions.
#include<stdio.h>
struct fractions
{
	int num, den;
};
typedef struct fractions frac;

frac input(frac a)
{
	scanf("%d%d", &a.num, &a.den);
	return a;
}

int gcd(int a, int b)
{ 
   int gcd = 1;
   for(int i=2;i<=a && i<=b; ++i)
   { 
      if(a%i==0 && b%i==0)
        { 
 	        gcd=i;
        }
    }
    return gcd;
}

frac addition(frac a, frac b)
{
	frac c;
	int n = (b.den*a.num) + (a.den*b.num);
	int d = (a.den*b.den);
	int fact = gcd(n, d);
	c.num = n/fact;
	c.den = d/fact;
	return c;
}

void output(frac a, frac b)
{
    printf("The sum of %d/%d and %d/%d is %d/%d \n", a.num, a.den, b.num, b.den, addition(a, b).num, addition(a,b).den);
}

int main()
{
	printf("Enter 1st fraction: ");
	frac a = input(a);
	printf("Enter 2nd fraction:  ");
	frac b = input(b);
	output(a, b);
	return 0;
}
