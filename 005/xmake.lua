add_rules("mode.debug", "mode.release")
 
target("uebung_003")
	set_kind("binary")
	add_files("a1.c")
	add_cflags("-fno-stack-protector")