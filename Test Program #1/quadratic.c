#include <stdio.h>
int main (){
	int n, i, max = 0, min = 0;
	printf("Enter no. of element you want: "); //Enter the number of elements
	scanf("%d", &n);
	int AR[n];
	for (i = 0; i < n; i++){
		printf("Enter element no. %d: ", i + 1);
		scanf("%d", &AR[i]);
		if (i == 0){
			min = max = AR[i];
		}
		else if (AR[i] < min) //Check whether element in Array is less than minimum
			min = AR[i];
		else if (AR[i] > max) //Check whether element in Array is greater than maximum
			max = AR[i];
	}
	printf("\n");
	printf("The maximum value is %d\n", max);
	printf("The minimum value is %d", min);
	return 0;
}

