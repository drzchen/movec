
all:	txt-dns-file-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

txt-dns-file-ok: txt-dns-file-ok.c  my-util.c  
	gcc -o txt-dns-file-ok txt-dns-file-ok.c my-util.c  -I . -lresolv

run: txt-dns-file-ok
	./txt-dns-file-ok > $<.output.txt 2> $<.error.txt
