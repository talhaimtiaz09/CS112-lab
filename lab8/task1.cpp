#include "helper.h"

int main()
{
    int option, choice;
    bankAccount *bankPtr;
    std::cout << "Hey welcome to L Bank!\n";
    std::cout << "What type of bank Account you want to make?\n";
    std::cout << "1.Checking Account\n2.Saving Account\n";
    std::cin >> option;
    if (option == 1)
    {
        checkingAccount checkAcc;
        bankPtr = &checkAcc;
    }
    else if (option == 2)
    {
        savingsAccount svgAcc;
        bankPtr = &svgAcc;
    }

    else
        std::cout << "Please enter a Valid option 1~2" << std::endl;

    while (1)
    {
        while (!(bankPtr->getAccNo()))
        {
            bankPtr->setAccNo();
        }
        bankPtr->menu();
        std::cout << "Please enter your option: ";
        std::cin >> choice;
        /**
         * @brief if you have selected saving account then you see limited option and
         * combination of if and while loop make sure that you can not enter choice
         * other than what is shown on your menu
         */
        if (option == 2)
            while (choice < 0 || choice >= 10)
            {
                std::cout << "Please enter valid option from 0-9\n";
                std::cin >> choice;
            }

        double temp = 0;
        switch (choice)
        {

        case 1:
            std::cout << "Your Account no. : ";
            std::cout << bankPtr->getAccNo() << std::endl;
            break;
        case 2:
            std::cout << "Please enter balance: ";
            std::cin >> temp;
            ValidInput(temp);
            bankPtr->setBalance(temp);
            break;
        case 3:
            std::cout << "Your current Balance is: ";
            std::cout << bankPtr->retrieveBalance() << std::endl;
            break;
        case 4:
            bankPtr->setInterest();
            break;
        case 5:
            std::cout << "Your current interest rate is: ";
            std::cout << bankPtr->retrieveInterest() << " %" << std::endl;
            break;
        case 6:
            bankPtr->print();
            break;
        case 7:
            bankPtr->deposit();
            break;
        case 8:
            bankPtr->widraw();
            break;
        case 9:
            std::cout << "Your current post Interest is: ";
            std::cout << bankPtr->postInterest() << std::endl;
            break;

        case 10:
            bankPtr->setMinBalance();
            break;
        case 11:
            std::cout << "Your current minimum Balance is: ";
            std::cout << bankPtr->retrieveMinBalance() << std::endl;
            break;
        case 12:
            bankPtr->setServiceCharge();
            break;
        case 13:
            std::cout << "Your current Service charge is: ";
            std::cout << bankPtr->retrieveServiceCharge() << std::endl;
            break;

        default:
            std::cout << "Please enter a valid option!\n";
            break;
        }
    }

    return 0;
}
