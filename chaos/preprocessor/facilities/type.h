# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_TYPE_H
# define CHAOS_PREPROCESSOR_FACILITIES_TYPE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/rail.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TYPE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TYPE(...) CHAOS_PP_RAIL(CHAOS_PP_TUPLE_REM)(?)(__VA_ARGS__)
#    define CHAOS_PP_TYPE_ID() CHAOS_PP_TYPE
#    define CHAOS_PP_TYPE_ CHAOS_PP_LAMBDA(CHAOS_PP_TYPE_ID)()
# endif
#
# endif
