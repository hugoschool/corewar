    .name "xor"
    .comment "caca"

# Only registers
    ld %3, r1
    ld %2, r2
    ld %84, r3
    xor r1, r2, r3 # should return 2

# Direct values
    xor %3, %2, r3 # should return 2
