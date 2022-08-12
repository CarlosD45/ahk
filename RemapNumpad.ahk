#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

^m::
Send, 1
return

^,::
Send, 2
return

^.::
Send, 3
return

^j::
Send, 4
return

^k::
Send, 5
return

^l::
Send, 6
return

^u::
Send, 7
return

^i::
Send, 8
return

^o::
Send, 9
return

^/::
Send, 0
return

!j::
Send, {Left}
return

!k::
Send, {Down}
return

!l::
Send, {Right}
return

!i::
Send, {Up}
return