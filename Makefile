linux: build
	./bin/main

windows: build
	./bin/main.exe

build:
	gcc main.c -o ./bin/main -lgdi32