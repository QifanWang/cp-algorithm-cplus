struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    void reset(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) { // if l = 0 , yield sum(r) - sum(-1) = sum(r)
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};



struct FenwickTree_OneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree_OneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int lowbit(int idx) {
        return idx & (-idx);
    }

	//in below funcions, the argument idx, l, r,  are not one-based
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= lowbit(idx))
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += lowbit(idx))
            bit[idx] += delta;
    }
};
