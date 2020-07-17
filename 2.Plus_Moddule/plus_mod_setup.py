from distutils.core import setup, Extension

source_mod = Extension('plus_mod', sources = ['plus_mod.c'])

setup(name = "plus_mod",

      version = "1.0",

      description = "A plus method extension module",
      ext_modules = [source_mod],

)