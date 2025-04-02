// SPDX-License-Identifier: MIT
#pragma once

#include <safu/path_types.h>

#include "safu/result.h"

__BEGIN_DECLS

/*******************************************************************
 * Initialize a new path object for a given string.
 *
 * Parameters:
 *      path: Pointer to the path struct to Initialize.
 *      elementCount: Number of elements that the vector should store.
 *      elementSize: Size of the elements type.
 *
 * Returns:
 *      - `SAFU_RESULT_OK` if successful
 *      - `SAFU_RESULT_FAIED` in error case
 ******************************************************************/
safuResultE_t safuPathInitialize(safuPath_t *path, const char *pathAsString);

/*******************************************************************
 * Free allocated members but not path object itself.
 *
 * Parameters:
 *      path: Pointer to the path struct to free members.
 *
 * Returns:
 *      - `SAFU_RESULT_OK` if successful
 *      - `SAFU_RESULT_FAIED` in case of an error if either path is NULL or
 *         freeing members failed. In the second case the path object stays
 *         in an undefined state do not use it anymore.
 ******************************************************************/
safuResultE_t safuPathDeleteMembers(safuPath_t *path);

safuResultE_t safuPathGetSegmentCount(const safuPath_t *path, size_t *count);
__END_DECLS
