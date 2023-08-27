#include <iostream>
#include <vector>

using namespace std;

void smth(vector<int>& answ);

int main() {
    int t;
    cin >> t;

    vector<vector<int>> vec(t);
    for(int i = 0; i < t; i++) {
        smth(vec[i]);
    }

    for(auto& a: vec) {
        for(auto val: a) {
            cout << val << '\n';
        }

        cout << '\n';
    }

}

void smth(vector<int>& answ) {
    int n;
    cin >> n;

    int mini = 15;
    int maxi = 30;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int t;
        cin >> t; 
        if(s == ">=") {
            mini = max(mini, t);
        }

        if(s == "<=") {
            maxi = min(maxi, t);
        }

        if(mini <= maxi) 
            answ.push_back(mini);
        else
            answ.push_back(-1);

    }

}