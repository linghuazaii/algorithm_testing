#include "generator.h"

vector<int> generate_vec(int num) {
    vector<int> result;
    for (int i = 0; i < num; ++i) {
        result.push_back(urandom32());
    }

    return result;
}

vector<int> unique_generate_vec(int num) {
    set<int> temp_set;
    vector<int> result;
    for (; temp_set.size() < num; ) {
        temp_set.insert(urandom32());
    }

    copy(temp_set.begin(), temp_set.end(), back_inserter(result));
    random_shuffle(result.begin(), result.end());

    return result;
}
