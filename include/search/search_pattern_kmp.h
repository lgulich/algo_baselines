#ifndef SEARCH_SEARCH_PATTERN_KMP_H_
#define SEARCH_SEARCH_PATTERN_KMP_H_

#include <vector>

using namespace std;

vector<int> createPrefixArray(const vector<int>& pattern) {
  vector<int> prefix(pattern.size(), -1);

  int i = 0;
  int j = 1;

  while (j < pattern.size()) {
    if (pattern[i] == pattern[j]) {
      // We have a match, thus prefix = suffix.
      prefix[j] = i;
      ++j;
      ++i;
    } else if (i > 0) {
      // No match but we are in string, thus we reset to the last pattern.
      i = prefix[i - 1] + 1;
    } else {
      // I is anyways already at beginnning, thus no need to reset.
      ++j;
    }
  }

  return prefix;
}

int searchPatternKmp(const vector<int>& data, const vector<int>& pattern) {
  const vector<int> prefix = createPrefixArray(pattern);

  int pattern_idx = 0;
  int data_idx = 0;

  while (data_idx < data.size()) {
    if (data[data_idx] == pattern[pattern_idx]) {
      if (pattern_idx == pattern.size()-1) {
        return true;
      } else {
        ++data_idx;
        ++pattern_idx;
      }
    } else if (pattern_idx > 0) {
      pattern_idx = prefix[pattern_idx - 1] + 1;
    } else {
      ++data_idx;
    }
  }

  return false;
}


#endif  // SEARCH_SEARCH_PATTERN_KMP_H_
