#ifndef DYNAMIC_PROGRAMMING_MOUNTAIN_SCENES_H_
#define DYNAMIC_PROGRAMMING_MOUNTAIN_SCENES_H_

#include <cmath>
#include <vector>

// Problem described here:
// https://open.kattis.com/problems/scenes

using namespace std;

int invalidScenes(const int S, const int W, const int H) {
  const int max_full_rows = std::min(H, S / W);
  return max_full_rows + 1;
}

// T~O(S*W), S~O(S*W);
int allScenesRecursive(
    const int S, const int W, const int H, vector<vector<int>>& memo) {
  if (S < 0) { return 0; }

  if (memo[S][W] != -1) { return memo[S][W]; }

  int res = 0;
  if (S == 0) {
    res = 1;
  } else if (W == 1) {
    res = min(S + 1, H + 1);
  } else {
    for (int i = 0; i <= H; ++i) {
      res += allScenesRecursive(S - i, W - 1, H, memo);
    }
  }

  memo[S][W] = res;
  return res;
}

// T~O(S*W), S~O(S);
int allScenesIterative(const int S, const int W, const int H) {
  vector<int> ways(S + 1);
  // Initialize ways for W = 1
  for (int s = 0; s <= S; ++s) { ways[s] = min(s + 1, H + 1); }

  for (int w = 2; w <= W; ++w) {
    vector<int> new_ways(S + 1, 0);
    for (int s = 0; s <= S; ++s) {
      for (int i = max(s - H, 0); i <= s; ++i) { new_ways[s] += ways[i]; }
    }
    ways = new_ways;
  }
  return ways[S];
}

int numMountainScenesRecursive(const int S, const int W, const int H) {
  vector<vector<int>> memo(S + 1, vector<int>(W + 1, -1));
  const int all_scenes = allScenesRecursive(S, W, H, memo);
  const int invalid_scenes = invalidScenes(S, W, H);
  return all_scenes - invalid_scenes;
}

int numMountainScenesIterative(const int S, const int W, const int H) {
  const int all_scenes = allScenesIterative(S, W, H);
  const int invalid_scenes = invalidScenes(S, W, H);
  return all_scenes - invalid_scenes;
}

#endif  // DYNAMIC_PROGRAMMING_MOUNTAIN_SCENES_H_
