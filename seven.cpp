#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h>  <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>    std:string std:stoi
#include <sstream>   std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

int main(int argc, char** argv) {
   int N = 0;
   scanf("%d", &N); 
   printf("%d\n", N);
   
   vector<int> v;
   int k = 0;
   while ((scanf("%d", &k) != EOF))
     v.push_back(k);

  int cnt = 0;
  for (int i=0; i<N; ++i) 
   for (int j=i+1; j<N; ++j) {
     string a = to_string(v[i]), b = to_string(v[j]);
     long long int s;
     s = stoi(a+b);
     if (s % 7 == 0) cnt++;
     s = stoi(b+a);
     if (s % 7 == 0) cnt++;
   } 
  return cnt;
}
