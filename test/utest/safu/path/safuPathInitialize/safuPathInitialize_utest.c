// SPDX-License-Identifier: MIT
#include "safuPathInitialize_utest.h"

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(safuTestSafuPathInitializeSuccess),
        // cmocka_unit_test(safuTestSafuPathInitializeErrOutOfBounds),
        // cmocka_unit_test(safuTestSafuPathInitializeErrUninitialized),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
