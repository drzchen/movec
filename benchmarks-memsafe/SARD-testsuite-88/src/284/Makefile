
all:	realpath-ok setup

clean:
	@rm -rf *-ok *-bad /tmp/foo *.output.txt *.error.txt

realpath-ok: call_fb_realpath.c realpath-ok.c
	gcc -o realpath-ok call_fb_realpath.c realpath-ok.c

setup:
	mkdir -p /tmp/foo/bar/foo/bar/foo/bar/foo/bar ; \
	touch /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi ; \
	ln -f -s /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh

run: realpath-ok setup
	./realpath-ok /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh > $<.output.txt 2> $<.error.txt
