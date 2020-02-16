// mess_auth.cpp : This file contains th`e 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#define SIZE 256
#define TAG_SIZE 128
#define BLOCK 16
#define RATE 4.0

 char ZEROS[8] = { 0x1,0x01,0x001,0x0001,0x00001,0x000001,0x0000001,0x00000001 };

double logMap(double seed, int iters) {
	double xn = seed;
	for (int i = 0; i<iters;i++) {
		xn = RATE * xn*(1 - xn);
	}
	return xn;
}


char* key_expander(char* key) {
	char* out = new char[BLOCK];
	int size = sizeof(key) / sizeof(key[0]);
	double base = 0;
	for (int i = 0; i < size; i++) {
		base += key[i];
	}

	return out;
}

bool verify(char* key, char* mess, char* tag) {
	return false;
}

char* tag(char* key, char* mess) {
	char* out = new char[SIZE];
	return out;
}

int main()
{

    std::cout << size(&gamer)<<std::endl;
}
