void __ExceptionPtrCreate(void*) {};
void __ExceptionPtrDestroy(void*) {};
void __ExceptionPtrCopy(void*, const void*) {};
void __ExceptionPtrAssign(void*, const void*) {};
bool __ExceptionPtrCompare(const void*, const void*) { return false; };
bool __ExceptionPtrToBool(const void*) { return false; };
void __ExceptionPtrSwap(void*, void*) {};
void __ExceptionPtrCurrentException(void*) {};
void __ExceptionPtrRethrow(const void*) {};
void __ExceptionPtrCopyException(void*, const void*, const void*) {};