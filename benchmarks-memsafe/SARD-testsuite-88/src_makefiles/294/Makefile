
all:	nxt-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

nxt-ok: nxt-ok.c 
	$(INSTRU_CC) -o nxt-ok nxt-ok.c -I . -lresolv

run: nxt-ok
	@/usr/bin/time $(INSTRU_BIN) ./nxt-ok > $<.output.txt 2> $<.error.txt
