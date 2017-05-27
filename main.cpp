#include "generator.h"

vector<int> max_length(vector<int> &data, vector<int> &Len, int index) {
    vector<int> candidates;
    int _max = 0;

    for (int i = 0; i < index; ++i) {
        if (_max < Len[i] && data[index] > data[i])
            _max = Len[i];
    }

    for (int i = 0; i < index; ++i) {
        if (_max == Len[i])
            candidates.push_back(i);
    }
    return candidates;
}

int longest_increasing_subsequence(vector<int> &data) {
    int count = data.size();
    vector<int> Len(count);
    map<int, vector<int> > Pre;
    vector<int> candidates;
    for (int i = 0; i < count; ++i) {
        candidates = max_length(data, Len, i);
        if (candidates.empty()) {
            Len[i] = 1;
            Pre[i] = vector<int>();
        }
        else {
            Len[i] = Len[candidates[0]] + 1;
            Pre[i] = candidates;
        }
    }
    int len = Len[count - 1];
    for (int i = count - 1; i >= 0; --i) {
        if (Len[i] == len)
            Pre[count].push_back(i);
    }

    //dfs_solutions(); 
    return len;
}

int main(int argc, char **argv) {
    vector<int> data;// = unique_generate_vec(12);
    data.push_back(2);
    data.push_back(4);
    data.push_back(3);
    data.push_back(5);
    data.push_back(1);
    data.push_back(7);
    data.push_back(6);
    data.push_back(9);
    data.push_back(8);
    dump_vec(data, "sequence");
    int len = longest_increasing_subsequence(data);
    cout<<"Max Length: "<<len<<endl;

    return 0;
}
