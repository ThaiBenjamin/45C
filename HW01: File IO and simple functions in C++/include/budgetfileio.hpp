// Students do not modify this file

#ifndef BUDGETFILEIO_H
#define BUDGETFILEIO_H

#include <string>

/**
 * @brief Reads and processes expenses CSV file.
 * 
 * @param inputFilename Name of input expenses CSV file.
 * @param grossIncome Reference to total income.
 * @param totalExpenses Reference to total expenses.
 * @param rent Reference to rent amount.
 * @param utilities Reference to utilities amount.
 * @param groceries Reference to groceries amount.
 * @param entertainment Reference to entertainment amount.
 * @param transportation Reference to transportation amount.
 * @return string
 */
std::string readExpensesCSV(
    const std::string& inputFilename,
    double& grossIncome,
    double& totalExpenses,
    double& rent,
    double& utilities,
    double& groceries,
    double& entertainment,
    double& transportation
);

/** 
 * @brief Writes budget analysis report to an output text file.
 * 
 * @param outputFilename Name of the output file.
 * @param grossIncome Total income amount.
 * @param totalExpenses Total expenses amount.
 * @param rent Rent amount.
 * @param utilities Utilities amount.
 * @param groceries Groceries amount.
 * @param entertainment Entertainment amount.
 * @param transportation Transportation amount.
 * @return string
 */
std::string writeBudgetReport(
    const std::string& outFilename,
    double grossIncome,
    double totalExpenses,
    double rent,
    double utilities,
    double groceries,
    double entertainment,
    double transportation
);

#endif