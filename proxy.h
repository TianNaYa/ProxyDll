#pragma once

#ifndef _PROXY_H
#define _PROXY_H

#include <windows.h>
#include <native.h>

#ifndef FUNCTION
#define FUNCTION
#endif

#ifdef _WIN64
#define QUOTE_SYMBOL( x )    x
#else
#define QUOTE_SYMBOL( x )    x
#endif

#define RVA_2_VA(T, B, R)                       ( T )( ( PVOID ) B + R )
#define RVA_2_VA_VALUE(T, B, R)                 *RVA_2_VA( T, B, R )
#define C_PTR( x )                              ( ( PVOID )    x )
#define U_PTR( x )                              ( ( UINT_PTR ) x )

#define PTR_TO_INT32( x, o )                    RVA_2_VA_VALUE( PDWORD32, x, o )
#define PTR_TO_INT64( x, o )                    RVA_2_VA_VALUE( PDWORD64, x, o )
#define PTR_TO_INT16( x, o )                    RVA_2_VA_VALUE( PWORD,    x, o )
#define PTR_TO_INT08( x, o )                    RVA_2_VA_VALUE( PBYTE,    x, o )

#define NAKED                __declspec( naked )
#define PROXY_ARGS_SIZE( N ) ( sizeof( PROXY_ARGS ) + ( N ) * sizeof( PVOID ) )
#define PROXY_FUNCTIOND( N ) PROXY_FUNCTION_NAME_##N

#define DEFINE_FUNC( x )     __typeof__( x ) * x

typedef struct
{
    LPVOID Call;
    LPVOID Retu;
    LPVOID Args[ 0 ];
} PROXY_ARGS, *LPROXY_ARGS;

typedef struct {
    DEFINE_FUNC( LdrLoadDll );
    DEFINE_FUNC( NtAllocateVirtualMemory );
    DEFINE_FUNC( NtProtectVirtualMemory );
    DEFINE_FUNC( NtFreeVirtualMemory );

    DEFINE_FUNC( TpAllocWork );
    DEFINE_FUNC( TpPostWork );
    DEFINE_FUNC( TpReleaseWork );
    DEFINE_FUNC( TpWaitForWork );

    DEFINE_FUNC( RtlAddVectoredExceptionHandler );
    DEFINE_FUNC( RtlRemoveVectoredExceptionHandler );
} INSTANCE, *PINSTANCE;

PVOID InvokeProxy( PINSTANCE Instance, LPVOID Target, LPROXY_ARGS Args );
PVOID BxLoadLibrary( PINSTANCE Instance, PCHAR String );
PVOID BxVirtualAlloc( PINSTANCE Instance, LPVOID Address, DWORD Size, DWORD AllocationType, DWORD Protect );
BOOL  BxVirtualFree( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD FreeType );
BOOL  BxVirtualProtect( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD NewProtect, PDWORD OldProtect );

VOID  CALLBACK PROXY_FUNCTIOND( 4 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work );
VOID  CALLBACK PROXY_FUNCTIOND( 5 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work );
VOID  CALLBACK PROXY_FUNCTIOND( 6 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work );

#endif
