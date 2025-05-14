    .name "zjmp"
    .comment "caca"

live:
    aff r8

ok:
	ld %0, r8
	zjmp %:live
