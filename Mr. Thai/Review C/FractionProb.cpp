#include <stdio.h>
typedef struct{
	int numerator;//tu
	int denominator;//mau
}Fraction;
Fraction read(){
	Fraction a;
	scanf("%d %d",&a.numerator,&a.denominator);
	return a;
}
void display(Fraction p){
	printf("%d/%d\n", p.numerator, p.denominator);
}
	int gcd(int a, int b){
		while(b!=0){
		int temp = b;
		b=a%b;
		a= temp;}
		return a;
}
void  reduce(Fraction *ps){
	int temp = gcd(ps->numerator,ps->denominator);
	ps->numerator/=temp;
	ps->denominator/=temp;
}
Fraction add(Fraction a, Fraction b){
	Fraction result;
	result.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	result.denominator = a.denominator*b.denominator;
	reduce(&result);
	return result;
}
Fraction subtract(Fraction a, Fraction b){
	Fraction result;
	result.numerator = a.numerator*b.denominator-b.numerator*a.denominator;
	result.denominator = a.denominator*b.denominator;
	reduce(&result);
	return result;	
}
Fraction multiply(Fraction a, Fraction b){
	Fraction result;
	result.numerator = a.numerator*b.numerator;
	result.denominator = a.denominator*b.denominator;
	reduce(&result);
	return result;
}
Fraction divide(Fraction a,Fraction b){
	Fraction result;
	result.numerator = a.numerator*b.denominator;
	result.denominator = a.denominator*b.numerator;
	reduce(&result);
	return result;
}
int main(){
	printf("Nhap phan so a : ");
	Fraction a = read();
	printf("Nhap phan so b : ");
	Fraction b = read();

	printf("a + b = ");
	Fraction sum = add(a,b);
	display(sum);
	
	printf("a - b = ");
	Fraction sub = subtract(a,b);
	display(sub);
	
	printf("a * b = ");
	Fraction mul = multiply(a,b);
	display(mul);
	
	printf("a : b = ");
	Fraction div = divide(a,b);
	display(div);
	
	return 0;	
}

	

