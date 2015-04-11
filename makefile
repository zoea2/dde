all: ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 ./bin/processData

./bin/main: population.o genotype.o general.o main.cpp
	g++ -o ./bin/main main.cpp population.o genotype.o general.o
./bin/main1: population.o genotype.o general.o main1.cpp
	g++ -o ./bin/main1 main1.cpp population.o genotype.o general.o
./bin/main2: population.o genotype.o general.o main2.cpp
	g++ -o ./bin/main2 main2.cpp population.o genotype.o general.o
./bin/main3: population.o genotype.o general.o main3.cpp
	g++ -o ./bin/main3 main3.cpp population.o genotype.o general.o
./bin/main4: population.o general.o genotype.o main4.cpp
	g++ -o ./bin/main4 main4.cpp population.o genotype.o general.o
./bin/processData: processData.cpp
	g++ -o ./bin/processData processData.cpp
population.o: population.cpp population.h
	g++ -c population.cpp
genotype.o: genotype.cpp genotype.h
	g++ -c genotype.cpp
general.o: general.cpp general.h
	g++ -c general.cpp
clean:
	rm ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 population.o genotype.o general.o output.txt output1.txt output2.txt output3.txt
