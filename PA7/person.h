#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

// Define a Person class, including age, gender, and yearlyIncome.
class Person {
public:
	Person();
	void Print();
	void SetData(int a, string g, int i);
	int GetAge();
	string GetGender();
	int GetYearlyIncome();
private:
	int age;
	string gender;
	int yearlyIncome;
};

#endif // !PERSON_H