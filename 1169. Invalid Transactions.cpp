// https://leetcode.com/problems/invalid-transactions/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct Node {
    string name, city;
    int time, amount;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Node> a(n);
        vector<string> ret;
        for (int i = 0; i < n; ++i) {
            string buf(transactions[i]);
            for (auto& c : buf) {
                if (c == ',') c = ' ';
            }
            stringstream ss(buf);
            ss >> a[i].name >> a[i].time >> a[i].amount >> a[i].city;
        }
        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (a[i].name == a[j].name 
                    && abs(a[i].time - a[j].time) <= 60 
                    && a[i].city != a[j].city) {
                        found = true;
                }
                if (a[i].amount > 1000) found = true;
            }
            if (found) ret.push_back(transactions[i]);
        }
        return ret;
    }
};