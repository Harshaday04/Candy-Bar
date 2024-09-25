#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

// Structure to store user information
typedef struct {
    int userId;          // User's ID
    char username[50];   // Username
    char firstName[50];  // First name
    char lastName[50];   // Last name
    char dob[15];        // Date of birth (format: DD/MM/YYYY)
    char mobile[15];     // Mobile number
    char email[100];     // Email
    char password[50];   // Password
    int isLoggedIn;      // 1 if logged in, 0 if not
} User;

// Function declarations
int addUser(User users[], int *userCount, char *username, char *firstName, char *lastName, char *dob, char *mobile, char *email, char *password);
int logIn(User users[], int userCount, char *username, char *password);
void logOut(User users[], int userId, int totalUsers);
void showProfile(User users[], int totalUsers, int userId);
void updateProfile(User users[], int userId, char *newEmail);
void updatePassword(User users[], int userId, char *newPassword);
int validateDOB(char *dob);
int validateMobile(char *mobile);

// Menus
void firstMenu(User users[], int *userCount);
void secondMenu(User users[], int userId, int totalUsers);

#endif
