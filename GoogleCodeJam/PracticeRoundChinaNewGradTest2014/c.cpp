#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
  vector<string> nameVec;  
  int t;
  int n;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    int count = 0;
    cin >> n;
    nameVec.clear();
    string temp;
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    for (int j = 0; j < n; j++) {
      getline(cin, temp);
      nameVec.push_back(temp);
    }
    string largest = nameVec[0];
    for (int j = 1; j < n; j++)
    {
     // cout << i << ":" << nameVec[j] << "," << largest << endl;
      if (nameVec[j] < largest) {
        count++;
      }
      else
      {
        largest = nameVec[j];
      }
    }
    printf("Case #%d: %d\n", i, count);
  }
}
