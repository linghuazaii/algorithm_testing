#ifndef _UTILITY_H
#define _UTILITY_H
/*
 * File: utility.h
 * Description: common functions 
 * Author: Charles. 2017-3-2
 * Mailto: charlesliu.cn.bj@gmail.com
 */
#include <vector>
#include <unistd.h>
#include <inttypes.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

uint32_t BKDRHash32(const char *str, uint32_t len); /* 32bit version */
uint64_t BKDRHash64(const char *str, uint64_t len); /* 64bit version */
int64_t urandom64(int64_t max = 100, int64_t min = 0, int64_t base = 256); /* 32bit version */
int32_t urandom32(int32_t max = 100, int32_t min = 0, int32_t base = 256); /* 64bit version */

void dump_vec(vector<int> &data, const char *description);

#endif
