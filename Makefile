CS:main.o  init coursemanage courseselection save studentmanage
	gcc -o CS main.o  init.o coursemanage.o courseselection.o save.o studentmanage.o
main:main.c coursemanage.h courseselection.h init.h save.h studentmanage.h
	gcc -c main.c
main_optimizer:main_clean main.c
	gcc -c -O3 main.c

main_clean:
	if [ -e main.o ] ; then rm main.o ; fi
coursemanage:coursemanage.c
	gcc -c coursemanage.c
coursemanage_optimizer:coursemanage.c
	gcc -c -O3 coursemanage.c
courseselection:courseselection.c
	gcc -c courseselection.c
courseselection_optimizer:courseselection.c
	gcc -c -O3 courseselection.c
init:init.c
	gcc -c init.c
init_optimizer:init.c
	gcc -c -O3 init.c
save:save.c
	gcc -c save.c
save_optimizer:save.c
	gcc -c -O3 save.c
studentmanage:studentmanage.c
	gcc -c studentmanage.c
studentmanage_optimizer:studentmanage.c
	gcc -c -O3 studentmanage.c

clean:
	if [ -e coursemanage.o ] ; then rm coursemanage.o ; fi
	if [ -e courseselection.o ] ; then rm courseselection.o ; fi
	if [ -e init.o ] ; then rm init.o ; fi
	if [ -e save.o ] ; then rm save.o ; fi
	if [ -e studentmanage.o ] ; then rm studentmanage.o ; fi

run:
	./CS
clean_run:
	if [ -e CS ] ; then rm CS ; fi
release:main_optimizer courseselection_optimizer coursemanage_optimizer save_optimizer init_optimizer studentmanage_optimizer
	gcc -o CS main.o coursemanage.o courseselection.o init.o save.o studentmanage.o