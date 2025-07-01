
                    // === Added by Ibrahim ===

// Transfer
void transfer_money(Customer customers[], int count) {
    int id_from, id_to; // Declare sender and receiver IDs
    float amount;       // Declare amount to transfer

    // Get sender ID using safe input
    id_from = safeInputInt("Sender ID: ");
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
        printf("Invalid IDs!\n");
        return;
    }

    // If not enough balance, show message and stop
    if (customers[from].balance < amount) {
        printf("Insufficient funds!\n");
        return;
    }


    // Ask for confirmation — now shows ID and name for both
    printf("Are you sure you want to transfer %.2f L.E from ID: %d (%s) to ID: %d (%s)? (Y/N): ",
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
    id = safeInputInt("Enter ID: ");
    // Get amount using safe input
    amount = safeInputFloat("Enter amount: ");

    // Check if amount is negative
    if (amount < 0) {
        printf("Invalid amount.\n"); // Show error if amount is invalid
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
    id = safeInputInt("Enter ID: ");
    // Get amount to withdraw using safe input
    amount = safeInputFloat("Enter amount: ");

    // Check if amount is valid (must be greater than 0)
    if (amount <= 0) {
        printf("Invalid amount!\n"); // Show error if invalid
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