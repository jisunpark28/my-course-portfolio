// Calculating the sum:

//this function sums the numbers in the numbers array
//used is the number of values stored in the numbers array
int sumArray(const int numbers[], int used)
{
	int total = 0;
	int i;
	//note this pattern for a for loop that will iterate through every element of the array
	//this is why we count from 0!
	for(i = 0; i < used; i++){
		total += numbers[i];
	}
	return total;
}