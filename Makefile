test: *.cpp *.h attach/*.cpp attach/*.h sensors/*.h sensors/*.cpp world/*.h
	g++ -Wall -g -o test *.cpp attach/*.cpp sensors/*.cpp

tags: *.cpp *.h attach/*.cpp attach/*.h sensors/*.cpp sensors/*.h world/*.h
	ctags --recurse *
