SOURCES = $(shell ls input/*)
#INPUT_DIRECTORY = ~/input


if [ ! -d "~/Dropbox" ]; then
	echo "The ~/Dropbox folder does not exist"
fi

compile: main

main: | $(INPUT_DIRECTORY)
	g++ -o InputFileGenerator -Wall -std=c++11 InputFileGenerator.cpp
	g++ -o Oruganti_SaiDurgaRithvik_QuickSort -Wall -std=c++11 Oruganti_SaiDurgaRithvik_QuickSort.cpp
	g++ -o FileRunner -Wall -std=c++11 FileRunner.cpp
	echo $(SOURCES) 
	

input:
	

quicksort:

filerunner:
	g++ -o FileRunner -Wall -std=c++11 FileRunner.cpp

clean:
	rm -rf InputFileGenerator Oruganti_SaiDurgaRithvik_QuickSort FileRunner