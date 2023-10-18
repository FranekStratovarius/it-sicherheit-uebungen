add_rules("mode.debug", "mode.release")

target("uebung_001")
    set_kind("binary")
    add_files("src/*.c")
	add_includedirs("include")