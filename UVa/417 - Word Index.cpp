/* USER: 308958 (osdajigu) */
/* PROBLEM: 358 (417 - Word Index) */
/* SUBMISSION: 14202455 */
/* SUBMISSION TIME: 2014-09-14 16:43:31 */
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
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define PB push_back
#define EPS 0.00000001
#define MAX 2e30 + 100
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

int gcd (int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool checkWord(string word) {
    if(word.size() == 1)
        return true;
    for(int i = 1; i < word.size(); i++) {
        if(word[i - 1] >= word[i])
            return false;
    }
    return true;
}
string alphabet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
vector<string> ans;
int current;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ans.PB("-1");
    queue<int> q;
    for(int i = 0; i < 26; i++) {
        ans.PB(alphabet[i]);
        q.push(i + 1);
    }
    while(q.front() <= 83681) {
        current = q.front(); //
        q.pop();
        for(int i = 0; i < 26; i++) {
            if(checkWord(ans[current] + alphabet[i])) {
                ans.PB(ans[current] + alphabet[i]);
                q.push(q.back() + 1);
            }
        }
        //system("pause");
    }
    /*for(int i = 0; i < 50; i++){
        cout << ans[i] << "->" << i << endl;
    }*/
    string word;
    while(cin >> word) {
        if(!checkWord(word)){
            cout << 0 << endl;
            continue;
        }
        else {
            for(int i = 1; i < ans.size(); i++) {
                if(ans[i] == word) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }



}
