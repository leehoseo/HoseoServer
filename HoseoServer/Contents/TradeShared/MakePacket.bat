SET solutionPath=%1
SET projectPath=%2

start "" "%solutionPath%trd\FlatBuffer\GenerateFlatBuffer.bat" %solutionPath% %projectPath% Trade.fbs

exit