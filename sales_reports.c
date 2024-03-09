/* sales reports */
#include <stdio.h>
#include <strings.h>
#define NUM_STRINGS 12
//sales_report takes in the sales float array
void sales_report(char *m[12], float s[12])
{
    printf("Month\t\tSales\n\n");
    for (int i = 0; i < 12; i++) {
        printf("%-12s\t$%-12.2f\n", m[i], s[i]);
    }
}

void sales_summary(char *m[12], float s[12]){
	//find maximum sales
	//sales must be attached to month
	//once we get index for sale, find corresponding index in m
	//find min
	float newmin = s[0];
	int jump;
	int min_index;
	for(int j = 0; j<12;j++){
		if (s[j] < newmin){
			newmin = s[j];
		}
	}
	for (int minpoint=0; minpoint<12;minpoint++){
		if(s[minpoint]==newmin){
			min_index = minpoint;
		}
	}
	printf("Minimum sales:\t$%-12.2f(%s)\n", newmin,m[min_index]);
	//find max
	//initialize max variable
	float newmax = s[0];
	int max_index;
	for (int i = 0; i < 12; i++){
		//look for largest element
		if (s[i] > newmax){
			newmax = s[i];
		}
	}
	//once we have the value of the max, find it in the array and keep track of index
	for (int maxpoint=0; maxpoint<12; maxpoint++){
		if (s[maxpoint] == newmax){
			max_index = maxpoint;
		}
	}
	printf("Maximum sales:\t$%-12.2f(%s)\n", newmax,m[max_index]);
	float average;
	float total = 0;
	//compute the average
	for (int t=0;t<12;t++){
		total +=s[t];
	}
	average = total/12;
	printf("Average sales:\t$%-12.2f\n", average);
	
}
void moving_average(char *m[12], float s[12]){
	//count plus 6 to determine what months averaged
	for (int i = 0; i<12;i++){
		//check that index after six months is valid
		if((i+5)<12){
		float average = (s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]+s[i+5])/6;
		printf("%-12s-\t%-12s$%-12.2f\n",m[i],m[i+5],average);
		}
	}
}
void high_to_low(char *m[12], float s[12]){
	//create duplicate arrays of sales and months
	float sorted[12];
	char *months[12];
	for(int k= 0; k<12;k++){
		months[k] = m[k];
		sorted[k] = s[k];
	}
	
	//sort the arrays from highest to lowest
	for(int i=0;i<12;i++){
		for(int j=0;j<11-i;j++)
		if (sorted[j]<sorted[j+1]){
			int tmp = sorted[j];
			sorted[j] = sorted[j+1];
			sorted[j+1] = tmp;
			char *tmp2 = months[j];
			months[j] = months[j+1];
			months[j+1] = tmp2;
		}
	}
	
	printf("%-12s%-12s\n\n","Month","Sales");
	//print the results
	for(int k=0;k<12;k++){
		printf("%-12s$%-12.2f\n",months[k],sorted[k]);
	}
}

int main()
{
    //declare array to store sales numbers
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
	
	//define array to hold months corresponding to sales
	char *months[NUM_STRINGS];
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
	months[11] = "December";
	//begin series of function calls
	printf("\nMonthly sales report for 2024:\n\n");
    sales_report(months, sales);
	printf("\nSales summary:\n\n");
	sales_summary(months, sales);
	printf("\nSix-Month Moving Average Report:\n\n");
	moving_average(months,sales);
	printf("\nSales Report (Highest to Lowest):\n\n");
	high_to_low(months,sales);
}