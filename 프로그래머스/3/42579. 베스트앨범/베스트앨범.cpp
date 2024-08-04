#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define SWAP(x,y) ((x)^=(y), (y)^=(x), (x)^=(y))

struct best_album {
    int top1;
    int top2;

    int sum;
    int top1_index;
    int top2_index;

    best_album() : top1(0), top2(0), sum(0), top1_index(-1), top2_index(-1) {}
};

struct genres_sort {
    string genres;
    int sum;
};

bool compare_genres(const genres_sort &p, const genres_sort &q) {
    return p.sum > q.sum;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, best_album> kind_of_genres;

    for (int i = 0; i < genres.size(); i++) {
        kind_of_genres[genres[i]].sum += plays[i];

        if (kind_of_genres[genres[i]].top2 < plays[i]) {
            kind_of_genres[genres[i]].top2 = plays[i];
            kind_of_genres[genres[i]].top2_index = i;

            if (kind_of_genres[genres[i]].top1 < kind_of_genres[genres[i]].top2) {
                SWAP(kind_of_genres[genres[i]].top1, kind_of_genres[genres[i]].top2);
                SWAP(kind_of_genres[genres[i]].top1_index, kind_of_genres[genres[i]].top2_index);
            }
        }
    }

    vector<genres_sort> sort_genres;

    for (auto it : kind_of_genres) {
        sort_genres.push_back({ it.first, it.second.sum });
    }

    sort(sort_genres.begin(), sort_genres.end(), compare_genres);

    for (int i = 0; i < sort_genres.size(); i++) {
        answer.push_back(kind_of_genres[sort_genres[i].genres].top1_index);

        if (kind_of_genres[sort_genres[i].genres].top2_index != -1)
            answer.push_back(kind_of_genres[sort_genres[i].genres].top2_index);
    }

    return answer;
}