//BankManagementSystem.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for holding account information
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void balanceInquiry();
void modifyAccount();
void displayMenu();
void loadData();
void saveData();

// Global variables
struct Account accounts[100];
int accountCount = 0;

int main() {
    int choice;

    loadData();

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                balanceInquiry();
                break;
            case 5:
                modifyAccount();
                break;
            case 6:
                saveData();
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\nBank Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Balance Inquiry\n");
    printf("5. Modify Account\n");
    printf("6. Exit\n");
}

void createAccount() {
    if (accountCount >= 100) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void balanceInquiry() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account holder: %s\n", accounts[i].name);
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void modifyAccount() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter new name: ");
            scanf("%s", accounts[i].name);
            printf("Account details updated successfully!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void loadData() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fread(&accountCount, sizeof(int), 1, file);
    fread(accounts, sizeof(struct Account), accountCount, file);
    fclose(file);
}

void saveData() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Error saving data.\n");
        return;
    }
    fwrite(&accountCount, sizeof(int), 1, file);
    fwrite(accounts, sizeof(struct Account), accountCount, file);
    fclose(file);
}