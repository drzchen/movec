
all:	ns-lookup-ok create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

ns-lookup-ok: ns-lookup-ok.c
	$(INSTRU_CC) -o ns-lookup-ok ns-lookup-ok.c

create:	create_address_file.c
	@gcc -o create create_address_file.c ; \
	./create

run: ns-lookup-ok create
	@/usr/bin/time $(INSTRU_BIN) ./ns-lookup-ok b4.in > $<.output.txt 2> $<.error.txt
