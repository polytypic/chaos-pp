# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_FROM_TO_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC(from, to, sep, ...) CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S(CHAOS_PP_STATE(), from, to, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC(from, to, sep, macro, data) CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S(CHAOS_PP_STATE(), from, to, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_ID() CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC
#
# /* CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S(s, from, to, sep, ...) \
        CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S(s, from, to, sep, macro, data) CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S_ID() CHAOS_PP_DELINEATE_FROM_TO_PARAMETRIC_S
#
# define CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), from, to, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_INDIRECT() CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_I
# define CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_I(s, o, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_LIMIT_EXPR))( \
        CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_II, CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_III \
    )(CHAOS_PP_PHASE(0), s, o, from, to, s1, s2, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_II(_, s, o, from, to, s1, s2, macro, _m, pd) \
    _(1, CHAOS_PP_IIF)(CHAOS_PP_NOT_EQUAL(from, to))( \
        _(1, CHAOS_PP_EXPR_S)(s), CHAOS_PP_TUPLE_EAT(1) \
    )( \
        _(1, s1)() _(1, _m)()(o, macro, from _(1, CHAOS_PP_EXPOSE)(pd)) \
        _(1, CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_INDIRECT)()( \
            CHAOS_PP_NEXT(s), o, CHAOS_PP_INC(from), to, s2, s2, macro, _m, pd \
        ) \
    ) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_III(_, s, o, from, to, s1, s2, macro, _m, pd) \
    CHAOS_IP_DELINEATE_FROM_TO_PARAMETRIC_II(CHAOS_PP_PHASE(1), o, o, from, to, s1, s2, macro, _m, pd) \
    /**/
#
# endif