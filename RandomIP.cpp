#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void generate_ip() {
    int bits[4][8];
    int octets[4];
    int row = sizeof(bits)/sizeof(bits[0]);
    int col = sizeof(bits[0])/sizeof(bits[0][0]);
 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int random = rand() % 2; // Generates random number between 0 and 1
            bits[i][j] = random;
        }
    }

    for (int i = 0; i < row; i++) {
        int octet = 0;
        int exponent = col - 1;
        for (int j = 0; j < col; j++) {
            octet += bits[i][j]*pow(2, exponent);
            exponent--;
        }
        octets[i] = octet;
        octet = 0;
    }
    
    for (int i = 0; i < 4; i++) {
        cout << octets[i];
        if (i < 3) {
            cout << ".";
        }
    }
}

int main() {
    int times;
    cout << "How many random IPs do you want?\n";
    cin >> times;
    for (int i = 0; i < times; i++) {
        generate_ip();
        cout << "\n";
    }
    return 0;
}


