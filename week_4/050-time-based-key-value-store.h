#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct pair_hash {
  size_t operator()(const pair<string, int> &p) const {
    return hash<string>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

class TimeMap { // optimize it by using
                // unordered_map<string,vector<pair<int,string>>>
private:
  unordered_map<pair<string, int>, string, pair_hash> cont;
  unordered_map<string, vector<int>> keys;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    if (!keys.count(key)) {
      cont[{key, timestamp}] = value;
      keys[key].push_back(timestamp);
      return;
    }

    int i = 0, j = keys[key].size() - 1, ind = 0;
    ;
    while (i <= j) {
      int mid = i + (j - i) / 2;

      if (keys[key][mid] > timestamp) {
        j = mid - 1;
      } else if (keys[key][mid] < timestamp) {
        i = mid + 1;
        ind = mid;
      }
    }

    cont[{key, timestamp}] = value;
    keys[key].insert(keys[key].begin() + ind + 1, timestamp);
  }

  string get(string key, int timestamp) {
    if (cont.count({key, timestamp}))
      return cont[{key, timestamp}];
    if (!keys.count(key))
      return "";

    int i = 0, j = keys[key].size() - 1, ind = -1;
    ;
    while (i <= j) {
      int mid = i + (j - i) / 2;

      if (keys[key][mid] > timestamp) {
        j = mid - 1;
      } else if (keys[key][mid] < timestamp) {
        i = mid + 1;
        ind = mid;
      }
    }

    if (ind == -1)
      return "";

    return cont[{key, keys[key][ind]}];
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
