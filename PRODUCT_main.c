#include "PRODUCT_MENU.h"  // Include the menu header

#define MAX_PRODUCTS 1000  // Define maximum product capacity

int main() {
    Product products[MAX_PRODUCTS];  // Array to store products
    int count = 0;                   // Counter for number of products

    loadProducts(products, &count);  // Load existing products from file

    // Display the menu and handle interactions
    displayMenu(products, &count);

    return 0;
}

