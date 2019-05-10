#include "mwbb_test.h"
#include "rc_test.h"
#include "shownonempty_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
