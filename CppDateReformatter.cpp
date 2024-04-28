//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <string>

std::string convertDateFormat(const std::string date) {
    std::string newDate = date;
    newDate[2] = '-';
    newDate[5] = '-';
    return newDate.substr(6, 4) + '-' + newDate.substr(3, 2) + '-' + newDate.substr(0, 2);
}

std::string findAndConvertDates(const std::string text) {
    std::string result = text;
    int pos = 0;
   
    while ((pos = result.find_first_of(".-", pos)) != std::string::npos) {
        if (pos > 0 && pos < result.length() - 10 && (result[pos + 3] == '.' || result[pos + 3] == '-') && isdigit(result[pos - 1]) && isdigit(result[pos + 4])) {
            
            std::string date = result.substr(pos - 2, 10);
            
            std::string convertedDate = convertDateFormat(date);
            
            result.replace(pos - 2, 10, convertedDate);
            
            pos += 10;
        }
        else {
            
            ++pos;
        }
    }
    return result;
}

int main() {
    std::string text = "Today's date is 28.04.2024";
    std::string convertedText = findAndConvertDates(text);
    std::cout << "Converted Text: " << convertedText << std::endl;
    return 0;
}
