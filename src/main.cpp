#include <iostream>

#include "misc.h"

int main() {
    std::string base_url = "http://swapi.co/api/";

    auto people_list = get_data_from_url(base_url + "people/");
    auto people_count = get_people_count(people_list);

    auto random_number = get_random_int(1, people_count);
    auto random_people = get_data_from_url(base_url + "people/" +
                                           std::to_string(random_number) + '/');
    auto name = get_name_from_people(random_people);

    std::cout << to_lower(replace_space_with_underscore(name)) << "\n";

    return 0;
}
