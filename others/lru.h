#pragma once

#include <optional>
#include <unordered_map>
#include <list>

template<typename K, typename V>
class LruCache{
private:
    std::list<std::pair<K,V> > list_;
    std::unordered_map<K, decltype(list_.begin())> map_;
    size_t capacity_;
public:
    explicit LruCache(int capacity) :capacity_(capacity) {}
    std::optional<V> get(K k) {
        auto it = map_.find(k);
        if (it == map_.end()) {
            return std::nullopt;
        }

        auto p = it->second;
        auto v = p->second;
        list_.emplace_front(k, v);
        map_[k] = list_.begin();
        list_.erase(p);
        return v;
    }
    void put(K k, V v) {
        if (auto it = map_.find(k); it != map_.end()) { // found -> update
            auto p = it->second;
            list_.erase(p);
            list_.emplace_front(k, v);
            map_[k] = list_.begin();
        } else {
            if (list_.size() == capacity_) { // full, remove last
                auto last = list_.back();
                map_.erase(last.first);
                list_.pop_back();
            }

            list_.emplace_front(k, v);
            map_[k] = list_.begin();
        }
    }
};
