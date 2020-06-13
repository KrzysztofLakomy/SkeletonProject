cpp_files := $(wildcard *.cpp)
wx_flags := $(shell wx-config --cxxflags)
wx_libs := $(shell wx-config --libs)

build:
	@echo "Compiling"
	g++ $(wx_flags) -o out $(cpp_files) $(wx_libs)
