#include "misc.h"

#include <cassert>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <random>

#include <curl/curl.h>

#include <rapidjson/document.h>

int writer(char *data, size_t size, size_t nmemb, std::string *buffer) {
    int result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}

std::string get_data_from_url(const std::string &url) {
    CURL *curl = curl_easy_init();
    assert(curl);

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    std::string buffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        auto error = curl_easy_strerror(res);
        curl_easy_cleanup(curl);
        throw std::runtime_error{error};
    }
    curl_easy_cleanup(curl);

    return buffer;
}

std::string replace_space_with_underscore(const std::string &str) {
    auto result{str};
    replace(result.begin(), result.end(), ' ', '_');
    return result;
}

std::string to_lower(const std::string &str) {
    std::string result;
    result.reserve(str.size());
    std::transform(str.begin(), str.end(), std::back_inserter(result), tolower);
    return result;
}

int get_people_count(const std::string &people_list) {
    rapidjson::Document document;
    document.Parse(people_list.c_str());
    return document["count"].GetInt();
}

int get_random_int(int from, int to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from, to);
    return dis(gen);
}

std::string get_name_from_people(const std::string &people) {
    rapidjson::Document document;
    document.Parse(people.c_str());
    return document["name"].GetString();
}