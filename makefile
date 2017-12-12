CC=/usr/bin/gcc.exe
FLAGS=-Wall -g
I=-I"D:\SDL2\x32\include"
L1=-L/d/SDL2/x32/lib
L2=-LD:/MinGW/lib
l=-lmingw32 -lSDL2 -lSDL2main -lSDL2_image
l1="D:\MinGW\lib\libmingw32.a"
l2="D:\SDL2\x32\lib\libSDL2main.a"
l3="D:\SDL2\x32\lib\libSDL2.dll.a"
l4="D:\SDL2\x32\lib\libSDL2_image.dll.a"
CFROM="C:\Users\nounoursnoir\Desktop\dev\C\exercices\SDL2_TimerTest\main.c"
OBJTO="obj\Debug\main.o"
EXETO="SDL2_TimerTest.exe"

main: main.o
	$(CC) $(L1) $(L2) -o $(EXETO) $(OBJTO) $(l) $(l1) $(l2) $(l3) $(l4); echo ""; echo "        BUILD DONE"; echo ""

main.o: main.c
	$(CC) $(FLAGS) $(I) -c $(CFROM) -o $(OBJTO)
