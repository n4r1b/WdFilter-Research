/*
  This headers file contain everything related and necessary
  to send and receive notifications
*/

// Async Messages
typedef struct _MP_ASYNC_NOTIFICATIONS
{
  USHORT Magic;
  USHORT Size;
  LIST_ENTRY AsyncNotificationsList;
  PVOID *__shifted(AsyncMessageData,8) pBuffer;
  _DWORD BufferSize;
} MP_ASYNC_NOTIFICATIONS, *PMP_ASYNC_NOTIFICATIONS;

struct  AsyncMessageData
{
  int Magic;
  int Size;
  __int64 NotificationNumber;
  _DWORD SizeOfData;
  int RefCount;
  MP_ASYNC_NOTIFICATION_OPERATION TypeOfOperation;
  union TypeOfMessage TypeOfMessage;
};

union TypeOfMessage
{
  ImageLoadAndProcessNotifyMessage ImageLoadAndProcessNotify;
  TrustedOrUntrustedProcessMessage TrustedProcess;
  ThreadNotifyMessage ThreadNotify;
  CheckJournalMessage CheckJournal;
  Wow64CpuLoadMessage Wow64CpuLoad;
  ObDesktopHandleMessage ObDesktopHandle;
  ObProcessHandleMessage ObProcessHandle;
};

enum MP_ASYNC_NOTIFICATION_OPERATION : __int32
{
  CreateProcess = 0x0,
  RegistryEvent = 0x1,
  SendFile = 0x2,
  LoadImage = 0x3,
  OpenProcess = 0x4,
  RawVolumeWrite = 0x5,
  CreateThread = 0x6,
  DocOpen = 0x7,
  PostMount = 0x8,
  OpenDesktop = 0x9,
  PanicMode = 0xB,
  CheckJournal = 0xC,
  TrustedOrUntrustedProcess = 0xD,
  LogPrint = 0xE,
  Wow64cpuLoad = 0xF,
  OpenWithoutRead = 0x10,
  EventsWorker = 0x11,
  DlpOnFileObjectClose = 0x13,
};

struct  ImageLoadAndProcessNotifyMessage
{
  AuxPidCreationTime ParentProcess;
  AuxPidCreationTime CurrentProcess;
  _BYTE CreationFlag;
  _BYTE ProcessFlags;
   int field_20;
  _DWORD FileNameLength;
  _DWORD OffsetToImageFileName;
  _DWORD SessionId;
  _DWORD CommandLineLenght;
  _DWORD OffsetToCommandLine;
  _DWORD TokenElevationType;
  _DWORD TokenElevation;
  _DWORD TokenIntegrityLevel;
  int Unk;
  AuxPidCreationTime CreatorProcess;
};

struct TrustedOrUntrustedProcessMessage
{
  BYTE UntrustedFlag;
  WCHAR ImageFileName[15];
};

struct ThreadNotifyMessage
{
  AuxPidCreationTime CurrentProcess;
  int CurrentThreadId;
  AuxPidCreationTime CreatedThreadProcess;
  AuxTidCreationTime CreatedThread;
  WCHAR ImageFileName[16];
};

struct CheckJournalMessage
{
  int FsControlCode;
  GUID VolumeGuid;
};

struct Wow64CpuLoadMessage
{
  int ProcessId;
  int ThreadId;
  __int64 Wow64CpuImageBase;
};

struct  ObDesktopHandleMessage
{
  AuxPidCreationTime Process;
  int ThreadId;
  int SessionId;
  char Operation;
  char KernelHandleFlag;
  int DesiredAccess;
  PWCHAR ObjectName;
};

struct  ObProcessHandleMessage
{
  AuxPidCreationTime Process;
  AuxPidCreationTime TargetProcess;
  int SessionId;
  int FinalDesiredAccess;
  int FileNameLen;
  int FileNameOffset;
  int TargeFileNameLen;
  int TargeFileNameOffset;
  BYTE HipRule[16];
  BYTE HipRule1[16];
  int Unk;
  MP_OB_NOTIFICATION_REASON NotificationReason;
};

enum MP_OB_NOTIFICATION_REASON
{
  DesiredAccessModified = 0x1,
  AllowCodeInjectionHIPSTrigger = 0x2,
  QuerySuspendResumeHIPSTrigger = 0x4,
  SameDesiredAccesAndAllowCodeInjectionHIPSTrigger = 0x8,
  SameDesiredAccessAndQuerySuspendResumeHIPSTrigger = 0x10,
};

// Sync messages
typedef struct _SyncMessageData
{
  __int16 Magic;
  __int16 SizeHeader;
  _DWORD TotalSize;
  MP_IO_PRIORITY MpIoPriority;
  MP_SYNC_NOTIFICATION_OPERATION TypeOfOperation;
  AuxPidCreationTime CurrentProcess;
  int SizeOfData;
  union TypeOfMessageSync TypeOfMessage;
} SyncMessageData, *PSyncMessageData;

union TypeOfMessageSync
{
  ThreadNotifySyncMessage ThreadNotify;
  ThreadNotifyCmdLine ThreadNotifyCmdLine[2];
};

enum MP_SYNC_NOTIFICATION_OPERATION
{
  NewImageLoadPerStream = 0x1,
  RegistryEventSync = 0x2,
  NewThreadDifferentProcess = 0x3,
  NewImageLoadPerProcess = 0x5,
  NewThreadSameProcess = 0x6,
  NewThreadAndCmdLine = 0x7,
};


struct MP_SYNC_NOTIFICATIONS_STATUS
{
  __int64 Timestamp;
  int NotificationsCount;
};

struct  ThreadNotifySyncMessage
{
  AuxTidCreationTime CreatedThread;
  AuxTidCreationTime CurrentThread;
  AuxPidCreationTime Process;
  __int64 VariableData;
  PVOID ThreadStartAddress;
};

struct ThreadNotifyCmdLine
{
  PUNICODE_STRING ProcessCtxCmdLine;
  PVOID ProcessCmdLineInformation;
};

/* 736 */
struct  ReplySyncMessage
{
  __int64 field_0;
  int OperationType;
  int field_C;
  int field_10;
};


// User-Mode Messages

enum MP_OPERATIONS
{
  MP_OPERATIONS_0 = 0x0,
  MP_OPERATIONS_1 = 0x1,
  CREATE_SECTION_FOR_SCAN = 0x2,
  QUERY_NAME = 0x3,
  PURGE_CACHE = 0x4,
  QUERY_STATISTICS = 0x5,
  QUERY_NAME_1 = 0x6,
  SET_PROCESS_EXCLUSION = 0x7,
  SET_VOLUME_EXCLUSION = 0x8,
  MP_OPERATIONS_9 = 0x9,
  REG_UPDATE_DATA = 0xA,
  SET_MONITOR_FLAGS = 0xB,
  QUERY_DOS_NAME = 0xC,
  SET_FILES_TIMEOUT = 0xD,
  MP_OPERATIONS_E = 0xE,
  MP_OPERATIONS_F = 0xF,
  MP_OPERATIONS_10 = 0x10,
  SET_DOC_OPEN_RULE = 0x11,
  QUERY_LOADED_DRIVERS = 0x12,
  MP_OPERATIONS_13 = 0x13,
  QUERY_FILE_USN = 0x14,
  QUERY_MOTW_ADS = 0x15,
  REGISTER_THREAD_BOOST = 0x16,
  MP_OPERATIONS_17 = 0x17,
  QUERY_TRUSTED_AND_UNTRUSTED_PROCESS = 0x18,
  QUERY_RUNTIME_DRIVERS = 0x19,
  SET_PROCESS_INFO = 0x1A,
  REGISTER_FRIENDLY_PROCESS = 0x1B,
  WRITE_BOOT_SECTOR = 0x1C,
  MP_OPERATIONS_1D = 0x1D,
  UPDATE_FG_USER_DATA = 0x1E,
  MP_OPERATIONS_1F = 0x1F,
  UPDATE_SYNC_MONITOR_CONFIG = 0x20,
  MP_OPERATIONS_21 = 0x21,
  SET_DATA_LOSS_PREVENTION = 0x22,
};

struct ReplyAsyncMessage
{
  char Magic;
  __int16 Size;
  __int64 field_8;
  __int64 field_10;
  __int64 field_18;
  __int64 field_20;
  __int64 field_28;
  __int64 field_30;
  __int64 field_38;
  __int64 field_40;
  char AccessDenied;
  __int64 field_50;
  __int64 field_58;
};

// Reg Notification

struct RegNotification
{
  PVOID KeyObject;
  PUNICODE_STRING KeyName;
  PUNICODE_STRING ValueName;
  PUNICODE_STRING NewKeyName;
  PUNICODE_STRING OldFileName;
  PUNICODE_STRING NewFileName;
  int ValueType;
  int ValueDataSize;
  __int64 ValueData;
  int NewValueType;
  int NewValueDataSize;
  _DWORD RegRestoreFlags;
  PVOID NewValueData;
  int FinalKeyRules;
  MP_REG_MATCH_INFO *MatchInfo;
};
