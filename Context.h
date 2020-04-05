/*
  This headers file contain the different Context used 
  throughout WdFilter
*/

// Process Context
enum MP_PROCESS_CTX_FLAGS
{
  ExcludedProcess = 0x1,
  MsMpEngProcess = 0x8,
  MpServiceSidProcess = 0x10,
  FriendlyProcess = 0x20,
  TrustedProcess = 0x40,
  MsSecesProcess = 0x80,
  SvchostProcess = 0x100,
  ImageWow64cpu = 0x200,
  ThreadNotifyRoutineExSet = 0x400,
  ProcessExplorer = 0x800,
};

enum MP_PROCESS_CTX_RULES
{
  DoNotNotifyDesktopHandlesOp = 0x8,
  AllowedToInjectCode = 0x10000,
  AllowIncomingCodeInjection = 0x80000,
  NotifyNewThreadDifferentProcess = 0x400000,
  AllowedToQuerySuspendResume = 0x1000000,
  AllowQuerySuspendResume = 0x2000000,
  NotifyNewThreadSameProcess = 0x10000000,
  NotifyProcessCmdLine = 0x20000000,
};

typedef struct _ProcessCtx
{
  USHORT Magic;
  USHORT StructSize;
  LIST_ENTRY ProcessCtxList;
  HANDLE ProcessId;
  _QWORD CreationTime;
  PUNICODE_STRING ProcessCmdLine;
  volatile signed __int32 RefCount;
  _DWORD ProcessFlags;
  _DWORD ProcessRules;
  _QWORD CodeInjectionTargetMask;
  _QWORD CodeInjectionRequestMask;
  MP_DOC_RULE *pDocRule;
  BOOLEAN (__fastcall *pCsrssPreScanHook)(PFLT_CALLBACK_DATA, FltStreamCtx *);
  int field_60;
  int NotificationsSent;
  int InjectionsHandlesCount;
  int field_6C;
  PVOID Wow64CpuImageBase;
  int ProcessSubsystemInformation;
  PUNICODE_STRING ImageFileName;
  BYTE HipRules[16];
  BYTE HipRules1[16];
  __int64 field_A8;
  __int64 field_B0;
  _PS_PROTECTION ProcessProtection;
  int StreamHandleCtxCount;
} ProcessCtx, *PProcessCtx;

typedef struct _MP_PROCESS_CTX_LIST_ENTRY
{
  __int16 Magic;
  __int16 Size;
  int field_4;
  PVOID *__shifted(MP_PROCESS_CTX_LIST_ENTRY,8) *PrevEntry;
  PProcessCtx ProcessCtx;
} MP_PROCESS_CTX_LIST_ENTRY, *PMP_PROCESS_CTX_LIST_ENTRY;

// Registry Contexts

typedef struct _KeyCtx
{
  USHORT Magic;
  USHORT Size;
  PVOID FreeKeyCtx;
  __int64 gap10;
  __int64 field_18;
  __int64 field_20;
  union TypeOfOperation Operation;

} KeyCtx, *PKeyCtx;

union TypeOfOperation : __int32
{
  CreateKeyCtx CreateKey;
  RenameKeyCtx RenameKey;
  SetValueKeyCtx SetValueKey;
  DeleteValueKeyCtx DeleteValueKey;
  DeleteKeyCtx DeleteKey;
}

struct CreateKeyCtx
{
  _QWORD RegKeyName;
  _QWORD RegMatchingInfo;
  __int64 field_38;
};

struct  RenameKeyCtx
{
  _QWORD RegKeyName;
  _QWORD RegMatchingInfo;
  _QWORD RegData;
};

struct  SetValueKeyCtx
{
  _QWORD RegKeyName;
  _QWORD KeyValuePartialInfo;
  _DWORD KeyType;
  _QWORD RegMatchingInfo;
};

struct  DeleteValueKeyCtx
{
  _QWORD RegKeyName;
  _QWORD RegMatchingInfo;
  PVOID KeyValuePartialInfo;
  _QWORD qword40;
};

struct  DeleteKeyCtx
{
  _QWORD qword28;
  _QWORD RegKeyName;
  PMP_REG_MATCHING_INFO MatchingInfo;
};


// Filtering Contexts - https://docs.microsoft.com/en-us/windows-hardware/drivers/ifs/managing-contexts
typedef struct _FltInstanceCtx
{
  _WORD Magic;
  _WORD Size;
  int field_4;
  LIST_ENTRY AnotherListEntry;
  UNICODE_STRING VolumeName;
  _UNICODE_STRING VolumeGuidName;
  GUID VolumeGuid;
  __int64 field_48;
  _DWORD InstanceFlags;
  int field_54;
  unsigned __int16 unsigned58;
  _DWORD dword5C;
  _DWORD dword60;
  int field_64;
  const PFLT_INSTANCE Instance;
  const PFLT_VOLUME Volume;
  FLT_FILESYSTEM_TYPE VolumeFileSystemType;
  _DWORD VolumeDeviceType;
  LIST_ENTRY StreamCtxList;
  int gap90;
  int field_94;
  LIST_ENTRY field_98;
  RTL_GENERIC_TABLE RtlGenericTable;
  int LimitSizeAVLTree;
  int GenericTableElementsCount;
  ERESOURCE FileStateGenericTableResource;
  _ERESOURCE InstanceExResource;
  LIST_ENTRY TransactionCtxList;
  PFLT_GENERIC_WORKITEM GenericWorkItem;
  union _SLIST_HEADER SingleListEntry;
  _DWORD dword1F0;
  PVOID qword1F8;
  char field_200;
} FltInstanceCtx, *PFltInstanceCtx;

typedef struct _TxfStreamCtx
{
  LIST_ENTRY StreamCtxList;
  __int64 field_10;
  _DWORD dword18;
  int field_1C;
  _QWORD qword20;
  __int64 gap28;
  volatile signed __int32 volatile30;
  int field_34;
  _QWORD qword38;
  PFLT_CONTEXT pFltContext;
  __int64 field_48;
  __int64 field_50;
  __int64 field_58;
  __int64 field_60;
  __int64 field_68;
  __int64 field_70;
  __int64 field_78;
  FltInstanceCtx *pFltInstanceCtx;
  __int64 field_88;
  __int64 field_90;
  PUNICODE_STRING field_98;
  PVOID field_A0;
  __int64 field_A8;
} TxfStreamCtx, *PTxfStreamCtx;


typedef struct _FltStreamHandleCtx
{
  __int16 Magic;
  __int16 Size;
  int field_4;
  __int64 field_8;
  PKTHREAD CurrentThread;
  ProcessCtx *pProcessCtx;
  int gap20;
  int AccessStateFlags;
  UNICODE_STRING SomeUnicodeString;
} FltStreamHandleCtx, *PFltStreamHandleCtx;


typedef struct _FltStreamCtx
{
  _WORD Magic;
  _WORD Size;
  FltInstanceCtx *pFltInstanceCtx;
  LIST_ENTRY StreamCtxList;
  _DWORD dword20;
  int field_24;
  __int64 field_28;
  _DWORD StreamCtxRules;
  _DWORD dword34;
  LIST_ENTRY char38;
  PFILE_OBJECT pFileObject;
  PKTHREAD CurrentThread;
  __int64 field_58;
  __int64 field_60;
  __int64 field_68;
  __int64 field_70;
  __int64 field_78;
  __int64 field_80;
  __int64 field_88;
  PKEVENT StreamCtxEvent;
  PVOID field_98;
  int IoPriority;
  _BYTE byteA4;
  _QWORD FileId;
  _QWORD qwordB0;
  unsigned __int64 StreamCtxLock;
  PVOID field_C0;
  __int64 field_C8;
  __int64 field_D0;
  __int64 field_D8;
  __int64 field_E0;
  __int64 field_E8;
  PVOID field_F0;
} FltStreamCtx, *PFltStreamCtx;


typedef struct _FltSectionCtx
{
  _WORD Magic;
  _WORD Size;
  int dword4;
} FltSectionCtx, *PFltSectionCtx;


typedef struct _FltTransactionCtx
{
  __int16 Magic;
  _WORD Size;
  _ERESOURCE ExResource;
  LIST_ENTRY TransactionCtxList;
  FltInstanceCtx *pFltInstanceCtx;
  LIST_ENTRY qword88;
  PUNICODE_STRING pGuidString;
  const GUID *const pGuid;
  int field_A8;
} FltTransactionCtx, *PFltTransactionCtx;