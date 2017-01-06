#include <iostream>
#include <string>
using namespace std;

int main() {
   string tweet;
   string result = "";
   int pos;
   
   cout << "Enter a complete tweet: ";
   getline(cin, tweet);
   
   // Resize the tweet to 160 chars
   tweet.resize(160);
   
   // Output decoded abbreviation from tweet
   pos = tweet.find("LOL");
   if (pos >= 0) {
      result += "LOL = laughing out loud\n";
   }
   pos = tweet.find("IRL");
   if (pos >= 0) {
      result += "IRL = in real life\n";
   }
   pos = tweet.find("AFK");
   if (pos >= 0) {
      result += "AFK = away from keyboard\n";
   }
   pos = tweet.find("NVM");
   if (pos >= 0) {
      result += "NVM = never mind\n";
   }
   pos = tweet.find("BFF");
   if (pos >= 0) {
      result += "BFF = best friends forever\n";
   }
   pos = tweet.find("FTW");
   if (pos >= 0) {
      result += "FTW = for the win\n";
   }
   pos = tweet.find("IIRC");
   if (pos >= 0) {
      result += "IIRC = if I recall correctly\n";
   }
   pos = tweet.find("TTYL");
   if (pos >= 0) {
      result += "TTYL = talk to you later\n";
   }
   pos = tweet.find("IMHO");
   if (pos >= 0) {
      result += "IMHO = in my humble opinion\n";
   }
   // No abbreviation found
   if ((result.length() <= 0)) {
      result = "Sorry, don't know that one.\n";
   }
   
   cout << result;
   
   return 0;
}
