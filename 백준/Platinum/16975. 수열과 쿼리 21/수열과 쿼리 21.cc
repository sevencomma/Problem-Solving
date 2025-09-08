#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, a, b, c, d;
vector<ll> arr, tree, lazy;

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (ll)(end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int range_start, int range_end, ll diff) {
    update_lazy(node, start, end);
    if (start > range_end || end < range_start) return;

    if (range_start <= start && end <= range_end) {
        tree[node] += (ll)(end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, range_start, range_end, diff);
    update_range(node * 2 + 1, mid + 1, end, range_start, range_end, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query_range(int node, int start, int end, int range_start, int range_end) {
    update_lazy(node, start, end);
    if (start > range_end || end < range_start) return 0;

    if (range_start <= start && end <= range_end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query_range(node * 2, start, mid, range_start, range_end) +
        query_range(node * 2 + 1, mid + 1, end, range_start, range_end);
}

void build(const vector<ll>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start - 1];
        return;
    }
    int mid = (start + end) / 2;
    build(arr, node * 2, start, mid);
    build(arr, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.resize(N);
    tree.resize(N * 4);
    lazy.resize(N * 4);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    build(arr, 1, 1, N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            update_range(1, 1, N, b, c, d);
        }
        else {
            cout << query_range(1, 1, N, b, b) << '\n';
        }
    }
}