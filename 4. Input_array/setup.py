from distutils.core import setup, Extension

source_mod = Extension('input_arr', sources = ['input_array.c'])

setup(name = "input_arr",

      version = "1.0",

      description = "A input array method extension module",
      ext_modules = [source_mod],

)