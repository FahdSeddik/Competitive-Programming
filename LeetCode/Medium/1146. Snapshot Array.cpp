class SnapshotArray {
  vector<vector<pair<int, int>>> data_;
  int snap_id;
 public:
    SnapshotArray(const int length) : data_(length), snap_id(0) {
    }
    void set(const int index, const int val) {
        if (data_[index].empty() || data_[index].back().first < snap_id) data_[index].emplace_back(snap_id, val);
        else data_[index].back().second = val;
    }
    int snap() {
        return snap_id++;
    }
    int get(const int index, const int snap_id) {
        auto ub = upper_bound(data_[index].begin(),data_[index].end(),make_pair(snap_id, 0),[&](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
        });
        if (ub == data_[index].begin()) return 0;
        return prev(ub)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */