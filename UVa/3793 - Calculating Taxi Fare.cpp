#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 100;
const double EPS = 1e-5;
const int INF = INT_MAX;

ll value_kilometer(int kilometer, int x = 0) {
    if(kilometer <= 10) return 1000 + x*200;
    if(kilometer <= 30) return 250 + x*50;
    return 100 + x*20;
}

int main( ) {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    ll l, m;
    while(cin >> s && s != "--") {
        vector<string> names;
        vector<ll> len, mins;

        cin >> l >> m;
        names.push_back(s);
        len.push_back(l);
        mins.push_back(m);
        while(cin >> s && s != "$") {
            cin >> l >> m;
            names.push_back(s);
            len.push_back(l);
            mins.push_back(m);
        }
        string start, finish; cin >> start >> finish;
        string hour; cin >> hour >> s;
        hour[2] = ' ';
        stringstream ss(hour);
        ll time, a, b, total_time = 0, ans = 0;
        ss >> a >> b;
        time = a*60+b;

        bool started = false;
        ll kilometers = 0;
        for(int i = 0; i < names.size(); i++) {
            if(names[i] == start) started = true;
            if(started) {
                for(int j = 0; j < len[i]; j++) {
                    total_time += mins[i];
                    bool night = false;
                    for(int k = 0; k < mins[i]; k++) {
                        time = (time+1)%(24*60);
                        if(time >= 1 && time <= 360)
                            night = true;
                    }
                    kilometers++;
                    if(night) {
                        ans += value_kilometer(kilometers, 1);
                    }
                    else {
                        ans += value_kilometer(kilometers);
                    }
                }
            }

            if(names[i] == finish) break;
        }

        double velocity = 60*(kilometers*1.0)/total_time;
        if(velocity < 30.0)
            ans = double(ans)*1.1;

        cout << ans << "\n";
    }

}

