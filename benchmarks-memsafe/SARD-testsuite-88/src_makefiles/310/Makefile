
all:	txt-dns-file-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

txt-dns-file-ok: txt-dns-file-ok.c  my-util.c  
	$(INSTRU_CC) -o txt-dns-file-ok txt-dns-file-ok.c my-util.c  -I . -lresolv

run: txt-dns-file-ok
	@/usr/bin/time $(INSTRU_BIN) ./txt-dns-file-ok > $<.output.txt 2> $<.error.txt
