# imgui
Dear ImGui: Bloat-free Graphical User interface for C++ with minimal dependencies

Our custom fork for dear imgui. This is a soft fork, i.e. we keep it up to date with the original repository since we only
maintain surface level patches. Changes we made:
1. Removed unneeded files such as docs and examples
1. Moved all source in the root of the repository to the `core` folder
1. Added `custom_funcs.hpp` and `custom_funcs.cpp` files that add some additional functionality we want for dear imgui
1. Removed a large amount of unneeded backends

The original developer is [ocornut](https://github.com/ocornut), the original repository is [this](https://github.com/ocornut/imgui)
