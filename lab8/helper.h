#include <iostream>

void ValidInput(int &input);
void ValidInput(double &input);

class bankAccount
{
private:
    int accNo;
    double balance;

public:
    bankAccount() : accNo(0), balance(0) {}
    virtual void setInterest() = 0;
    virtual double retrieveInterest() = 0;
    virtual void setMinBalance() {}
    virtual double retrieveMinBalance() { return 0; }
    virtual void setServiceCharge() {}
    virtual double retrieveServiceCharge() { return 0; }
    virtual double postInterest() { return 0; }

    virtual void setAccNo()
    {
        int temp = 0;
        std::cout << "Enter a acc no. in digits: ";
        std::cin >> temp;
        ValidInput(temp);
        accNo = temp;
    }
    virtual int getAccNo() { return accNo; }

    virtual double retrieveBalance()
    {
        return balance;
    }

    virtual void setBalance(double _balance)
    {
        this->balance = _balance;
    }
    virtual void deposit()
    {
        double temp = 0;
        std::cout << "Enter the amount: ";
        std::cin >> temp;
        ValidInput(temp);
        balance += temp;
        std::cout << "Deposit successfull\n";
    }
    virtual void widraw()
    {
        double temp = 0;
        std::cout << "Enter the amount you want to widraw: ";
        std::cin >> temp;
        ValidInput(temp);
        if (temp <= balance)
        {
            balance -= temp;
            std::cout << "widraw successful\n";
        }
        else
            std::cout << "You don't have sufficient balance\n";
    }
    virtual void print()
    {
        std::cout << "Account No: " << accNo << std::endl;
        std::cout << "Balance   : " << balance << std::endl;
    }
    virtual void menu()
    {
        std::cout << "\n\n-----Menu------\n";
        std::cout << "01. Check your Account Number\n";
        std::cout << "02. Enter balance\n";
        std::cout << "03. Check your current balance\n";
        std::cout << "04. Set Interest rate\n";
        std::cout << "05. Check your current Interest rate\n";
        std::cout << "06. See all your account's details\n";
        std::cout << "07. Deposit money\n";
        std::cout << "08. Withdraw money\n";
        std::cout << "09. Check post Interest\n";
    }
};
class checkingAccount : public bankAccount
{
    double minBalance;
    double interest;
    double serviceCharge;

public:
    checkingAccount() : bankAccount(), minBalance(0.0), serviceCharge(0.0) {}
    void setBalance(double _balance)
    {
        bankAccount::setBalance(_balance);
    }
    double retrieveBalance()
    {
        return bankAccount::retrieveBalance();
    }
    void setAccNo()
    {
        bankAccount::setAccNo();
    }
    int getAccNo()
    {
        return bankAccount::getAccNo();
    }

    void widraw()
    { /**
       * @brief Widraw funciton
       * if your balance fall below minimum balance limit it deducts service charge from your account
       * However, if your balance is already less than minimum balance limit then you can not widraw
       */

        if (bankAccount::retrieveBalance() < minBalance)
            std::cout << "Error:Your Balance is less than minimum balance limit!" << std::endl;
        else
        {
            bankAccount::widraw();
            if (bankAccount::retrieveBalance() < minBalance)
            {
                bankAccount::setBalance(bankAccount::retrieveBalance() - serviceCharge);
                std::cout << "Service charge " << serviceCharge << " has been deducted from your account due to exceding minimum Balance limit\n";
            }
        }
    }
    void setInterest()
    {
        std::cout << "Enter Interest rate: " << std::endl;
        std::cin >> interest;
        ValidInput(interest);
    }
    double retrieveInterest()
    {
        return interest;
    }
    void setMinBalance()
    {
        std::cout << "Enter the minimum balance: ";
        std::cin >> minBalance;
        ValidInput(minBalance);
    }
    double retrieveMinBalance()
    {
        return minBalance;
    }
    void setServiceCharge()
    {
        std::cout << "Enter the service charge: ";
        std::cin >> serviceCharge;
        ValidInput(serviceCharge);
    }
    double retrieveServiceCharge()
    {
        return serviceCharge;
    }

    double postInterest()
    {
        int temp = 0;
        temp = bankAccount::retrieveBalance();
        return temp - (temp * interest);
    }
    void print()
    {
        bankAccount::print();
        std::cout << "Interest       : " << interest << std::endl;
        std::cout << "Minimum balance: " << minBalance << std::endl;
        std::cout << "Service charge : " << serviceCharge << std::endl;
        std::cout << "Money after deduction of interest: " << postInterest() << std::endl;
    }

    void menu()
    {
        bankAccount::menu();
        std::cout << "10. Set minimum balance limit\n";
        std::cout << "11. Check your minimum balance limit\n";
        std::cout << "12. Set a service Charge\n";
        std::cout << "13. Check your service Charge\n";
        std::cout << "--------------------\n\n";
    }
};

class savingsAccount : public bankAccount
{
    double interest;

public:
    savingsAccount() : bankAccount(), interest(0.0) {}

    void setInterest()
    {
        std::cout << "Enter the interest rate: ";
        std::cin >> interest;
        ValidInput(interest);
    }
    double retrieveInterest()
    {
        return interest;
    }
    void deposit()
    {
        bankAccount::deposit();
        setInterest();
    }
    void print()
    {
        bankAccount::print();
        std::cout << "Interest rate: " << interest << std::endl;
    }

    double postInterest()
    {
        double temp = bankAccount::retrieveBalance();
        return temp - (temp * interest);
    }

    void widraw()
    {
        bankAccount::widraw();
    }
    void menu()
    {
        bankAccount::menu();
        std::cout << "--------------------\n\n";
    }
};
// following are the overloaded global function to check the input shoudl be greater than zero
void ValidInput(double &input)
{
    while (input < 0)
    {
        std::cout << "Enter value should be positive: ";
        std::cin >> input;
    }
}
void ValidInput(int &input)
{
    while (input < 0)
    {
        std::cout << "Enter value should be positive: ";
        std::cin >> input;
    }
}
