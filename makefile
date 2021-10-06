compile: main.cpp 
	 g++  main.cpp -o bubble

compileSelection: main_selection.cpp 
	 g++  main_selection.cpp -o selection

runSelection: selection
	  ./selection

run: bubble
	 ./bubble


clean: bubble
	 rm bubble
