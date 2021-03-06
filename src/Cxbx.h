// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Cxbx.h
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#ifndef CXBX_H
#define CXBX_H

#define FUNC_EXPORTS __pragma(comment(linker, "/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__))

/*! \name primitive typedefs */
/*! \{ */
typedef signed int     sint;
typedef unsigned int   uint;
typedef char           int8;
typedef char           int08;
typedef short          int16;
typedef long           int32;
typedef unsigned char  uint8;
typedef unsigned char  uint08;
typedef unsigned short uint16;
typedef unsigned long  uint32;
/*! \} */

typedef signed char      s8;
typedef __int16          s16;
typedef __int32          s32;
typedef __int64          s64;
typedef unsigned char    u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;
typedef s8               i8;
typedef s16              i16;
typedef s32              i32;
typedef s64              i64;

/*! xbaddr is the type of a physical address */
typedef u32              xbaddr;

/*! xbnullptr is the type of null pointer address*/
#define xbnullptr nullptr

/*! xbnull is the type of null address or value*/
#define xbnull  0

/*! define this to track vertex buffers */
#define _DEBUG_TRACK_VB
/*! define this to track vertex shaders */
#define _DEBUG_TRACK_VS
/*! define this to track pixel shaders */
#define _DEBUG_TRACK_PS
/*! define this to track push buffers */
#define _DEBUG_TRACK_PB
/*! define this to track memory allocations */
#ifdef _DEBUG
//#define _DEBUG_ALLOC
#endif
/*! define this to trace intercepted function calls */
#ifdef _DEBUG
#define _DEBUG_TRACE 1
#endif
/*! define this to trace warnings */
#define _DEBUG_WARNINGS
/*! define this to trace vertex shader constants */
#define _DEBUG_TRACK_VS_CONST
/*! define this to print current configuration at kernel startup */
#define _DEBUG_PRINT_CURRENT_CONF

/*! define this to dump textures that have been set */
//#define _DEBUG_DUMP_TEXTURE_SETTEXTURE "D:\\xbox\\_textures\\"
/*! define this to dump textures that are registered */
//#define _DEBUG_DUMP_TEXTURE_REGISTER   "D:\\cxbx\\_textures\\"

extern bool g_bIntegrityChecking;
#ifdef _DEBUG
//extern void CxbxCheckIntegrity();
#define CXBX_CHECK_INTEGRITY() //CxbxCheckIntegrity()
#else
#define CXBX_CHECK_INTEGRITY()
#endif

/*! debug mode choices */
enum DebugMode { DM_NONE, DM_CONSOLE, DM_FILE };

/*! type of Xbe */
enum XbeType { xtRetail, xtDebug, xtChihiro };

extern XbeType g_XbeType;

/*! indicates emulation of an Chihiro (arcade, instead of Xbox console) executable */
extern bool g_bIsChihiro;

/*! maximum number of threads cxbx can handle */
#define MAXIMUM_XBOX_THREADS 256

/*! runtime DbgPrintf toggle boolean */
extern volatile bool g_bPrintfOn;

#ifdef _MSC_VER
#pragma warning(disable : 4477)
#endif

/*! DbgPrintf enabled if _DEBUG_TRACE is set */
#ifdef _DEBUG_TRACE
	#define DbgPrintf(fmt, ...) { \
        CXBX_CHECK_INTEGRITY(); \
        if(g_bPrintfOn) printf("[0x%.4X] "##fmt, GetCurrentThreadId(), ##__VA_ARGS__); \
     }
#else
	inline void null_func(...) { }
	#define DbgPrintf null_func
#endif

#endif
