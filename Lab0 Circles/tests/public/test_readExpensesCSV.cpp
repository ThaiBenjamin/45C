#include "budgetfileio.hpp"

#include <fstream>
#include <sstream>

#include <catch_amalgamated.hpp>

namespace {

    TEST_CASE("reads csv correctly", "[read-expenses]") {
        std::string mock_csv = R"(
Category,Type,Amount,Date
Rent,Expense,1500,2023-01-01
Utilities,Expense,200,2023-01-02
Groceries,Expense,500,2023-01-03
Entertainment,Expense,300,2023-01-04
Transportation,Expense,100,2023-01-05
Income,Income,4000,2023-01-06
)";

        double total_income = 0;
        double total_expenses = 0;
        double rent = 0;
        double utilities = 0;
        double groceries = 0;
        double entertainment = 0;
        double transportation = 0;
        std::string error_message
            = readExpensesCSV("mock.csv", total_income, total_expenses, rent, utilities, groceries,
                              entertainment, transportation);

        CHECK(error_message == "");
        CHECK_THAT(total_income, Catch::Matchers::WithinAbs(4000, 0.001));
        CHECK_THAT(total_expenses, Catch::Matchers::WithinAbs(2600, 0.001));
        CHECK_THAT(rent, Catch::Matchers::WithinAbs(1500, 0.001));
        CHECK_THAT(utilities, Catch::Matchers::WithinAbs(200, 0.001));
        CHECK_THAT(groceries, Catch::Matchers::WithinAbs(500, 0.001));
        CHECK_THAT(entertainment, Catch::Matchers::WithinAbs(300, 0.001));
        CHECK_THAT(transportation, Catch::Matchers::WithinAbs(100, 0.001));
    }

    TEST_CASE("sets error message correctly", "[read-expenses]") {
        double total_income = 0;
        double total_expenses = 0;
        double rent = 0;
        double utilities = 0;
        double groceries = 0;
        double entertainment = 0;
        double transportation = 0;

        // Simulate file open failure
        std::string error_message
            = readExpensesCSV("non_existent_file.txt", total_income, total_expenses, rent,
                              utilities, groceries, entertainment, transportation);
        REQUIRE(error_message == "Error: Cannot open file non_existent_file.txt");

        // Simulate CSV parsing error
        error_message = readExpensesCSV("invalid_csv.csv", total_income, total_expenses, rent,
                                        utilities, groceries, entertainment, transportation);
        REQUIRE(error_message == "Error: Cannot open file invalid_csv.csv");
    }

} // namespace