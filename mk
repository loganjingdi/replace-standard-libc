gcc -g -fpic -shared -o hook.so hook.c -ldl -lc
gcc -g main.c