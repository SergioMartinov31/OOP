#include <iostream>
#include "include/allNumbers.h"
using namespace std;

int main() {
    string text;

    cout << "Введите текст из которого хотите получить все числа:\n";
    getline(cin, text);

    cout << allNumbers(text);
    return 0;
}