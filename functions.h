// === FUNCTIONS.H === By Nasser
// Struct and function prototypes with documentation

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_CUSTOMERS 100 // Max number of customers

typedef struct {
    int id;             // Customer ID
    char password[5];       // Customer password
    char name[100];     // Customer name
    char phone[20];     // Phone number
    float balance;      // Account balance
} Customer;

// === File I/O Functions ===
void load_data(Customer customers[], int *count);
void save_data(Customer customers[], int count);

// === Core Functionalities ===
void create_customer(Customer customers[], int *count);
void edit_customer(Customer customers[], int count);
void view_customer(Customer customers[], int count);
void delete_customer(Customer customers[], int *count);

// === Banking Operations ===
void transfer_money(Customer customers[], int count);
void deposit(Customer customers[], int count);
void withdraw(Customer customers[], int count);

// === Utility Functions ===
int safeInputInt(const char *prompt);
float safeInputFloat(const char *prompt);
int findCustomerIndex(Customer customers[], int count, int id);
void clearScreen();

#endif
