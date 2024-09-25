// PRODUCT_sorting.c
#include <stdio.h>
#include <string.h>
#include "PRODUCT_Sorting.h"

// Helper function to swap two products
void swap(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

// Sort products by name (alphabetical order)
void sortProductsByName(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(products[j].name, products[j + 1].name) > 0) {
                swap(&products[j], &products[j + 1]);
            }
        }
    }
    printf("\nProducts sorted by name.\n");
}

// Sort products by price (ascending order)
void sortProductsByPrice(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                swap(&products[j], &products[j + 1]);
            }
        }
    }
    printf("\nProducts sorted by price.\n");
}

// Sort products by stock (ascending order)
void sortProductsByStock(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].stock > products[j + 1].stock) {
                swap(&products[j], &products[j + 1]);
            }
        }
    }
    printf("\nProducts sorted by stock.\n");
}

// Function to display sorting menu and handle user input for sorting
void displaySortingMenu(Product products[], int count) {
    int sortChoice;
    printf("1. Sort by Name\n");
    printf("2. Sort by Price\n");
    printf("3. Sort by Stock\n");
    printf("Enter your sorting choice: ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
            sortProductsByName(products, count);
            displayProducts(products, count);  // Assuming you have a displayProducts function
            break;
        case 2:
            sortProductsByPrice(products, count);
            displayProducts(products, count);
            break;
        case 3:
            sortProductsByStock(products, count);
            displayProducts(products, count);
            break;
        default:
            printf("Invalid sort choice.\n");
    }
}
