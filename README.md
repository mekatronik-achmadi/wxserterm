# wxserterm
Simple Serial Terminal based on wxWidgets and ceSerial

This is a simple Serial terminal build on top wxWidgets and ceSerial.

### How to build

You can build from this source using provided Code::Blocks project file.
If you don't want to open Code::Blocks, you can use [cbp2make](https://github.com/mirai-computing/cbp2make) to generate GNU Makefile.

#### ArchLinux:
You can use provided [PKGBUILD](https://github.com/mekatronik-achmadi/wxserterm/blob/master/PKGBUILD).

You need to install [cbp2make](https://github.com/mirai-computing/cbp2make) first and a PKGBUILD for it available [here](https://github.com/mekatronik-achmadi/archmate/blob/master/packages/pkgbuild/cbp2make/PKGBUILD).

#### Other distribution:
You need install:
  - [wxWidget](https://github.com/wxWidgets/wxWidgets) or wxGTK 
  - [Make](https://www.gnu.org/software/make)
  - [Codeblocks](https://github.com/svn2github/CodeBlocks) or [cbp2make](https://github.com/mirai-computing/cbp2make)
 
 If you use cbp2make instead of Codeblocks, you can do as following:
 
 ```
 cbp2make -in wxserterm.cbp -cfg Release -out Makefile
 make
 ./bin/Release/wxserterm
 ```
 
### Thanks to:
 - [wxWidget](https://github.com/wxWidgets/wxWidgets)
 - [ceSerial](https://github.com/yan9a/serial)
 - [Codeblocks](https://github.com/svn2github/CodeBlocks)
 - [wxFormBuilder](https://github.com/wxFormBuilder/wxFormBuilder)
 - [cbp2make](https://github.com/mirai-computing/cbp2make)
 
