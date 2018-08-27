#include<bits/stdc++.h>
using namespace std;

// 
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> range;
	for (int i=0, start=0; i<nums.size(); ++i) {
		if (i==nums.size()-1 || nums[i+1]>nums[i]+1) {
			// current i is the end of previous range
			range.push_back(to_string(nums[start]));
			if (i > start) range.back() += "->" + to_string(nums[i]);
			// new range start
			start = i+1;
		}
	}        
	return range;
}

//
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> range;
	int start = 0;	// range start pos
	for (int i=0; i<nums.size(); ++i) {
		while (i+1<nums.size() && nums[i]+1==nums[i+1]) 
			++i;			// sliding through range
		// current i is the end of this range
		range.push_back(to_string(nums[start]));
		if (i>start) range.back() += "->" + to_string(nums[i]);
		start = i+1;
	}
	return range;
}

int main(int argc, char** argv) {
  return 0;
}
