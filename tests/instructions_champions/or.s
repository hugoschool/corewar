    .name "or"
    .comment "caca"

# Only registers
    ld %3, r1
    ld %2, r2
    ld %84, r3
    or r1, r2, r3 # should return 2

# Direct values
    or %3, %2, r3 # should return 2
