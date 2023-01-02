#include <iostream>
#include "Word.h"
#include "Word.h" // This is intentional
using namespace sdds;
using namespace std;
int main() {
   char filename[256];
   cout << "Enter the following file name" << endl
      << "> FoxInSocks.txt" << endl << "---------------------" << endl;
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
