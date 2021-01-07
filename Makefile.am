## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projetc

projetc_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	capteur.c capteur.h \
	affichage.c affichage.h \
	troupeau.c troupeau.h \
	ouvrier.c ouvrier.h \
	affichage2.c affichage2.h \
	abs.c abs.h \
	equipement.c equipement.h \
	affichage3.c affichage3.h

projetc_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

