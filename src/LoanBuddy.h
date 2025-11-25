#ifndef LOAN_H
#define LOAN_H

// LoanBuddy — a tiny helper for basic loan math.


class LoanBuddy {
public:
    // A simple constructor:
    // startingAmount  -> the borrowed money
    // annualRatePct   -> yearly interest rate (in %)
    // loanYears       -> total years to repay
    LoanBuddy(long double startingAmount,
              long double annualRatePct,
              long double loanYears);

    // Works out the final payable amount using plain/simple interest.
    long double getSimpleTotal() const;

    // Returns only the interest portion (simple interest style).
    long double getSimpleInterest() const;

    // Produces the monthly EMI using the standard EMI formula.
    long double getMonthlyEMI() const;

private:
    long double startingAmount;   // acts like the principal (P)
    long double annualRatePct;    // yearly percentage rate
    long double loanYears;        // total duration in years
};

#endif // LOAN_H
