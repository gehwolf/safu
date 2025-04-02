// SPDX-License-Identifier: MIT
#include "safu/path.h"

#include <stdlib.h>

#include "safu/log.h"
#include "safu/path_types.h"
#include "safu/result.h"
#include "safu/vector.h"

safuResultE_t safuPathInitialize(safuPath_t *path, const char *pathAsString) {
    safuResultE_t result = SAFU_RESULT_OK;

    if (path == NULL || pathAsString == NULL) {
        result = SAFU_RESULT_FAILED;
    } else {
        path->delimiter = '/';
        result = safuVecCreate(&path->segments, 10, sizeof(safuPathSegment_t));
        if (result != SAFU_RESULT_OK) {
            safuLogErr("Failed to create vector for path segments");
        } else {
            const char *currentSegment = pathAsString;
            const char *nextSegment = currentSegment;
            for (size_t pos = 0; pathAsString[pos] != '\0'; pos++) {
                if (pathAsString[pos] == path->delimiter || pathAsString[pos + 1] == '\0') {
                    nextSegment = &pathAsString[pos + 1];
                    safuPathSegment_t segment = {
                        .begin = &currentSegment[0],
                        .end = &nextSegment[0],
                        .length = &nextSegment[0] - &currentSegment[0] ,
                    };

                    if(pathAsString[pos] == path->delimiter){
                        segment.length -= 1;
                    }

                    if (segment.length > 0) {
                        safuVecPush(&path->segments, &segment);
                    }
                    currentSegment = nextSegment;
                }
            }
        }
    }

    return result;
}

safuResultE_t safuPathGetSegmentCount(const safuPath_t *path, size_t *count) {
    int result = SAFU_RESULT_FAILED;
    if (path != NULL) {
        *count = safuVecElements(&path->segments);
        result = SAFU_RESULT_OK;
    }
    return result;
}

safuResultE_t safuPathDeleteMembers(safuPath_t *path) {
    int result = SAFU_RESULT_FAILED;
    if (path != NULL) {
        safuVecFree(&path->segments);
        result = SAFU_RESULT_OK;
    }
    return result;
}
