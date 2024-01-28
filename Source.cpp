#include <iostream>
#include <vector>
#include <iomanip>

std::vector<char> Float_To_Hex(float number) {
    std::vector<char> hexNumber;

    
    int integerPart = static_cast<int>(number);
    while (integerPart != 0) {
        int remainder = integerPart % 16;
        if (remainder < 10)
            hexNumber.insert(hexNumber.begin(), '0' + remainder);
        else
            hexNumber.insert(hexNumber.begin(), 'A' + remainder - 10);
        integerPart /= 16;
    }

    
    hexNumber.push_back('.');

    
    float fractionalPart = number - static_cast<int>(number);
    for (int i = 0; i < 4; ++i) {
        fractionalPart *= 16;
        int digit = static_cast<int>(fractionalPart);
        if (digit < 10)
            hexNumber.push_back('0' + digit);
        else
            hexNumber.push_back('A' + digit - 10);
        fractionalPart -= digit;
    }

    return hexNumber;
}

void Display_1D_Vector(const std::vector<char>& vec) {
    for (char c : vec) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    char continueFlag = 'y';

    while (continueFlag == 'y' || continueFlag == 'Y') {
        float number;

        std::cout << "Enter a floating-point number: ";
        std::cin >> number;

        std::vector<char> hexNumber = Float_To_Hex(number);

        std::cout << "Hexadecimal number: ";
        Display_1D_Vector(hexNumber);

        std::cout << "Do you want to continue (Y/N)? ";
        std::cin >> continueFlag;
    }

    return 0;
}
