find_package (Doxygen)

message(VERBOSE "Doxigen settings :")
message(VERBOSE "libRational_SOURCE_DIR :  " ${libRational_SOURCE_DIR})
message(VERBOSE "libRational_BINARY_DIR :  " ${libRational_BINARY_DIR})
message(VERBOSE "DOXYGEN_EXECUTABLE :  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${libRational_SOURCE_DIR}/doc/Doxyfile-html.cmake ${libRational_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${libRational_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
