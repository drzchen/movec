
all:	iquery-bad create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

iquery-bad: iquery-bad.c
	$(INSTRU_CC) -o iquery-bad iquery-bad.c -lresolv

create: create_iquery.c
	@gcc -o create create_iquery.c  -lresolv ; \
	./create

run: iquery-bad create
	@/usr/bin/time $(INSTRU_BIN) ./iquery-bad b3.in > $<.output.txt 2> $<.error.txt
