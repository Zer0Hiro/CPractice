#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account
{
	char* name;
	double balance;
	float history[100];
	int transacitons;
}Account;

typedef struct Bank
{
	char* name;
	Account* accounts;
	int check_amount;
}Bank;

void createAccount(Account* acc);
int add(Account* acc, int amount);
void transfer(Account* from, Account* to, int amount);
void printAccount(Account acc);

void createBank(Bank* bank);
void sort(Bank* bank);

int main()
{

}

// This function will create account
void createAccount(Account* acc)
{
	char tempName[100];
	printf("Enter your name: ");
	if (scanf("%s", tempName) != 1) 
		exit(1); // Error
	if ((acc->name = (char*)malloc(strlen(tempName) + 1)) == NULL)
		exit(1);
	strcpy(acc->name, tempName);
	acc->balance = acc->transacitons = 0;
}

// This function will check amount of money and transactions
int add(Account* acc, int amount)
{
	if (acc->transacitons >= 100)
		return 0;
	acc->balance += amount;
	acc->history[acc->transacitons++] = acc->balance;
}

void transfer(Account* from, Account* to, int amount)
{
	if (from->transacitons >= 100 || to->transacitons >= 100)
	{
		printf("\nFail");
		exit(1);
	}
	add(from, (-1) * amount);
	add(to, amount);
	printf("\nSuccess");
}

void printAccount(Account acc)
{
	int i;
	printf("\nNum Balance :");
	for (i = 0; i < acc.transacitons; i++)
	{
		printf("\n%lf %f", acc.balance, acc.history[i]);
	}
}

void createBank(Bank* bank)
{
	int i;
	char buffer[100];
	if (scanf("%s", buffer) != 1)
		exit(1);
	if ((bank->name = (char*)malloc(strlen(buffer) + 1)) == NULL) exit(1);
	
	strcpy(bank->name, buffer);

	if (scanf("%d", &bank->check_amount) != 1)
	{
		free(bank->name);
		exit(1);
	}
	
	if ((bank->accounts = (Account*)malloc(bank->check_amount * sizeof(Account))) == NULL)
	{
		free(bank->name);
		exit(1);
	}
	
	for (i = 0;i < bank->check_amount;i++)
		createAccount(&bank->accounts[i]);
}

void sort(Bank* bank)
{
	int i, j;
	Account temp;
	for(i = 0; i<bank->check_amount;i++)
	{	
		for (j = i;j < bank->check_amount;j++)
		{
			if (bank->accounts[i].balance > bank->accounts[j].balance)
			{
				temp = 
			}
		}
	}
}