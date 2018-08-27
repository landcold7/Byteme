#include<bits/stdc++.h>
using namespace std;

// Numbers can be regarded as product of its factors. For example,
// 8 = 2 x 2 x 2;
  // = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.
// Note:
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Note: 
// Each combination's factors must be sorted ascending, 
// for example: The factors of 2 and 6 is [2, 6], not [6, 2].
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.

// Examples: 
// input: 1
// output: 
// []

// input: 37
// output: 
// []

// input: 12
// output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]

// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

#define vvi vector<vector<int>>
#define pvi(v) for(auto& e: v) cout << e << " "; cout << endl

void dfs(vector<vector<int>> &ret, vector<int> &path, int n) {
  int i = path.empty() ? 2 : path.back();
  for (; i * i <= n; ++i) {
    if (n % i == 0) {
      path.push_back(i);
      path.push_back(n / i);
      ret.push_back(path); 

      path.pop_back();
      dfs(ret, path, n / i);
      path.pop_back();
    }
  }  
}

vector<vector<int>> getFactors(int n) {
  vector<vector<int>> ret;
  vector<int> path;
  dfs(ret, path, n);
  return ret;
}

int main(int argc, char** argv) {
  vvi res = getFactors(32);  
  for (auto &r : res) {
    pvi(r);
  }
  return 0;
}