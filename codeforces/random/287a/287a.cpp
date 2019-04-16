//============================================================================
// Name        : 287a
// Date        : Mon Apr 15 21:03:47 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fori(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
  vs a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= 2; ++i) {
    for (int j = 0; j <= 2; ++j) {
      int w, b;
      w = b = 0;
      for (int h = i; h < i + 2; ++h) {
        for (int k = j; k < j + 2; ++k) {
          if (a[h][k] == '#') {
            ++b;
          } else {
            ++w;
          }
        }
      }
      if (w <= 1 || b <= 1) {
        output("YES");
        return;
      }
    }
  }
  output("NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

