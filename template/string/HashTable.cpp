#include <cstring>
#include <algorithm>

using namespace std;
typedef unsigned long long ULL;

template <class value_type>
struct HashTable {
    static const int MAX = 5009;
    int first[MAX], tot;
    struct Node {
        ULL key;
        value_type value;
        int next;
    } node[MAX];
    void clear() {
        memset(first, -1, sizeof(first)), tot = 0;
    }
    int count(ULL key) const {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) return 1;
        }
        return 0;
    }
    // insert `value` into the hashtable
    // if the key is already exist,  returns <true, the old value>
    // if the key is not already exist, returns <false, the new value>
    pair<bool, value_type> insert(ULL key, value_type value) {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) {
                value_type old = node[i].value;
                node[i].value = value;
                return make_pair(true, old);
            }
        }
        node[tot].key = key, node[tot].value = value, node[tot].next = first[k];
        first[k] = tot++;
        return make_pair(false, value);
    }

    value_type &operator[](ULL key) {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) {
                return node[i].value;
            }
        }
        node[tot].key = key, node[tot].value = value_type(), node[tot].next = first[k];
        first[k] = tot++;
        return node[tot - 1].value;
    }
};

HashTable<int> mp;

int main() {

    return 0;
}