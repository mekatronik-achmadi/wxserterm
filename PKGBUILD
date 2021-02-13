pkgname=wxserterm
pkgver=0.1
pkgrel=1
pkgdesc="wxWidgets simple Serial Terminal"
arch=('x86_64')
license=('MIT')
depends=()
makedepends=('git' 'cbp2make')
source=("git+https://github.com/mirai-computing/cbp2make")
md5sums=('SKIP')

pkgver() {
  cd "${srcdir}/$pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
  cd "$srcdir/${pkgname}"
  make -f cbp2make.cbp.mak.unix release
}

package() {
  cd "$srcdir/${pkgname}"
  install -Dm 755 ./bin/Release/cbp2make $pkgdir/usr/bin/cbp2make
}
