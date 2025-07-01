# BANK CUSTOMER MANAGEMENT SYSTEM

## 📌 Project Overview

This project is a **Bank Customer Management System** written in C, built as part of the IEEE-RAS Embedded Project 1. The system manages customer data, including creation, editing, deletion, money transfer, deposits, and withdrawals.

It is a **menu-driven console application** that stores and retrieves data from a text file (`customers.txt`) using structured programming and modular design.

---

## ⚙️ How to Run the Project

### 1. Clone the Repository

```bash
git clone https://github.com/MNasser55/IEEE-RAS-Embeddded-Project1.git
cd IEEE-RAS-Embeddded-Project1
```

### 2. Compile the Project

```bash
gcc main.c functions.c -o bank_system
```

### 3. Run the Program

```bash
./bank_system
```

### 4. Files Required

Ensure the following files are in the same directory:

* `main.c`
* `functions.c`
* `functions.h`
* `customers.txt` (will be created if not present)

---

## 🧠 Project Structure

### `main.c`

* Displays the menu.
* Calls appropriate functions based on user input.
* Manages user interaction loop.

### `functions.c`

* Contains all business logic and file operations.
* Main functions include:

  * `create_customer`
  * `edit_customer`
  * `view_customer`
  * `delete_customer`
  * `transfer_money`
  * `deposit`
  * `withdraw`
  * `load_data`
  * `save_data`

### `functions.h`

* Contains structure definitions and function prototypes.

### `customers.txt`

* Data file storing customer information persistently.

---

## 👥 Team Members and Tasks

| Name            | Task Description                           |
| --------------- | ------------------------------------------ |
| Mohamed Nasser  | Project leader, system design, integration |
| Ibrahim Mohamed | Handled deposit/withdraw functions         |
| Kareem Kotb     | Responsible for customer data structure    |
| Hagar Marzouk   | File I/O and persistence                   |

---

## 💡 Features Implemented

* Add/Edit/Delete customers
* View customer by ID
* Transfer money between accounts
* Deposit and withdraw money with validation
* Save and load data from text file
* Safe input handling to prevent crashes

---

## 💻 Input Example

```
=== BANK CUSTOMER MANAGEMENT SYSTEM ===
1. Add Customer
2. Edit Customer
...
Enter your choice: 1
Enter ID: 1001
Enter Name: Ahmed Ali
Enter Phone: 01012345678
Enter Initial Balance: 5000
Customer added successfully.
```

---

## 📁 GitHub Collaboration Process

* Each member worked on a separate **branch**.
* Pull Requests (PRs) were used to merge into `main`.
* All PRs reviewed by team leader before merging.
* Git history shows active contributions per member.

---

## 🏁 Final Notes

* The code is well-organized with clean structure and comments.
* Input validation functions were used to avoid invalid entries.
* The system is expandable for future improvements (e.g., password security, search by name).

> "This project demonstrates our ability to work in teams using GitHub, write modular C code, and build a reliable user-facing application."

---

Made for IEEE-RAS Embedded Project 1 by>>> NODE1 💪🏻.
