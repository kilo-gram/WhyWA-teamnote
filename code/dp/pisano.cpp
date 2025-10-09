// return pisano period(maybe you can modify m * m to m + m in 'for')
// then you should calculate fibbonacci value at most Pth (P is pisano period)
// and just find i%pth fibbonacci value. That's collect value.
ll pisano(ll m) {
    ll previous = 0;
    ll cur = 1;
    ll temp;

    for (ll i = 0; i < m * m; i++) {
        temp = (previous + cur) % m;
        previous = cur;
        cur = temp;

        // found pisano period
        if (previous == 0 && cur == 1) {
            return i + 1;
        }
    }
}
