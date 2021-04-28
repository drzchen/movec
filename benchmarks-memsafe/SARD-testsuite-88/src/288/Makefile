
all:	mapped-path-ok create

clean:	
	@rm -f *-ok create *.output.txt *.error.txt

mapped-path-ok: mapped-path-ok.c
	gcc -o mapped-path-ok mapped-path-ok.c

create: make-long-path.c
	gcc -o create make-long-path.c ; \
	touch pathfile ; \
	./create

run: mapped-path-ok create
	./mapped-path-ok pathfile > $<.output.txt 2> $<.error.txt
