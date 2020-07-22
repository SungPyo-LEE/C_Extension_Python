from distutils.core import setup, Extension

source_mod = Extension('recursion', sources = ['recursion.c'])

setup(name = "recursion",

      version = "1.0",

      description = "A plus method extension module",
      ext_modules = [source_mod],

)