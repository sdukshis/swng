#ifndef MISC_H
#define MISC_H

#include <string>

std::string get_data_from_url(const std::string &url);

std::string replace_space_with_underscore(const std::string &str);

std::string to_lower(const std::string &str);

int get_people_count(const std::string &people_list);

int get_random_int(int from, int to);

std::string get_name_from_people(const std::string &people);

#endif