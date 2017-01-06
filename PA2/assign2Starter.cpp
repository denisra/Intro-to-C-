#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double width = 0.0;
    double height = 0.0;
    double area = 0.0;
	const double sqrPerGallon = 350.0;
	double amountOfPaint = 0.0;
	int costPerGallon = 27;
	double sqrPerHour = 100.0;
	    
    cout << "Enter the width of the wall in feet: ";
    cin >> width;
    
	cout << "Enter the height of the wall in feet: ";
    cin >> height;
    
    // Calculate and output area of wall
    area = height * width;
    cout << "Total area to paint in square feet: "
         << area 
         << endl;

    // Calculate the total number of gallons of paint needed (rounded up)
	amountOfPaint = ceil(area / sqrPerGallon);
	cout << "Total number of gallons of paint needed: "
		 << amountOfPaint
		 << endl;

	// Calculate the total cost	 
    cout << "Total cost of paint in dollars: "
		 << amountOfPaint * costPerGallon
		 << endl;

	// Calculate the time needed to paint the wall	 
    cout << "Total time to paint in hours: "
		 << area / sqrPerHour
		 << endl;

    return 0;
}
