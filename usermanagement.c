#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "usermanagement.h"

// Add a new user and save to a file
int addUser(User users[], int *userCount, char *username, char *firstName, char *lastName, char *dob, char *mobile, char *email, char *password) {
    FILE *file = fopen("RegisteredUsers.txt", "a");  // Open file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    // Check if the username already exists
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists!\n");
            fclose(file);  // Close the file before returning
            return 0;
        }
    }

    // Add the new user to the array
    users[*userCount].userId = *userCount + 1;
    strcpy(users[*userCount].username, username);
    strcpy(users[*userCount].firstName, firstName);
    strcpy(users[*userCount].lastName, lastName);
    strcpy(users[*userCount].dob, dob);
    strcpy(users[*userCount].mobile, mobile);
    strcpy(users[*userCount].email, email);
    strcpy(users[*userCount].password, password);
    users[*userCount].isLoggedIn = 0;

    // Write the user details to the file (in CSV format for easy readability)
    fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s\n", 
            users[*userCount].userId, 
            users[*userCount].username, 
            users[*userCount].firstName, 
            users[*userCount].lastName, 
            users[*userCount].dob, 
            users[*userCount].mobile, 
            users[*userCount].email, 
            users[*userCount].password);

    // Increment user count
    (*userCount)++;
    printf("User added successfully. Please login.\n");

    fclose(file);  // Close the file
    return 1;
}

// Log in a user
int logIn(User users[], int userCount, char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            users[i].isLoggedIn = 1;
            printf("Login successful!\n");
            return users[i].userId;
        }
    }
    printf("Invalid username or password.\n");
    return 0;
}

// Log out a user
void logOut(User users[], int userId, int totalUsers) {
    for (int i = 0; i < totalUsers; i++) {
        if (users[i].userId == userId) {
            users[i].isLoggedIn = 0;
            printf("User logged out.\n");
            return;
        }
    }
    printf("Invalid user ID.\n");
}

// Show user profile
void showProfile(User users[], int totalUsers, int userId) {
    for (int i = 0; i < totalUsers; i++) {
        if (users[i].userId == userId) {
            printf("Username: %s\n", users[i].username);
            printf("First Name: %s\n", users[i].firstName);
            printf("Last Name: %s\n", users[i].lastName);
            printf("Date of Birth: %s\n", users[i].dob);
            printf("Mobile: %s\n", users[i].mobile);
            printf("Email: %s\n", users[i].email);
            printf("Status: %s\n", (users[i].isLoggedIn ? "Logged In" : "Logged Out"));
            return;
        }
    }
    printf("User ID not found.\n");
}

// Update user password
void updatePassword(User users[], int userId, char *newPassword) {
    for (int i = 0; i < userId; i++) {
        if (users[i].userId == userId) {
            strcpy(users[i].password, newPassword);
            printf("Password updated successfully.\n");
            return;
        }
    }
    printf("Invalid user ID.\n");
}

// Validate date of birth (format: DD/MM/YYYY)
int validateDOB(char *dob) {
    if (strlen(dob) != 10 || dob[2] != '/' || dob[5] != '/') {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(dob[i])) return 0;
    }
    return 1;
}

// Validate mobile number (must be digits and 10-14 characters)
int validateMobile(char *mobile) {
    int len = strlen(mobile);
    if (len < 10 || len > 14) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(mobile[i])) return 0;
    }
    return 1;
}

// First Menu: Register, Login, Exit
void firstMenu(User users[], int *userCount) {
    int choice, userId = 0;
    char username[50], firstName[50], lastName[50], dob[15], mobile[15], email[100], password[50];

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter first name: ");
                scanf("%s", firstName);
                printf("Enter last name: ");
                scanf("%s", lastName);

                do {
                    printf("Enter date of birth (DD/MM/YYYY): ");
                    scanf("%s", dob);
                    if (!validateDOB(dob)) {
                        printf("Invalid DOB format! Please use DD/MM/YYYY.\n");
                    }
                } while (!validateDOB(dob));

                do {
                    printf("Enter mobile number: ");
                    scanf("%s", mobile);
                    if (!validateMobile(mobile)) {
                        printf("Invalid mobile number! It should be 10-14 digits.\n");
                    }
                } while (!validateMobile(mobile));

                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter password: ");
                scanf("%s", password);

                addUser(users, userCount, username, firstName, lastName, dob, mobile, email, password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                userId = logIn(users, *userCount, username, password);

                if (userId) {
                    secondMenu(users, userId, *userCount);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);
}

// Second Menu: View Profile, Update Password, Logout, Exit
void secondMenu(User users[], int userId, int totalUsers) {
    int choice;
    char newPassword[50];

    do {
        printf("\n--- User Menu ---\n");
        printf("1. View Profile\n");
        printf("2. Update Password\n");
        printf("3. Logout\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showProfile(users, totalUsers, userId);
                break;

            case 2:
                printf("Enter new password: ");
                scanf("%s", newPassword);
                updatePassword(users, userId, newPassword);
                break;

            case 3:
                logOut(users, userId, totalUsers);
                printf("Logged out. Returning to main menu...\n");
                return;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
}

// Main function
int main() {
    User users[100];  // Array to store up to 100 users
    int userCount = 0;  // To keep track of the number of users

    firstMenu(users, &userCount);
    return 0;
}
