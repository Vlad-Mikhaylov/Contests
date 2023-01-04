bool check(int x) {
    int cows = 1;
    int last_cow = coords[0];
    for (int c : coords) {
        if (c - last_cow >= x) {
            cows++;
            loast_cow = c;
        }
    }
    return cows >= k;    
}

int solve() {
    sort(coords.begin(), coords.end());
    int left = 0;
    int right = coords.back() - coords[0] + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}