
all:	mapped-path-ok create

clean:	
	@rm -f *-ok create *.output.txt *.error.txt

mapped-path-ok: mapped-path-ok.c
	$(INSTRU_CC) -o mapped-path-ok mapped-path-ok.c

create: make-long-path.c
	@gcc -o create make-long-path.c ; \
	touch pathfile ; \
	./create

run: mapped-path-ok create
	@/usr/bin/time $(INSTRU_BIN) ./mapped-path-ok pathfile > $<.output.txt 2> $<.error.txt
