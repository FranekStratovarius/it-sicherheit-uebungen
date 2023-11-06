add_rules("mode.debug", "mode.release")

target("uebung_002")
    set_kind("binary")
    add_files("src/*.c")
	add_includedirs("include")
