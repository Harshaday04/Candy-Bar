#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PRODUCT_M.h"
#define MAX_PRODUCTS 1000
#define FILE_NAME "Database Candy Bar.txt"

// Load products from file
void loadProducts(Product products[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", FILE_NAME);
        return;
    }
    char header[500];  // Buffer to read and discard the header
    fgets(header, sizeof(header), file);  // Skip header line

    *count = 0;  // Initialize product count to 0
    char line[500];  // Buffer to read each line
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d,%99[^,],%254[^,],%f,%d,%49[^,],%f",
                   &products[*count].productID,
                   products[*count].name,
                   products[*count].description,
                   &products[*count].price,
                   &products[*count].stock,
                   products[*count].category,
                   &products[*count].netWeight) == 7) {
            (*count)++;
            if (*count >= MAX_PRODUCTS) {  // Safety check for product limit
                break;
            }
        } else {
            printf("Error reading line: %s\n", line); // Debugging output
        }
    }

    fclose(file);
    printf("Loaded %d products from file %s.\n", *count, FILE_NAME);
}

// Get the next available ProductID
int getNextID(Product products[], int count) {
    return (count > 0) ? products[count - 1].productID + 1 : 1;
}

// Add a new product
void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum limit reached.\n");
        return;
    }

    Product newProduct;
    newProduct.productID = getNextID(products, *count);
    printf("Enter name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter description: ");
    scanf(" %[^\n]", newProduct.description);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    printf("Enter stock: ");
    scanf("%d", &newProduct.stock);
    printf("Enter category: ");
    scanf(" %[^\n]", newProduct.category);
    printf("Enter net weight (oz): ");
    scanf("%f", &newProduct.netWeight);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully with ID %d.\n", newProduct.productID);
}

// Save products to file
void saveProducts(Product products[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Could not open file %s for writing.\n", FILE_NAME);
        return;
    }

    // Write the header to the file
    fprintf(file, "CandyID,Name,Description,Price($),Stock,Category,Net Weight (oz)\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%.2f,%d,%s,%.2f\n",
                products[i].productID,
                products[i].name,
                products[i].description,
                products[i].price,
                products[i].stock,
                products[i].category,
                products[i].netWeight);
    }

    fclose(file);
    printf("Products saved successfully.\n");
}

// Display all products
void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    // Print the header
    printf("ID, Name, Description, Price, Stock, Category, Net Weight\n");
    printf("-------------------------------------------------------------------------------------------\n");
    
    // Loop through products and print with IDs
    for (int i = 0; i < count; i++) {
        printf("%d,%s,%s,%.2f,%d,%s,%.2f \n",
               products[i].productID,
               products[i].name,
               products[i].description,
               products[i].price,
               products[i].stock,
               products[i].category,
               products[i].netWeight);
    }
}

void removeProduct(Product products[], int *count) {
    int found = 0;
    int productId;
    printf("Enter the ID of the product to remove: ");
    scanf("%d", &productId);

    for (int i = 0; i < *count; i++) {
        if (products[i].productID == productId) {
            found = 1;
            // Shift products left to fill the gap
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;  // Decrease the product count
            printf("Product with ID %d removed successfully.\n", productId);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", productId);
    }
}