
all:	iquery-ok  create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

iquery-ok: iquery-ok.c
	$(INSTRU_CC) -o iquery-ok iquery-ok.c -lresolv

create: create_iquery.c
	@gcc -o create create_iquery.c  -lresolv ; \
	./create

run: iquery-ok  create
	@/usr/bin/time $(INSTRU_BIN) ./iquery-ok b3.in > $<.output.txt 2> $<.error.txt

