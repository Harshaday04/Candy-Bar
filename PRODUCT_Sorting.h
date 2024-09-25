// PRODUCT_sorting.h
#ifndef PRODUCT_Sorting_H
#define PRODUCT_Sorting_H

#include "PRODUCT_M.h"

// Function prototypes for sorting
void sortProductsByName(Product products[], int count);
void sortProductsByPrice(Product products[], int count);
void sortProductsByStock(Product products[], int count);

// Sorting menu function prototype
void displaySortingMenu(Product products[], int count);

#endif
