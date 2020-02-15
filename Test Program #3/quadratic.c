#include<stdio.h>
#include<math.h>
int main(){
	float a,b,c,answer,answer1,check;
	printf("Enter the 1st coefficient(a):  ");
	scanf("%f",&a);
	/*To
	ENTER 
	1st COEFFICIENT
	*/
	printf("Enter the 2nd coefficient(b):  ");
	scanf("%f",&b);
	printf("Enter the 3rd coefficient(c):  ");
	scanf("%f",&c);
	check=sqrt(pow(b,2)-(4*a*c));
	if (check>=0){
		answer=(-b+check)/(2*a);
	    answer1=(-b-check)/(2*a);
	    printf("\n\nThe answer is x=%.2f and x=%.2f \n\nProgram ended gracefully.\n",answer,answer1);
	
	else {
		printf("\n\nImaginary answer obtained. \n\nProgram ended gracefully.\n");
	}
	return 0;
}
