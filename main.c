
// === MAIN.C === By Nasser
// Main program with user interface (menu) and documentation

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Customer customers[MAX_CUSTOMERS]; //create an array of struct
    int count = 0; // to count the num of customers i have
    int choice; //the choice will control to the below while
    char continueChoice = 'y'; // Intial choice

    load_data(customers, &count); //get the information of the system file to the array of struct

    while (continueChoice == 'y' || continueChoice == 'Y') {
        clearScreen();

        printf("=== BANK CUSTOMER MANAGEMENT SYSTEM ===\n");
        printf("1. Add Customer\n");
        printf("2. Edit Customer\n");
        printf("3. View Customer\n");                       //making a nice menu to choose
        printf("4. Delete Customer\n");
        printf("5. Transfer Money\n");
        printf("6. Deposit\n");
        printf("7. Withdraw\n");
        printf("8. Save & Exit\n");
        choice = safeInputInt("Enter your choice: "); //this function tp make sure the input is num not a character


   switch (choice) {  //switch case to do the order of the user
case 1:
    create_customer(customers, &count);
    save_data(customers, count); // and making sure the data saved after the process
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
    return 0;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to perform another operation? (y/n): "); //to repeat the while again and in another meaning to return to the menu
        fflush(stdin); //
        scanf(" %c", &continueChoice);
        while ((getchar()) != '\n');
    }

    printf("Thank you for using our system!\n"); //The End
    return 0;
}

