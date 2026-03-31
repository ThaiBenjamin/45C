#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
#include "budgetfileio.hpp"

std::string readExpensesCSV(const std::string& inputFilename, double& grossIncome, double& totalExpenses, double& rent, double& utilities, double& groceries, double& entertainment, double& transportation){
    std::ifstream inFile;
    inFile.open(inputFilename);

    if(!inFile.is_open()){
        return "Error: Cannot open file " + inputFilename;
    }

    grossIncome = 0.0;
    totalExpenses = 0.0;
    rent = utilities = groceries = entertainment = transportation = 0.0;

    std::string line;
    getline(inFile, line); 

    while (getline(inFile, line)) {
        double amount = 0.0; 
        std::stringstream currentline(line);
        std::string category, type, amountStr, date;
        getline(currentline, category, ',');
        getline(currentline, type, ',');
        getline(currentline, amountStr, ',');
        getline(currentline, date, ',');

        amount = std::stod(amountStr);

        if(type == "Income"){
            grossIncome += amount;
        } 
        else{
            totalExpenses += amount;
            if(category == "Rent"){
                rent += amount;
            }
            else if(category == "Utilities"){
                utilities += amount;
            }
            else if(category == "Groceries"){
                groceries += amount;
            } 
            else if(category == "Entertainment"){
                entertainment += amount;
            } 
            else if(category == "Transportation"){
                transportation += amount;
            } 
        }
    }

    inFile.close();
    return "";
}

std::string writeBudgetReport(const std::string& outFilename, double grossIncome, double totalExpenses, double rent, double utilities, double groceries, double entertainment, double transportation){
    std::ofstream outFile;
    outFile.open(outFilename);

    if(!outFile.is_open()){
        return "Error: Cannot open file " + outFilename;
    }

    outFile << std::fixed << std::setprecision(2);

    outFile << "+---------------------------------------------+\n";
    outFile << "|             Budget Analysis Report          |\n";
    outFile << "+---------------------------------------------+\n";
    outFile << "| Expenses        | Total Spent | %of Income  |\n";
    outFile << "+---------------------------------------------+\n";
  
    double percent;
    
    percent = rent / grossIncome * 100;
    outFile << "| " << std::left << std::setw(15) << "Rent" << " | $" << std::right << std::setw(10) << rent << " |" << std::setw(11) << percent << "% |\n";

    percent = utilities / grossIncome * 100;
    outFile << "| " << std::left << std::setw(15) << "Utilities" << " | $" << std::right << std::setw(10) << utilities << " |" << std::setw(11) << percent << "% |\n";

    percent = groceries / grossIncome * 100;
    outFile << "| " << std::left << std::setw(15) << "Groceries" << " | $" << std::right << std::setw(10) << groceries << " |" << std::setw(11) << percent << "% |\n";

    percent = entertainment / grossIncome * 100;
    outFile << "| " << std::left << std::setw(15) << "Entertainment" << " | $" << std::right << std::setw(10) << entertainment << " |" << std::setw(11) << percent << "% |\n";

    percent = transportation / grossIncome * 100;
    outFile << "| " << std::left << std::setw(15) << "Transportation" << " | $" << std::right << std::setw(10) << transportation << " |" << std::setw(11) << percent << "% |\n";
    outFile << "+---------------------------------------------+\n";

    double netChange = grossIncome - totalExpenses;
    double incomePercent = totalExpenses / grossIncome * 100;

    outFile << "Gross Income: $" << grossIncome << "\n";
    outFile << "Total Expenses: $" << totalExpenses << "\n";
    outFile << "Net Change: $" << netChange << "\n";
    outFile << "Income Percentage: " << incomePercent << "%\n";

    outFile.close();
    return "";
}

