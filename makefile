MyTunes: MyTunes.c LinkedList.c LinkedList.h
	gcc LinkedList.c MyTunes.c Main.c -o Driver
	clear
	echo "Note: please wait a bit before running the driver file again"

run: MyTunes
	./Driver

clear:
	rm *~
