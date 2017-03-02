#include "utility.h"

/**
 * BKDRHash 32bit version
 */
uint32_t BKDRHash32(const char *str, uint32_t len) {
    uint32_t seed = 1313131;
    uint32_t hash = 0;
    uint32_t i = 0;

    for (i = 0; i < len; ++str, ++i) {
        hash = (hash * seed) + (*str);
    }

    return (hash & 0x7FFFFFFF);
}
/**
 * BKDRHash 64bit version
 */
uint64_t BKDRHash64(const char *str, uint64_t len) {
    uint64_t seed = 1313131;
    uint64_t hash = 0;
    uint64_t i = 0;

    for (i = 0; i < len; ++str, ++i) {
        hash = (hash * seed) + (*str);
    }

    return (hash & 0x7FFFFFFFFFFFFFFF);
}

/**
 * get a random number, 64bit version.
 * @max: set max, 0 to ignore, default is (0)
 * @min: set min, 0 to ignore, default is (0)
 * @base: string length retrieve from /dev/urandom, default (256)
 *        the longer the length, the longer cpu time will be used
 *        to caculate BKDRHash.
 */
int64_t urandom64(int64_t max, int64_t min, int64_t base) {
    if (max <= min || base < 64)
        return -1;

    int fd = open("/dev/urandom", O_RDONLY);
    char buffer[base];
    uint64_t hash;
    int64_t result;

    read(fd, buffer, base);
    hash = BKDRHash64(buffer, base);

    int64_t seed = (int64_t)(hash % (max - min));
    result = min + seed;

    close(fd);

    return result;
}


/**
 * get a random number, 32bit version.
 * @max: set max, 0 to ignore, default is (0)
 * @min: set min, 0 to ignore, default is (0)
 * @base: string length retrieve from /dev/urandom, default (256)
 *        the longer the length, the longer cpu time will be used
 *        to caculate BKDRHash.
 */
int32_t urandom32(int32_t max, int32_t min, int32_t base) {
    if (max <= min || base < 64)
        return -1;

    int fd = open("/dev/urandom", O_RDONLY);
    char buffer[base];
    uint32_t hash;
    int32_t result;

    read(fd, buffer, base);
    hash = BKDRHash32(buffer, base);
    int32_t seed = (int32_t)(hash % (max - min));
    result = min + seed;

    close(fd);

    return result;
}

void dump_vec(vector<int> &data, const char *description) {
    vector<int>::iterator it;
    cout<<"=========== "<<description<<" ==========="<<endl;
    for (it = data.begin(); it != data.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<"\n============================================"<<endl;
}
