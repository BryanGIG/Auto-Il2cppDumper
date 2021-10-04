# Auto-Il2cppDumper
This is for helping you get dump.cs from Android Il2cpp game

# Important
This project is modifying version of [Riru-Il2cppDumper](https://github.com/Perfare/Riru-Il2CppDumper) <br />
Credit : [Perfare](https://github.com/Perfare)

# Changelog Update
- Fix error in version 2020.2.0f1 and up
- Migrate from kotlin -> java
- Migrate from cmake-build -> ndk-build [enhancement from #1]

# Usage 
- change unity version in Includes/il2cpp_dump.h with your game unity version
- if the unity version is 2018.3.0f2 and above please define VersionAboveV24
- if the unity version is 2020.2.0f1 and above please define VersionAbove2020V2 
- Build with Android Studio
- Decompile the game 
- copy result libnative-lib.so into decompiled lib folder apk
- search the "main" activity of the game
- put this on onCreate function
```smali
 const-string v0, "native-lib"
 
 invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```
- re-compile and run it
- once the dump complete it will auto generate dump.cs in /sdcard/Download

# Credit :
[Riru-Il2cppDumper](https://github.com/Perfare/Riru-Il2CppDumper) <br/>
[Il2CppVersions](https://github.com/nneonneo/Il2CppVersions)