#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(string str) {
    int result = 0;
    for (int i = str.length() - 1, j = 0; i >= 0; --i, ++j) {
        result += str[i] == '1' ? pow(2, j) : 0;
    }

    return result;
}

string decimalToBinary(int n) {
    string result;
    while (n > 0) {
        if (n % 2 == 0) {
            result += '0';
        } else {
            result += '1';
        }

        n /= 2;
    }

    result += "00000000";
    result = string(result.rbegin(), result.rend());

    return result.substr(result.length() - 8, 8);
}

void drawLine(int screen[], int width, int x1, int x2, int y) {
    int start = floor(x1 / 8) + (y * width / 8);
    int end = ceil(x2 / 8) + (y * width / 8);

    for (int i = start + 1; i < end; ++i) {
        screen[i] |= binaryToDecimal("11111111");
    }

    int maskStart = (1 << (8 - (x1 % 8))) - 1;
    int maskEnd = binaryToDecimal("11111111") << (8 -  (x2 % 8));

    screen[start] |= maskStart;
    screen[end] |= maskEnd;
}

int main() {
    string lines[9] = { "00000011", "00000111", "11001000",
                        "10001011", "11011010", "00000100",
                        "00100101", "00100010", "10010011" };
    int width = 24;

    int screen[9];
    for (int i = 0; i < 9; ++i) {
        screen[i] = binaryToDecimal(lines[i]);
    }

    int x1 = 4, x2 = 20, y = 1;
    drawLine(screen, width, x1, x2, y);

    for (int i = 0; i < 9; ++i) {
        if (i != 0 && (i * 8) % width == 0) {
            cout << endl;
        }
        cout << decimalToBinary(screen[i]) << " ";
    }

    return 0;
}