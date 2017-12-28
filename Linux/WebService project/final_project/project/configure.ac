#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([tic_tac_toe], [1.0], [timorsa@ac.sce.ac.il])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/tic_tac_toe/tic_tac_toe.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AM_PROG_LIBTOOL

AC_CONFIG_MACRO_DIR([m4])


# Checks for libraries.


# Checks for library functions.
AC_CHECK_HEADERS([stdlib.h])


AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/tic_tac_toe/Makefile
                 src/util/Makefile])


AC_OUTPUT
