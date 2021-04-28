
all:	sig-bad create

clean:	
	@rm -f *-bad *-ok create SIGFILE *.output.txt *.error.txt

sig-bad: sig-bad.c
	$(INSTRU_CC) -o sig-bad sig-bad.c -I . -lresolv

create:	create_msg_file.c
	@gcc -o create create_msg_file.c -lresolv ; \
	./create

run: sig-bad create
	@/usr/bin/time $(INSTRU_BIN) ./sig-bad > $<.output.txt 2> $<.error.txt



