add_rules("mode.debug", "mode.release")
 
target("uebung_005_1")
	set_kind("binary")
	add_files("a1.c")
	add_cflags("-fno-stack-protector")

target("uebung_005_2")
	set_kind("binary")
	add_files("a2.c")
	add_cflags("-fno-stack-protector")

target("uebung_005_3")
	set_kind("binary")
	add_files("a3.c")