#include <proxy.h>

FUNCTION NAKED VOID CALLBACK PROXY_FUNCTIOND( 4 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    __asm(
#ifdef _WIN64
        "push rbx                     \n"
        "sub  rsp,  0x20              \n"

        "mov  rbx,  rdx               \n"
        "mov  rax,  rdx               \n"

        "mov  rcx,  [ rax + 0x10 ]    \n"
        "mov  rdx,  [ rax + 0x18 ]    \n"
        "mov  r8,   [ rax + 0x20 ]    \n"
        "mov  r9,   [ rax + 0x28 ]    \n"

        "mov  rax,  [ rax ]           \n"
        "mov  r10,  0x04              \n"
        "push r10                     \n"
        "jmp  rax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "mov  [ rbx + 0x08 ], rax     \n"

        "add  rsp,  0x20              \n"
        "pop  rbx                     \n"

        "ret                          \n"
#else
        "mov  eax,  [ esp + 0x08 ]    \n"

        "push ebp                     \n"

        "mov  ebp, esp                \n"
        "sub  esp, 0x38               \n"

        "mov  ebx,  [ eax + 0x14 ]    \n"
        "mov  [ esp + 0x0C ], ebx     \n"

        "mov  ebx,  [ eax + 0x10 ]    \n"
        "mov  [ esp + 0x08 ], ebx     \n"

        "mov  ebx,  [ eax + 0x0C ]    \n"
        "mov  [ esp + 0x04 ], ebx     \n"

        "mov  ebx,  [ eax + 0x08 ]    \n"
        "mov  [ esp ], ebx            \n"

        "mov  eax,  [ eax ]           \n"
        "mov  ebx,  0x04              \n"
        "push ebx                     \n"
        "jmp  eax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "sub  esp, 0x10               \n"
        "leave                        \n"

        "mov  ebx, [ esp + 0x08 ]     \n"
        "mov  [ ebx + 0x04 ], eax     \n"

        "ret                          \n"
#endif
    );
}

FUNCTION NAKED VOID CALLBACK PROXY_FUNCTIOND( 5 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    __asm(
#ifdef _WIN64
        "push rbx                     \n"
        "sub  rsp,  0x30              \n"

        "mov  rbx,  rdx               \n"
        "mov  rax,  rdx               \n"

        "mov  rcx,  [ rax + 0x30 ]    \n"
        "mov  [ rsp + 0x20 ], rcx     \n"

        "mov  rcx,  [ rax + 0x10 ]    \n"
        "mov  rdx,  [ rax + 0x18 ]    \n"
        "mov  r8,   [ rax + 0x20 ]    \n"
        "mov  r9,   [ rax + 0x28 ]    \n"

        "mov  rax,  [ rax ]           \n"
        "mov  r10,  0x05              \n"
        "push r10                     \n"
        "jmp  rax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "mov  [ rbx + 0x08 ], rax     \n"

        "add  rsp,  0x30              \n"
        "pop  rbx                     \n"

        "ret                          \n"
#else
        "mov  eax,  [ esp + 0x08 ]    \n"

        "push ebp                     \n"

        "mov  ebp, esp                \n"
        "sub  esp, 0x38               \n"

        "mov  ebx,  [ eax + 0x18 ]    \n"
        "mov  [ esp + 0x10 ], ebx     \n"

        "mov  ebx,  [ eax + 0x14 ]    \n"
        "mov  [ esp + 0x0C ], ebx     \n"

        "mov  ebx,  [ eax + 0x10 ]    \n"
        "mov  [ esp + 0x08 ], ebx     \n"

        "mov  ebx,  [ eax + 0x0C ]    \n"
        "mov  [ esp + 0x04 ], ebx     \n"

        "mov  ebx,  [ eax + 0x08 ]    \n"
        "mov  [ esp ], ebx            \n"

        "mov  eax,  [ eax ]           \n"
        "mov  ebx,  0x05              \n"
        "push ebx                     \n"
        "jmp  eax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "sub  esp, 0x14               \n"
        "leave                        \n"

        "mov  ebx, [ esp + 0x08 ]     \n"
        "mov  [ ebx + 0x04 ], eax     \n"

        "ret                          \n"
#endif
    );
}

FUNCTION NAKED VOID CALLBACK PROXY_FUNCTIOND( 6 )( PTP_CALLBACK_INSTANCE Instance, LPROXY_ARGS Args, PTP_WORK Work )
{
    __asm(
#ifdef _WIN64
        "push rbx                     \n"
        "sub  rsp,  0x38              \n"

        "mov  rbx,  rdx               \n"
        "mov  rax,  rdx               \n"

        "mov  rcx,  [ rax + 0x30 ]    \n"
        "mov  [ rsp + 0x20 ], rcx     \n"

        "mov  rcx,  [ rax + 0x38 ]    \n"
        "mov  [ rsp + 0x28 ], rcx     \n"

        "mov  rcx,  [ rax + 0x10 ]    \n"
        "mov  rdx,  [ rax + 0x18 ]    \n"
        "mov  r8,   [ rax + 0x20 ]    \n"
        "mov  r9,   [ rax + 0x28 ]    \n"

        "mov  rax,  [ rax ]           \n"
        "mov  r10,  0x06              \n"
        "push r10                     \n"
        "jmp  rax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "mov  [ rbx + 0x08 ], rax     \n"

        "add  rsp,  0x38              \n"
        "pop  rbx                     \n"

        "ret                          \n"
#else
        "mov  eax,  [ esp + 0x08 ]    \n"
        "push ebp                     \n"

        "mov  ebp,  esp               \n"
        "sub  esp,  0x38              \n"

        "mov  ebx,  [ eax + 0x1C ]    \n"
        "mov  [ esp + 0x14 ], ebx     \n"

        "mov  ebx,  [ eax + 0x18 ]    \n"
        "mov  [ esp + 0x10 ], ebx     \n"

        "mov  ebx,  [ eax + 0x14 ]    \n"
        "mov  [ esp + 0x0C ], ebx     \n"

        "mov  ebx,  [ eax + 0x10 ]    \n"
        "mov  [ esp + 0x08 ], ebx     \n"

        "mov  ebx,  [ eax + 0x0C ]    \n"
        "mov  [ esp + 0x04 ], ebx     \n"

        "mov  ebx,  [ eax + 0x08 ]    \n"
        "mov  [ esp ], ebx            \n"

        "mov  eax,  [ eax ]           \n"
        "mov  ebx,  0x06              \n"
        "push ebx                     \n"
        "jmp  eax                     \n"

        "nop                          \n"
        "nop                          \n"
        "nop                          \n"
        "nop                          \n"

        "sub  esp, 0x18               \n"
        "leave                        \n"

        "mov  ebx, [ esp + 0x08 ]     \n"
        "mov  [ ebx + 0x04 ], eax     \n"

        "ret                          \n"
#endif
    );
}

FUNCTION VOID ToWideString( PWSTR Destination, PCHAR Source )
{
    while ( *Source != 0 )
    {
        *Destination++ = *Source++;
    }
}

FUNCTION INT StringLengthA( PCHAR String )
{
    INT Length = 0;

    while ( String[ Length ] != 0 )
    {
        Length++;
    }

    return Length;
}

FUNCTION PVOID PROXY_FIND_MARKER( PCHAR Ptr )
{
    /* Find our marker */
    while ( TRUE )
    {
        /* Check if we found our marker | nop nop nop nop */
        if ( PTR_TO_INT32( Ptr, 0 ) == 0x90909090 )
        {
            /* Return our pointer + 0x4, skip our marker */
            return Ptr + 0x4;
        }
        
        /* Increment our pointer */
        Ptr++;
    }
    
    /* We should never get here */
    return NULL;
}

FUNCTION DWORD PROXY_EXCEPTION_HANDLER( PEXCEPTION_POINTERS ExceptionInfo )
{
    PVOID Type = ExceptionInfo->ExceptionRecord->ExceptionAddress;
    DWORD Code = ExceptionInfo->ExceptionRecord->ExceptionCode;
    PVOID Call = NULL;

    /* We only care about our marker and access violations */
    if ( Code != EXCEPTION_ACCESS_VIOLATION || ! ( Type == 4 || Type == 5 || Type == 6 ) )
    {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    /* Handle our marker */
    if ( Type == 4 )
    {
        Call = PROXY_FIND_MARKER( QUOTE_SYMBOL( PROXY_FUNCTIOND( 4 ) ) );
    }
    else if ( Type == 5 )
    {
        Call = PROXY_FIND_MARKER( QUOTE_SYMBOL( PROXY_FUNCTIOND( 5 ) ) );
    }
    else if ( Type == 6 )
    {
        Call = PROXY_FIND_MARKER( QUOTE_SYMBOL( PROXY_FUNCTIOND( 6 ) ) );
    }

    /* Set our call address */
#ifdef _WIN64
    ExceptionInfo->ContextRecord->Rip = Call;
#else
    ExceptionInfo->ContextRecord->Eip = Call;
#endif

    /* Continue execution */
    return EXCEPTION_CONTINUE_EXECUTION;
}

FUNCTION PVOID InvokeProxy( PINSTANCE Instance, LPVOID Target, LPROXY_ARGS Args )
{
    PTP_WORK Work = NULL;

    /* Add exception handler */
    Instance->RtlAddVectoredExceptionHandler( TRUE, QUOTE_SYMBOL( PROXY_EXCEPTION_HANDLER ) );

    /* Create work */
    Instance->TpAllocWork( &Work, Target, Args, NULL );
    
    /* Post work */
    Instance->TpPostWork( Work );

    /* Wait work */
    Instance->TpWaitForWork( Work, FALSE );

    /* Release work */
    Instance->TpReleaseWork( Work );

    /* Remove exception handler */
    Instance->RtlRemoveVectoredExceptionHandler( QUOTE_SYMBOL( PROXY_EXCEPTION_HANDLER ) );

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
    Args->Call      = Instance->LdrLoadDll;
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
    Args->Call      = Instance->NtAllocateVirtualMemory;
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
    Args->Call      = Instance->NtFreeVirtualMemory;
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
    Args->Call      = Instance->NtProtectVirtualMemory;
    Args->Args[ 0 ] = -1;
    Args->Args[ 1 ] = &Memory;
    Args->Args[ 2 ] = &Length;
    Args->Args[ 3 ] = NewProtect;
    Args->Args[ 4 ] = OldProtect;

    /* Call proxy function */
    return NT_SUCCESS( InvokeProxy( Instance, QUOTE_SYMBOL( PROXY_FUNCTIOND( 5 ) ), Args ) );
}
