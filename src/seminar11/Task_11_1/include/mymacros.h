#ifndef MYMACROS_H
#define MYMACROS_H

#define MY_MAX(a,b) (( (a) > (b) ) ? (a) : (b))
#define MY_MIN(a,b) (( (a) < (b) ) ? (a) : (b))
#define MY_ABS(x)   (( (x) < 0 ) ? -(x) : (x))
#define MY_CLAMP(x,lo,hi) (( (x) < (lo) ) ? (lo) : ( ((x) > (hi)) ? (hi) : (x) ))

#endif
