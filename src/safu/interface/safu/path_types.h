// SPDX-License-Identifier: MIT
#pragma once

#include "safu/vector_types.h"

typedef struct safuPathSegment {
    const char *begin;
    const char *end;
    size_t length;
} safuPathSegment_t;

typedef struct safuPath {
    char delimiter;
    safuVec_t segments;
} safuPath_t;
