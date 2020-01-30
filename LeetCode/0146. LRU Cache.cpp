// Time  : 112 ms (95.14%)
// Memory: 40.3 MB (8.81%)

class LRUCache {
   public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        lst.erase(it->second.second);
        lst.push_back(key);
        it->second.second = --lst.end();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            // inserting a new value.
            if (lst.size() == capacity) {
                mp.erase(lst.front());
                lst.pop_front();
            }
            lst.push_back(key);
            mp.emplace(key, make_pair(value, --lst.end()));
        } else {
            lst.erase(it->second.second);
            lst.push_back(key);
            it->second.first = value;
            it->second.second = --lst.end();
        }
    }

   private:
    list<int> lst;
    unordered_map<int, pair<int, typename list<int>::iterator>> mp;
    // typename 关键字告诉编译器 list<int>::iterator 在这里是一个类型
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */