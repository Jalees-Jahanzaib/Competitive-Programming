#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

bool used[100000][1070];
vector<int> cur_ans;
vector<ii> to_reset;

bool go(int sum, int idx, vector<int> &money) {
    if(sum < 0) return false;
    if(idx == money.size()) {
        if(sum == 0) return true;
        return false;
    }
    if(sum == 0) return true;
    if(used[sum][idx]) return false;
    used[sum][idx] = true;
    to_reset.push_back(ii(sum, idx));
    if(go(sum-money[idx], idx+1, money)) {
        cur_ans.push_back(money[idx]);
        return true;
    }
    if(go(sum, idx+1, money)) return true;
    return false;
}

inline bool is_square(int x) {
    return int(sqrt(x))*int(sqrt(x)) == x;
}

vector<int> solve(int amount, vector<int> &money) {
    to_reset.clear();
    cur_ans.clear();
    go(amount, 0, money);
    for(int i = 0; i < to_reset.size(); i++) {
        used[ to_reset[i].first ][ to_reset[i].second ] = false;
    }
    return cur_ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    for(int i = 1; i <= 10000; i++) {
        int n; cin >> n;
//        int n = i;
        vector<int> ans, money, assigned(n+1);
        for(auto &x : assigned) {
        }
        int sum = 0;
        int s = 0, c = 0;
        for(int i = 1; i <= n; i += 2) cout << i << " ", sum += i, assigned[i] = 1, s += i, c += is_square(s);
        int square = sqrt(sum);
        for(int i = (n&1 ? n-1 : n); i >= 2; i -= 2) money.push_back(i), sum += i;
        int total = square*square;
        for(int i = square+1; i*i <= sum; i++) {

            vector<int> tmp = solve(i*i - total, money);
            for( int j = 0; j < tmp.size(); j++) {
                cout << tmp[j] << " ";
                assigned[ tmp[j] ] = 1;
                total += tmp[j];
                s += tmp[j]; c += is_square(s);
            }

            if(tmp.size() > 0 ) {
                i++;
                money.clear();
                for(int i = (n&1 ? n-1 : n); i >= 2; i -= 2) {
                    if(!assigned[i])
                        money.push_back(i);
                }
            }
        }

        for(int k = 0; k < money.size(); k++) cout << money[k] << " "; cout << "\n";
//        if((c*1.0/n)*1000000 <= 600000)
//            cout << i << " = " << (c*1.0/n)*1000000 <<" " << c << endl;
//    }

}

