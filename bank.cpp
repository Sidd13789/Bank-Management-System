#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
	private:
		string accountHolder;
		int accountNumber;
		double balance;
	public:
		BankAccount(string name,int accNumber,double initialBalance)
		{
			accountHolder=name;
			accountNumber= accNumber;
			balance=initialBalance;
		}
		void deposit(double amount)
		{
			if(amount>0)
			{
				balance +=amount;
				cout<<"Deposit successful!New balance:"<<balance<<endl;
			}
			else
			{
				cout<<"Invalid deposit amount!"<<endl;
			}
		}
		void Withdraw(double amount)
		{
			if(amount>balance)
			{
				cout<<"Insufficient balance!"<<endl;
			}
			else
			{
				balance-=amount;
				cout<<"Withdraw successful!remaining balance:"<<balance<<endl;
			}
		}
		void checkBalance()
		{
			cout<<"current balance:"<<balance<<endl;
		}
};
int main()
{
	string name;
	int accNumber;
	double initialBalance;
	cout<<"Enter account holder's name:";
	getline(cin, name);
	cout<<"Enter a account number:";
	cin>>accNumber;
	cout<<"Enter initial balance";
	cin>>initialBalance;
	BankAccount myAccount(name,accNumber,initialBalance);
	int choice;
	do
	{
		cout<<"\nMenu:\n";
		cout<<"1:Deposit\n";
		cout<<"2:Withdraw\n";
		cout<<"3:checkbalance\n";
		cout<<"4:Exit\n";
		cout<<"Enter your choice:\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					double depositAmount;
					cout<<"Enter amount to deposit:";
					cin>>depositAmount;
					myAccount.deposit(depositAmount);
					break;
				}
			case 2:
				{
					double withdrawAmount;
					cout<<"Enter amount to withdraw:";
					cin>>withdrawAmount;
					myAccount.Withdraw(withdrawAmount);
					break;
				}
			case 3:
				myAccount.checkBalance();
				break;
			case 4:
				cout<<"Existing --"<<endl;
				break;
			default:
				cout<<"Invalid choice!please try again."<<endl;
		}
	}
	while(choice!=4);
	return 0;
}