compile: main.cpp 
	 g++  main.cpp -o bubble

compileSelection: main_selection.cpp 
	 g++  main_selection.cpp -o selection

compileInsertion: main_insertion.cpp 
	 g++  main_insertion.cpp -o insertion

runInsertion: insertion
		./insertion

runSelection: selection
	  ./selection

run: bubble
	 ./bubble

clean: bubble
	 rm bubble
