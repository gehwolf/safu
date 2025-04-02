# SPDX-License-Identifier: MIT
create_unit_test(
  NAME
  test_path_safuPathInitialize_utest
  SOURCES
    case_success.c
    # case_err_out_of_bounds.c
    # case_err_uninitialized.c
    safuPathInitialize_utest.c
  LIBRARIES
    safu_static
)
