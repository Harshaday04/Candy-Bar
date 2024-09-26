#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "PRODUCT_filtering.h"

// Function to flush the input buffer
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void filterProducts(Product products[], int count) {
    char category[50];
    float minPrice, maxPrice;

    // Read category
    printf("Enter category (or 'all' for any category): ");
    scanf("%s", category);

    // Convert category to lowercase for case-insensitive comparison
    for (int i = 0; category[i]; i++) {
        category[i] = tolower(category[i]);
    }

    // Flush the input buffer to ensure clean input for the next step
    flushInput();

    // Ensure valid input for price range
    printf("Enter minimum price: ");
    if (scanf("%f", &minPrice) != 1) {
        printf("Invalid input for minimum price.\n");
        flushInput();  // Clean buffer for next inputs
        return;
    }

    printf("Enter maximum price: ");
    if (scanf("%f", &maxPrice) != 1) {
        printf("Invalid input for maximum price.\n");
        flushInput();  // Clean buffer for next inputs
        return;
    }

    printf("\n--- Filtered Product List ---\n");
    printf("CandyID, Name, Description, Price($), Stock, Category, Net Weight (oz)\n");
    printf("-------------------------------------------------------------------------------\n");

    int found = 0;

    for (int i = 0; i < count; i++) {
        // Convert product category to lowercase for comparison
        char productCategory[50];
        strcpy(productCategory, products[i].category);
        for (int j = 0; productCategory[j]; j++) {
            productCategory[j] = tolower(productCategory[j]);
        }

        // Compare category (or match "all") and check price range
        if ((strcmp(productCategory, category) == 0 || strcmp(category, "all") == 0) &&
            products[i].price >= minPrice && products[i].price <= maxPrice) {
            printf("%-10d %-30s %-20s %-10.2f %-10d %-20s %-15.2f\n",
                   products[i].productID, products[i].name, products[i].description,
                   products[i].price, products[i].stock, products[i].category,
                   products[i].netWeight);
            found = 1;
        }
    }

    if (!found) {
        printf("No products found matching the criteria.\n");
    }
}
