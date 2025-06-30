
// === MAIN.C ===
// Main program with user interface (menu) and documentation

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Customer customers[MAX_CUSTOMERS];
    int count = 0;
    int choice;
    char continueChoice = 'y';

    load_data(customers, &count);

    while (continueChoice == 'y' || continueChoice == 'Y') {
        clearScreen();

        printf("=== BANK CUSTOMER MANAGEMENT SYSTEM ===\n");
        printf("1. Add Customer\n");
        printf("2. Edit Customer\n");
        printf("3. View Customer\n");
        printf("4. Delete Customer\n");
        printf("5. Transfer Money\n");
        printf("6. Deposit\n");
        printf("7. Withdraw\n");
        printf("8. Save & Exit\n");
        choice = safeInputInt("Enter your choice: ");


   switch (choice) {
case 1:
    create_customer(customers, &count);
    save_data(customers, count);
    break;
case 2:
    edit_customer(customers, count);
    save_data(customers, count);
    break;
case 3:
    view_customer(customers, count);
    break;
case 4:
    delete_customer(customers, &count);
    save_data(customers, count);
    break;
case 5:
    transfer_money(customers, count);
    save_data(customers, count);
    break;
case 6:
    deposit(customers, count);
    save_data(customers, count);
    break;
case 7:
    withdraw(customers, count);
    save_data(customers, count);
    break;
case 8:
    printf("Exiting... Data saved!\n");
    break;

            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        fflush(stdin);
        scanf(" %c", &continueChoice);
    }

    printf("Thank you for using our system!\n");
    return 0;
}

