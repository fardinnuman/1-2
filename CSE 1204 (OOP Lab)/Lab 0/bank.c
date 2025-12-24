#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Bank {
    int acno;
    char name[50];
    float balance;
};

struct Bank accounts[MAX_ACCOUNTS];
int totalAccounts = 6;

void initializeAccounts();
int findAccount(int acno);
void newAccount();
void withdraw();
void deposit();
void fundTransfer();
void showBalance();

int main() {
    initializeAccounts();
    int choice;

    while (1) {
        printf("\n//...................Menu......................//\n");
        printf("1) New Account\n");
        printf("2) Withdrawal\n");
        printf("3) Deposit\n");
        printf("4) Fund Transfer\n");
        printf("5) Show Balance\n");
        printf("6) Exit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: newAccount(); break;
            case 2: withdraw(); break;
            case 3: deposit(); break;
            case 4: fundTransfer(); break;
            case 5: showBalance(); break;
            case 6:
                printf("\nExiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Initialize 6 default accounts
void initializeAccounts() {
    for (int i = 0; i < totalAccounts; i++) {
        accounts[i].acno = 1000 + i + 1;
        sprintf(accounts[i].name, "User%d", i + 1);
        accounts[i].balance = 1000.0f * (i + 1);
    }
}

// Find account by account number
int findAccount(int acno) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].acno == acno)
            return i;
    }
    return -1;
}

// Create new account
void newAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts.\n");
        return;
    }

    struct Bank newAcc;
    printf("Enter new account number: ");
    scanf("%d", &newAcc.acno);
    getchar(); // clear input buffer
    printf("Enter account holder name: ");
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0; // remove newline
    printf("Enter initial balance: ");
    scanf("%f", &newAcc.balance);

    accounts[totalAccounts++] = newAcc;
    printf("Account created successfully!\n");
}

// Withdraw money
void withdraw() {
    int acno;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acno);

    int idx = findAccount(acno);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[idx].balance) {
        printf("Invalid amount! Current balance: %.2f\n", accounts[idx].balance);
    } else {
        accounts[idx].balance -= amount;
        printf("Withdrawal successful! Updated balance: %.2f\n", accounts[idx].balance);
    }
}

// Deposit money
void deposit() {
    int acno;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acno);

    int idx = findAccount(acno);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[idx].balance += amount;
    printf("Deposit successful! Updated balance: %.2f\n", accounts[idx].balance);
}

// Transfer funds between accounts
void fundTransfer() {
    int fromAcc, toAcc;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &fromAcc);
    int fromIdx = findAccount(fromAcc);

    printf("Enter receiver's account number: ");
    scanf("%d", &toAcc);
    int toIdx = findAccount(toAcc);

    if (fromIdx == -1 || toIdx == -1) {
        printf("Invalid account number(s).\n");
        return;
    }

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (amount > accounts[fromIdx].balance) {
        printf("Insufficient balance! Current balance: %.2f\n", accounts[fromIdx].balance);
        return;
    }

    accounts[fromIdx].balance -= amount;
    accounts[toIdx].balance += amount;

    printf("Transfer successful!\n");
    printf("Your updated balance: %.2f\n", accounts[fromIdx].balance);
}

// Show account balance
void showBalance() {
    int acno;
    printf("Enter account number: ");
    scanf("%d", &acno);

    int idx = findAccount(acno);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("\nAccount Number: %d\n", accounts[idx].acno);
    printf("Name: %s\n", accounts[idx].name);
    printf("Current Balance: %.2f\n", accounts[idx].balance);
}