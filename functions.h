
// === FUNCTIONS.H === By Nasser
// Struct and function prototypes with documentation

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_CUSTOMERS 100 // Max number of customers

typedef struct {
    int id;             // Customer ID
    char name[100];     // Customer name
    char phone[20];     // Phone number
    float balance;      // Account balance
} Customer;

// Function prototypes
void load_data(Customer customers[], int *count);
void save_data(Customer customers[], int count);
void create_customer(Customer customers[], int *count);
void edit_customer(Customer customers[], int count);
void view_customer(Customer customers[], int count);
void delete_customer(Customer customers[], int *count);
void transfer_money(Customer customers[], int count);
void deposit(Customer customers[], int count);
void withdraw(Customer customers[], int count);
int safeInputInt(const char *prompt);
float safeInputFloat(const char *prompt);
void clearScreen();

#endif
