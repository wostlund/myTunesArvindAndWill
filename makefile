compile: LinkedList.c LinkedList.h
	gcc LinkedList.c LinkedList.h -o LinkedList

run: compile
	./LinkedList