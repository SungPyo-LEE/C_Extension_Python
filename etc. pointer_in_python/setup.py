from distutils.core import setup, Extension

source_mod = Extension('python_pointer', sources = ['pointer.c'])

setup(name = "python_pointer",

      version = "1.0",

      description = "A plus method extension module",
      ext_modules = [source_mod],

)