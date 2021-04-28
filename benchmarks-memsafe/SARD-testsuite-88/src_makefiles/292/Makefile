
all:	sig-ok create

clean:	
	@rm -f *-bad *-ok create SIGFILE *.output.txt *.error.txt

sig-ok: sig-ok.c
	$(INSTRU_CC) -o sig-ok sig-ok.c -I . -lresolv

create:	create_msg_file.c
	@gcc -o create create_msg_file.c -lresolv ; \
	./create

run: sig-ok create
	@/usr/bin/time $(INSTRU_BIN) ./sig-ok > $<.output.txt 2> $<.error.txt



