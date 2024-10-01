#include <stdio.h>
#include <stdlib.h>
#include "PRODUCT_MENU.h"

void displayMenu(Product products[], int *count) {
    int choice;

    while (1) {
        printf("\n--- Product Management System ---\n");
        printf("1. Display Products\n");
        printf("2. Add Product\n");
        printf("3. Remove Product\n");
        printf("4. Filter Products\n");
        printf("5. Sort the List of Products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayProducts(products, *count);  // Display all products
                break;
            case 2:
                addProduct(products, count);        // Add a new product
                break;
            case 3:
                removeProduct(products, count);     // Remove a product by ID
                break;
            case 4:
                filterProducts(products, *count);   // Filter products
                break;
            case 5:
                displaySortingMenu(products, *count);  // Sort products
                break;
            case 6:
                saveProducts(products, *count);     // Save products before exiting
                printf("Exiting the program...\n");
                exit(0);                            // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}