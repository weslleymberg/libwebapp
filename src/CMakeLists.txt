add_library(webapp hash.c http_messages.c iterator.c)

install(TARGETS webapp DESTINATION lib)
install(FILES hash.h http_messages.h iterator.h DESTINATION include/libwebapp)
