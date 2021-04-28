
/*

MIT Copyright Notice

Copyright 2003 M.I.T.

Permission is hereby granted, without written agreement or royalty fee, to use, 
copy, modify, and distribute this software and its documentation for any 
purpose, provided that the above copyright notice and the following three 
paragraphs appear in all copies of this software.

IN NO EVENT SHALL M.I.T. BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, 
INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE 
AND ITS DOCUMENTATION, EVEN IF M.I.T. HAS BEEN ADVISED OF THE POSSIBILITY OF 
SUCH DAMANGE.

M.I.T. SPECIFICALLY DISCLAIMS ANY WARRANTIES INCLUDING, BUT NOT LIMITED TO 
THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, 
AND NON-INFRINGEMENT.

THE SOFTWARE IS PROVIDED ON AN "AS-IS" BASIS AND M.I.T. HAS NO OBLIGATION TO 
PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

$Author: tleek $
$Date: 2004/01/05 17:27:41 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/bind/b4/my-named.h,v 1.1.1.1 2004/01/05 17:27:41 tleek Exp $



*/


/*

BIND Copyright Notice

 Copyright (C) 2000-2002  Internet Software Consortium.

 Permission to use, copy, modify, and distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM
 DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL
 INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,
 INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


$Author: tleek $
$Date: 2004/01/05 17:27:41 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/bind/b4/my-named.h,v 1.1.1.1 2004/01/05 17:27:41 tleek Exp $



*/


/*

<source>

*/

#define INIT(x) = x
#define NSMAX         16 

/*
 * Hash table structures.
 */
struct databuf {
	struct databuf	*d_next;	/* linked list */
	u_int32_t	d_ttl;		/* time to live */
					/* if d_zone == DB_Z_CACHE, then
					 * d_ttl is actually the time when
					 * the record will expire.
					 * otherwise (for authoritative
					 * primary and secondary zones),
					 * d_ttl is the time to live.
					 */
	unsigned	d_flags :7;	/* see below */
	unsigned	d_cred :3;	/* DB_C_{??????} */
	unsigned	d_clev :6;
	int16_t		d_zone;		/* zone number or 0 for the cache */
	int16_t		d_class;	/* class number */
	int16_t		d_type;		/* type number */
	int16_t		d_mark;		/* place to mark data */
	int16_t		d_size;		/* size of data area */
#ifdef NCACHE
	int16_t		d_rcode;	/* rcode added for negative caching */
#endif
	int16_t		d_rcnt;
#ifdef STATS
	struct nameser	*d_ns;		/* NS from whence this came */
#endif
/*XXX*/
	u_int32_t       d_nstime;       /* NS response #define INIT(x) = x
time, milliseconds */
	u_char		d_data[sizeof(char*)]; /* malloc'd (padded) */
};


struct nameser {
  struct in_addr	addr;		/* key */
};


/* these fields are ordered to maintain word-alignment;
 * be careful about changing them.
 */
struct zoneinfo {
	char		*z_origin;	/* root domain name of zone */
	time_t		z_time;		/* time for next refresh */
	time_t		z_lastupdate;	/* time of last refresh */
	u_int32_t	z_refresh;	/* refresh interval */
	u_int32_t	z_retry;	/* refresh retry interval */
	u_int32_t	z_expire;	/* expiration time for cached info */
	u_int32_t	z_minimum;	/* minimum TTL value */
	u_int32_t	z_serial;	/* changes if zone modified */
	char		*z_source;	/* source location of data */
	time_t		z_ftime;	/* modification time of source file */
	struct in_addr	z_xaddr;	/* override server for next xfer */
	struct in_addr	z_addr[NSMAX];	/* list of master servers for zone */
	u_char		z_addrcnt;	/* number of entries in z_addr[] */
	u_char		z_type;		/* type of zone; see below */
	u_int16_t	z_flags;	/* state bits; see below */
	pid_t		z_xferpid;	/* xfer child pid */
	int		z_class;	/* class of zone */
#ifdef SECURE_ZONES
	struct netinfo *secure_nets;	/* list of secure networks for zone */
#endif	
#ifdef BIND_NOTIFY
	/* XXX - this will have to move to the name when we do !SOA notify */
	struct notify	*z_notifylist;	/* list of servers we should notify */
#endif
};

#ifdef BIND_NOTIFY
struct notify {
	struct in_addr	addr;		/* of server */
	time_t		last;		/* when they asked */
	struct notify	*next;
	/* XXX - this will need a type field when we do !SOA notify */
};
#endif


/* modified namebuf struct */
struct namebuf {	
  char		*n_dname;	/* domain name */ 
  	struct databuf	*n_data;	/* data records */
        
};


/*

</source>

*/

