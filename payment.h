#ifndef PAYMENT_H
#define PAYMENT_H

// Structure to hold payment details
typedef struct {
    char cardNumber[20];
    char expiryDate[10];
    char cvv[5];
} PaymentDetails;

// Function declarations
void processPayment(int userId, int orderId, PaymentDetails paymentDetails);
void applyDiscountCode(int orderId, char *discountCode);

#endif
