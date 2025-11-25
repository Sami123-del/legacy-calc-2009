#include <iostream>
#include "LoanBuddy.h"
#include "Utils.cpp"

int main() {
    long double amount, rate, years;

    std::cout << "Enter loan amount: ";
    std::cin >> amount;

    std::cout << "Enter loan years: ";
    std::cin >> years;

    // Optional: get default rate from config
    rate = readDefaultRate();
    std::cout << "Using interest rate from config: " << rate << "%\n";

    try {
        LoanBuddy loan(amount, rate, years);

        std::cout << "Simple Interest: " << loan.getSimpleInterest() << "\n";
        std::cout << "Total Payable: " << loan.getSimpleTotal() << "\n";
        std::cout << "Monthly EMI: " << loan.getMonthlyEMI() << "\n";
    }
    catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
