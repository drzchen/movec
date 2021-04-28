
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
$Date: 2004/02/05 15:21:24 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f1/mapped-path-ok.c,v 1.2 2004/02/05 15:21:24 tleek Exp $



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
$Date: 2004/02/05 15:21:24 $
$Header: /mnt/leo2/cvs/sabo/hist-040105/wu-ftpd/f1/mapped-path-ok.c,v 1.2 2004/02/05 15:21:24 tleek Exp $



*/


/*

<source>

*/

#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
/*#include <pwd.h>*/  /* Using custom made pwd() */
#include <string.h>
#include <unistd.h>
#include "my-include.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#ifdef MAPPING_CHDIR
/* Keep track of the path the user has chdir'd into and respond with
 * that to pwd commands.  This is to avoid having the absolue disk
 * path returned, which I want to avoid.
 */
char mapped_path[ MAXPATHLEN ] = "/";


char *mapping_getcwd(char *path, size_t size)  /* NEW.. a replacement for mapping_getwd */
{

  printf("Copying at most %lu chars into buffer path[] whose size = %d\n", size, MAXPATHLEN + 1);

  /* OK */
  strncpy(path, mapped_path, size);
  path[size-1] = '\0';
  return path;
}


/* Make these globals rather than local to mapping_chdir to avoid stack overflow */
char pathspace[ MAXPATHLEN ];
char old_mapped_path[ MAXPATHLEN ];


void
#ifdef __STDC__
do_elem(char *dir)
#else
do_elem( dir )
      char *dir;
#endif
{
      /* . */
      if( dir[0] == '.' && dir[1] == '\0' ){
              /* ignore it */
              return;
      }

      /* .. */
      if( dir[0] == '.' && dir[1] == '.' && dir[2] == '\0' ){
              char *last;
              /* lop the last directory off the path */
              if(( last = strrchr( mapped_path, '/') )){
                      /* If start of pathname leave the / */
                      if( last == mapped_path )
                              last++;
                      *last = '\0';
              }
              return;
      }
      
      /* append the dir part with a leading / unless at root */
      if( !(mapped_path[0] == '/' && mapped_path[1] == '\0') )
        if (strlen(mapped_path) < sizeof(mapped_path) - 1)       /* NEW */
	  /*OK*/
	  strcat(mapped_path, "/");
      
      if (sizeof(mapped_path) - strlen(mapped_path) > 1)     /* NEW */
	/*OK*/
	strncat(mapped_path, dir, sizeof(mapped_path) - strlen(mapped_path) - 1);  /* NEW */
}


int
#ifdef __STDC__
mapping_chdir(char *orig_path)
#else
mapping_chdir( orig_path )
      char *orig_path;
#endif
{
      int ret;
      char *sl, *path;

      strcpy( old_mapped_path, mapped_path );
      path = &pathspace[0];
      
      /*OK*/
      printf ("strlen(path) = %lu \t path=%s\n", strlen (path), path);
      printf ("strlen(orig_path) = %lu \t orig_path=%s\n", strlen (orig_path), orig_path);

      if (strlen (path) >0) 
	strcpy( path, orig_path );

      /* / at start of path, set the start of the mapped_path to / */
      if( path[0] == '/' ){
              mapped_path[0] = '/';
              mapped_path[1] = '\0';
              path++;
      }

      while( (sl = strchr( path, '/' )) ){
              char *dir;
              dir = path;
              *sl = '\0';
              path = sl + 1;
              if( *dir )
                      do_elem( dir );
              if( *path == '\0' )
                      break;
      }

      if( *path ){
	printf("path = %s.. calling do_elem\n", path);
	do_elem( path );
      }
      printf("mapped_path = %s\n", mapped_path);
      
      if (strlen(mapped_path) >= MAXPATHLEN){
	printf("ALERT: mapped_path[MAXPATHLEN] has been overflowed!\n");
      }
      
      if( (ret = chdir( mapped_path )) < 0 ){
	printf("couldn't chdir to %s !\n", mapped_path);
	strcpy(mapped_path, old_mapped_path );
	printf("mapped_path changed to %s\n", mapped_path);
      }

      return ret;
}


#define getwd(d) mapping_getwd(d)
#define getcwd(d,u) mapping_getcwd((d), (u))   /* NEW */

#endif /* MAPPING_CHDIR */


/* Define pwd */

void
#ifdef __STDC__
pwd(void)
#else
pwd()
#endif
{
  int canary = 7;
  char path[MAXPATHLEN + 1]; /* Path to return to client */

#ifndef MAPPING_CHDIR
#ifdef HAVE_GETCWD
  extern char *getcwd();
#else
#ifdef __STDC__
  extern char *getwd(char *);
#else
  extern char *getwd();
#endif
#endif
#endif /* MAPPING_CHDIR */
  
#ifdef HAVE_GETCWD
  if (getcwd(path,MAXPATHLEN) == (char *) NULL)     /* call is made to mapping_getcwd */
    {
      printf("wu-ftpd: Illegal path supplied!\n");
    }
#else
    if (getwd(path) == (char *) NULL)
#endif
      {
      printf("path = %s\n", path);
      printf("Current directory = %s\n", path);
      printf("max len of path is %d, strlen(path) = %lu\n", MAXPATHLEN, strlen(path));
      printf("Canary should be 7.  Canary = %d\n", canary);
      if (canary != 7)
	printf("ALERT: path[MAXPATHLEN + 1] has been overflowed!\n");
      }
}


  int main(int argc, char **argv){

  char orig_path[MAXPATHLEN + 20];
  FILE *f;

  f = fopen("pathfile", "r");
  fgets(orig_path, MAXPATHLEN + 20, f);  /* get path name */
  fclose(f);
 
  printf("orig_path = %s\n", orig_path);

  mapping_chdir(orig_path);   /* this can overflow mapped_path[] and pathspace[] */
  pwd();            /* get current working directory.. this calls getwcd = mapping_getwd*/
                    /* mapping_getwd may overflow path[] */
 

  return 0;

}
  

/*

</source>

*/

