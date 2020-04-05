typedef struct __unaligned _AuxPidCreationTime
{
  int ProcessId;
  LONGLONG CreationTime;
} AuxPidCreationTime, *PAuxPidCreationTime;

typedef struct __unaligned _AuxTidCreationTime
{
  int ThreadId;
  LONGLONG CreationTime;
} AuxTidCreationTime, *PAuxTidCreationTime;

struct ExcludedHardenedProcess
{
  PWSTR ProcessName;
  int Flag;
  int ProcessFlag;
};