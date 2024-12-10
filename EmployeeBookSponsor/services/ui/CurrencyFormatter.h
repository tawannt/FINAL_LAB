#ifndef CURRENCYFORMATTER_H
#define CURRENCYFORMATTER_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <locale>


using namespace std;

/// @brief Lop chuyen doi so sang chuoi tien te $
class CurrencyFormatter {
public:
    // Method to convert a float to formatted currency string
    static std::string format(float amount) {
        // Convert float to an integer for formatting as currency (round to nearest dollar)
        int roundedAmount = static_cast<int>(amount + 0.5f);
        
        // Convert integer to string
        std::string amountStr = std::to_string(roundedAmount);
        
        // Insert commas for thousands, millions, etc.
        int insertPosition = amountStr.length() - 3;
        while (insertPosition > 0) {
            amountStr.insert(insertPosition, ",");
            insertPosition -= 3;
        }
        
        // Add dollar sign and trailing space
        return "$" + amountStr;
    }

};

#endif // CURRENCYFORMATTER_H