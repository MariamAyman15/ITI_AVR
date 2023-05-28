#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var,b) ((var)|=(1<<b))
#define CLR_BIT(var,b) ((var) &= ~((1<<b)))
#define TOGGLE_BIT(var,b) ((var) ^=(1<<b))
#define GET_BIT(var,b)(((var)>>(b))&1)
#define NULL_POINTER ((void*)0)
#define NULL  0
#endif
