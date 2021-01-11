# Pheromones
A repo that regroup SwarmUS communication messages with protobuf.


## Requirements

* `protoc` to compile .proto files
* python libraries for protobuf to generate the files

On ubuntu 20.04 you can install it using `apt install protobuf-compiler python3-protobuf`

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

This project is meant to be used as a library for other project to allow serialization/deserialization. Use as a submodule or a cmake external project on the user code.
 
An example is provided with the usage of the library.
