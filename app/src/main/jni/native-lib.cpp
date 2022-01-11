#include <jni.h>
#include <string>
#include <thread>
#include <dlfcn.h>
#include <unistd.h>
#include "Includes/il2cpp_dump.h"

bool isLibraryLoaded(const char *libraryName) {
    char line[512] = {0};
    FILE *fp = fopen("/proc/self/maps", "rt");
    if (fp != nullptr) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, libraryName)) {
                return true;
            }
        }
        fclose(fp);
    }
    return false;
}
#define libTarget "libil2cpp.so"

void dump_thread() {
    do {
        sleep(1);
    } while (!isLibraryLoaded(libTarget));
    sleep(4);
    auto il2cpp_handle = dlopen(libTarget, 4);
    il2cpp_dump(il2cpp_handle, "/sdcard/Download");
}

__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    std::thread(dump_thread).detach();
}
