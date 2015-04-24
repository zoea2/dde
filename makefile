all: ./bin/processData ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 ./bin/main5 ./bin/main6 ./bin/main7 ./bin/main8 ./bin/main9 ./bin/main10 ./bin/main11 ./bin/main12 ./bin/main13 ./bin/main14 ./bin/main15 ./bin/main16 ./bin/main17 ./bin/main18 

./bin/main: population.o genotype.o general.o main.cpp
	g++ -O3 -o ./bin/main main.cpp population.o genotype.o general.o 
./bin/main1: population.o genotype.o general.o main1.cpp
	g++ -O3 -o ./bin/main1 main1.cpp population.o genotype.o general.o 
./bin/main2: population.o genotype.o general.o main2.cpp
	g++ -O3 -o ./bin/main2 main2.cpp population.o genotype.o general.o 
./bin/main3: population.o genotype.o general.o main3.cpp
	g++ -O3 -o ./bin/main3 main3.cpp population.o genotype.o general.o 
./bin/main4: population.o general.o genotype.o main4.cpp
	g++ -O3 -o ./bin/main4 main4.cpp population.o genotype.o general.o 
./bin/processData: processData.cpp general.o
	g++ -O3 -o ./bin/processData processData.cpp general.o 
./bin/main5: population.o genotype.o general.o main5.cpp
	g++ -O3 -o ./bin/main5 main5.cpp population.o genotype.o general.o 
./bin/main6: population.o genotype.o general.o main6.cpp
	g++ -O3 -o ./bin/main6 main6.cpp population.o genotype.o general.o 
./bin/main7: population.o genotype.o general.o main7.cpp
	g++ -O3 -o ./bin/main7 main7.cpp population.o genotype.o general.o 
./bin/main8: population.o genotype.o general.o main8.cpp
	g++ -O3 -o ./bin/main8 main8.cpp population.o genotype.o general.o 
./bin/main9: population.o genotype.o general.o main9.cpp
	g++ -O3 -o ./bin/main9 main9.cpp population.o genotype.o general.o 
./bin/main10: population.o genotype.o general.o main10.cpp
	g++ -O3 -o ./bin/main10 main10.cpp population.o genotype.o general.o 
./bin/main11: population.o genotype.o general.o main11.cpp
	g++ -O3 -o ./bin/main11 main11.cpp population.o genotype.o general.o 
./bin/main12: population.o genotype.o general.o main12.cpp
	g++ -O3 -o ./bin/main12 main12.cpp population.o genotype.o general.o 
./bin/main13: population.o genotype.o general.o main13.cpp
	g++ -O3 -o ./bin/main13 main13.cpp population.o genotype.o general.o 
./bin/main14: population.o genotype.o general.o main14.cpp
	g++ -O3 -o ./bin/main14 main14.cpp population.o genotype.o general.o 
./bin/main15: population.o genotype.o general.o main15.cpp
	g++ -O3 -o ./bin/main15 main15.cpp population.o genotype.o general.o 
./bin/main16: population.o genotype.o general.o main16.cpp
	g++ -O3 -o ./bin/main16 main16.cpp population.o genotype.o general.o 
./bin/main17: population.o genotype.o general.o main17.cpp
	g++ -O3 -o ./bin/main17 main17.cpp population.o genotype.o general.o 
./bin/main18: population.o genotype.o general.o main18.cpp
	g++ -O3 -o ./bin/main18 main18.cpp population.o genotype.o general.o 
population.o: population.cpp population.h
	g++ -c population.cpp 
genotype.o: genotype.cpp genotype.h
	g++ -c genotype.cpp 
general.o: general.cpp general.h
	g++ -c general.cpp 
clean:
	rm ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 ./bin/main5 ./bin/main6 ./bin/main7 population.o genotype.o general.o output.txt output1.txt output2.txt output3.txt ./bin/main8 ./bin/main9 ./bin/main10 ./bin/main11 ./bin/main12 ./bin/main13 ./bin/main14 
