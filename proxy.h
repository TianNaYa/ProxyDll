#pragma once

#ifndef _PROXY_H
#define _PROXY_H

#include <windows.h>
#include <native.h>

#ifndef FUNCTION
#define FUNCTION
#endif

#define PROXY_CALL_1( X )    ( ( PVOID( WINAPI * )( LPVOID ) ) X )
#define PROXY_CALL_2( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID ) ) X )
#define PROXY_CALL_3( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_4( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_5( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_6( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_7( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_8( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID ) ) X )
#define PROXY_CALL_9( X )    ( ( PVOID( WINAPI * )( LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID, LPVOID ) ) X )

#define PROXY_CALL( X, Y )   PROXY_CALL_##X( Y )

#ifdef _WIN64
#define QUOTE_SYMBOL( x )    x
#else
#define QUOTE_SYMBOL( x )    x
#endif

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
    struct {
        DEFINE_FUNC( LdrLoadDll );
        DEFINE_FUNC( NtAllocateVirtualMemory );
        DEFINE_FUNC( NtProtectVirtualMemory );
        DEFINE_FUNC( NtFreeVirtualMemory );

        DEFINE_FUNC( TpAllocWork );
        DEFINE_FUNC( TpPostWork );
        DEFINE_FUNC( TpReleaseWork );
        DEFINE_FUNC( TpWaitForWork );
    } Api ;
    
    struct {
        PVOID Ntdll;
    } Dll;
} INSTANCE, *PINSTANCE;

PVOID BxLoadLibrary( PINSTANCE Instance, PCHAR String );
PVOID BxVirtualAlloc( PINSTANCE Instance, LPVOID Address, DWORD Size, DWORD AllocationType, DWORD Protect );
BOOL  BxVirtualFree( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD FreeType );
BOOL  BxVirtualProtect( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD NewProtect, PDWORD OldProtect );

#endif
