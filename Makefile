main: main.o Avalon.o
  g++ main.o Avalon.o -o main

main.o: main.cpp
  g++ -c main.cpp

Avalon.o: Avalon.cpp
  g++ -c Avalon.cpp
  
clean:
  rm *.o main
  
