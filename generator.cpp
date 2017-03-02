#include "generator.h"

vector<int> generate_vec(int num) {
    vector<int> result;
    for (int i = 0; i < num; ++i) {
        result.push_back(urandom32());
    }

    return result;
}
