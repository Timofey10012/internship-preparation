#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct Train
{
    Train(int id, int pos, int dir, int v)
        :id(id), pos(pos), dir(dir), v(v) {
    }

    int id, pos, v;
    char dir;
};

int main() {
    int N, L, M, T;
    std::cin >> N >> L >> M >> T;

    std::vector<Train> trains;
    for (int i = 0; i < N; ++i) {
        int id, pos, v;
        char dir;
        std::cin >> id >> pos >> dir >> v;
        trains.emplace_back(id, pos, dir, v);
    }

    std::unordered_set<int> sensors;
    for (int i = 0; i < M; ++i) {
        int s;
        std::cin >> s;
        sensors.insert(s);
    }

    bool any = false;
    for (int i = 0; i < N; ++i) {
        int trainPosNow = trains[i].pos;
        int delta = trains[i].v * T;
        if (trains[i].dir == 'L') delta *= -1;
        int trainPosFuture = trainPosNow + delta;
        if (trains[i].dir == 'L') std::swap(trainPosNow, trainPosFuture);

        for (int pos = trainPosNow; pos <= trainPosFuture; pos++) {
            if (sensors.count(pos % L)) {
                std::cout << trains[i].id << " ";
                any = true;
                break;
            }
        }
    }

    if (!any) std::cout << "-1";

    return 0;
}