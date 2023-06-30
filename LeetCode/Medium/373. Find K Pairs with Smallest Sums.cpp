class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		if(nums1.empty() || nums2.empty() || k<=0) return {};
		auto comp = [&nums1, &nums2](auto const &lhs, auto const &rhs){
            auto &[li, lj] = lhs;
            auto &[ri, rj] = rhs;
			return nums1[li] + nums2[lj] > nums1[ri] + nums2[rj];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
		pq.emplace(0, 0);
		vector<vector<int>> ans;
		while (k-- && pq.size()) {
			auto [i, j] = pq.top();
			pq.pop();
			ans.push_back({nums1[i], nums2[j]});
			if(i+1<nums1.size()) pq.emplace(i+1, j);
			if(i==0 && j+1<nums2.size()) pq.emplace(i, j+1);
		}
		return ans;
	}
};