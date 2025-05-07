    .name "and"
    .comment "caca"

# Only registers
    ld %3, r1
    ld %2, r2
    ld %84, r3
    and r1, r2, r3 # should return 2

# Direct values
    and %3, %2, r3 # should return 2
