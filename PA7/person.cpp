#include <iostream>
#include <string>

#include "person.h"
using namespace std;

// Constructor for the Person class.
Person::Person() {
	age = 0;
	gender = "default";
	yearlyIncome = 0;
	return;
}

// Print the Person class.
void Person::Print() {
	cout << "Age = " << this->age
		<< ", gender = " << this->gender
		<< ", yearly income = " << this->yearlyIncome
		<< endl;
	return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int a, string g, int i) {
	this->age = a;
	this->gender = g;
	this->yearlyIncome = i;
	return;
}

// Get the age of a Person.
int Person::GetAge() {
	return this->age;
}

// Get the gender of a Person
string Person::GetGender() {
	return this->gender;
}

// Get the Yearly income of a Person
int Person::GetYearlyIncome() {
	return this->yearlyIncome;
}
