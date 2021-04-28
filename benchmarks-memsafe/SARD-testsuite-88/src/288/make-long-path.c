
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
$Date: 2004/01/05 17:27:52 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f1/make-long-path.c,v 1.1.1.1 2004/01/05 17:27:52 tleek Exp $



*/


/*

WU-FTPD Copyright Notice


  Copyright (c) 1999,2000 WU-FTPD Development Group.  
  All rights reserved.
  
  Portions Copyright (c) 1980, 1985, 1988, 1989, 1990, 1991, 1993, 1994
    The Regents of the University of California.
  Portions Copyright (c) 1993, 1994 Washington University in Saint Louis.
  Portions Copyright (c) 1996, 1998 Berkeley Software Design, Inc.
  Portions Copyright (c) 1989 Massachusetts Institute of Technology.
  Portions Copyright (c) 1998 Sendmail, Inc.
  Portions Copyright (c) 1983, 1995, 1996, 1997 Eric P.  Allman.
  Portions Copyright (c) 1997 by Stan Barber.
  Portions Copyright (c) 1997 by Kent Landfield.
  Portions Copyright (c) 1991, 1992, 1993, 1994, 1995, 1996, 1997
    Free Software Foundation, Inc.  
 
  Use and distribution of this software and its source code are governed 
  by the terms and conditions of the WU-FTPD Software License ("LICENSE").
 
  If you did not receive a copy of the license, it may be obtained online
  at http://www.wu-ftpd.org/license.html.


$Author: tleek $
$Date: 2004/01/05 17:27:52 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f1/make-long-path.c,v 1.1.1.1 2004/01/05 17:27:52 tleek Exp $



*/


/*

<source>

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "my-include.h"
// MAXPATHLEN is 10 

int main(){

  char orig_path[MAXPATHLEN + 20];
  char *temp;
  FILE *f; 
  int i, n;

  temp = orig_path;  

  
  /* define a long path /tmp/aaaaa... */
  strcpy(temp, "/tmp/");                 
  temp = temp + 5; 
  memset(temp, 'a', sizeof(char) * (MAXPATHLEN + 24));
  orig_path[MAXPATHLEN + 19] = '\0'; 
  mkdir(orig_path, O_RDONLY);
  chmod(orig_path, 0700); 

  f = (FILE *) fopen("pathfile", "r+");
  
  n = strlen(orig_path);

  for(i=0; i<n; i++) 
    fputc(orig_path[i], f);  
  
  fputc('\0', f);

  fclose(f);
  

  return 0;

}

/*

</source>

*/

