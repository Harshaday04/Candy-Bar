#include <stdio.h>
#include <stdlib.h>
#include "PRODUCT_M.h"
#include "PRODUCT_filtering.h"
#define MAX_PRODUCTS 1000

int main() {
	Product products[MAX_PRODUCTS];
	int count = 0;
	int choice;

	loadProducts(products, &count);

	while (1) {
		printf("\n--- Product Management System ---\n");
		printf("1. Display Products\n");
		printf("2. Add Product\n");
		printf("3. Remove Product\n");
		printf("4. Filtering Product\n");
		printf("5. Sort the list of Products");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			displayProducts(products, count);
			break;
		case 2:
			addProduct(products, &count);
			break;
		case 3:
			removeProduct(products, &count);
			break;
		case 4:
            filterProducts(products, count);
		case 5:
		displaySortingMenu(products, count);  // Now the sorting menu is in PRODUCT_sorting.c
                break;
		case 6:
			saveProducts(products, count);
			exit(0);
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}