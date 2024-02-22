call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsamd64_x86.bat"
cd \myco\edk2
call edksetup.bat
call build -p EmulatorPkg/EmulatorPkg.dsc -a X64 -b DEBUG -t VS2019 -DSECURE_BOOT_ENABLE=TRUE -DSMM_REQUIRE -j c:\tmp\log\bldEdk2.log -v
