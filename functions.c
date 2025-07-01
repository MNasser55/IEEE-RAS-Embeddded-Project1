
//hagar Marzouk
// functions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

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

//added By Nasser
int safeInputInt(const char *prompt) { // this function made for make sure the input is num not character (for int)
    char buffer[100];
    int value;
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) { //here when sscan see a character will failed and return 0
            return value;
        } else {
            printf("Invalid input! Please enter a number.\n");
        }
    }
}

float safeInputFloat(const char *prompt) {// this function made for make sure the input is num not character but (for float)
    char buffer[100];
    float value;
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &value) == 1) {//here when sscan see a character will failed and return 0
            return value;
        } else {
            printf("Invalid input! Please enter a valid amount.\n");
        }
    }
}

// added by kareem_kotb
void create_customer(Customer customers[], int *count) {
    // بنشيك الأول لو عدد العملاء وصل الحد الأقصى
    int ID;
    if (*count >= MAX_CUSTOMERS) {
        printf("Database full!\n");
        return;
    }

    // بنفضل نطلب ID لحد ما يبقى جديد مش مكرر
    while (1) {

        // بناخد ID من اليوزر باستخدام فانكشن بتضمن إنه صحيح
        ID = safeInputInt("\nEnter ID: ");

        int exists = 0;
        // بندور هل الـ ID ده موجود قبل كده ولا لأ
        for (int i = 0; i < *count; i++) {
            if (ID == customers[i].id) {
                exists = 1;
                char choice;
                // لو موجود بنسأله عايز يعدل بياناته بدل ما يضيفه تاني؟
                printf("This ID already exists.\nDo you want to edit this customer instead? (Y/N): ");
                scanf(" %c", &choice);
                while ((getchar()) != '\n');  // تنظيف البفر من أي مدخلات زيادة

                if (choice == 'Y' || choice == 'y') {
                    // لو قال اه بنديله فانكشن التعديل ونرجع
                    edit_customer(customers, *count);
                    return;
                } else {
                    // لو قال لأ، بنطلب ID جديد
                    printf("Please enter a different ID.\n");
                    break;
                }
            }
        }
        // لو الـ ID مش مكرر بنخرج من اللوب ونكمل
        if (!exists) break;
    }

    // بنخزن الـ ID اللي ادخله المستخدم
    customers[*count].id = ID;
    printf("Enter Name: ");
    scanf("%s", customers[*count].name);  // بنقرأ الاسم

    printf("Enter Phone: ");
    scanf("%s", customers[*count].phone);  // بنقرأ رقم التليفون

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // تنظيف البفر من أي حاجة بعد scanf

    customers[*count].balance = safeInputFloat("Enter Initial Balance: ");  // بندخل الرصيد

    // لو الرصيد بالسالب بنرفض الإدخال
    if (customers[*count].balance < 0) {
        printf("Balance cannot be negative!\n");
        return;
    }

    // لو كل حاجة تمام بنزود العداد
    (*count)++;
    printf("Customer added successfully.\n");
}


void edit_customer(Customer customers[], int count) {
    // دالة لتعديل بيانات عميل موجود
    int id, found = 0;
    id = safeInputInt("\nEnter ID to edit: ");
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه، بنطلب الاسم الجديد والتليفون
            printf("Enter New Name: ");
            scanf("%s", customers[i].name);
            printf("Enter New Phone: ");
            scanf("%s", customers[i].phone);
            printf("Updated successfully.\n");
            found = 1;
            break;
        }
    }
    // لو ملقيناش الـ ID بنقول للمستخدم
    if (!found) printf("Customer not found!\n");
}

void view_customer(Customer customers[], int count) {
    // دالة لعرض بيانات عميل معين
    int id, found = 0;
    id = safeInputInt("\nEnter ID to view: ");
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه بنطبع البيانات بتاعته
            printf("\nID: %d\nName: %s\nPhone: %s\nBalance: %.2f\n",
                   customers[i].id, customers[i].name,
                   customers[i].phone, customers[i].balance);
            found = 1;
            break;
        }
    }
    // لو ملقيناش العميل
    if (!found) printf("Customer not found!\n");
}

void delete_customer(Customer customers[], int *count) {
    // دالة لحذف عميل من الليستة
    int id, found = 0;
    id = safeInputInt("\nEnter ID to delete: ");
    for (int i = 0; i < *count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه، بنحرك باقي العملاء فوقه علشان نحذف
            for (int j = i; j < (*count) - 1; j++) {
                customers[j] = customers[j + 1];
            }
            // نقلل العداد بعد الحذف
            (*count)--;
            printf("\nCustomer deleted.\n");
            found = 1;
            break;
        }
    }
    // لو ملقيناش العميل
    if (!found) printf("\nCustomer not found!\n");
}

                    // === Added by Ibrahim ===

// Transfer
void transfer_money(Customer customers[], int count) {
    int id_from, id_to; // Declare sender and receiver IDs
    float amount;       // Declare amount to transfer

    // Get sender ID using safe input
    id_from = safeInputInt("\nSender ID: ");
    // Get receiver ID using safe input
    id_to = safeInputInt("Receiver ID: ");
    // Get transfer amount using safe input
    amount = safeInputFloat("Amount: ");

    int from = -1, to = -1; // Initialize indexes for sender and receiver

    // Find sender and receiver in array
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id_from) from = i; // Save sender index
        if (customers[i].id == id_to) to = i;     // Save receiver index
    }

    // If IDs are invalid, show message and stop
    if (from == -1 || to == -1) {
        printf("\nInvalid IDs!\n");
        return;
    }

    // If not enough balance, show message and stop
    if (customers[from].balance < amount) {
        printf("\nInsufficient funds!\n");
        return;
    }


    // Ask for confirmation — now shows ID and name for both
    printf("\nAre you sure you want to transfer %.2f L.E from ID: %d (%s) to ID: %d (%s)? (Y/N): ",
           amount,
           id_from, customers[from].name, // Show sender name
           id_to, customers[to].name);    // Show receiver name

    char confirm = 'N'; // Initialize confirmation char
    scanf("%c", &confirm); // Read confirmation

    // If user cancels with anything other than Y/y
    if (confirm != 'Y' && confirm != 'y') {
        printf("Transfer cancelled.\n");
        return;
    }

    // Subtract from sender's balance
    customers[from].balance -= amount;
    // Add to receiver's balance
    customers[to].balance += amount;

    // Show success message
    printf("Transfer done successfully!\n");
}


//deposit
void deposit(Customer customers[], int count) {
    // Declare variable for customer ID
    int id;
    // Declare variable for amount to deposit
    float amount;

    // Get customer ID using safe input
    id = safeInputInt("\nEnter ID: ");
    // Get amount using safe input
    amount = safeInputFloat("Enter amount: ");

    // Check if amount is negative
    if (amount < 0) {
        printf("Invalid amount. The amount should be positive\n"); // Show error if amount is invalid
        return; // Stop function
    }

    // Loop through all customers to find ID
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            customers[i].balance += amount; // Add amount to balance
            printf("Deposit done.\n"); // Show success message
            return; // Stop function after deposit
        }
    }

    // If ID not found
    printf("Customer not found!\n");
}


//withdraw
void withdraw(Customer customers[], int count) {
    // Declare variable for customer ID
    int id;
    // Declare variable for amount to withdraw
    float amount;

    // Get customer ID using safe input
    id = safeInputInt("\nEnter ID: ");
    // Get amount to withdraw using safe input
    amount = safeInputFloat("Enter amount: ");

    // Check if amount is valid (must be greater than 0)
    if (amount <= 0) {
        printf("Invalid amount! The amount should be positive\n"); // Show error if invalid
        return; // Stop function
    }

    // Loop through all customers to find matching ID
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            // Check if customer has enough balance
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount; // Subtract amount
                printf("Withdraw done.\n"); // Show success message
            } else {
                printf("Insufficient funds.\n"); // Not enough money
            }
            return; // Stop after processing
        }
    }

    // If customer ID not found
    printf("Customer not found!\n");
}

// Function to clear the screen using system command
void clearScreen() {
    system("cls"); // Clear console screen on Windows
}

