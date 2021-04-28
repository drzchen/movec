
all:	mapped-path-bad create

clean:	
	@rm -f *-bad create *.output.txt *.error.txt

mapped-path-bad: mapped-path-bad.c
	$(INSTRU_CC) -o mapped-path-bad mapped-path-bad.c

create: make-long-path.c
	@gcc -o create make-long-path.c ; \
	touch pathfile ; \
	./create

run: mapped-path-bad create
	@/usr/bin/time $(INSTRU_BIN) ./mapped-path-bad pathfile > $<.output.txt 2> $<.error.txt
