#ifndef PRODUCT_M_H
#define PRODUCT_M_H

// Structure to hold product information
typedef struct {
    int productID;
    char name[100];
    char description[255];
    float price;
    int stock;
    char category[50];
    float netWeight;
} Product;

// Function prototypes
void loadProducts(Product products[], int *count);
void addProduct(Product products[], int *count);
void saveProducts(Product products[], int count);
void displayProducts(Product products[], int count);
void removeProduct(Product products[], int *count);
int getNextID(Product products[], int count);

#endif // PRODUCT_M_H
