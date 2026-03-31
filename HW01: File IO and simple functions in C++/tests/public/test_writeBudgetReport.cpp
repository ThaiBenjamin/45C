#include "budgetfileio.hpp"

#include <fstream>
#include <iostream>

#include <catch_amalgamated.hpp>

namespace {

    void writeTestFile(const std::string & filename, const std::string & content) {
        std::ofstream outFile(filename);
        outFile << content;
    }

    TEST_CASE("generate correct report", "[write-report]") {
        double total_income = 4000;
        double total_expenses = 2600;
        double rent = 1500;
        double utilities = 200;
        double groceries = 500;
        double entertainment = 300;
        double transportation = 100;
        std::string error_message
            = writeBudgetReport("test_report.txt", total_income, total_expenses, rent, utilities,
                                groceries, entertainment, transportation);

        std::string expected_content = R"(+---------------------------------------------+
|             Budget Analysis Report          |
+---------------------------------------------+
| Expenses        | Total Spent | %of Income  |
+---------------------------------------------+
| Rent            | $   1500.00 |      37.50% |
| Utilities       | $    200.00 |       5.00% |
| Groceries       | $    500.00 |      12.50% |
| Entertainment   | $    300.00 |       7.50% |
| Transportation  | $    100.00 |       2.50% |
+---------------------------------------------+
Gross Income: $4000.00
Total Expenses: $2600.00
Net Change: $1400.00
Income Percentage: 65.00%
)";

        writeTestFile("expected_test_report.txt", expected_content);

        // Read the generated file and compare content
        std::ifstream actual_file("test_report.txt");
        std::stringstream buffer;
        buffer << actual_file.rdbuf();
        std::string actual_content = buffer.str();

        REQUIRE(actual_content == expected_content);
        REQUIRE(error_message.empty());
    }

} // namespace