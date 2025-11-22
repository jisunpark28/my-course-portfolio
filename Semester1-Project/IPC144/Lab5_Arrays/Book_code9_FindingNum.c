/********************************************************************* 
Finding the Largest Value in an Array:


**********************************************************************/

int biggest(int array[], int used)
{
	int i;
	int biggestSoFar = array[0];
	for (i = 1; i < used; i++){
		if(array[i] > biggestSoFar){
			biggestSoFar = array[i];
		}
	}
	return biggestSoFar;
}