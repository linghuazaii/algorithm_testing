#include "generator.h"

int main(int argc, char **argv) {
    vector<int> result = unique_generate_vec(12);
    dump_vec(result, "test_data");

    return 0;
}
