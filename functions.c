// functions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
//hagar Marzouk
void load_data(Customer customers[], int *count) { // function to load customer data from a file
    FILE *fp = fopen("customers.txt", "r");// Open the file "customers.txt" for reading

    if (fp == NULL) return; // If the file doesn't exist, exit the function

    while (fscanf(fp, "%d %s %s %f", // Read each customer's data from the file until end-of-file
                  &customers[*count].id,       // Read customer ID
                  customers[*count].name,      // Read customer name
                  customers[*count].phone,     // Read customer phone number
                  &customers[*count].balance)  // Read customer balance
           != EOF) {
        (*count)++; // Increase the count after reading each customerD
    }

    // Close the file after reading
    fclose(fp);
}
void save_data(Customer customers[], int count) {   // function to save all customer data after finished
    FILE *fp = fopen("customers.txt", "w");  //Open the file "customers.txt" for writing (overwrite mode)

    if(fp == NULL) return;  // If the file cannot be opened, exit the function

    for (int i = 0; i < count; i++) {  // Loop through all customers and write their data to the file
        fprintf(fp, "%d %s %s %.2f\n",       // Write customer data in one line
                customers[i].id,            // Write customer ID
                customers[i].name,          // Write customer name
                customers[i].phone,         // Write customer phone number
                customers[i].balance);      // Write customer balance
    }

    // Close the file after saving
    fclose(fp);
}
