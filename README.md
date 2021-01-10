# Pheromones
A repo that regroup SwarmUS communication messages with protobuf.


## Requirements
* `protoc` to compile .proto files, on ubuntu 20.04 you can install it using `apt install protobuf-compile`

## Building 
You can build the project using those commands

```
git clone https://github.com/SwarmUS/Pheromones
cd Pheromones
mkdir build && cd build
cmake ..
make
```
## Usage

This project is meant to be used as a library for other project. As a submodule or a cmake external project.
 
An example is provided for now with the usage of the generated file.
