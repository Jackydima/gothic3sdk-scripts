# Forked from gothic3sdk-examples 
For available at https://github.com/georgeto/gothic3sdk-examples

# Gothic 3 SDK Examples
Examples demonstrating how to use the [Gothic 3 SDK](https://github.com/georgeto/gothic3sdk).

## Build
The Gothic 3 SDK examples are built with [CMake](https://cmake.org/).

To download and build the Gothic 3 SDK examples (here using Visual Studio 2022) execute the following commands:
```cmd
git clone https://github.com/georgeto/gothic3sdk-scripts
cd gothic3sdk-scripts
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release -j
```

The above sequence creates a build directory, generates a Visual Studio solution, and then builds the project in Release mode.
If you prefer working from within Visual Studio, you can skip the last build step and instead open the generated solution in Visual Studio and then build from there.

## Installation
Copy the `Script_*.dll` build artifacts from the build directory into the `scripts` folder in your Gothic 3 installation directory.
Every DLL inside the `scripts` folder following the naming convention `Script_*.dll` is automatically loaded by the game.

## Formatting
All code, except  third-party code, is formatted with clang-format according to the style configured in [.clang-format](.clang-format).

## Credits
* [protobuf](https://github.com/protocolbuffers/protobuf)
* [ZeroMQ](https://github.com/zeromq/zeromq4-x)
* [PCG](http://www.pcg-random.org/)
