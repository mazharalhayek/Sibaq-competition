#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    int maximum = *std::max_element(values.begin(), values.end());
    int threshold = std::max(0, maximum - d);

    int ans = 0;
    for (int value : values) {
        ans += std::max(0, threshold - value);
    }

    std::cout << ans << std::endl;

    return 0;
}
