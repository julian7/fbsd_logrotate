# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD: sysutils/logrotate/Makefile 327772 2013-09-20 23:05:58Z bapt $

PORTNAME=		logrotate
PORTVERSION=		3.8.5
CATEGORIES=		sysutils
MASTER_SITES=		https://fedorahosted.org/releases/l/o/logrotate/

MAINTAINER=		js@iksz.hu
COMMENT=		Daemon to rotate, compress, remove, and mail system log files

LIB_DEPENDS=		popt.0:${PORTSDIR}/devel/popt

PATCH_STRIP=		-p1
USE_GMAKE=	yes
MAKE_ENV=	"BASEDIR=${PREFIX}"
CPP=		${CC} -E

MAN5=		logrotate.conf.5
MAN8=		logrotate.8
MANCOMPRESSED=	no

NO_STAGE=	yes
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${SED} -e 's|__PREFIX__|${PREFIX}|' \
		< ${FILESDIR}/logrotate.conf.sample > ${PREFIX}/etc/logrotate.conf.sample
	@${INSTALL_DATA} ${FILESDIR}/syslog.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
