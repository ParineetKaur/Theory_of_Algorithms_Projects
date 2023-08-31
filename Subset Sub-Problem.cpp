//Question: How can we partition a set of integers into two subsets with equal sums, and if such a partition exists, what are the subsets?
//Topics Covered: 1)Subset Sub-Problem: The code, in this case, aims to find two subsets with equal sums, 2) Combinatorial Algorithm: With the usage of 'all_subsets', the function generates all possible subsets of a given set, 3) Recursion, 4) Date Structures

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> all_subsets(vector<int> set) {
    vector<vector<int>> subsets;
    for (int k = 0; k <= set.size(); k++) {
        vector<vector<int>> subsets_of_k = {{}};
        for (int x : set) {
            vector<vector<int>> new_subsets_of_k;
            for (vector<int> subset : subsets_of_k) {
                if (subset.size() < k) {
                    new_subsets_of_k.push_back(subset);
                }
                if (subset.size() == k - 1) {
                    subset.push_back(x);
                    new_subsets_of_k.push_back(subset);
                }
            }
            subsets_of_k = new_subsets_of_k;
        }
        subsets.insert(subsets.end(), subsets_of_k.begin(), subsets_of_k.end());
    }
    return subsets;
}

pair<vector<int>, vector<int>> partition(vector<int> set) {
    int S = 0;
    for (int x : set) {
        S += x;
    }
    if (S % 2 == 1) {
        return make_pair(vector<int>(), vector<int>());
    }

    for (vector<int> subset : all_subsets(set)) {
        if (!subset.empty() && subset.size() < set.size()) {
            int s = 0;
            for (int x : subset) {
                s += x;
            }
            if (2 * s == S) {
                vector<int> complement;
                for (int x : set) {
                    if (find(subset.begin(), subset.end(), x) == subset.end()) {
                        complement.push_back(x);
                    }
                }
                return make_pair(subset, complement);
            }
        }
    }
    return make_pair(vector<int>(), vector<int>());
}
