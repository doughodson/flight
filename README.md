# flight
Repo to support development of flight instruments & FDM

### deps folder contains Lua 5.3, sol 2 v3.0.3, and SDL2
The src folder contains original source code, the include and lib folders contain header and compiled static versions of these libraries

### Compiling SDL2:
configure --prefix=[install location] --enable-static

make

make install

### Compiling SDL2_image:
export SDL2_PATH=[SDL2 install location]

configure --prefix=[install location] --enable-static

install location must be the same as SDL2 install location

make

make install

### Compiling SDL2_image:
export SDL2_PATH=[SDL2 install location]

configure --prefix=[install location] --enable-static

install location must be the same as SDL2 install location

make

make install

### Compiling SDL2_net:
export SDL2_PATH=[SDL2 install location]

configure --prefix=[install location] --enable-static

install location must be the same as SDL2 install location

make

make install

### Compiling Lua:
make linux

### To Install Image Libraries

apt-get install libpng-dev

apt-get install libjpeg-dev

apt-get install zlib1g-dev


