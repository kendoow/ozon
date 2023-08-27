#include <iostream>
#include <vector>
#include <string>

using namespace std;

void answ(vector<string>& pic);

int main() {
    int t;
    cin >> t;

    vector<vector<string>> vec(t);
    for(int i = 0; i < t; ++i) {
        answ(vec[i]);
    }

    for(int i = 0; i < t; i++) {
        for(auto& str: vec[i]) {
            cout << str << '\n';
        }

        cout << '\n';
    }
}

void input(vector<string>& arr, int n) {
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }
}

void answ(vector<string>& pic) {
    int k, n, m;
    cin >> k >> n >> m;

    vector<string> arr(n);
    input(arr, n);
    vector<string> tmp(n);
    for(int i = 1; i < k; i++) {
        input(tmp, n);
        for(int j = 0; j < n; j++) {
            for(int l = 0; l < m; l++) {
                if(arr[j][l] == '.') arr[j][l] = tmp[j][l];
            }
        }
    }
    pic = arr;
}