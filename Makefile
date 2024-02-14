all:
	cmake -S ./src -B build_make
	make -C build_make
	rm -rf bin
	mkdir bin
	cp build_make/bubble_sort/bubble_sort bin
	cp build_make/menu/menu bin
	cp build_make/shell_sort/shell_sort bin

ninja:
	cmake -S ./src -B build_ninja -G Ninja
	ninja -C build_ninja
	rm -rf bin
	mkdir bin
	cp build_ninja/bubble_sort/bubble_sort bin 
	cp build_ninja/menu/menu bin
	cp build_ninja/shell_sort/shell_sort bin
