# -c -Wall 
gcc leaf2.c -fPIC -shared -o libleaf.dll 
# $(CC) -shared -fPIC $(CFLAGS) -o libbeps.dll $(OBJS) -lm
julia .\hello.jl
