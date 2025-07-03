#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    int N, T;
    std::cin >> N >> T;

    std::vector<std::tuple<int, int, int>> trucks;
    std::vector<bool> canTruckArrive(N, false);

    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        trucks.emplace_back(i, l, r);
    }

    std::sort(trucks.begin(), trucks.end(), [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        auto [idA, lA, rA] = a;
        auto [idB, lB, rB] = b;
        return lA < lB;
        });

    std::vector<bool> timeOccupied(T, false);
    
    for (auto [id, l, r] : trucks) {
        if (l >= T) break;
        for (int i = l; i < T && i <= r; i++) {
            if (!timeOccupied[i]) {
                timeOccupied[i] = true;
                canTruckArrive[id] = true;
                break;
            }
        }
    }

    for (bool canArrive : canTruckArrive) {
        std::cout << (canArrive ? "Yes\n" : "No\n");
    }

    return 0;
}