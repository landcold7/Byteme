#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

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

using T = map<string, int>; // c++11

T helper(string s) {
  if (s.empty()) return T();
  if (s[0] == '(') {  // Note
    int n=1, i=1;
    while (i<s.size() && n) { // find the index which matches '(' such as (..(..)..)
      if (s[i]== '(') n++;
      else if (s[i]==')') n--;
      i++;
    }
    T res = helper(s.substr(1, i-2)); // parse string inside parentheses
    // parse number after parentheses
    int num = 0;
    while (i<s.size()&& isdigit(s[i]))
      num = 10*num + s[i++]-'0';
    if (num == 0) num = 1;

    for (auto &it : res) 
      it.second *= num; // times num for each string in m 

    T m = helper(s.substr(i));  // parse rest of string
    for (auto &it : m) {
      res[it.first] += it.second; // if elements already in res then plus the number from m
                                      // if not then just set to count from m
      /* for clear, we can also write like this */
      /*if (res.find(it.first) != it.end())
        res[it.first] += it.second;
      else
        res[it.first] = it.second;*/
    } 
    return res;
  } else {
    T res;
    int i=0, num=0;
    string element = "";
    element += s[i++];  // first uppercase character
    while (i<s.size() && islower(s[i])) // following lowercase characters 
      element += s[i++];
    // parse number of this element
    while (i<s.size() && isdigit(s[i])) 
      num = 10*num + s[i++]-'0';
    if (num == 0) num = 1;
    // put (element, number) pair into map
    res[element] = num;
    // parse rest of string
    T m = helper(s.substr(i));
    for (auto &it: m)
      res[it.first] += it.second; // merge two maps
    return res;
  } 
}

string countOfAtoms(string s) {
    T mp = helper(s);
    string ret = ""; 
    for (auto it: mp) {
      ret += it.first;
      if (it.second > 1) ret += to_string(it.second);
    } 
    return ret;
}

int main(int argc, char** argv) {
  return 0;
}
