#include "LoanBuddy.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

LoanBuddy::LoanBuddy(long double startingAmount,
                     long double annualRatePct,
                     long double loanYears)
    : startingAmount(startingAmount), annualRatePct(annualRatePct), loanYears(loanYears)
{
    // Input validation
    if (startingAmount <= 0) 
        throw std::invalid_argument("Loan amount must be positive.");
    if (annualRatePct < 0)
        throw std::invalid_argument("Interest rate cannot be negative.");
    if (loanYears <= 0)
        throw std::invalid_argument("Loan duration must be positive.");
}

long double LoanBuddy::getSimpleInterest() const {
    return startingAmount * (annualRatePct / 100.0) * loanYears;
}

long double LoanBuddy::getSimpleTotal() const {
    return startingAmount + getSimpleInterest();
}

long double LoanBuddy::getMonthlyEMI() const {
    // EMI formula: E = P*r*(1+r)^n / ((1+r)^n - 1)
    long double principal = startingAmount;
    long double monthlyRate = annualRatePct / (12.0 * 100.0);
    long double totalMonths = loanYears * 12.0;

    if (monthlyRate == 0) // zero interest
        return principal / totalMonths;

    long double emi = principal * monthlyRate * std::pow(1 + monthlyRate, totalMonths) /
                      (std::pow(1 + monthlyRate, totalMonths) - 1);

    return emi;
}
