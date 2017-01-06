#include <iostream>
#include <string>
using namespace std;

int main() {
   string tweet;
   
   cout << "Enter abbreviation from tweet: ";
   cin >> tweet;
   
   // Output decoded abbreviation from tweet
   if (tweet == "LOL") {
      cout << "LOL = laughing out loud" << endl;
   }
   else if (tweet == "IRL") {
      cout << "IRL = in real life" << endl;
   }
   else {
      cout << "Sorry, don't know that one." << endl;
   }
   
   return 0;
}
