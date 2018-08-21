#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

// Accepted
string shortestPalindrome(string s) {
  string r = "";
  for (auto c : s)
    r = c + r;    // reverse input string
  for (int i=0; i<r.size(); ++i) {
    string t = r.substr(0, i);
    string o = r.substr(i); 
    if (s.substr(0, o.size()) == o)
      return t + s;
  }
  return "";
}