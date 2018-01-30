//-----BEGIN union find tree-----
//complexity: -

// [0, n) をノードとする union find tree
class UnionFindTree {
	public:
		UnionFindTree(int n) : N_(n) {
			rank_ = std::vector<int>(n, 0);
			for(int i = 0; i < n; ++i) {
				parent_.push_back(i);
			}
		}
		bool same(int x, int y) {
			assert(0 <= x && x < N_ && 0 <= y && y < N_);
			return findRoot(x) == findRoot(y);
		}
		void unite(int x, int y) {
			assert(0 <= x && x < N_ && 0 <= y && y < N_);
			x = findRoot(x);
			y = findRoot(y);
			if(x == y) return;
			if(rank_[x] < rank_[y]) {
				parent_[x] = y;
			} else {
				parent_[y] = x;
				if(rank_[x] == rank_[y]) ++rank_[x];
			}
		}
	private:
		int findRoot(int x) {
			if(parent_[x] == x) {
				return x;
			} else {
				//rank_[x] = 1; // rank_[x] < N_ なので不要
				return parent_[x] = findRoot(parent_[x]);
			}
		}
		const int N_;
		std::vector<int> parent_;
		std::vector<int> rank_;
};
//-----END union find tree-----
