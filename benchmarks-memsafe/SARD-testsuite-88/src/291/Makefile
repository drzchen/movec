
all:	sig-bad create

clean:	
	@rm -f *-bad *-ok create SIGFILE *.output.txt *.error.txt

sig-bad: sig-bad.c
	gcc -o sig-bad sig-bad.c -I . -lresolv

create:	create_msg_file.c
	gcc -o create create_msg_file.c -lresolv ; \
	./create

run: sig-bad create
	./sig-bad > $<.output.txt 2> $<.error.txt



