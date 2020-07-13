from distutils.core import setup, Extension

source_mod = Extension('hello', sources = ['hello.c'])

setup(name = "hello",

      version = "1.0",

      description = "A sample extension module",
      ext_modules = [source_mod],

)