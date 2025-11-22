/******************************************
Palleral Array

Array Practice 4 - palleral array

Create the following program

1. Obtain the following information for
X products (X could be 3 to begin).
Use a macro directive to X

2. You need to obtain:
i. product id,
ii. price
iii. quantity
iv. taxed (y or n as input) ?char initialization??
for each product.
Decide on how to store the values (arrays...)

3. Create a function called populate to populate all
product information. Decide on what comes in and what to return

4. Display all product information in main using a tabular format

******************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 3 
void populate(int [], float [], int [], char [], int );

void populate(int id[], float prices[], int quantity[], char taxed[], int sz) {
	
	int i;
	for (i = 0; i < sz; i++) {
		printf("Product %d Info: \n", i + 1);
		printf("Enter ID: ");
		scanf("%d%*c", &id[i]);

		printf("Enter Price: ");
		scanf("%f%*c", &prices[i]);

		printf("Enter Quantity: ");
		scanf("%d%*c", &quantity[i]);

		printf("Enter is Taxed: ");
		scanf("%c%*c", &taxed[i]);
		printf("\n");
	}
}

int main() {

	int id[SIZE], quantity[SIZE], i;
	float prices[SIZE];
	char taxed[SIZE];
	
	populate(id, prices, quantity, taxed, SIZE);

	for (i = 0; i < SIZE; i++) {
		printf("%d\t%.2f\t%d\t%c\n", id[i], prices[i], quantity[i], taxed[i]);
	}



	return 0;

}



// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #define SIZE 3 

// void populate(int [], float [], int [], char [], int);

// void populate(int productId[], float price[], int quantity[], char taxed[], int sz){ //왜 여기서 SIZE로 하면 안되지? sz로 해야하지?
//     int i;
//     for(i=0;i<SIZE;i++){
//         printf("Enter Product ID for Product %d: \n", i+1);
//         scanf("%d*c", &productId[i]);
//         printf("Enter price for Product %d: ", i+1);
//         scanf("%f*c", &price[i]); 
//         printf("Enter quantity for Product %d: ", i+1);
//         scanf("%d*c", &quantity[i]);    
//         printf("Enter taxed for Product %d (y or n): ", i+1);
//         scanf("%c*c", &taxed[i]);
//     }
// }

// int main(){

//     int productId[SIZE], quantity[SIZE], i;
//     float price[SIZE];
//     char taxed[SIZE];

//     populate(productId, price, quantity, taxed, SIZE);

//     for(i=0; i<SIZE; i++){
//         printf("Product ID: %d, price: %.2lf, quantity: %d, taxed: %c\n", productId[i], price[i], quantity[i], taxed[i]);
//     }


//     return 0;
// }