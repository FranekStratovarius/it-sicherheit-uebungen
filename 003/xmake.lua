add_rules("mode.debug", "mode.release")

target("uebung_003")
    set_kind("binary")
    add_files("src/*.c")
	add_includedirs("include")

	-- copy assets after build
	after_build(function (target)
		os.cp(path.join("assets"), path.join("$(buildir)", "$(os)", "$(arch)", "$(mode)"))
	end)