FIND_PATH(LIBCURL_INCLUDE_DIR NAMES curl/curl.h)
MARK_AS_ADVANCED(LIBCURL_INCLUDE_DIR)

FIND_LIBRARY(LIBCURL_LIBRARY NAMES curl)
MARK_AS_ADVANCED(LIBCURL_LIBRARY)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBCURL DEFAULT_MSG LIBCURL_LIBRARY LIBCURL_INCLUDE_DIR)