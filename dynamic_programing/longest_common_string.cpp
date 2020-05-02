#include <iostream>

using namespace std;

string lcs(string s1, string s2) {

    return "";    
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    string result = lcs(s1, s2);

    cout << "LCS of " << s1 << " and " << s2 << " is: " << result;

    return 0;
}
