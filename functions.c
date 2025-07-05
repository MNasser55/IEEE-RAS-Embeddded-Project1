
//hagar Marzouk
// functions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void load_data(Customer customers[], int *count) { // function to load customer data from a file
    FILE *fp = fopen("customers.txt", "r");// Open the file "customers.txt" for reading

    if (fp == NULL) return; // If the file doesn't exist, exit the function

    while (fscanf(fp, "%d %4s %s %s %f", // Read each customer's data from the file until end-of-file
                  &customers[*count].id,
                  &customers[*count].password,       // Read customer ID
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
        fprintf(fp, "%d %4s %s %s %.2f\n",       // Write customer data in one line
                customers[i].id,            // Write customer ID
                customers[i].password,      //write the password
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

        // بندور هل الـ ID ده موجود قبل كده ولا لأ
        if (findCustomerIndex(customers, *count, ID) == -1) break;
                char choice;
                // لو موجود بنسأله عايز يعدل بياناته بدل ما يضيفه تاني؟
                printf("This ID already exists.\nDo you want to edit this customer instead? (Y/N): ");
                scanf(" %c", &choice);
                while ((getchar()) != '\n');  // تنظيف البفر من أي مدخلات زيادة

                if (choice == 'Y' || choice == 'y') {
                    // لو قال اه بنديله فانكشن التعديل ونرجع
                    edit_customer(customers, *count);
                    return;

            }
        }


    // بنخزن الـ ID اللي ادخله المستخدم
    customers[*count].id = ID;
    printf("Enter Name: ");
    scanf("%s", customers[*count].name); // بنقرأ الاسم
    while ((getchar()) != '\n');
    printf("Enter Password (4 digits): ");
    scanf("%4s", customers[*count].password);
    while ((getchar()) != '\n');//نقري الباسورد
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
    int  id = safeInputInt("\nEnter ID to edit: ");
    int index = findCustomerIndex(customers, count, id);

    if (index == -1) {
        printf("Customer not found!\n");
        return;
    }

        while (1) {
       char password[5];
    printf("Enter your password: ");
    scanf("%4s", password);
    while ((getchar()) != '\n');
    if (strcmp(customers[index].password, password) == 0) break;
        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    printf("Enter New Name: ");
    scanf("%s", customers[index].name);
    printf("Enter New Phone: ");
    scanf("%s", customers[index].phone);
    printf("Customer updated successfully.\n");
}

void view_customer(Customer customers[], int count) {
    // دالة لعرض بيانات عميل معين
    int id = safeInputInt("\nEnter ID to view: ");
     int index = findCustomerIndex(customers, count, id);
      if (index == -1) {
        printf("Customer not found!\n");// لو ملقيناش العميل
        return;
    }

 while (1) {
        char password[5];
        printf("Enter your password: ");
        scanf("%4s", password);
        while ((getchar()) != '\n');
if (strcmp(customers[index].password, password) == 0) break;

        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    printf("\nID: %d\nName: %s\nPhone: %s\nBalance: %.2f\n",
           customers[index].id,
           customers[index].name,
           customers[index].phone,
           customers[index].balance);
}


void delete_customer(Customer customers[], int *count) {
    // دالة لحذف عميل من الليستة
    int id = safeInputInt("\nEnter ID to delete: ");
    int index = findCustomerIndex(customers, *count, id);

     if (index == -1) {
        printf("Customer not found!\n");
        return;
    }

         while (1) {
       char password[5];
       printf("Enter your password: ");
       scanf("%4s", password);
       while ((getchar()) != '\n');
       if (strcmp(customers[index].password, password) == 0) break;

        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    // تنفيذ الحذف
    for (int j = index; j < (*count) - 1; j++) {
        customers[j] = customers[j + 1];
    }

    (*count)--; // تقليل عدد العملاء
    printf("Customer deleted successfully.\n");
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

   int from = findCustomerIndex(customers, count, id_from);
    int to = findCustomerIndex(customers, count, id_to);

    // If IDs are invalid, show message and stop
    if (from == -1 || to == -1) {
        printf("\nInvalid IDs!\n");
        return;
    }

    while (1) {
        char password[5];
        printf("Enter your password: ");
        scanf("%4s", password);
        while ((getchar()) != '\n');
if (strcmp(customers[from].password, password) == 0) break;
        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    if (customers[from].balance < amount) {
        printf("Insufficient funds!\n");
        return;
    }

    printf("\nAre you sure you want to transfer %.2f L.E from ID: %d (%s) to ID: %d (%s)? (Y/N): ",
           amount,
           id_from, customers[from].name,
           id_to, customers[to].name);

    char confirm;
    scanf(" %c", &confirm);
    while (getchar() != '\n');
    if (confirm != 'Y' && confirm != 'y') {
        printf("Transfer cancelled.\n");
        return;
    }

    customers[from].balance -= amount;
    customers[to].balance += amount;
    printf("Transfer done successfully!\n");
}


//deposit
void deposit(Customer customers[], int count) {
    // Declare variable for customer ID and Get customer ID using safe input
    int id = safeInputInt("\nEnter ID: ");
    int index = findCustomerIndex(customers, count, id); //try to find the user


if (index == -1) {
        printf("Customer not found!\n");
        return;
    }

    while (1) {
        char password[5];
        printf("Enter your password: ");
        scanf("%4s", password);
        while ((getchar()) != '\n');
if (strcmp(customers[index].password, password) == 0) break; //get the password

        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    float amount = safeInputFloat("Enter amount to deposit: "); // Get amount using safe input
    if (amount < 0) {
        printf("Invalid amount!\n");// Check if amount is valid (must be greater than 0)
        return;
    }

    customers[index].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", customers[index].balance);
}



//withdraw
void withdraw(Customer customers[], int count) {
    // Declare variable for customer ID
    int id = safeInputInt("\nEnter ID: ");
    int index = findCustomerIndex(customers, count, id);//try to find the user

if (index == -1) {
        printf("Customer not found!\n");
        return;
    }


     while (1) {
        char password[5];
        printf("Enter your password: ");
        scanf("%4s", password);
        while ((getchar()) != '\n');
if (strcmp(customers[index].password, password) == 0) break;
        char retry;
        printf("Wrong password! Try again? (Y/N): ");
        scanf(" %c", &retry);
        while (getchar() != '\n');
        if (retry != 'Y' && retry != 'y') return;
    }

    float amount = safeInputFloat("Enter amount to withdraw: ");    // Get amount to withdraw using safe input
    if (amount <= 0) {
        printf("Invalid amount!\n");// Check if amount is valid (must be greater than 0)
        return;
    }

    if (customers[index].balance >= amount) {
        customers[index].balance -= amount;
        printf("Withdraw successful! Remaining balance: %.2f\n", customers[index].balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to clear the screen using system command
void clearScreen() {
    system("cls"); // Clear console screen on Windows
}

 // added by Nasser
int findCustomerIndex(Customer customers[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) return i;
    }
    return -1;
}
