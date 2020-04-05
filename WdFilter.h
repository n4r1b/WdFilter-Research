/*
  This headers file contain the main structures used by WdFilter
*/

typedef struc _MP_DATA
{
  SHORT Magic;
  SHORT StructSize;
  PDRIVER_OBJECT pDriverObject;
  PFLT_FILTER MpFilter;
  NTSTATUS (__fastcall *pPsSetCreateProcessNotifyRoutineEx)(PCREATE_PROCESS_NOTIFY_ROUTINE_EX, BOOLEAN);
  NTSTATUS (__fastcall *pPsSetCreateProcessNotifyRoutineEx2)(PSCREATEPROCESSNOTIFYTYPE, PVOID, BOOLEAN);
  NTSTATUS (__fastcall *pPsSetCreateThreadNotifyRoutineEx)(PSCREATETHREADNOTIFYTYPE, PVOID);
  NTSTATUS (__fastcall *pObRegisterCallbacks)(POB_CALLBACK_REGISTRATION, PVOID *);
  void (__stdcall *pObUnRegisterCallbacks)(PVOID);
  NTSTATUS (__fastcall *pFltRegisterForDataScan)(const PFLT_INSTANCE);
  NTSTATUS (__fastcall *pFltCreateSectionForDataScan)(PFLT_INSTANCE Instance, PFILE_OBJECT FileObject, PFLT_CONTEXT SectionContext, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PLARGE_INTEGER MaximumSize, ULONG SectionPageProtection, ULONG AllocationAttributes, ULONG Flags, PHANDLE SectionHandle, PVOID *SectionObject, PLARGE_INTEGER SectionFileSize);
  NTSTATUS (__fastcall *pFltCloseSectionForDataScan)(PFLT_CONTEXT);
  NTSTATUS (__fastcall *pFltRequestFileInfoOnCreateCompletion)(PFLT_FILTER, PFLT_CALLBACK_DATA, ULONG);
  PVOID (__fastcall *pFltRetrieveFileInfoOnCreateCompletion)(PFLT_FILTER Filter, PFLT_CALLBACK_DATA Data, ULONG InfoClass, PULONG Size);
  NTSTATUS (__fastcall *pFsRtlQueryCachedVdl)(PFILE_OBJECT FileObject, PLONGLONG Vdl);
  PVOID pIoBoostThreadIo;
  PVOID pKeSetActualBasePriorityThread;
  PVOID pSeGetCachedSigningLevel;
  PIO_FOEXT_SILO_PARAMETERS (__fastcall *pIoGetSiloParameters)(const PFILE_OBJECT);
  char field_90;
  char PanicModeFlag;
  char field_92;
  char field_93;
  int ScannedFilesCount;
  int field_98;
  int field_9C;
  PEPROCESS MsMpEngProcess;
  HANDLE MsMpEngProcessId;
  int ConnectionPortCookieSet;
  PFLT_PORT FltProtectionControlPort;
  PFLT_PORT ProtectionControlPortServerCookie;
  PFLT_PORT FltProtectionPort;
  PFLT_PORT ProtectionPortServerCookie;
  PFLT_PORT FltProtectionVeryLowIoPort;
  PFLT_PORT ProtectionVeryLowIoServerCookie;
  PFLT_PORT FltProtectionRemoteIoPort;
  PFLT_PORT ProtectionRemoteIoServerCookie;
  PFLT_PORT FltProtectionAsyncPort;
  PFLT_PORT ProtectionAsyncServerCookie;
  int SomeScanFileFlag;
  int SendSyncNotificationFlag;
  KSEMAPHORE ScanFileSemaphore1;
  KSEMAPHORE ScanFileSempahore2;
  KSEMAPHORE SendingSyncSemaphore;
  PVOID pBootSectorCache;
  LIST_ENTRY FltInstanceCtxList;
  LIST_ENTRY FltStreamCtxList;
  PCWSTR RegistryParametersPath;
  char DriverVerifiedFlag;
  char field_1A1;
  char field_1A2;
  char field_1A3;
  int VerifyDriverLevelValue;
  __int64 ResetTimer;
  int FileScanConsecutiveTimeoutsCount;
  int field_1B4;
  KDPC WdFilterDPC;
  KTIMER WdFilterTimer;
  ERESOURCE MpDataResource;
  __int64 AsyncNotificationCount;
  int OsVersionMask;
  int MonitorFlags;
  __int64 field_2B0;
  __int64 field_2B8;
  PAGED_LOOKASIDE_LIST CompletionContextLookaside;
  NPAGED_LOOKASIDE_LIST WriteContextLookaside;
  NPAGED_LOOKASIDE_LIST field_3C0;
  PAGED_LOOKASIDE_LIST InstanceContextLookaside;
  PAGED_LOOKASIDE_LIST FltInputMessagesLookaside;
  PAGED_LOOKASIDE_LIST FltOutputMessagesLookaside;
  ULONG MpFilterEcpSize;
  __int64 field_5C8;
  __int64 field_5D0;
  __int64 field_5D8;
  __int64 field_5E0;
  __int64 field_5E8;
  __int64 field_5F0;
  __int64 field_5F8;
  NPAGED_LOOKASIDE_LIST ExtraCreateParamsLookaside;
  PVOID ObRegistrationHandle;
  PSID MpServiceSID;
  PSID NriServiceSID;
  PSID TrustedInstallerSID;
  int MaxLocalScanTimeout;
  int MaxNetworkScanTimeout;
  int field_6A8;
  int ObAndRegCallbackUnset;
  char RawVolumeWriteFlag;
  char MpOrWdFlag;
  char field_6B2;
  char field_6B3;
  int field_6B4;
  PVOID PowerSettingCbHandle;
  char LowPowerEpochOn;
  char field_6C1;
  char field_6C2;
  char field_6C3;
  int field_6C4;
  __int64 MachineUptime;
  MP_CSRSS_HOOK_DATA *pCsrssHookData;
  PCALLBACK_OBJECT pProcessNotificationCallback;
  PCALLBACK_OBJECT pNriNotificationCallback;
  __int64 NriNotificationCallbackHandle;
  __int64 field_6F0;
  __int64 field_6F8;
  LIST_ENTRY field_700;
  FAST_MUTEX MpDataFastMutex;
  __int64 field_748;
  __int64 field_750;
  __int64 field_758;
  __int64 field_760;
  __int64 field_768;
  __int64 field_770;
  __int64 field_778;
  PAGED_LOOKASIDE_LIST PagedLookasideMPbc;
  int field_800;
  int field_804;
  __int64 field_808;
  __int64 field_810;
  __int64 field_818;
  __int64 field_820;
  __int64 field_828;
  __int64 field_830;
  __int64 field_838;
  __int64 field_840;
  __int64 field_848;
  __int64 field_850;
  __int64 field_858;
  __int64 field_860;
  int CsvFileStateCacheType;
  int FileStateCachePolicy;
  __int64 field_870;
  int field_878;
  int field_87C;
  int CounterFileSystemTypeCSVFS;
  int field_884;
  int field_888;
   int RefsFileStateCacheType;
  int FileStateCachePolicy1;
  __int64 field_898;
  int field_8A0;
  int field_8A4;
  int CounterFileSystemTypeREFS;
  int field_8AC;
  int field_8B0;
  __int64 FltSendMessageTimeStamp;
  int FltSendMessageCount;
  int field_8C4;
  int SomethingWithSettingProcessInfo;
  int FltSendMessageError;
  int FltSendMessageErrorCode;
  int FltSendMessageStatusTimeout;
  int FltSendMessageReplyBufferMismatch;
  int AllowFilterManualDetach;
  LIST_ENTRY BootScanCtxList;
  ERESOURCE ExResource1;
  ERESOURCE ExResource2;
  int field_9C0;
  int field_9C4;
  PUNICODE_STRING SystemRootPath;
  int field_9D0;
  int field_9D4;
  char OpenWithoutReadNotificationFlag;
  RTL_GENERIC_TABLE RtlGenericTable;
  FAST_MUTEX WdFilterGenericTableMutex;
  MP_SYNC_NOTIFICATIONS_STATUS SyncNotifications[8];
  signed __int32 SyncNotificationRecvCount[8];
  signed __int32 ErrorSyncNotificationsCount[8];
  signed __int32 ErrorSyncNotificationsStatus[8];
  signed __int32 SyncNotificationsIoTimeoutCount[8];
  signed __int32 SyncNotificationsRecvErrorCount[8];
  int SyncMonitorNotificationFlag;
  int field_B84;
  __int64 SyncMonitorNotificationTimeout;
  __int64 RandNumber;
  char MpEaString[256];
  int AsyncDirectoryNotificationFlag;
  char DataLossPreventionFlag;
  char field_C9D;
  char field_C9E;
  char field_C9F;
  __int64 field_CA0;
  __int64 field_CA8;
  __int64 field_CB0;
  __int64 field_CB8;
} MP_DATA, *PMP_DATA;

typedef struct _MP_PROCESS_TABLE
{
  __int16 Magic;
  __int16 Size;
  ERESOURCE ExResource;
  PAGED_LOOKASIDE_LIST ProcessCtxLookaside;
  PAGED_LOOKASIDE_LIST ProcessCtxListLookaside;
  LIST_ENTRY *__shifted(ProcessCtx,8) (*ProcessCtxArray)[128];
  KEVENT ProcessTableEvent;
  _DWORD BeingAccessed;
  int TrustedProcessCtxCounter;
  int UntrustedProcessCtxCounter;
  int Unk;
  int CreateThreadNotifyLock;
} MP_PROCESS_TABLE, *PMP_PROCESS_TABLE;

typedef struct _MP_REG_DATA
{
  __int16 Magic;
  __int16 Size;
  ULONG_PTR RegDataPushLock;
  PVOID field_10;
  int field_18;
  int field_1C;
  NTSTATUS (__fastcall *pCmCallbackGetKeyObjectIDEx)(PLARGE_INTEGER Cookie, PVOID Object, PULONG_PTR ObjectID, PCUNICODE_STRING *ObjectName, ULONG Flags);
  void (__fastcall *pCmCallbackReleaseKeyObjectIDEx)(PCUNICODE_STRING ObjectName);
  LARGE_INTEGER CmCallbackGetKeyCookie;
  __int64 field_38;
  PAGED_LOOKASIDE_LIST NotificationsLookaside;
  FAST_MUTEX CmUnregisterFastMutex;
  LARGE_INTEGER CmRegisterCallbackCookie;
  int HardeningCbUnsetFlag;
  UNICODE_STRING LoadAppInitString;
  LIST_ENTRY ServiceKeyHardeningList;
  FAST_MUTEX CallCtxFastMutex;
  LIST_ENTRY CallCtxList;
  __int64 field_170;
  __int64 field_178;
  PAGED_LOOKASIDE_LIST CreateKeyCtxLookaside;
  PAGED_LOOKASIDE_LIST SetValueKeyCtxLookaside;
  PAGED_LOOKASIDE_LIST DeleteValueKeyCtxLookaside;
  PAGED_LOOKASIDE_LIST DeleteKeyCtxLookaside;
  PAGED_LOOKASIDE_LIST RegDataEntry;
  PAGED_LOOKASIDE_LIST KeyNamesLookaside;
  PAGED_LOOKASIDE_LIST RenameKeyCtxLookaside;
} MP_REG_DATA, *PMP_REG_DATA;

typedef struct _MP_CONFIG
{
  int ResetToUnknownTimer;
  int MaxLocalScanTimeout;
  int MaxNetworkScanTimeout;
  int MaxProcessCreationMessageTimeout;
  int MaxConsecutiveTimeoutsUntilPassThrough;
  int StartScanningAgainTimer;
  int DebugPassthroughEnabled;
  ULONG MaxAsyncNotificationCount;
  int AsyncStarvationLimit;
  int AsyncTimeout;
  int AllowManualDetach;
  int MaxCopyCacheSize;
  int KnownBadHashSize;
  char DirectionalScanningNonNTFS;
  char DisableQueryNameNormalize;
  char ThreadBoostingFlag;
  int CsvFileStateCacheType;
  int RefsFileStateCacheType;
  int FileStateCachePolicy;
  int DisableReadHooking;
  int FolderGuardDispatchTimer;
  int FolderGuardDispatchLimit;
  int DisableTransactionCallback;
  __int64 BreakOnStream;
} MP_CONFIG, *PMP_CONFIG;

typedef struct _MP_CONFIG_PARAMS
{
  PVOID *Name;
  PMP_CONFIG *pMpConfig;
  __int64 DefaultData;
} MP_CONFIG_PARAMS, *PMP_CONFIG_PARAMS;

typedef struct _MP_PROCESS_EXCLUSION
{
  ERESOURCE ProcessExclusionResource;
  PMP_PROCESS_EXCLUDED ProcessExclusionList;
  PMP_PROCESS_HARDENING_EXCLUDED ProcessHardenedExclusionList;
} MP_PROCESS_EXCLUSION, *PMP_PROCESS_EXCLUSION;

typedef struct _MP_ASYNC
{
  __int16 Magic;
  __int16 StructSize;
  LIST_ENTRY HighPriorityNotificationsList;
  LIST_ENTRY NotificationsList;
  PETHREAD WorkerThread;
  KEVENT AsyncNotificationEvent;
  KSEMAPHORE AsyncSemaphore;
  FAST_MUTEX FastMutex;
  int NotificationsCount;
  __int64 field_A8;
  __int64 field_B0;
  __int64 field_B8;
  PAGED_LOOKASIDE_LIST AsyncNotificationsLookaside;
  __int64 TotalSizeAsyncMessageSent;
  __int64 TotalSizeRemainingNotifications;
  int AsyncMessagesFailed;
  __int64 field_158;
  __int64 field_160;
  __int64 field_168;
  __int64 field_170;
  __int64 field_178;
} MP_ASYNC, *PMP_ASYNC;

typedef struct _MP_DOC_OPEN_RULES
{
  SHORT Magic;
  SHORT StructSize;
  SINGLE_LIST_ENTRY *__shifted(MP_DOC_RULE,8) DocObjectsList;
  ERESOURCE DocRulesResource;
  struct _PAGED_LOOKASIDE_LIST DocObjectsLookasideList;
} MP_DOC_OPEN_RULES, *PMP_DOC_OPEN_RULES;

typedef struct _MP_DRIVERS_INFO
{
  int Status;
  BYTE field_4[8];
  int ElamSignaturesMajorVer;
  int ElamSignatureMinorVer;
  LIST_ENTRY LoadedDriversList;
  PSLIST_ENTRY ElamRegistryEntries;
  LIST_ENTRY BootProcessList;
  PCALLBACK_OBJECT CallbackObject;
  PVOID BootDriverCallbackRegistration;
  struct _FAST_MUTEX DriversInfoFastMutex;
  int TotalDriverEntriesLenght;
  NTSTATUS (__fastcall *pSeRegisterImageVerificationCallback)(SE_IMAGE_TYPE, SE_IMAGE_VERIFICATION_CALLBACK_TYPE, PSE_IMAGE_VERIFICATION_CALLBACK_FUNCTION, PVOID, SE_IMAGE_VERIFICATION_CALLBACK_TOKEN, PVOID *);
  void (__fastcall *pSeUnregisterImageVerificationCallback)(PVOID);
  PVOID ImageVerificationCbHandle;
  int RuntimeDriversCount;
  int RuntimeDriversArrayLenght;
  PVOID RuntimeDriversArray;
  LIST_ENTRY RuntimeDriversList;
  __int64 field_C8;
} MP_DRIVERS_INFO, *PMP_DRIVERS_INFO;

struct MP_REG_HARDENING
{
  LPWSTR ServiceName;
  __int64 Flag;
};

struct MP_SERVICE_HARDENING
{
  LIST_ENTRY ServiceKeyHardeningList;
  PUNICODE_STRING ServiceKeyName;
};

typedef struct _MP_REG_KEY_NAME
{
  UNICODE_STRING KeyName;
  POBJECT_NAME_INFORMATION pObjectNameInfo;
  _DWORD ObjectNameSize;
  struct _OBJECT_NAME_INFORMATION ObjectNameInfo;
} MP_REG_KEY_NAME, *PMP_REG_KEY_NAME;

typedef struct _MP_DOC_RULE
{
  SHORT Magic;
  SHORT StructSize;
  int RefCount;
  SINGLE_LIST_ENTRY SingleListEntryDocRules;
  WCHAR DocProcessName[261];
  PCWSTR RuleExtension;
} MP_DOC_RULE, *PMP_DOC_RULE;

typedef struct _MP_CSRSS_HOOK_DATA
{
  POBJECT_NAME_INFORMATION ObjNameInfoSystemRootDir;
  POBJECT_NAME_INFORMATION ObjNameInfoWinSxsDir;
  POBJECT_NAME_INFORMATION ObjNameInfoCsrssPath;
  char HookSetFlag;
} MP_CSRSS_HOOK_DATA, *PMP_CSRSS_HOOK_DATA;

typedef struct _MP_PROCESS_HARDENING_EXCLUDED
{
  LIST_ENTRY ProcessExcludedList;
  PUNICODE_STRING ProcessPath;
  int ProcessHardeningExcludedFlag;
} MP_PROCESS_HARDENING_EXCLUDED, *PMP_PROCESS_HARDENING_EXCLUDED;

struct  MP_BOOT_PROCESS
{
  LIST_ENTRY BootProcessList;
  HANDLE ProcessId;
  HANDLE ParentProcessId;
  UNICODE_STRING ImageFileName;
  UNICODE_STRING CommandLine;
  _DWORD SomeFlag;
};

typedef struct _MP_PROCESS_CB_NOTIFY
{
  HANDLE ProcessId;
  HANDLE ParentId;
  PUNICODE_STRING ImageFileName;
  MP_NOTIFY_CB_OPERATION_TYPE OperationType;
  char ProcessFlags;
} MP_PROCESS_CB_NOTIFY, *PMP_PROCESS_CB_NOTIFY;

enum MP_NOTIFY_CB_OPERATION_TYPE
{
  ProcessCreation = 0x1,
  ProcessTermination = 0x2,
  SetProcessInfo = 0x3,
};

struct  MP_PROCESS_EXCLUDED
{
  SINGLE_LIST_ENTRY ExcludedProcessList;
  UNICODE_STRING ProcessFullPath;
  char NoBackslashFlag;
  char WildcardPathFlag;
};

typedef struct _MP_SCAN_FILE
{
  __int16 Magic;
  __int16 Size;
  _DWORD VariableSize;
  MP_IO_PRIORITY IoPriority;
  _DWORD dword18;
  _DWORD ScanAttributes;
  signed __int64 StreamSize;
  _QWORD RequestorProcessId;
  int ProcessRules;
  __unaligned __declspec(align(1)) __int64 RequestorProcessCreationTime;
  int field_3C;
  HANDLE CurrentThreadId;
  _QWORD TokenSessionId;
  __int64 AsyncNotificationsCount;
  __int64 field_58;
  _WORD word58;
  _OWORD oword5A;
  _OWORD oword6A;
  _OWORD oword7A;
  _OWORD oword8A;
  _OWORD oword9A;
  _OWORD owordAA;
  _WORD wordBA;
  _WORD wordBC;
  _WORD wordBE;
  char charC0;
  __unaligned __declspec(align(1)) __int64 gapC1;
  __unaligned __declspec(align(1)) __int64 field_DF;
  __unaligned __declspec(align(1)) __int64 field_E7;
  __unaligned __declspec(align(1)) __int64 field_EF;
  __unaligned __declspec(align(1)) __int64 field_F7;
  __unaligned __declspec(align(1)) __int64 field_FF;
  __unaligned __declspec(align(1)) __int64 field_107;
  __unaligned __declspec(align(1)) __int64 field_10F;
  char field_117;
  int field_118;
  int field_11C;
  __int64 FileId;
  _QWORD qword110;
  int RequestorMode;
  int field_134;
  _QWORD qword120;
  ACCESS_MASK DesiredAccess;
  int ShareAccess;
  _DWORD CreateOptions;
  _DWORD dword134;
  _DWORD AccessStateFlags;
  _DWORD dword13C;
  _DWORD BackingFileInfo;
  _DWORD dword144;
  __int64 field_160;
  __int64 field_168;
  __int64 field_170;
  __int64 field_178;
  FILE_BASIC_INFORMATION FileBasicInformation;
  int field_1A8;
  __int16 field_1AC;
  __int16 field_1AE;
  _OWORD oword190;
  _QWORD qword1A0;
  _DWORD dword1A8;
  _WORD word1AC;
  _WORD word1AE;
  char char1B0;
  __unaligned __declspec(align(1)) __int64 field_1D1;
  __unaligned __declspec(align(1)) int field_1D9;
} MP_SCAN_FILE, *PMP_SCAN_FILE;

typedef struct _MP_EP_GLOBALS
{
  UNICODE_STRING RegistryPath;
  PVOID pHandleRegistration;
  PVOID IoUnregisterBootDriverCallback;
  DWORD Magic;
  DWORD SignaturesVersionMajor;
  DWORD SignaturesVersionMinor;
  LIST_ENTRY DriversListEntry;
  PSLIST_ENTRY ElamRegistryEntries;
  PCALLBACK_OBJECT pWdCallbackObject;
  LARGE_INTEGER Cookie;
  _QWORD Unk_Unused1;
  SLIST_HEADER SlistHeader;
  DWORD LoadedDriversCount;
  DWORD LoadedDriversArrayLen;
  PVOID LoadedDriversArray;
  DWORD TotalModulesEntryLen;
  BYTE EntryPointWdFilter[32];
  BYTE FlagWdOrMp;
  BYTE FlagTestMode;
  BYTE FlagPersistElamInfo;
  _QWORD Unk_Unused2;
} MP_EP_GLOBALS, *PMP_EP_GLOBALS;

typedef struct _MP_DRIVER_INFO_EX
{
  __int16 Magic;
  __int16 Size;
  _QWORD WdFilterFlag;
  PVOID SameIndexList;
  _QWORD IndexHash;
  MP_DRIVER_INFO DriverInfo;
} MP_DRIVER_INFO_EX, *PMP_DRIVER_INFO_EX;

struct MP_ELAM_REGISTRY_ENTRY
{
  PSLIST_ENTRY SlistEntry;
  __int64 field_8;
  UNICODE_STRING field_10;
  UNICODE_STRING field_20;
  int field_30;
  int field_34;
  int field_38;
  int field_3C;
};

typedef struct _MP_DRIVER_INFO
{
  LIST_ENTRY DriverInfoList;
  UNICODE_STRING ImageName;
  UNICODE_STRING DriverRegistryPath;
  UNICODE_STRING CertPublisher;
  UNICODE_STRING CertIssuer;
  PVOID ImageHash;
  int ImageHashAlgorithm;
  int ImageHashLength;
  PVOID CertThumbprint;
  int ThumbprintHashAlgorithm;
  int CertificateThumbprintLength;
  PVOID ImageBase;
  __int64 ImageSize;
  int ImageFlags;
  int DriverClassification;
  int ModuleEntryEnd;
} MP_DRIVER_INFO, *PMP_DRIVER_INFO;

typedef struct _MP_REG_DATA_ENTRY
{
  LIST_ENTRY RegDataEntriesList;
  MP_KEY_ENTRY *RegKeyEntry;
  UNICODE_STRING RegKeyName;
} MP_REG_DATA_ENTRY, *PMP_REG_DATA_ENTRY;

typedef struct _MP_REG_MATCHING_INFO
{
  unsigned int Size;
  _DWORD dword4;
  PVOID pvoid8;
  char field_10;
  __declspec(align(4)) char field_14;
  char field_15;
  char field_16;
} MP_REG_MATCHING_INFO, *PMP_REG_MATCHING_INFO;

typedef struct _MP_KEY_ENTRY
{
  MP_KEY_ENTRY *SubKey;
  MP_KEY_ENTRY *NextKey;
  PWSTR KeyName;
  USHORT field_18;
  __int64 field_20;
  PVOID field_28;
} MP_KEY_ENTRY, *PMP_KEY_ENTRY;

