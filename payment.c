#include <stdio.h>
#include <string.h>
#include "payment.h"

// Process payment for an order
void processPayment(int userId, int orderId, PaymentDetails paymentDetails) {
    printf("Processing payment for user %d and order %d...\n", userId, orderId);
    printf("Payment Details:\n");
    printf("Card Number: %s\n", paymentDetails.cardNumber);
    printf("Expiry Date: %s\n", paymentDetails.expiryDate);
    printf("CVV: %s\n", paymentDetails.cvv);
    printf("Payment successful!\n");
}

// Apply a discount code to the 

void applyDiscountCode(int orderId, char *discountCode) {
    printf("Applying discount code '%s' to order %d...\n", discountCode, orderId);
    printf("Discount applied successfully!\n");
}

// Main function with menu
int main() {
    int userId, orderId;
    PaymentDetails paymentDetails;
    char discountCode[20];
    int choice;

    do {
        printf("\n--- Payment Menu ---\n");
        printf("1. Process Payment\n");
        printf("2. Apply Discount Code\n");
        printf("3. Exit Payment Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &userId);
                printf("Enter Order ID: ");
                scanf("%d", &orderId);
                printf("Enter Card Number: ");
                scanf("%s", paymentDetails.cardNumber);
                printf("Enter Expiry Date (MM/YY): ");
                scanf("%s", paymentDetails.expiryDate);
                printf("Enter CVV: ");
                scanf("%s", paymentDetails.cvv);
                processPayment(userId, orderId, paymentDetails);
                break;

            case 2:
                printf("Enter Order ID: ");
                scanf("%d", &orderId);
                printf("Enter Discount Code: ");
                scanf("%s", discountCode);
                applyDiscountCode(orderId, discountCode);
                break;

            case 3:
                printf("Exiting Payment Menu...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
