#pragma once

#ifndef _NATIVE_H
#define _NATIVE_H

#include <windows.h>

/* Native API Return Value Macros */
#define NT_SUCCESS( Status )              ( ( ( NTSTATUS )( Status ) ) >= 0  )
#define NT_INFORMATION( Status )          ( ( ( ( ULONG ) ( Status ) ) >> 30 ) == 1 )
#define NT_WARNING( Status )              ( ( ( ( ULONG ) ( Status ) ) >> 30 ) == 2 )
#define NT_ERROR( Status )                ( ( ( ( ULONG ) ( Status ) ) >> 30 ) == 3 )

typedef VOID (*PPS_POST_PROCESS_INIT_ROUTINE) ( VOID );

typedef struct _UNICODE_STRING
{
	USHORT                        Length;
	USHORT                        MaximumLength;
	PWSTR                         Buffer;
} UNICODE_STRING, *PUNICODE_STRING, **PPUNICODE_STRING;

typedef struct _PEB_LDR_DATA
{
	ULONG                         Length;
	BOOLEAN                       Initialized;
	HANDLE                        SsHandle;
	LIST_ENTRY                    InLoadOrderModuleList;
	LIST_ENTRY                    InMemoryOrderModuleList;
	LIST_ENTRY                    InInitializationOrderModuleList;
	PVOID                         EntryInProgress;
	BOOLEAN                       ShutdownInProgress;
	HANDLE                        ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _LDR_DATA_TABLE_ENTRY
{
    LIST_ENTRY                    InLoadOrderLinks;
    LIST_ENTRY                    InMemoryOrderLinks;
    LIST_ENTRY                    InInitializationOrderLinks;
    PVOID                         DllBase;
    PVOID                         EntryPoint;
    ULONG                         SizeOfImage;
    UNICODE_STRING                FullDllName;
    UNICODE_STRING                BaseDllName;
    ULONG                         Flags;
    USHORT                        LoadCount;
    USHORT                        TlsIndex;
    union
    {
        LIST_ENTRY                HashLinks;
        struct
        {
            PVOID                 SectionPointer;
            ULONG                 CheckSum;
        };
    };
    union
    {
        ULONG                     TimeDateStamp;
        PVOID                     LoadedImports;
    };
    PVOID                         EntryPointActivationContext;
    PVOID                         PatchInformation;
    LIST_ENTRY                    ForwarderLinks;
    LIST_ENTRY                    ServiceTagLinks;
    LIST_ENTRY                    StaticLinks;
    PVOID                         ContextInformation;
    ULONG_PTR                     OriginalBase;
    LARGE_INTEGER                 LoadTime;
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

typedef struct _RTL_USER_PROCESS_PARAMETERS 
{
    BYTE                          Reserved1[ 16 ];
    PVOID                         Reserved2[ 10 ];
    UNICODE_STRING                ImagePathName;
    UNICODE_STRING                CommandLine;
} RTL_USER_PROCESS_PARAMETERS,*PRTL_USER_PROCESS_PARAMETERS;

typedef struct _PEB 
{
	BYTE                          Reserved1[ 2 ];
	BYTE                          BeingDebugged;
	BYTE                          Reserved2[ 1 ];
	PVOID                         Reserved3[ 2 ];
	PPEB_LDR_DATA                 Ldr;
	PRTL_USER_PROCESS_PARAMETERS  ProcessParameters;
	BYTE                          Reserved4[ 104 ];
	PVOID                         Reserved5[ 52 ];
	PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
	BYTE                          Reserved6[ 128 ];
	PVOID                         Reserved7[ 1 ];
	ULONG                         SessionId;
} PEB,*PPEB;

NTSTATUS
NTAPI
LdrLoadDll(
	IN OPTIONAL PWSTR DllPath,
	IN OPTIONAL PULONG DllCharacteristics,
	IN PUNICODE_STRING DllName,
	OUT PVOID *DllHandle
	);

NTSTATUS
NTAPI
NtAllocateVirtualMemory (
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN ULONG_PTR ZeroBits,
    IN OUT PSIZE_T RegionSize,
    IN ULONG AllocationType,
    IN ULONG Protect
    );

NTSTATUS
NTAPI
NtFreeVirtualMemory (
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN OUT PSIZE_T RegionSize,
    IN ULONG FreeType
    );

NTSTATUS
NTAPI
NtProtectVirtualMemory (
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN OUT PSIZE_T RegionSize,
    IN ULONG NewProtect,
    OUT PULONG OldProtect
    );

NTSTATUS
NTAPI
TpAllocWork(
	PVOID WorkObject,
	PVOID WorkItem,
	PVOID WorkItemData,
	PVOID WorkItemRoutine
);

NTSTATUS
NTAPI
TpPostWork(
	PTP_WORK Work
);

NTSTATUS
NTAPI
TpReleaseWork(
	PTP_WORK Work
);

NTSTATUS
NTAPI
TpWaitForWork(
	PTP_WORK Work,
    BOOL     Data
);


#endif