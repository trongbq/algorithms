#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

void display(string s1, string s2, vector<vector<int> > mem) {
    cout << "Mem:" << endl;
    int n = s1.size();
    int m = s2.size();
    for (int i = 0; i<= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j != 0) {
                cout << s2[j-1] << "\t";
            } else if (j == 0 && i != 0) { 
                cout << s1[i-1] << "\t";
            } else if (i == 0 && j == 0){
                cout << "\t";
            } else {
                cout << mem[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

string reverse(string str) { 
    string s;
    for (int i = str.size() - 1; i >= 0; i--) {
        s.push_back(str[i]);
    }
    return s;
} 

string buildStringFromMem(string s1, string s2, vector<vector<int> > mem) {
    string s;
    int i = s1.size();
    int j = s2.size();
    while (i != 0 && j != 0) {
        if (s1[i-1] == s2[j-1]) {
            s.push_back(s1[i-1]);
            i--;
            j--;
        } else if (mem[i-1][j] > mem[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return reverse(s);
}

vector<vector<int> > lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> > mem(n+1, vector<int>(m+1, 0));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0 || i == 0) {
                mem[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]) {
                mem[i][j] = mem[i-1][j-1] + 1;
            } else {
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
    }
    
    return mem;
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    vector<vector<int> > mem = lcs(s1, s2);
    display(s1, s2, mem);
    string s = buildStringFromMem(s1, s2, mem);
    cout << "\nLCS of " << s1 << " and " << s2 << " is: " << s << endl;

    return 0;
}
