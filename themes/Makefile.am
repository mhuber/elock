MAINTAINERCLEANFILES = Makefile.in

EDC = elock.edc
EDJ = $(EDC:%.edc=%.edj)

EXTRA_DIST = $(EDC)

#CLEANFILES = $(EDJ)

themedir =  $(pkgdatadir)/themes
theme_DATA = $(EDJ)

all: $(EDJ)

.edc.edj:
	edje_cc $<
