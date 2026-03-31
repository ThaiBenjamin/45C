# HW01: Functions and file I/O in C++

Author: Benjamin Thai

## Part 0: `git` basics
1. Update the author line beneath the title of the assignment from `Firstname Lastname` to be your first and last name.
2. Run `git status` in the terminal to see that the file is changed.
3. Run `git diff` to see the changes.
4. Run `git add README.md` to stage those changes'
5. Run `git commit -m $YOUR_MESSAGE` to save those changes (replace the `$YOUR_MESSAGE` with an appropriate message about the changes you made).

## Problem 1: Functions and circles.
The following formula gives the distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ in the Cartesian plane:

$$ d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$

Given the center and a point on the circle, you can use this formula to find the radius of the circle. Write a program that prompts the user to enter the center and a point on the circle. The program should then output the circle's radius, diameter, circumference, and area. Your program must have the following functions:

 - `radius`: This function takes as its parameters four numbers that represent the center and a point on the circle, and utilizes the distance formula to calculate the radius.
- `circumference`: This function takes as its parameter a number that represents the radius of the circle and returns the circle's circumference. (If $r$ is the radius, the circumference is $2\pi r$)
- `area`: This function takes as its parameter a number that represents the radius of the circle and returns the circles are. (If $r$ is the radius, the area is $\pi r^2$)

Use the value of the constant $\pi$ provided by the [C++ standard library](https://en.cppreference.com).


### Files to work on
- `src/circle.cpp` and implement the necessary function definitions therein.
- `src/circle_main.cpp` and implement the `main()` function there.

### Compiling and Running the Program
To run the program, first compile the function definition file `src/circle.cpp` and save the output executable as `circle.o`. Then, link the file to the driver main function in `src/circle_main.cpp` that you use to test whether your code works by typing the following shell command: 

```bash
g++ -c src/circle.cpp -o src/circle.o
g++ src/circle_main.cpp -o hw01_circle src/circle.o
```

The second command will compile `src/circle_main.cpp` and will save and executable as `hw01_circle` in the root directory of the repo.
Notice that `src/circle_main.cpp` will depend on the function definitions in `include/circle.h`, which is the reason for the `#include "include/circle.h"` to test your code.
You may adapt `src/circle_main.cpp` as a driver to test edge cases.

### Script Generation
To show that you are adept at manually running your code please create a script file to run each problem and save the command line interaction.

Use the command `script` to capture your interaction compiling and running the program as shown:

```bash
script hw01_circle.scr
date
pwd
ls -l
g++ -c src/circle.cpp -o src/circle.o
g++ src/circle_main.cpp -o hw01_circle src/circle.o
./hw01_circle
ls -l
exit
mkdir scripts
mv hw01_circle.scr scripts
```

## CMake: A quick explainer

To handle the complexity of building C++ projects (imagine the `g++` commands above for a project with 10 files), projects in this class will use `cmake` to generate the build scripts. `cmake` uses a `CMakeLists.txt` file to define these build scripts.

 **For projects in this class, the root directory is where the `CMakeLists.txt` will live and so is the place to run all `cmake` commands from.**

To setup the project in a build folder, run `cmake -B $BUILD_FOLDER -S .` in the same directory as the `CMakeLists.txt` file, replacing `$BUILD_FOLDER` with the name of the build folder that `cmake` will create. A very common name for this folder is `build` (making the command be `cmake -B build -S .`).

To build the whole project after the setup, run `cmake --build $BUILD_FOLDER`.

Often, we do not want to build the whole project, but just one part of it.
To build just one part, run `cmake --build $BUILD_FOLDER --target $TARGET`, where `$TARGET` is the part that we want to build.
This class will use this feature to run subsets of the tests by filename.
For example, the file named `tests/public/test_readExpensesCSV.cpp` defines a target named `test_readExpensesCSV`, which can be built with `cmake --build $BUILD_FOLDER --target test_readExpensesCSV`.

In this class we use Catch2 as our testing suite which compiles tests into executables in the `$BUILD_FOLDER`. You may run all public test cases with the command `./$BUILD_FOLDER/bin/all-tests` or specific test executables listed in the `$BUILD_FOLDER` directory.

## Problem 2: File I/O and monthly expenses
Living on campus or off-campus can be tricky, especially when you are supporting yourself through school. Budgeting is the key to understanding how you utilize your money in a given month. You would like to develop a program that processes your expenditures and income from an input comma separated values (CSV) file and reports metrics such as total income, total expenses, net change, and percentage of income spent. The categories of expenses encountered are Rent, Utilities, Groceries, Entertainment, and Transportation.

The input CSV is structured as follows:
```
Category,Type,Amount,Date
Rent,Expense,1200.00,2024-09-01
Utilities,Expense,150.00,2024-09-10
Groceries,Expense,75.00,2024-09-22
Salary,Income,4000.00,2024-09-31
Entertainment,Expense,100.00,2024-09-25
Transportation,Expense,0.00,2024-09-31
```
Your program should be able to:
1. Read the input CSV file `sept_expenses.csv`
2. Parse the data to extract categories, types, amounts, and dates
3. Calculate the gross income and total expenses
4. Determine the net income (gross income - total expenses)
5. Calculate the percentage of gross income spent in each category
6. Write the results to a new text file named `budget_out.txt` with proper formatting, alignment and spacing.

The output text file should have the following structure:
```
+---------------------------------------------+
|             Budget Analysis Report          |
+---------------------------------------------+
| Expenses        | Total Spent | %of Income  |
+---------------------------------------------+
| Rent            | $   1200.00 |      30.00% |
| Utilities       | $    150.00 |       3.75% |
| Groceries       | $     75.00 |       1.88% |
| Entertainment   | $    100.00 |       2.50% |
| Transportation  | $      0.00 |       0.00% |
+---------------------------------------------+
Gross Income: $4000.00
Total Expenses: $1525.00
Net Change: $2475.00
Income Percentage: 38.12%
```
Note that the output file `budget_out.txt`:
- Uses borders to construct a visually appealing table
- Aligns columns
- Formats dollar amounts to two decimal places
- Rounds up percentage calculations
- Includes table headers and a report title
- Displays a summary at the bottom of the file
- Has only the five expense categories listed in the above example

Note: if a category does not appear in the CSV file, you may assume that the expense was $0.00.

### Files to work on
Only `src/budgetfileio.cpp` and implement the necessary function definitions therein

Use `cmake` as described in the quick explainer to build this program

### Functions to work on

#### `readExpensesCSV`
This function takes as its parameters the input file name and references to the category sums.
Its objective is to open the input file and process the contents to correctly set the value of each category.
Since functions in C++ cannot return multiple values, gross income, total expenses, rent, utilities, groceries, entertainment, and transportation category expenses must be passed by reference into the function.
If the file cannot be opened, the function should return `"Error: Cannot open file $INPUTFILENAME"`. Otherwise, it should return the empty string.

#### `writeBudgetReport`
This function takes as its parameters the name of the file to write the budget analysis report to.
The report places all expenses into a three column table identifying the category, the associated value, and the percentage of gross income that the expense represents.
Be careful with the appearance of the table, it should present visually identical to the table presented in this README.
Often as software engineers, we must produce visually appealing information to the standards of our client who may be very specific with spacing, decimal point and dollar sign alignment, etc.
This function is also returns its error message.
If the output file cannot be opened, the return value should be `"Error: Cannot open file $OUTPUTFILENAME"`. Otherwise, it should return the empty string.

## Note
- It is required that you add your full name to `README.md` in the location specified.
- Run local test cases to verify the correctness of your program before submission.
- The initial code will not compile. You will have to implement the functions specified.
- Commit all changes as you develop the code in your individual private repo. Please provide descriptive commit messages and push from local to your remote repository. If you do not stage, commit, and push github classroom will not receive your code at all.
- Make sure when submitting your code to Gradescope you select GitHub as your submission method and select your repository and the branch of your solution.
- Please submit before the assignment deadline specified in Gradescope.

In order to receive full credit for this programming assignment you must complete:
- [ ] `src/circle.cpp`
- [ ] `scripts/hw01_circle.scr`
- [ ] `src/budgetfileio.cpp`



