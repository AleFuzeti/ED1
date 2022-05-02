EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
    rm *.o
    rm $(PROJECT_NAME)

$(PROJECT_NAME): main.o circ.o line.o list.o paths.o rect.o svg.o system.o text.o #qry.o queue.o 
    $(EXEC) $(CFLAGS) main.o circ.o line.o list.o paths.o rect.o svg.o system.o text.o -o ted #qry.o queue.o

main.o: main.c 
    $(EXEC) $(CFLAGS) -c main.c

circ.o: circ.c data.h
    $(EXEC) $(CFLAGS) -c circ.c

line.o: line.c data.h
    $(EXEC) $(CFLAGS) -c line.c

list.o: list.c data.h
    $(EXEC) $(CFLAGS) -c list.c

paths.o: paths.c paths.h
    $(EXEC) $(CFLAGS) -c paths.c

#qry.o: qry.c qry.h
#    $(EXEC) $(CFLAGS) -c qry.c

#queue.o: queue.c queue.h
#    $(EXEC) $(CFLAGS) -c queue.c

rect.o: rect.c data.h
    $(EXEC) $(CFLAGS) -c rect.c

svg.o: svg.c svg.h
    $(EXEC) $(CFLAGS) -c svg.c

system.o: system.c system.h
    $(EXEC) $(CFLAGS) -c system.c

text.o: text.c data.h
    $(EXEC) $(CFLAGS) -c text.c

#txt.o: txt.c txt.h
#    $(EXEC) $(CFLAGS) -c txt.c