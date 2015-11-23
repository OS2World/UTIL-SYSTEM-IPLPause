/**********************************************************************/
/*  PROGRAM:  IPLPAUSE.EXE - config.sys timer utility.		      */
/*  BY:  Knight Research - Copyright (c) 1993 All Rights Reserved.    */
/**********************************************************************/
/* Compiled with MSC 6.0 */
#define INCL_DOSPROCESS
#include <os2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int	key;
char	szInput[80];
USHORT	usSeconds;
RESULTCODES resc;
UCHAR szFailName[CCHMAXPATH];
UCHAR szCommandLine[] = { "cmd\0 /K \0" };

/***************************************************************************/
/* Main 								   */
/***************************************************************************/
void main (int argc, char *argv[])
{
 if (argc > 1) {
     strcpy(szInput,argv[1]);
     strupr(szInput);
     usSeconds = atoi(szInput);
     }

 if (usSeconds == 0)
     usSeconds = 15;

 printf("\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
   printf("³IPLPAUSE:  Knight Research - Copyright \(c\) 1993 All Rights Reserved. ³\n");
   printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
 printf("Press ANY KEY to PAUSE System Startup...OR Press <ESC> to Continue NOW.\n\n");

 while (usSeconds > 0) {
     if (kbhit()) {
	 key = getch();
	 if (key != 27) {
	     printf("\n\nIPL has been Paused....type EXIT to continue system startup.\n\n", usSeconds);
	     DosExecPgm(szFailName, sizeof(szFailName), EXEC_SYNC,
			szCommandLine, (PSZ) NULL, &resc, "C:\\OS2\\CMD.EXE");
	     printf("\n\nOS/2 Presentation Manager will now start.\n\n");
	     exit(1);
	     }
	 else {
	     printf("\n\nOS/2 Presentation Manager will now start.\n\n");
	     exit(0);  /* Boot Immediately */
	     }
	 }
     DosSleep(1000L);
     usSeconds--;
     printf("===> COUNTDOWN TO PM STARTUP: %d \r", usSeconds);
     }

 printf("\n\nOS/2 Presentation Manager will now start.\n\n");
 exit(0);
}
