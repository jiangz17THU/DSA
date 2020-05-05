:loop
random.exe >in.txt
std.exe <in.txt >ans.txt
DSA2-1.exe <in.txt >out.txt
fc out.txt ans.txt
if not errorlevel 1 goto loop
pause
