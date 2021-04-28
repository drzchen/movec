
all:	iquery-bad create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

iquery-bad: iquery-bad.c
	gcc -o iquery-bad iquery-bad.c -lresolv

create: create_iquery.c
	gcc -o create create_iquery.c  -lresolv ; \
	./create

run: iquery-bad create
	./iquery-bad b3.in > $<.output.txt 2> $<.error.txt
