#include <gtest/gtest.h>

#include "../src/misc.h"

TEST(replace_space_with_underscore, test) {
    ASSERT_STREQ("a_b", replace_space_with_underscore("a b").c_str());
    ASSERT_STREQ("a_b_c", replace_space_with_underscore("a b c").c_str());
}
