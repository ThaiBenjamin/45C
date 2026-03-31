// complete the function source
#include "../include/gen_number.h"
#include <string>
#include <iostream>
#include <cmath>

int generateNum(){
    return rand() % 90 + 10;

}
int doubleNum(int num){
    return num * 2;
}

int reverseDigit(int num){
    int number = num/10;
    int newNumber = num%10;
    int currDigit = 0;

    
    while(number > 0){
        currDigit = number % 10;
        number = number/10;
        newNumber = newNumber * 10 + currDigit;
    }

    return newNumber;
}

int sumDigits(int num){
    int number = num/10;
    int newNumber = num%10;
    int currDigit = 0;

    
    while(number > 0){
        currDigit = number % 10;
        number = number/10;
        newNumber = newNumber + currDigit;
    }

    return newNumber;
}
int raisePow2_3_4(int num, int exp){
    return pow(num, exp);
}
int raiseFirstDigitPowSecondDigit(int num){
    int firstDigit = num/10;
    int secondDigit = num%10;
    
    return pow(firstDigit, secondDigit);
}
int raiseFirstAndSecondDigitPowThirdDigit(int num){
    int firstsecondDigit = num/10;
    int thirdDigit = num%10;

    return pow(firstsecondDigit, thirdDigit);
}