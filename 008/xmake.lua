add_rules(
	"mode.debug",
	"mode.release"
)

target("uebung_008_3") do
	set_kind("binary")
	set_warnings("all", "error")

	add_files("src/**.c")
end