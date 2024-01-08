SET solutionPath=%1
SET outPath=%2
SET fbs=%3

echo MakeFlat %fbs%

cd /d %solutionPath%trd\FlatBuffer

start "" "flatc.exe" -c -o %outPath%\Generated %outPath%\Fbs\%fbs%

exit