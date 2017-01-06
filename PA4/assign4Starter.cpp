#include <iostream>
using namespace std;

int main() {
	
	int height;
	int width;
	int spaces;
	int lwidth;
	int lheight;
	int lspaces;
	int lstars;
	
	cout << "Enter trunk height: ";
	cin >> height;
	cout << "Enter trunk width: ";
	cin >> width;
	cout << "Enter leaves width: ";
	cin >> lwidth;

	lheight = lwidth / 2;
	lspaces = lheight;
	lstars = lwidth - 1;
	
	// Iterate over leaves height
	for (int i = 0; i <= lheight; ++i) {
		// Draw leaves spaces
		for (int i = lspaces; i > 0; --i) {
			cout << " ";
		}
		// Draw leaves stars
		for (int i = lstars; i < lwidth; ++i) {
			cout << "*";
		}
		cout << endl;
		lspaces -= 1;
		lstars -= 2;		
	}

	// Add extra spaces to the trunk
	if (lwidth > width) {
		spaces = (lwidth - width) / 2;
	}
	
	// Iterate over the height
	for (int i = 0; i < height; ++i) {
		// Draw spaces to keep it aligned
		for (int i = 0; i < spaces; ++i) {
			cout << " ";
		}
		// Draw the trunk lines
		for (int i = 0; i < width; ++i) {
			cout << "*";
		}
		cout << endl;
	}

    return 0;
}
