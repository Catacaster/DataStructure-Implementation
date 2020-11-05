/*
 * sort_common function
 * 2020-06-25
 */
#ifndef SORT_COMMON_H
#define SORT_COMMON_H

#include <vector>

//check if vector a is sorted or not
bool isSorted(std::vector<int> &a);

//print a vector and print whether it is sorted
void print_vector(std::vector<int> &a);

//return a randomized vector of size (length)
std::vector<int> rand_vector(int length);
//return a randomized vector of size (length), from 0 to upper-1
std::vector<int> rand_vector(int length, int upper);

#endif
