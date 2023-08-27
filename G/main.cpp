#include <iostream>
#include <vector>

using namespace std;

vector<string> translatorToVal{
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};

vector<string> translatorToMast{
    "S", "C", "D", "H"
};

int toNum(string& card) {
    char val = card[0];
    int res = 0;
    if('2' <= val && val <= '9') {
        res += (val - '2')*4;
    }

    if('A' <= val && val <= 'Z') {
        if(val == 'T') res += 8*4;
        if(val == 'J') res += 9*4;
        if(val == 'Q') res += 10*4;
        if(val == 'K') res += 11*4;
        if(val == 'A') res += 12*4;
    }

    char mast = card[1];
    if(mast == 'S') res += 0;
    if(mast == 'C') res += 1;
    if(mast == 'D') res += 2;
    if(mast == 'H') res += 3;

    return res;
}

string toCard(int num) {
    return translatorToVal[num/4] + translatorToMast[num%4];
}

void solution(vector<int>& win_cards);

int main() {
    int t;
    cin >> t;

    vector<vector<int>> ans(t);
    for(int i = 0; i < t; i++) {
        solution(ans[i]);
    }

    for(auto& a: ans) {
        cout << a.size() << '\n';
        for(auto val: a) {
            cout << toCard(val) << '\n';
        }
    }
}

struct hand {
    int card1 = -1;
    int card2 = -1;

    bool isSet(int table_card) {
        if (card1/4 == table_card/4 && card2/4 == table_card/4) return true;
        return false;
    }
    bool isPair(int table_card) {
        if(card1/4 == table_card/4 || card2/4 == table_card/4 || card1/4 == card2/4) return true;
        return false;
    }

    pair<int, int> retPair(int table_card) {
        if(card1/4 == table_card/4) return {card1, table_card};
        if(card2/4 == table_card/4) return {card2, table_card};
        if(card1/4 == card2/4) return {card1, card2};
        return {-1, -1};
    }

    bool isEqual(hand other) {
        return card1 == other.card1 && card2 == other.card2;
    } 

    int retBestCard(int table_card) {
        return max(max(card1, card2), table_card);
    }
};


void solution(vector<int>& win_cards) {
    int n;
    cin >> n;

    vector<int> isIn(52, 0);
    vector<hand> coloda(n);

    string c1, c2;
    for(int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        int card1 = toNum(c1);
        int card2 = toNum(c2);
        isIn[card1] = 1;
        isIn[card2] = 1;
        coloda[i] = hand{card1, card2};
    }
    
    for(int i = 0; i < 52; i++) {
        if(isIn[i] == 1) continue;
        hand maxi = coloda[0];
        for(auto& val: coloda) {
            if(val.isSet(i)) {
                if(maxi.isSet(i)) {
                    if(maxi.card1/4 < val.card1/4) {
                        maxi = val;
                    }
                    continue;
                }

                maxi = val;
                continue;
            }

            if(val.isPair(i)) {
                if(maxi.isSet(i)) continue;
                if(maxi.isPair(i)) {
                    if(maxi.retPair(i).first/4 < val.retPair(i).first/4) {
                        maxi = val;
                    }
                    continue;
                }
                maxi = val;
                continue;
            }

            // its bestcard
            if(maxi.isSet(i) || maxi.isPair(i)) continue;
            if(maxi.retBestCard(i)/4 < val.retBestCard(i)/4) maxi = val;
        }

        if(maxi.isEqual(coloda[0])) win_cards.push_back(i);
    }


}