#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

SetStoreCapsLockMode, Off

CapsLock & y::
Send, (
return

CapsLock & u::
Send, )
return

CapsLock & h::
Send, [
return

CapsLock & j::
Send, ]
return

CapsLock & n::
Send, {
return

CapsLock & m::
Send, }
return

CapsLock & e::
Send, ;
return

CapsLock & w::
Send, :
return

CapsLock & s::
Send, !
return

CapsLock & d::
Send, =
return

CapsLock & n::
Send, ñ
return

CapsLock & c::
Send, +
return

CapsLock & x::
Send, -
return