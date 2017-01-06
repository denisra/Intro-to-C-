#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<char> normalV(26);
    vector<char> cipherV(26);
    string toDec = "";
    string beenDec = "";
	int i = 0;
    
	// Set each char to both the normal and cipher Vectors
    normalV.at(i) = 'a'; cipherV.at(i) = '!'; ++i;
	normalV.at(i) = 'b'; cipherV.at(i) = '^'; ++i;
	normalV.at(i) = 'c'; cipherV.at(i) = '&'; ++i;
	normalV.at(i) = 'd'; cipherV.at(i) = '*'; ++i;
	normalV.at(i) = 'e'; cipherV.at(i) = '@'; ++i;
	normalV.at(i) = 'f'; cipherV.at(i) = '('; ++i;
	normalV.at(i) = 'g'; cipherV.at(i) = ')'; ++i;
	normalV.at(i) = 'h'; cipherV.at(i) = '-'; ++i;
	normalV.at(i) = 'i'; cipherV.at(i) = '#'; ++i;
	normalV.at(i) = 'j'; cipherV.at(i) = '_'; ++i;
	normalV.at(i) = 'k'; cipherV.at(i) = '='; ++i;
	normalV.at(i) = 'l'; cipherV.at(i) = '+'; ++i;
	normalV.at(i) = 'm'; cipherV.at(i) = '['; ++i;
	normalV.at(i) = 'n'; cipherV.at(i) = '{'; ++i;
	normalV.at(i) = 'o'; cipherV.at(i) = '$'; ++i;
	normalV.at(i) = 'p'; cipherV.at(i) = ']'; ++i;
	normalV.at(i) = 'q'; cipherV.at(i) = '}'; ++i;
	normalV.at(i) = 'r'; cipherV.at(i) = ';'; ++i;
	normalV.at(i) = 's'; cipherV.at(i) = ':'; ++i;
	normalV.at(i) = 't'; cipherV.at(i) = ','; ++i;
	normalV.at(i) = 'u'; cipherV.at(i) = '%'; ++i;
	normalV.at(i) = 'v'; cipherV.at(i) = '<'; ++i;
	normalV.at(i) = 'w'; cipherV.at(i) = '.'; ++i;
	normalV.at(i) = 'x'; cipherV.at(i) = '>'; ++i;
	normalV.at(i) = 'y'; cipherV.at(i) = '/'; ++i;
	normalV.at(i) = 'z'; cipherV.at(i) = '?'; ++i;
    
    // Get secret message
    do {
        cout << "Enter a secret message: ";
        getline(cin, toDec);
    } while (toDec.length() == 0);

    beenDec = toDec;

    // Iterate over each letter of the message
	for (int i = 0; i < toDec.length(); ++i) {
		// Iterate over the cipher vector to find a match
		for (int j = 0; j < cipherV.size(); ++j) {
			if (toDec.at(i) == cipherV.at(j)) {
				beenDec.at(i) = normalV.at(j);
				break; // There is only one entry, so we can break out of the loop
			}		
		}
	}    
    
    // Output decrypted message
	cout << "Decrypted message: " << beenDec << endl;
    
    return 0;
}
