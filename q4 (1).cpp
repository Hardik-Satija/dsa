#include <iostream>
#include <queue>
using namespace std;
void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};
    for (char ch : str) {
        int idx = ch - 'a';
        freq[idx]++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
}
int main() {
    string s;
    cout << "Enter characters (no spaces): ";
    cin >> s;
    cout << "Output: ";
    firstNonRepeating(s);
    return 0;
}

