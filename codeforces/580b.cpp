#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

double tick() {
  static clock_t oldtick;
  clock_t newtick = clock();
  double diff = 1.0 * (newtick - oldtick) / CLOCKS_PER_SEC;
  oldtick = newtick;
  return diff;
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 1e5 + 10;
pii aa[maxn];

int main(int argc, char** argv) {
  int n, d; cin >> n >> d;
  fori (i, 0, n) {
    int a, b; cin >> a >> b;
    aa[i].first = a;
    aa[i].second = b; 
  } 

  sort(aa, aa + n);

  // fori (i, 0, n) {
  //   trace(aa[i].first, aa[i].second);
  // } 

  ll lo, cur, ret;
  lo = 0;
  cur = aa[0].second;
  ret = 0;
  fori (i, 1, n) {
    while (aa[i].first - aa[lo].first >= d) {
      // trace(ret, cur, lo);
      ret = max(ret, cur);
      cur -= aa[lo].second;
      ++lo;
    } 
    cur += aa[i].second;
  }

  ret = max(ret, cur);
  output(ret);
  return 0;
}
