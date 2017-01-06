#include <iostream>
#include <string>
using namespace std;

int main() {
   string tweet;
   int pos;
   const string LOL = "LOL";
   const string IRL = "IRL";
   const string AFK = "AFK";
   const string NVM = "NVM";
   const string BFF = "BFF";
   const string FTW = "FTW";
   const string IIRC = "IIRC";
   const string TTYL = "TTYL";
   const string IMHO = "IMHO";
   
   
   cout << "Enter a complete tweet: ";
   getline(cin, tweet);
   
   // Resize the tweet to 160 chars
   tweet.resize(160);
   
   // Output decoded abbreviation from tweet
   pos = tweet.find(LOL);
   if (pos >= 0) {
	  tweet.replace(pos, LOL.length(), "laughing out loud");
   }
   pos = tweet.find(IRL);
   if (pos >= 0) {
      tweet.replace(pos, IRL.length(), "in real life");
   }
   pos = tweet.find(AFK);
   if (pos >= 0) {
      tweet.replace(pos, AFK.length(), "away from keyboard");
   }
   pos = tweet.find(NVM);
   if (pos >= 0) {
      tweet.replace(pos, NVM.length(), "never mind");
   }
   pos = tweet.find(BFF);
   if (pos >= 0) {
      tweet.replace(pos, BFF.length(), "best friends forever");
   }
   pos = tweet.find(FTW);
   if (pos >= 0) {
      tweet.replace(pos, FTW.length(), "for the win");
   }
   pos = tweet.find(IIRC);
   if (pos >= 0) {
      tweet.replace(pos, IIRC.length(), "if I recall correctly");
   }
   pos = tweet.find(TTYL);
   if (pos >= 0) {
      tweet.replace(pos, TTYL.length(), "talk to you later");
   }
   pos = tweet.find(IMHO);
   if (pos >= 0) {
      tweet.replace(pos, IMHO.length(), "in my humble opinion");
   }
   
   // Print the updated tweet
   cout << tweet;
   
   return 0;
}
