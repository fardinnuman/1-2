<div align="center">

# <a href="https://archiveprogram.github.com/"><img src="https://raw.githubusercontent.com/acervenky/animated-github-badges/master/assets/acbadge.gif" width="26" height="25"></a> MyCash <a href="https://archiveprogram.github.com/"><img src="https://raw.githubusercontent.com/acervenky/animated-github-badges/master/assets/acbadge.gif" width="26" height="25"></a>

![C++](https://img.shields.io/badge/Programming-blue?style=for-the-badge\&logo=c%2B%2B\&logoColor=white)
  ![Course](https://img.shields.io/badge/CSE%201203-Object%20Oriented%20Programming-blue?style=for-the-badge&logo=read-the-docs&logoColor=white)

This **C++ program** was developed as a part of my **CSE 1203 (Object Oriented Programming)** course. It demonstrates intermediate concepts of the C++ language, including **classes, file I/O, vectors, enums, OTP generation and console manipulation**, simulating a mobile financial service **(myCash)** with **secure user authentication and transaction management**

</div>

---

<div align="center">

## ✨ FEATURES

</div>

### **I. User Account Management**

- 📝 **Registration**: New users can register with 11-digit mobile number, name and 5-digit PIN
- 🔑 **Login**: Secure login using mobile number and PIN
- ✏️ **Profile Management**: Update name and PIN with OTP verification
- ❌ **Account Removal**: Delete account permanently with OTP confirmation

> All user data is persistently stored in `members.txt`

### **II. Security Features**

- ⏰ **OTP Verification**: 4-digit OTP generated for sensitive operations (registration, PIN change, cash-out, send money, bill pay, account removal)
- ⏱ **OTP Expiry**: OTP expires after 120 seconds (2 minutes)
- 🔒 **Hidden PIN Input**: PIN entry masked with asterisks (`*`) using `_getch()`
- ✅ **PIN Confirmation**: Double PIN entry during registration and updates

### **III. Wallet Operations**

- 💰 **Cash In**: Add money to account
- 💸 **Cash Out**: Withdraw money from account
- 📲 **Send Money**: Transfer money between registered members
- 🧾 **Pay Bills**: Pay Gas, Electricity, Water, Internet bills
- 📊 **Check Balance**: View current account balance
- 📜 **Transaction History**: View all transactions with timestamps

> Transaction history is automatically saved in `history.txt` with unique transaction IDs and automated date & time stamps

### **IV. Transaction Types**

| Type | Description | OTP Required |
| --- | --- | --- |
| **Cash In** | Add money to account | ❌ No |
| **Cash Out** | Withdraw money from account | ✅ Yes |
| **Send Money** | Transfer money to another account | ✅ Yes |
| **Pay Bill** | Pay utility bills | ✅ Yes |

### **V. Bill Payment Options**

| Option | Bill Type | Fixed Amount |
| --- | --- | --- |
| 1 | Gas | 850.0 Taka |
| 2 | Electricity | 1250.0 Taka |
| 3 | Water | 480.0 Taka |
| 4 | Internet | 1000.0 Taka |

---

<div align="center">

## ⚙️ TECHNOLOGIES USED

| Category                   | Technology                        | Purpose                                                   |
| -------------------------- | --------------------------------- | --------------------------------------------------------- |
| **💻 Core Language**       | **C++ Programming**                           | Program logic, menus, wallet operations                   |
| **🧩 OOP Design**          | **Classes (`Member`, `History`)** | Model users and transaction records                       |
| **🗂 Data Structures**     | **`std::vector`**                 | Store multiple members dynamically                        |
| **📁 File Handling**       | **`ifstream`, `ofstream`**        | Persist data in `members.txt`, `history.txt`              |
| **🎲 Randomization**       | **`rand()`**                      | Generate OTP codes                                        |
| **⏱ Time Handling**        | **`time()`, `ctime()`**           | Timestamp transactions & OTP expiry                       |
| **🔤 String Processing**   | **`stringstream`, `getline`**     | CSV parsing & validation                                  |
| **🔐 Security System**     | OTP + Hidden PIN (`_getch()`)     | Secure sensitive operations                               |
| **🎨 Console UI**          | `windows.h` Color Control         | Highlight OTP in yellow                                   |
| **📦 Modular Programming** | Separate Functions                | `cashIn()`, `cashOut()`, `sendMoney()`, `payBill()` etc.  |
| **⚠️ Validation System**   | Input Checks                      | Mobile validation, balance checks, PIN length enforcement |

</div>

---

<div align="center">

## 🧩 USER INTERFACE | HOW IT WORKS?

</div>

### 🟢 0 | **Program Startup**

When you run it, the first output will be:

```cpp
WELCOME TO MyCash!

SUBMITTED BY:
FARDIN BIN ASLAM NUMAN
2403179 | CSE-C | 24 SERIES
```

---

### 🔐 1 | **Login Menu**

```cpp
*** MyCash Login ***
1. Login
2. Register
3. Exit
   Enter Your Option:
```

### 📝 1.1 | **Registration Flow**

- If you select option `2`:

```cpp
--- Register New Member ---
Enter Mobile No. (11-digit): 01406369675
Enter Name: Fardin Numan
Enter pin (5-digit): *****
Reconfirm pin: *****
myCash OTP: 1234  // displayed in YELLOW
Enter OTP: 1234
Registration is Successful
Press any key to go to main menu...
```

### 🔑 1.2 | **Login Flow**

- If you select option `1`:

```cpp
--- Login ---
Enter Mobile No. (11-digit): 01406369675
Enter pin: *****
Login is Successful
Welcome, Fardin Numan!
```

- If wrong PIN:

```cpp
Enter Mobile No. (11-digit): 01712345678
Enter pin: *****
Error: Invalid login
```

- If member doesn't exist:

```cpp
Enter Mobile No. (11-digit): 01987654321
Enter pin: *****
Error: Member NOT exists
```

---

### 🧩 2 | **Main Menu**

After successful login:

```cpp
********** MyCash Menu **********
1. Update Me
2. Remove Me
3. Send Money
4. Cash-in
5. Cash-out
6. Pay Bill
7. Check Balance
8. History
9. Logout
   Enter Your Option (1-9):
```

### ✏️ 2.1 | **Update Me (Option 1)**

```cpp
--- Update Member ---
Old Name: John Doe
New Name (enter to ignore): Fardin Numan
Old pin: *****
New pin (enter to ignore): *****
Confirm New pin: *****
myCash OTP: 5678  // displayed in YELLOW
Enter OTP: 5678
Update is Successful
```

### ❌ 2.2 | **Remove Me (Option 2)**

```cpp
--- Remove Account ---
myCash OTP: 9012  // displayed in YELLOW
Enter OTP: 9012
Remove is Successful
Back to MyCash Login Menu
```

### 📤 2.3 | **Send Money (Option 3)**

```cpp
--- Send Money ---
Enter Destination no. (11-digit): 01716096916
Enter Amount: 500
Sending 500 to 01716096916
Are you sure(Y/N)? y
myCash OTP: 7890  // displayed in YELLOW
Enter OTP: 7890
Send Money is Successful
```

- If destination no. doesn't exist:

```cpp
Enter Destination no. (11-digit): 01777777777
Error: Member NOT exists
```

- If destination no. is invalid:

```cpp
Enter Destination no. (11-digit): 017777
Error: Destination Mobile no. is invalid
```

- If sending to self:

```cpp
Enter Destination no. (11-digit): 01406369675
Error: Cannot send money to yourself
```

- If insufficient balance:

```cpp
Enter Amount: 10000
Error: Insufficient Fund
```

### 💵 2.4 | **Cash-in (Option 4)**

```cpp
--- Cash-in ---
Enter Amount: 5000
Cash-in 5000
Are you sure(Y/N)? y
Cash-in is Successful
```

### 💸 2.5 | **Cash-out (Option 5)**

```cpp
--- Cash-out ---
Enter Amount: 1000
Cash-out 1000
Are you sure(Y/N)? y
myCash OTP: 3456  // displayed in YELLOW
Enter OTP: 3456
Cash-out is Successful
```

- If insufficient balance:

```cpp
--- Cash-out ---
Enter Amount: 5000
Error: Insufficient Fund
```

### 🧾 2.6 | **Pay Bill (Option 6)**

```cpp
--- Pay Bill ---
Enter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4): 1
Your Gas Bill: 850
Want to pay(Y/N)? y
myCash OTP: 2468  // displayed in YELLOW
Enter OTP: 2468
Bill Payment is Successful
```

- If insufficient balance:

```cpp
Error: Insufficient Fund
```

### 📊 2.7 | **Check Balance (Option 7)**

```cpp
--- Check Balance ---
Balance: 2650
```

### 📜 2.8 | **History (Option 8)**

```cpp
--- History ---
Tran ID  Description     Amount  Balance
    101  Cash-in         5000    5000
    102  Cash-out        1000    4000
    103  Send Money      500     3500
    104  Bill Payment    850     2650
```

- If no transactions:

```cpp
--- History ---
No transactions found
```

### 🔓 2.9 | **Logout (Option 9)**

```cpp
Successfully logged out.
*** MyCash Login ***
1. Login
2. Register
3. Exit
   Enter Your Option:
```

---

### 🔴 3 | **Exit Program**

```cpp
   Enter Your Option: 3

THANK YOU FOR USING MyCash!
```

---

<div align="center">

## 📁 FILE STRUCTURE

</div>

```
/ (root)
├── MyCash.cpp                 # Source code
├── MyCash.exe                 # Executable file
├── members.txt                # User account data (created at runtime)
├── history.txt                # Transaction history (created at runtime)
└── README.md                  # Project documentation
```

### 📁 Data Logging System

### **members.txt**

```
01406369675,Fardin Numan,2650,40404
01716096915,Aslam,500,50505
```
* All members are stored in `members.txt`

### **history.txt**

```
101,01406369675,0,5000,5000,Fri Feb 27 21:59:31 2026
102,01406369675,1,1000,4000,Fri Feb 27 21:59:43 2026
103,01406369675,2,500,3500,Fri Feb 27 22:00:00 2026
104,01716096915,2,500,500,Fri Feb 27 22:00:00 2026
105,01406369675,3,850,2650,Fri Feb 27 22:00:10 2026
```
* All transactions are stored in `history.txt` 
  * Each transaction stores:
    * Transaction ID
    * Mobile Number
    * Type (Cash-in, Cash-out, Send Money, Bill Payment)
    * Amount
    * Balance After Transaction
    * Date & Time

> **Note:** Transaction types are stored as integers (0=CASH_IN, 1=CASH_OUT, 2=SEND_MONEY, 3=PAY_BILL)

## 🔐 OTP Security System

* OTP generated for:
  * Registration
  * PIN Change
  * Cash-out
  * Send Money
  * Bill Payment
  * Account Removal
* OTP expires after **120 seconds**
* OTP printed in **yellow console color**
* Validation prevents unauthorized transactions

---

<div align="center">

## ⚠️ ERROR HANDLING & VALIDATION

| Scenario | Error Message |
| --- | --- |
| Invalid mobile number | `Error: Invalid Mobile Number` |
| Member already exists | `Error: Member already exists` |
| PIN length invalid | `PIN must be 5 digits` |
| PIN mismatch | `Error: Pins must be same` |
| Wrong OTP | `Error: OTP does NOT matched` |
| Expired OTP | `Error: OTP time has expired` |
| Invalid amount | `Invalid amount. Amount must be positive` |
| Insufficient funds | `Error: Insufficient Fund` |
| Member not found | `Error: Member NOT exists` |
| Sending to self | `Error: Cannot send money to yourself.` |
| Invalid menu option | `Error: Invalid Option` |
| Invalid bill type | `Invalid bill type.` |
| Invalid Y/N choice | `Error: Enter Y or N` |

</div>