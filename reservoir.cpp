#include "generator.h"

vector<int> random_k(vector<int> pool, int k) {
    vector<int> result;
    if (pool.size() < k)
        return result;
    
    for (int i = 0; i < k; ++i)
        result.push_back(pool[i]);

    for (int i = k; i < pool.size(); ++i) {
        int32_t rand = urandom32(i);
        if (rand < k)
            result[rand] = pool[i];
    }

    return result;
}

int main(int argc, char **argv) {
    vector<int> data = unique_generate_vec(100);
    dump_vec(data, "data");
    vector<int> rand = random_k(data, 6);
    dump_vec(rand, "random k");

    return 0;
}
