/********************************************************************* 
Linear Search


**********************************************************************/


int linearSearch(int key, int array[], int used)
{

	int i;
	int rc = -1;
	for (i = 0;rc == -1 && i<used;i++){
		if (array[i] == key){
			rc = i;
		}
	}
	return rc;
}