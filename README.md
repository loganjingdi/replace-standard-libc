Once the program has been built, generally its output will be like this
```
5 char has been written to file :test.data 
```

Then , we use the variable LD_PRELOAD just like this
```
[root@dd t]# export LD_PRELOAD=./hook.so
[root@dd t]# a.out
----------hello from jdliu-------------
5 char has been written to file :test.data

[root@dd t]# cat test.data 
----------hello from jdliu-------------hello

[root@dd t]# unset LD_PRELOAD
[root@dd t]# cat test.data
hello
```

As you can see, it actually affects other program until you unset it ....

To use the hook in a specific program , you need 
```
[root@dd t]# LD_PRELOAD=./hook.so a.out 
```

The a.out will be the only affected program.