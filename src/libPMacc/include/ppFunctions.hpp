/**
 * Copyright 2013-2017 Axel Huebl, Rene Widera
 *
 * This file is part of libPMacc.
 *
 * libPMacc is free software: you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License or
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libPMacc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License and the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * and the GNU Lesser General Public License along with libPMacc.
 * If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once


#define PMACC_MIN(x,y) (((x)<=(y))?x:y)
#define PMACC_MAX(x,y) (((x)>(y))?x:y)


#define PMACC_JOIN_DO(x,y) x##y
#define PMACC_JOIN(x,y) PMACC_JOIN_DO(x,y)

#define PMACC_MAX_DO(what,x,y) (((x)>(y))?x what:y what)
#define PMACC_MIN_DO(what,x,y) (((x)<(y))?x what:y what)

/**
 * Returns number of args... arguments.
 *
 * @param type type of the arguments in ...
 * @param ... arguments
 */
#define PMACC_COUNT_ARGS(type,...)  (sizeof((type[]){type{}, ##__VA_ARGS__})/sizeof(type)-1u)

/**
 * Check if ... has arguments or not
 *
 * Can only used if values of ... can be casted to int type
 *
 * @param ... arguments
 * @return false if no arguments are given, else true
 */
#define PMACC_HAS_ARGS(...)  ((sizeof((int[]){0, ##__VA_ARGS__}))==sizeof(int)?false:true)

/** round up to next higher pow 2 value
 *
 * - if value is pow2, value is returned
 * - maximal pow 2 value is 128
 * - negative values are not supported
 *
 * @param value integral number between [1,Inf]
 * @return next higher pow 2 value
 */
#define PMACC_ROUND_UP_NEXT_POW2(value) \
        ((value)==1?1:                  \
        ((value)<=2?2:                  \
        ((value)<=4?4:                  \
        ((value)<=8?8:                  \
        ((value)<=16?16:                \
        ((value)<=32?32:                \
        ((value)<=64?64:128             \
        )))))))
