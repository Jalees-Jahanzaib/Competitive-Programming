/* USER: 308958 (osdajigu) */
/* PROBLEM: 59 (123 - Searching Quickly) */
/* SUBMISSION: 15014519 */
/* SUBMISSION TIME: 2015-02-20 23:12:15 */
/* LANGUAGE: 3 */

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>
using namespace std;
#define ii pair<double, double>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 100000 + 100
#define LIMIT 1000000
#define MOD 1000000007

map<string, bool> words;
map<string, vector<string> > print;
map<string, vector<string> >::iterator it;
string s;

string toLowerCase(string s) {
    for(int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
    return s;
}

string toUpperCase(string s) {
    for(int i = 0; i < s.size(); i++) s[i] = toupper(s[i]);
    return s;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin >> s && s != "::") words[s] = true;

    while(getline(cin, s)) {
        string aux, current = "";
        s = toLowerCase(s);
        istringstream ss(s);
        while(ss >> aux){
            aux = toLowerCase(aux);
            if(!words[aux]) {
                string toAdd = s;
                toAdd.replace(current.size(), aux.size(), toUpperCase(aux));
                print[aux].PB(toAdd);
            }
            current += aux + " ";
        }
    }

    for(it = print.begin(); it != print.end(); it++) {
        for(int i = 0; i < (*it).second.size(); i++) {
            cout << (*it).second[i] << "\n";
        }
    }

}
