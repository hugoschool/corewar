.name "test"
    .comment "Nah, I'd lose"

    ld %1 r2
    ld %1 r3
    sti r1 %:live %1
live: live %0
test:    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    aff r2
    add r3, r2, r2
    ld %0, r8
    zjmp %:test
