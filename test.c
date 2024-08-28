#include <proxy.h>
#include <stdio.h>

int main( void )
{
    INSTANCE   Instance = { 0 };
    HMODULE    Ntdll    = NULL;
    HMODULE    User32   = NULL;
    PROXY_ARGS Args     = { 0 };

    /* Load Ntdll */
    Ntdll = GetModuleHandleA( "ntdll" );

    /* Get Ntdll Functions */
    Instance.LdrLoadDll                        = GetProcAddress( Ntdll, "LdrLoadDll" );
    Instance.NtAllocateVirtualMemory           = GetProcAddress( Ntdll, "NtAllocateVirtualMemory" );
    Instance.NtProtectVirtualMemory            = GetProcAddress( Ntdll, "NtProtectVirtualMemory" );
    Instance.NtFreeVirtualMemory               = GetProcAddress( Ntdll, "NtFreeVirtualMemory" );

    Instance.RtlAddVectoredExceptionHandler    = GetProcAddress( Ntdll, "RtlAddVectoredExceptionHandler" );
    Instance.RtlRemoveVectoredExceptionHandler = GetProcAddress( Ntdll, "RtlRemoveVectoredExceptionHandler" );

    Instance.TpAllocWork                       = GetProcAddress( Ntdll, "TpAllocWork" );
    Instance.TpPostWork                        = GetProcAddress( Ntdll, "TpPostWork" );
    Instance.TpReleaseWork                     = GetProcAddress( Ntdll, "TpReleaseWork" );
    Instance.TpWaitForWork                     = GetProcAddress( Ntdll, "TpWaitForWork" );

    /*
        Demo
    */
    if ( ( User32 = BxLoadLibrary( &Instance, "user32" ) ) == NULL )
    {
        printf( "[-] Failed to load user32.dll\n" ); return -1;
    }

    /* Fill proxy args */
    Args.Call      = GetProcAddress( User32, "MessageBoxA" );
    Args.Args[ 0 ] = NULL;
    Args.Args[ 1 ] = "Hello World";
    Args.Args[ 2 ] = "Title";
    Args.Args[ 3 ] = MB_OK;

    /* Call proxy function */
    InvokeProxy( &Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 4 ) ), &Args );

    return 0;
}
