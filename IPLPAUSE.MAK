IPLPAUSE.EXE : IPLPAUSE.obj
     link IPLPAUSE.obj /align:16, IPLPAUSE.exe, NUL, /NOD os2.lib llibce.lib;

IPLPAUSE.obj : IPLPAUSE.c
     cl -c -G2s -Zp -ALu -W3 -Ox IPLPAUSE.c

