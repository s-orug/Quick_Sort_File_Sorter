compile: main

main: 
	g++ -o InputFileGenerator -Wall -std=c++11 InputFileGenerator.cpp
	g++ -o Oruganti_SaiDurgaRithvik_QuickSort -Wall -std=c++11 Oruganti_SaiDurgaRithvik_QuickSort.cpp
	g++ -o FileRunner -Wall -std=c++11 FileRunner.cpp

input:

quicksort:

filerunner:
	g++ -o FileRunner -Wall -std=c++11 FileRunner.cpp

clean:
	rm -rf InputFileGenerator Oruganti_SaiDurgaRithvik_QuickSort FileRunner