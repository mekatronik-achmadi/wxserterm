pkgname=wxserterm
pkgver=r7.ad976ae
pkgrel=1
pkgdesc="wxWidgets simple Serial Terminal"
arch=('x86_64')
license=('MIT')
depends=('wxgtk2')
makedepends=('git' 'cbp2make')
source=("git+https://github.com/mekatronik-achmadi/wxserterm")
md5sums=('SKIP')

pkgver() {
  cd "${srcdir}/$pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
  cd "$srcdir/${pkgname}"
  cbp2make -in wxserterm.cbp -cfg Release -out Makefile
  make
}

package() {
  cd "$srcdir/${pkgname}"
  install -Dm 755 ./bin/Release/${pkgname} $pkgdir/usr/bin/${pkgname}
  install -Dm 644 ${pkgname}.desktop $pkgdir/usr/share/applications/${pkgname}.desktop
}
