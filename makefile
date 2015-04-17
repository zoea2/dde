all: ./bin/processData ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 ./bin/main5 ./bin/main6 ./bin/main7 ./bin/main8 ./bin/main9 ./bin/main10 ./bin/main11 ./bin/main12 ./bin/main13 ./bin/main14 

./bin/main: population.o genotype.o general.o main.cpp
	g++ -o ./bin/main main.cpp population.o genotype.o general.o -g
./bin/main1: population.o genotype.o general.o main1.cpp
	g++ -o ./bin/main1 main1.cpp population.o genotype.o general.o -g
./bin/main2: population.o genotype.o general.o main2.cpp
	g++ -o ./bin/main2 main2.cpp population.o genotype.o general.o -g
./bin/main3: population.o genotype.o general.o main3.cpp
	g++ -o ./bin/main3 main3.cpp population.o genotype.o general.o -g
./bin/main4: population.o general.o genotype.o main4.cpp
	g++ -o ./bin/main4 main4.cpp population.o genotype.o general.o -g
./bin/processData: processData.cpp general.o
	g++ -o ./bin/processData processData.cpp general.o -g
./bin/main5: population.o genotype.o general.o main5.cpp
	g++ -o ./bin/main5 main5.cpp population.o genotype.o general.o -g
./bin/main6: population.o genotype.o general.o main6.cpp
	g++ -o ./bin/main6 main6.cpp population.o genotype.o general.o -g
./bin/main7: population.o genotype.o general.o main7.cpp
	g++ -o ./bin/main7 main7.cpp population.o genotype.o general.o -g
./bin/main8: population.o genotype.o general.o main8.cpp
	g++ -o ./bin/main8 main8.cpp population.o genotype.o general.o -g
./bin/main9: population.o genotype.o general.o main9.cpp
	g++ -o ./bin/main9 main9.cpp population.o genotype.o general.o -g
./bin/main10: population.o genotype.o general.o main10.cpp
	g++ -o ./bin/main10 main10.cpp population.o genotype.o general.o -g
./bin/main11: population.o genotype.o general.o main11.cpp
	g++ -o ./bin/main11 main11.cpp population.o genotype.o general.o -g
./bin/main12: population.o genotype.o general.o main12.cpp
	g++ -o ./bin/main12 main12.cpp population.o genotype.o general.o -g
./bin/main13: population.o genotype.o general.o main13.cpp
	g++ -o ./bin/main13 main13.cpp population.o genotype.o general.o -g
./bin/main14: population.o genotype.o general.o main14.cpp
	g++ -o ./bin/main14 main14.cpp population.o genotype.o general.o -g
population.o: population.cpp population.h
	g++ -c population.cpp -g
genotype.o: genotype.cpp genotype.h
	g++ -c genotype.cpp -g
general.o: general.cpp general.h
	g++ -c general.cpp -g
clean:
	rm ./bin/main ./bin/main1 ./bin/main2 ./bin/main3 ./bin/main4 ./bin/main5 ./bin/main6 ./bin/main7 population.o genotype.o general.o output.txt output1.txt output2.txt output3.txt ./bin/main8 ./bin/main9 ./bin/main10  
