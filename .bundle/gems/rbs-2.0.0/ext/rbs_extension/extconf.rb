require 'mkmf'
$INCFLAGS << " -I$(top_srcdir)" if $extmk
$arch_hdrdir = "$(hdrdir)/../.ext/include/$(arch)"
$DLDFLAGS << " -L#{$top_srcdir}"
create_makefile 'rbs_extension'
