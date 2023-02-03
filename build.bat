@echo off
setlocal EnableDelayedExpansion

if not exist bin\ {
    mkdir bin
}

set c_filenames=
for /R %%f in (*.c) do (
    set c_filenames=!c_filenames! %%f
)

set assembly=lumi
set compiler_flags=/Zi

echo "Building %assembly%..."
cl %compiler_flags% %c_filenames% /Fe:bin\%assembly%.exe
