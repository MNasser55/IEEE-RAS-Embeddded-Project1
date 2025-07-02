# Bank Customer Management System

🧾 **Project Overview**  
A simple C-based command-line banking system that manages customer records using a static array of structures. The program allows adding, editing, deleting, and viewing customers, along with essential banking operations such as money transfer, deposit, and withdrawal. All data is stored persistently in a text file (`customers.txt`).

---

## 📁 Project Structure
```
├── main.c          // Main menu logic and user interface
├── functions.c     // Business logic and operations
├── functions.h     // Structs and function declarations
├── customers.txt   // Data storage file (generated automatically)
```

---

## 🔧 Features
- Add a new customer with password protection  
- Edit and view customer details after verifying password  
- Delete customers after verifying password  
- Deposit & withdraw money with validation and password checks  
- Transfer money between customers with confirmation step  
- All changes saved immediately to `customers.txt`  
- Input validation using custom `safeInputInt` and `safeInputFloat`  
- Static array for customer storage (up to 100 customers)  

---

## 🧠 Data Model
```c
typedef struct {
    int id;
    char password[5];
    char name[100];
    char phone[20];
    float balance;
} Customer;
```

---

## ▶️ How to Compile and Run
**Compile**
```bash
gcc main.c functions.c -o bank_system
```

**Run**
```bash
./bank_system   # or .\bank_system.exe on Windows
```

---

## 📌 Security Features
- Password verification for all sensitive operations  
- Prompts for retry or cancellation upon incorrect password  
- Uses safe input functions to handle invalid user input  

---

## 👥 Team Members

| Name           | Task Description                         |
|----------------|-------------------------------------------|
| Mohamed Nasser | Team Leader, system integration          |
| Kareem         | Deposit / Withdraw functionality         |
| Ibrahim        | Transfer & security logic                |
| Hagar Marzouk  | Data loading/saving & structure          |

---

## 🛠 Technologies Used
- C Language (GCC Compiler)  
- Git & GitHub for collaboration  
- Static array structure (no dynamic allocation)  
- Windows Command Line / Linux Terminal  

---

## 💡 What We Learned
- Modular programming in C  
- File I/O handling (save/load)  
- Input validation & buffer clearing  
- Team collaboration using Git branches & pull requests  

---

## 📬 Notes
- The system uses a static array with a maximum of 100 customers.  
- File `customers.txt` is automatically created if not found.  
- All operations instantly update the stored file.  

---

©️ IEEE-RAS Embedded Project 1 Team – 2025