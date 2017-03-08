# Introduction

This module demonstrates how to wrap C++ code and use it in Mathematica 
environment through MathLink. Essentially the user construct an extern C
wrapper due to the naming mangling of C++ and ensures the correct 
transformation of the inputs/outputs interface:

[Mathematica doc](https://reference.wolfram.com/language/LibraryLink/tutorial/InteractionWithMathematica.html#280210622)

This particular project wraps custom code which contains some interface
functions to demonstrates the usage. The test_wrapper.nb loads the created
dynamic library and calls the appropriate functions.

This code is based on:

[Sascha Kratky](https://github.com/sakra/FindMathematica)