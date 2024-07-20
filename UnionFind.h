#pragma once

#include <unordered_map>

template <typename T, typename H = std::hash<T>>
class UnionFind {
public:
    UnionFind() = default;

    ~UnionFind() {
        _root.clear();
        _rank.clear();
    }

    T Find(const T& element) {
        if (_root[element] == element) {
            return element;
        }
        return _root[element] = Find(_root[element]);
    }

    void Union(const T& element_a, const T& element_b) {
        T root_a = Find(element_a);
        T root_b = Find(element_b);

        if (root_a == root_b) {
            return;
        }

        if (_rank[root_a] < _rank[root_b]) {
            _root[root_a] = root_b;
        }
        else if (_rank[root_b] < _rank[root_a]) {
            _root[root_a] = root_b;
        }
        else {
            _root[root_b] = root_a;
            ++_rank[root_a];
        }
    }

    void Connected(const T& element_a, const T& element_b) {
        return Find(element_a) == Find(element_b);
    }

private:
    std::unordered_map<T, T, H>   _root;
    std::unordered_map<T, int, H> _rank;
};
