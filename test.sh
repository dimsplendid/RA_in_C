# File    : test.sh
# Dscrpt. : test unit of RA_in_C
# Author  : dimsplendid@gmail.com
# Date    : 2020/04/17

#!/bin/bash

try() {
    expected="$1"
    function="$2"
    # input="$3"

    ./test_RA_in_C "$function" # "$input"
    actual="$?"

    if [ "$actual" = 1 ]; then
        echo "$function => $actual"
    else
        echo "$function => 1 expected, but got $actual"
        exit 1
    fi
}

try 1 testAdd

echo OK