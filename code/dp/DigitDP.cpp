vector<int> num;
int a, b, d, k;
int DP[12][12][2];

int find(int pos, int cnt, int f) {
    if (cnt > k) return 0;

    if (pos == num.size()) {
        if (cnt == k) return 1;
        return 0;
    }

    if (DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    // f ? (greater than b) : (already smaller than b)
    if (f == 0) LMT = num[pos];
    else LMT = 9;

    for (int dgt = 0; dgt <= LMT; dgt++) {
        int nf = f;
        int ncnt = cnt;
        if (f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if (dgt == d) ncnt++;
        if (ncnt <= k) res += find(pos + 1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int digitcount(int b) {
    num.clear();
    while(b > 0) {
        num.push_back(b % 10);
        b /= 10;
    }
    reverse(num.begin(), num.end());

    memset(DP, -1, sizeof(DP));
    int res = find(0, 0, 0);
    return res;
}
