
all:	ns-lookup-bad create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

ns-lookup-bad: ns-lookup-bad.c
	$(INSTRU_CC) -o ns-lookup-bad ns-lookup-bad.c

create:	create_address_file.c
	@gcc -o create create_address_file.c ; \
	./create

run: ns-lookup-bad create
	@/usr/bin/time $(INSTRU_BIN) ./ns-lookup-bad b4.in > $<.output.txt 2> $<.error.txt
