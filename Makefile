server: server.cpp server.h attach/*.cpp attach/*.h misc/*.h sensors/*.h sensors/*.cpp world/*.h world/*.cpp
	g++ -Wall -g -lpthread -o server server.cpp attach/*.cpp sensors/*.cpp world/*.cpp

tags: *.cpp *.h attach/*.cpp attach/*.h sensors/*.cpp sensors/*.h world/*.h world/*.cpp
	ctags --recurse *

.PHONY: doc
doc: *.cpp *.h attach/*.cpp attach/*.h sensors/*.h sensors/*.cpp world/*.h world/*.cpp
	doxygen

.PHONY: all
all: test tags doc
