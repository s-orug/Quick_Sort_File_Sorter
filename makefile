SOURCES = $(shell ls input/*)
INPUT_DIRECTORY = ~/input
LIST1 = 10 100 1000



compile: main

main:
	g++ -o InputFileGenerator -Wall -std=c++11 InputFileGenerator.cpp
	g++ -o Oruganti_SaiDurgaRithvik_QuickSort -Wall -std=c++11 Oruganti_SaiDurgaRithvik_QuickSort.cpp
	
generate:
	./InputFileGenerator

run:
	@for x in $(LIST1); do \
		for (( y=1; y<=25; y++ )); do\
			bash -c "./Oruganti_SaiDurgaRithvik_QuickSort input_$${x}_$$y output_$${x}_$$y"; \
		done \
	done \

#average:
#	bash -c "awk '{t[$1]+=$2;n[$1]++}END{for(i in t){print i,t[i]/n[i]}}' Oruganti_SaiDurgaRithvik_executionTime.txt >> Oruganti_SaiDurgaRithvik_averageExecutionTime.txt"; \

# awk '{t[$1]+=$2;n[$1]++}END{for(i in t){print i,t[i]/n[i]}}' Oruganti_SaiDurgaRithvik_executionTime.txt >> Oruganti_SaiDurgaRithvik_averageExecutionTime.txt

remove:
	@for x in $(LIST1); do \
		for (( y=1; y<=25; y++ )); do\
			bash -c "rm input_$${x}_$$y output_$${x}_$$y"; \
		done \
	done \

clean:
	rm -rf InputFileGenerator Oruganti_SaiDurgaRithvik_QuickSort 
