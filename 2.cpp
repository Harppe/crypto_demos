// streamcipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#define R 4.0
#define SEED 0.4
#define ITERS 10000
#define RANDOM_NUMS 5000
#define STANDARD 256
int *randNums=new int[RANDOM_NUMS];
int currentRInd = 0;
double current_seed = SEED;
char bit_table[8] = { 0x1,0x01,0x001,0x0001,0x00001,0x000001,0x0000001,0x00000001 };
double logMap(double r, double x, int iter) {
    double xn = x;
    for (int i = 0; i < iter; i++) {
        xn = r * xn*(1 - xn);
    }
    return xn;
}

void pseudoNGen(double seed) {
    current_seed = seed;
    std::vector<double> doubles;
    for (int i = 0; i < ITERS; i++) {
        doubles.push_back(logMap(R, seed, i));
    }
    doubles.erase(doubles.begin(), doubles.begin() + (ITERS - RANDOM_NUMS));
    for (int i = 0; i < RANDOM_NUMS; i++) {
        int digit = ((int)(doubles[i] * 100000000));
        while (digit > 10) {
            digit = digit % 10;
        }
        randNums[i] = digit;
    }
}

int getRandNum() {
    if (currentRInd >= RANDOM_NUMS) {
        currentRInd = 0;
    }
    int x = randNums[currentRInd];
    currentRInd++;
    return x;
}

bool getRandResult() {
    int num = getRandNum();
    if (num >= 5) {
        return true;
    }
    return false;
}

char getRandByte() {
    char ch = 0;
    for (int i = 0; i < 8; i++) {
        if (!getRandResult()) {
            ch = ch | bit_table[i];
        }
    }
    return ch;
}

char* expand_key(char* k) {
    char* out = new char[STANDARD];
    const int len = sizeof(k) / sizeof(k[0]) + 2;
    char seed = 0;
    for (int i = 0; i < len; i++) {
        seed = seed ^ k[i];
    }
    double seedD = (double)seed;
    while (seedD > 1) {
        seedD /= 10;
    }
    pseudoNGen(seedD);
    for (int i = 0; i < STANDARD; i++) {
        out[i] = getRandByte();
    }
    return out;
}

char* feistel_encrypt(char *k, char *m) {
    char * temp = new char[10];
    const int len = sizeof(k) / sizeof(k[0]) + 2;

    return temp;
}

void testUniformity() {
    std::map<int, int> intMap;
    for (int i = 0; i < RANDOM_NUMS; i++) {
        intMap[randNums[i]]++;
    }
    std::cout << "\nUniformity Results:"<<std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout <<i << ": " << ((double)intMap[i]) / RANDOM_NUMS << std::endl;
    }
}

char * otp(char *k, char *m) {
    const int len = sizeof(k) / sizeof(k[0])+2;
    char * ciphert = new char[len];
    for (int i = 0; i < len; i++) {
        ciphert[i] = (char)(k[i] ^ m[i]);
    }
    return ciphert;
}

int main()
{
    char mess[6] = "gamer";
    char key[6] = "ignis";
    char *messE = otp(key,mess);
    char *messD = otp(key, messE);
    pseudoNGen(SEED);
    std::cout << messE<<std::endl<<messD;
    testUniformity();
}