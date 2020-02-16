// cipher-c.cpp : can deploy various encryptian schemes, such as very bad ones like caesar cipher
//

#include <iostream>

const int MIN = 'a';
const int MAX = 'z';
const int NUM = 26;
const int SIZE = 128;


struct cipher_pair {
	int k;
	char* ptext;
	char* ctext;
};

char* caesar(char arr[], int r) {
	char replica[SIZE];
	for (int i = 0; i < SIZE; i++) {
		replica[i] = ((arr[i] - MIN)%NUM+ r) + MIN;
	}
	replica[13] = 0;
	return replica;
}

template <class T> int filledSize(T arr[]) {
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int size = 0;
	for (int i = 0; i < capacity; i++) {
		if (arr[i] == 0 || arr[i] > SIZE) {
			return i + 1;
		}
	}
	return capacity;
}

char* onetimepad(char mess[], int k) {
	char replica[SIZE];
	for (int i = 0; i < SIZE; i++) {
		if (mess[i] < SIZE) {

		}
		else {
			mess[i] = 0;
			break;
		}
	}
	std::string plain = mess;
	//
	return replica;
}

char* decrypt_onetimepad(char c[], int k) {
	char dog[10] = "mrm";
	return dog;
}

char* decrypt_caesar(char arr[], int r) {
	char replica[SIZE];
	for (int i = 0; i < SIZE; i++) {
		replica[i] = ((arr[i] - MIN) - r) + MIN;
	}
	replica[13] = 0;
	return replica;
}

void copy(char out[], char in[], int termin) {
	for (int i = 0; i < termin; i++) {
		out[i] = in[i];
	}
}

void cut(char arr[], int ind) {
	arr[ind] = 0;
}

void println(char arr[]) {
	printf("%s\n", arr);
}


int main()
{
	char message[100] = "boat";
	int size = 4;
	cut(message, size);
	//std::cin >> message;
	printf("input message: %s\n", message);
	std::cout<<filledSize(message);

	char* temp = caesar(message, 4);
	char numess[100];
	for (int i = 0; i < size; i++) {
		numess[i] = temp[i];
	}
	cut(numess, size);

	printf("encrypted message: %s\n", numess);

	char* temp2 = decrypt_caesar(numess, 4);
	char numess2[100];
	for (int i = 0; i < size; i++) {
		numess2[i] = temp2[i];
	}
	cut(numess2,size);

	printf("decrypted message: %s\n", numess2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
