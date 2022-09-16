/**
 * [1 1 9 2 2 2 6]
 *  i=0 sum = 10
 *  i=1 sum = sum + 1 - 2 = 10 + 1 - 2 = 9
 *  i=2 sum = sum + 1 - 2 = 9 + 1 - 2 = 8
 *  i=3 sum = sum + 9 - 0 = 17
 */
#include <iostream>
#include <vector>

int maxScore(const std::vector<int> &cardPoints, const int k) {
    int sum{0};
    auto n = cardPoints.size();
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }
    auto max = sum;
    for (int i = k - 1; i >= 0; i--) {
        sum -= cardPoints[i];
        sum += cardPoints[n - k + i];
        max = std::max(sum, max);
    }
    return max;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    std::vector<int> cards(n);
    for (auto &el: cards) {
        scanf("%d", &el);
    }
    printf("%d\n", maxScore(cards, k));
}