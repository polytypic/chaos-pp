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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_FLAG_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_FLAG_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_one.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_FLAG */
#
# define CHAOS_PP_IS_FLAG(id) \
    CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_EMPTY(id CHAOS_PP_EMPTY()))( \
        1, CHAOS_PP_IS_ONE(id) \
    ) \
    /**/
# define CHAOS_PP_IS_FLAG_ID() CHAOS_PP_IS_FLAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_FLAG_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_FLAG)
# endif
#
# endif
