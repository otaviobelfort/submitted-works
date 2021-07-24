# OpenGL

### Ferramentas para compilação

```
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install g++ cmake
sudo apt-get install binutils-gold
sudo apt-get install freeglut3 freeglut3-dev
sudo apt-get install mesa-common-dev
sudo apt-get install libglew1.5-dev libglm-dev libglew-dev

```

* Install vcpkg
* Step 1: Clone the vcpkg repo

``` 
git clone https://github.com/Microsoft/vcpkg.git

``` 

* Step 2: Run the bootstrap script to build vcpkg
``` 
./vcpkg/bootstrap-vcpkg.sh
``` 

* Compile
```
g++ -o main main.cpp -lglut -lGL -lGLU -lm
```
```
./main
```

### Referencias:
1. http://www.ecp.ufma.br/wener/
2. https://vcpkg.io/en/getting-started.html