#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, long long> merge(vector<int>& left, vector<int>& right) {
    vector<int> merged;
    long long inversions = 0;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
            inversions += left.size() - i;
        }
    }

    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }

    return {merged, inversions};
}

pair<vector<int>, long long> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1)
        return {arr, 0};

    size_t mid = arr.size() / 2;
    auto left = vector<int>(arr.begin(), arr.begin() + mid);
    auto right = vector<int>(arr.begin() + mid, arr.end());

    auto leftResult = mergeSort(left);
    auto rightResult = mergeSort(right);

    auto mergedResult = merge(leftResult.first, rightResult.first);

    return {mergedResult.first, mergedResult.second + leftResult.second + rightResult.second};
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    auto result = mergeSort(heights);

    cout << result.second << endl;

    return 0;
}
