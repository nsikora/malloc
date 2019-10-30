#!/bin/sh
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="/Users/nsikora/my_github/malloc/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
