add_compile_options(-Wall)
add_compile_options(-g)

option( TRACE "Debug Trace" OFF)
if (TRACE)
add_compile_options(-finstrument-functions)
add_compile_options(-D_GNU_SOURCE)
endif()
