#include <iostream>
#include <vector>
#include <set>

class UnionFind
{
public:
    UnionFind(size_t size) {
        graph.resize(size + 1);
        
        for (int i = 0; i < graph.size(); i++) {
            graph[i] = i;
        }
    }

    void unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            graph[b] = a;
        }
    }
    
    std::set<int> getRootsSet() {
        std::set<int> roots;
        for (int i = 1; i < graph.size(); i++) {
            if (!roots.count(find(i))) {
                roots.insert(find(i));
            }
        }

        return roots;
    }

private:
    std::vector<int> graph;

    int find(int a) {
        if (graph[a] != a) {
            graph[a] = find(graph[a]);
        }
        return graph[a];
    }
};

int main() {
    
    int N, M;
    std::cin >> N >> M;
    
    std::set<int> roots;

    if (M) {
        UnionFind union_find(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            std::cin >> u >> v;
            union_find.unionSets(u, v);
        }

        roots = union_find.getRootsSet();

    }
    else {
        for (int i = 1; i <= N; i++) {
            roots.insert(i);
        }
    }

    std::cout << roots.size() - 1 << "\n";

    int rootKing = *roots.begin();
    for (auto root : roots) {
        if (root != rootKing) {
            std::cout << rootKing << " " << root << "\n";
        }
    }

    return 0;
}
