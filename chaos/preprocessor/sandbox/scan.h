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
# ifndef CHAOS_PREPROCESSOR_DETAIL_SANDBOX_SCAN_H
# define CHAOS_PREPROCESSOR_DETAIL_SANDBOX_SCAN_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_SCAN */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SCAN(p, n, ...) CHAOS_PP_SCAN_BYPASS(CHAOS_PP_LIMIT_EXPR,, n, p ## __VA_ARGS__)
#    define CHAOS_PP_SCAN_ID() CHAOS_PP_SCAN
#    define CHAOS_PP_SCAN_ CHAOS_PP_LAMBDA(CHAOS_PP_SCAN_ID)()
# endif
#
# /* CHAOS_PP_SCAN_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SCAN_BYPASS(s, p, n, ...) CHAOS_IP_SCAN_I(s,, CHAOS_PP_DEC(n), p ## __VA_ARGS__)
#    define CHAOS_PP_SCAN_BYPASS_ID() CHAOS_PP_SCAN_BYPASS
#    define CHAOS_PP_SCAN_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SCAN_BYPASS_ID)()
#    define CHAOS_IP_SCAN_I(s, p, n, ...) \
        CHAOS_PP_IF(n)( \
            CHAOS_IP_SCAN_II, CHAOS_IP_SCAN_V \
        )(s,, CHAOS_PP_DEC(n), p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_SCAN_II(s, p, n, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SCAN_III( \
            CHAOS_PP_PREV(s),, n, p ## __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_SCAN_INDIRECT() CHAOS_IP_SCAN_III
#    define CHAOS_IP_SCAN_III(s, p, n, ...) \
        CHAOS_PP_IF(n)( \
            CHAOS_IP_SCAN_IV, CHAOS_IP_SCAN_V \
        )(s,, n, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_SCAN_IV(s, p, n, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_SCAN_INDIRECT)()( \
            CHAOS_PP_PREV(s),, CHAOS_PP_DEC(n), p ## __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_SCAN_V(s, p, n, ...) p ## __VA_ARGS__
# endif
#
# endif