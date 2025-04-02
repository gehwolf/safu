// SPDX-License-Identifier: MIT
#include <safu/result.h>
#include <stdio.h>

#include "safu/path.h"
#include "safu/path_types.h"
#include "safu/vector.h"
#include "safuPathInitialize_utest.h"

void safuTestSafuPathInitializeSuccess(UNUSED void **state) {
    safuResultE_t result = SAFU_RESULT_OK;

    struct {
        size_t segmentCount;
        const char *value;
    } testPaths[] = {
        {0, ""},
        {0, "/"},
        {0, "///"},
        {3, "/a/b/c/"},
        {3, "a/b/c/"},
        {3, "/a/b/c"},
        {3, "a/b/c"},
        {3, "/a//b/c/"},
    };

    for (uint32_t i = 0; i < ARRAY_SIZE(testPaths); i++) {
        PARAM("Path %s", testPaths[i].value);

        safuPath_t path = {0};
        result = safuPathInitialize(&path, testPaths[i].value);
        assert_int_equal(result, SAFU_RESULT_OK);

        size_t segmentCount = 0;
        result = safuPathGetSegmentCount(&path, &segmentCount);
        assert_int_equal(result, SAFU_RESULT_OK);
        assert_int_equal(segmentCount, testPaths[i].segmentCount);

        printf("%c", path.delimiter);
        for (size_t j = 0 ; j < segmentCount; j++) {
            safuPathSegment_t* segment = safuVecGet(&path.segments, j);
            printf("%.*s%c", (int)segment->length, segment->begin, path.delimiter);
        }
        printf("\n");

        safuPathDeleteMembers(&path);
    }
}
