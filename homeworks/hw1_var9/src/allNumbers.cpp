#include "../include/allNumbers.h"
#include <iostream> 

string allNumbers(string text){
    string result = "";
    string cur = "";

    for(size_t index = 0; index < text.length(); ++index){
        char c = text[index];
        if (c >= '0' && c <= '9'){
            cur += c;
        } else {
            if (!cur.empty()) {
                if (!result.empty()){
                    result += " ";
                }
                result += cur;
                cur.clear();

            }

        }
    }
    if (!cur.empty()) {
        if (!result.empty()){ 
            result += " ";
        }
        result += cur;
    }


    return result;
}