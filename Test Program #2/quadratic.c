#include <stdio.h>
int BinToDec(int n); //function prototype
int main(){
	int num, x;
	do{
		printf("Enter a Binary Number: ");
		scanf("%d", &num);
		x = BinToDec(num);
		printf("The number you have entered in Decimal is %d\n", x);
	}while(num >= 0);
	return 0;
}
/*Here function
starts*/
int BinToDec(int no){
	int rem; 
 	int decimal = 0, i = 1;
	while (no >= 0){
        rem = no % 10;
        decimal = decimal + rem * i;
        no = no / 10 ;
        i = i * 2;
    }
    return decimal;
}
