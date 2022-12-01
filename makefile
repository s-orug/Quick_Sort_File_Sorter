SOURCES = $(shell ls input/*)
INPUT_DIRECTORY = ~/input
LIST1 = 10 100 1000

#if [ ! -d "~/Dropbox" ]; then
#	echo "The ~/Dropbox folder does not exist"
#fi



compile: main

main:
	g++ -o InputFileGenerator -Wall -std=c++11 InputFileGenerator.cpp
	g++ -o Oruganti_SaiDurgaRithvik_QuickSort -Wall -std=c++11 Oruganti_SaiDurgaRithvik_QuickSort.cpp
	
generate:
	./InputFileGenerator

run:
	@for x in $(LIST1); do \
		for (( y=1; y<=25; y++ )); do\
			bash -c "./Oruganti_SaiDurgaRithvik_QuickSort input/$${x}_$$y output/$${x}_$$y"; \
		done \
	done

clean:
	rm -rf InputFileGenerator Oruganti_SaiDurgaRithvik_QuickSort 