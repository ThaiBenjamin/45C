// student needs to write this
#include "include/gen_number.h"
#include "include/post_process.h"
#include "include/print_menu.h"
#include <iostream>
#include <string>

int main(int argc, char ** argv) {
    srand((unsigned) time(NULL));
    int num;
    int choice;
    int power;

    // Check if a command line argument was provided and assign it to num using atoi(), else call the random number generator function.
    if(argc > 1){
        num = atoi(argv[1]);
    }
    else{
        num = generateNum();
    }
    // Print the value of the number
    std::cout << "The number is: " << num << "\n";
    // Print the menu and ingest the choice selected by the user
    while(true){

    
        print_menu();

        std::cin >> choice;

        if(choice == 1){
            num = doubleNum(num);
        }

        else if(choice == 2){
            num = reverseDigit(num); 
        }

        else if(choice == 3){
            std::cout << "Enter power (2, 3, or 4): ";
            std::cin >> power;

            if(power != 2 && power != 3 && power != 4){
                std::cout << "Only powers 2, 3, or 4 is allowed.\n";
                break;
            }
            else{   
                num = raisePow2_3_4(num, power); 
            }
        }

        else if(choice == 4){
            num = sumDigits(num); //fix function
        }

        else if(choice == 5){
            std::string strNum = std::to_string(num);
            int length = strNum.length();
            if(length == 2){
                num = raiseFirstDigitPowSecondDigit(num);
            }
            else{
                 std::cout << "The number must be two digits in length";
            }  

        }

        else if(choice == 6){
            std::string strNum = std::to_string(num);
            int length = strNum.length();
            if(length == 3 && num%10 <= 4){
                num = raiseFirstAndSecondDigitPowThirdDigit(num);
            }
            else if(length != 3){
                std::cout << "The number must be three digits in length";
            }

            else{
             std::cout << "The last digit must be <= 4";
            }
        }
        else if(choice == 9){
            break;
        }
        else{
            std::cout <<"\nInvalid choice.";
        }
    
        // check for overflow
        if(num < 0){
            std::cout << "Overflow occured!";
            num = generateNum();
        }
        // check if prime
        if(isNumPrime(num)){
            std::cout << "\n" << num << " is prime.\n";
        }
        
        else{
            std::cout << "\n" << num << " is not prime.\n";
        }
        
        // check if zero
        if(num == 0){
            std::cout << "The number is now 0. Exiting program.\n";
            break;
        }
       
        // call addTen function
        if(num < 10){
            num = addTen(num);
        }
        // repeat
    }

	return 0;
}
